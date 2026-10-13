#include <Servo.h>
Servo servo1;
int pos = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo1.attach(10);
}

void loop() {
  long duration,cm;
  // put your main code here, to run repeatedly:
   for(pos = 0; pos <= 180; pos += 1){
    servo1.write(pos);
    delay(15);
  }
  for(pos = 180; pos >= 0; pos -= 1){
    servo1.write(pos);
    delay(15);
  }

  pinMode(7,OUTPUT);
  
  digitalWrite(7,LOW);
  delayMicroseconds(2);// short low pulse and give a clear high pulse for a clear answer _ _ - - - - - _ _
  digitalWrite(7,HIGH);
  delayMicroseconds(5);
  digitalWrite(7,LOW);

  pinMode(8, INPUT);
  duration = pulseIn(8,HIGH); // read the duration of the high pulse

  cm = microsecondsToCentimeters(duration);

  Serial.print(cm);
  Serial.println("cm ");
  delay(100);

  pinMode(10,OUTPUT);
  if (cm <= 10) {
    Serial.println("WARNING");
  }
  else if (cm > 10 && cm <=30){
    Serial.println("CLOSE") ;
}
  else if (cm > 30){
    Serial.println("Okay");
  }
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds /29/2;
}