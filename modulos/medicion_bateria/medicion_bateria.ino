int pinBattery = 4;
float vBattery = 0.0;
float vPin = 0.0;
float R1 = 2000.0; 
float R2 = 1000.0; 
int RAW = 0;
int ledOut = 13;

void setup(){
   pinMode(pinBattery, INPUT);
   Serial.begin(9600);

   Serial.print("RAW ");
   Serial.print("\t");
   Serial.print("Voltaje pin ");
   Serial.print("\t");
   Serial.println("Voltaje Bateria ");
}
void loop(){

   RAW = analogRead(pinBattery);
   
   vPin = (RAW * 5) / 1023.0; 
   
   vBattery = vPin / (R2/(R1+R2)); 
   
   Serial.print(RAW);
   Serial.print("\t");
   Serial.print(vPin);
   Serial.print("V");
   Serial.print("\t\t");
   Serial.print(vBattery);
   Serial.println("V");

    if (vPin<0.09) {
       vPin=0.0;
    } 

   if(vPin > 5){
    digitalWrite(ledOut, HIGH);
  } else {
    digitalWrite(ledOut, LOW);
  }
   delay(2000);
}
