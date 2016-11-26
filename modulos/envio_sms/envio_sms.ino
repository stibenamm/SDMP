#include <DFRobot_sim808.h>
#include <SoftwareSerial.h>

#define PHONE_NUMBER "XXXXXXXXXXX"  
 
#define MESSAGE  "el veloz murcielago hindu comia feliz cardillo y kiwi"
//#define MESSAGE  "el veloz murciélago hindú comía feliz cardillo y kiwi"

#define PIN_TX    3
#define PIN_RX    2
SoftwareSerial mySerial(PIN_TX,PIN_RX);
DFRobot_SIM808 sim808(&mySerial);

void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);
 
  while(!sim808.init()) {
      delay(1000);
      Serial.print("SIM808 error al iniciar\r\n");
  }  
  Serial.println("SIM808 inicializado");
  Serial.print("Enviando mensaje ...");

  sim808.sendSMS(PHONE_NUMBER,MESSAGE); 
  Serial.println("Listo");
}

void loop() {
}
