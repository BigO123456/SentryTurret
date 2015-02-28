int motorPin = 4;

void setup(){
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  if (Serial.available())  {
     fire(Serial.read() - '0');
  }
  delay(500);
}

void fire(int n){
  for (int i = 0; i < n; i++)  {
   digitalWrite(motorPin, HIGH);
     delay(3000); 
     digitalWrite(motorPin, LOW);
  }
}
