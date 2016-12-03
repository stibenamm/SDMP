
const int inPin = A0;  
int input = 0;        
int output = 0;    
int resolution=255;    

void setup() {
   Serial.begin(9600);

   Serial.print("Entrada ");
   Serial.print("\t");
   Serial.println("Salida");
}

void loop() {
  input = analogRead(inPin);
  output = map(input, 0, 1023, 0, resolution);

  Serial.print(input);
  Serial.print("\t\t");
  Serial.println(output);

  delay(2000);
}
