const int buttonPin = 7;     
const int outputPin =  13;      

int buttonState = 0;

unsigned long start, finished, elapsed, total;
boolean flag;

void setup() {
  pinMode(outputPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    digitalWrite(outputPin, HIGH);
    finished=millis();
    elapsed=finished-start;
    //Serial.print(elapsed);
    //Serial.print("\t");
    //Serial.println(total);
    displayResult();
    
    flag = 1;
  } else {
    digitalWrite(outputPin, LOW);
    start = millis();

    if(flag){
      total += elapsed;
      formatMillis();
    }
    flag=0;
  }
}

void displayResult()
{
  float h,m,s,ms;
  unsigned long res;
  h=int(elapsed/3600000);
  res=elapsed%3600000;
  m=int(res/60000);
  res=res%60000;
  s=int(res/1000);
  ms=res%1000;
  Serial.print("Corriendo:\t");
  Serial.print(h,0);
  Serial.print("h ");
  Serial.print(m,0);
  Serial.print("m ");
  Serial.print(s,0);
  Serial.print("s ");
  Serial.print(ms,0);
  Serial.print("ms ");
  Serial.println();
}

void formatMillis(){
  float h,m,s,ms;
  unsigned long over;
  h=int(total/3600000);
  over=total%3600000;
  m=int(over/60000);
  over=over%60000;
  s=int(over/1000);
  ms=over%1000;
  Serial.print("Acumulado:\t");
  Serial.print(h,0);
  Serial.print("h ");
  Serial.print(m,0);
  Serial.print("m ");
  Serial.print(s,0);
  Serial.print("s ");
  Serial.print(ms,0);
  Serial.print("ms ");
  Serial.println();
}

