#include <DFRobot_sim808.h>
#include <SoftwareSerial.h>

#define PIN_TX    3
#define PIN_RX    2
SoftwareSerial mySerial(PIN_TX,PIN_RX);
DFRobot_SIM808 sim808(&mySerial);

void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);

  while(!sim808.init()) { 
      delay(1000);
      Serial.print("SIM808 inicializado\r\n");
  }

  if( sim808.attachGPS())
      Serial.println("GPS encendido");
  else 
      Serial.println("Error al encender GPS");
  
}

void loop() {
   if (sim808.getGPS()) {
    Serial.print(sim808.GPSdata.year);
    Serial.print("/");
    Serial.print(sim808.GPSdata.month);
    Serial.print("/");
    Serial.print(sim808.GPSdata.day);
    Serial.print(" ");
    Serial.print(sim808.GPSdata.hour);
    Serial.print(":");
    Serial.print(sim808.GPSdata.minute);
    Serial.print(":");
    Serial.print(sim808.GPSdata.second);
    Serial.print(":");
    Serial.println(sim808.GPSdata.centisecond);
    Serial.print("latitude :");
    Serial.println(sim808.GPSdata.lat);
    Serial.print("longitude :");
    Serial.println(sim808.GPSdata.lon);
    Serial.print("speed_kph :");
    Serial.println(sim808.GPSdata.speed_kph);
    Serial.print("heading :");
    Serial.println(sim808.GPSdata.heading);
    Serial.println();

    sim808.detachGPS();
  }

}
