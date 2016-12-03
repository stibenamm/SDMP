const int ignitionPin = 5;     
const int ledOut =  13;      

int ignitionState = 0;

void setup() {
  pinMode(ledOut, OUTPUT);
  pinMode(ignitionPin, INPUT);
}

void loop() {
  ignitionState = digitalRead(ignitionPin);

  if (ignitionState == HIGH) {
    digitalWrite(ledOut, HIGH);
  } else {
    digitalWrite(ledOut, LOW);
  }
}