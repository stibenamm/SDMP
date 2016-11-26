#include <DFRobot_sim808.h>
#include <SoftwareSerial.h>

#define MESSAGE_LENGTH 160
char message[MESSAGE_LENGTH];
int messageIndex = 0;

char phone[16];
char datetime[24];

#define PIN_TX    3
#define PIN_RX    2
SoftwareSerial mySerial(PIN_TX,PIN_RX);
DFRobot_SIM808 sim808(&mySerial);
void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);

  while(!sim808.init()) {
      Serial.print("Sim808 iniciando\r\n");
      delay(1000);
  }
  delay(3000);  
}

void loop() {

   messageIndex = sim808.isSMSunread();

   if (messageIndex > 0) { 
      sim808.readSMS(messageIndex, message, MESSAGE_LENGTH, phone, datetime);
                 
      sim808.deleteSMS(messageIndex);
      Serial.print("Numero: ");
      Serial.println(phone);  
      Serial.print("Fecha: ");
      Serial.println(datetime);        
      Serial.print("Mensaje: ");
      Serial.println(message);    
   }
}
