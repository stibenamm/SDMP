char    pinFuel = A2;                                   
int     RAW = 0;                                        
float   voltage = 0.0;                                         
float   dividingVoltage = 10000;                                
float   resistance = 0.0;                                   

void setup()
{                                            
  Serial.begin(9600);                                    

  pinMode(pinFuel, INPUT);                          

  Serial.print("RAW");
  Serial.print("\t");
  Serial.print("Voltaje");
  Serial.print("\t\t");
  Serial.println("Resistencia");
}


void loop()
{

  RAW = analogRead(pinFuel);                    

  voltage = ( 5.0 * RAW ) / 1023.0;                      

                        
  // R = ((VIN * VR")/VR1) - V2
  resistance = ( ( 5 * dividingVoltage ) / voltage) - dividingVoltage;                          
  
  Serial.print(RAW);
  Serial.print("\t");
  Serial.print(voltage);
  Serial.print("\t\t");
  Serial.println(resistance);     
  
  delay(2000);       
}

