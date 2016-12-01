#include "Arduino.h"
#include <EDB.h>

#include <SPI.h>
#include <SD.h>

#define SD_PIN 10  
#define TABLE_SIZE 8192

char* db_name = "/db/test.db";
File dbFile;

struct tableRecord {
    int id;
    String firstName;
    String lastName;
    String phoneNumber;
}

tableRecord;

void writer (unsigned long address, byte data) {
    digitalWrite(13, HIGH);
    dbFile.seek(address);
    dbFile.write(data);
    dbFile.flush();
    digitalWrite(13, LOW);
}

byte reader (unsigned long address) {
    digitalWrite(13, HIGH);
    dbFile.seek(address);
    byte b = dbFile.read();
    digitalWrite(13, LOW);
    return b;
}

EDB db(&writer, &reader);

void setup() {
    pinMode(13, OUTPUT);
    digitalWrite(13, LOW);

    Serial.begin(9600);
    
    if (!SD.begin(SD_PIN)) {
        Serial.println("Inserte la tarjeta SD");
        return;
    }

    if (!SD.exists("/db")) {
        Serial.println("Creando directorio");
        SD.mkdir("/db");
    }

    if (SD.exists(db_name)) {

        dbFile = SD.open(db_name, FILE_WRITE);

        if (!dbFile) {
            dbFile = SD.open(db_name, FILE_WRITE);
        }

        if (dbFile) {
            Serial.print("Abriendo tabla...");
            EDB_Status result = db.open(0);
            if (result == EDB_OK) {
                Serial.println("OK");
            } else {
                Serial.println("ERROR");
                Serial.println("No se encontró ninguna base de datos en el archivo" + String(db_name));
                Serial.print("Creando tabla...");
                db.create(0, TABLE_SIZE, (unsigned int)sizeof(tableRecord));
                Serial.println("OK");
                return;
            }
        } else {
            Serial.println("No se pudo abrir el archivo " + String(db_name));
            return;
        }
    } else {
        Serial.print("Creando tabla... ");
        // create table at with starting address 0
        dbFile = SD.open(db_name, FILE_WRITE);
        db.create(0, TABLE_SIZE, (unsigned int)sizeof(tableRecord));
        Serial.println("OK");
    }

    //dbFile.close();
    Serial.println();
    printMenu();
}

void loop() {
  
    if (Serial.available()) {
        switch (Serial.read()) {
    
            case '1': {//crear registro
        
                Serial.print("Ingrese el nombre: ");
                String fn = Serial.readString();
                Serial.println(fn);
      
                Serial.print("Ingrese los apellidos: ");
                String ln = Serial.readString();
                Serial.println(fn);
      
                Serial.print("Ingrese el número telefónico: ");
                String pn = Serial.readString();
                Serial.println(fn);
      
                //id
                int id = 1;
                createRecord(id, fn, ln, pn);
                break;
            }
    
            case '2': {//Seleccionar registro
                
                Serial.print("Ingrese el número de registro: ");
                int id = Serial.read();
                Serial.println(id);
        
                selectRecord(id);
                
                break;
            }
      
            case '3': {//actualizar registro
                printMenu();
                break;
            }
        
            case '4': {//borrar registro
        
                Serial.print("Ingrese el número de registro: ");
                int id = Serial.read();
                Serial.println(id);
        
                deleteRecord(id);
                
                break;
            }
        
            case '5': {//mostrar todos los registros
                
                selectAll();
        
                break;
            }
      
            case '6': {//total de registros
              
                db.count();
                
                break;
            }
        
            case '7': {
                printMenu();
                break;
            }
        
            default: {
                printMenu();
                break;
            }
        }
        printMenu();
    }  
}

void printMenu(){
  Serial.println("[1] Crear registro");
  Serial.println("[2] Mostrar registro");
  Serial.println("[3] Actualizar registro");
  Serial.println("[4] Eliminar registro");
  Serial.println("[5] Mostrar todos los registros");
  Serial.println("[6] Total de registros");
  Serial.println("[7] Ultimo registro");
}

void createRecord(int id, String fn, String ln, String pn)
{
    Serial.print("ID: ");
    Serial.print(id);
    Serial.print(", Nombre: ");
    Serial.print(fn);
    Serial.print(", Apellidos: ");
    Serial.print(ln);
    Serial.print(", Teléfono: ");
    Serial.println(pn);
    Serial.print("Creando registro... ");
    
    tableRecord.id = id;
    tableRecord.firstName = fn;
    tableRecord.lastName = fn;
    tableRecord.phoneNumber = pn;
    EDB_Status result = db.appendRec(EDB_REC tableRecord);
    if (result != EDB_OK) printError(result);
    Serial.println("OK");
}

void selectRecord(int recno)
{
  
    EDB_Status result = db.readRec(recno, EDB_REC tableRecord);
    if (result == EDB_OK)
    {
        Serial.print("\tID: ");
        Serial.print("\t");
        Serial.print(tableRecord.id);
        Serial.print("\tNombre: ");
        Serial.print("\t");
        Serial.print(tableRecord.firstName);
        Serial.print("\tApellidos: ");
        Serial.print("\t");
        Serial.print(tableRecord.lastName);
        Serial.print("\tNúmero telefónico: ");
        Serial.print("\t");
        Serial.print(tableRecord.phoneNumber);
    }
    else printError(result);

}

void updateRecord(int id, String fn, String ln, String pn)
{
    Serial.print("Actualizando registro...");
    tableRecord.id = 1234;
    tableRecord.firstName = fn;
    tableRecord.lastName = ln;
    tableRecord.phoneNumber = pn;
    EDB_Status result = db.updateRec(id, EDB_REC tableRecord);
    if (result != EDB_OK) printError(result);
    Serial.println("OK");
}

void deleteRecord(int id)
{
    Serial.print("Borrando registro...");
    db.deleteRec(id);
    Serial.print("OK");
}

void selectAll()
{
    for (int recno = 1; recno <= db.count(); recno++)
    {
        EDB_Status result = db.readRec(recno, EDB_REC tableRecord);
        if (result == EDB_OK)
        {
            Serial.print("\tID: ");
            Serial.print("\t");
            Serial.print(tableRecord.id);
            Serial.print("\tNombre: ");
            Serial.print("\t");
            Serial.print(tableRecord.firstName);
            Serial.print("\tApellidos: ");
            Serial.print("\t");
            Serial.print(tableRecord.lastName);
            Serial.print("\tNúmero telefónico: ");
            Serial.print("\t");
            Serial.print(tableRecord.phoneNumber);
        }
        else printError(result);
    }
}

void deleteAll()
{
    Serial.print("Borrando tabla...");
    db.clear();
    Serial.println("OK");
}

void printError(EDB_Status err)
{
    Serial.print("ERROR: ");
    switch (err)
    {
        case EDB_OUT_OF_RANGE:
            Serial.println("Registro fuera de rango");
            break;
        case EDB_TABLE_FULL:
            Serial.println("Tabla llena");
            break;
        case EDB_OK:
        default:
            Serial.println("OK");
            break;
    }
}


