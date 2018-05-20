#include <Servo.h>              
Servo left;
Servo right;
               
const int TrigPin = 2;
const int EchoPin = 3; 

int Sensor_L=A0;  
int Sensor_R=A5;
float da;
float dl;
float val=0;
char IR;

void setup()
{
  
Serial.begin(115200);
left.attach(10);
right.attach(11);
pinMode(TrigPin, OUTPUT);
pinMode(EchoPin, INPUT);     
  
left.write(90);
  
right.write(90);
  
  
delay(1000);
}

float detect_forward_distance()
{
      digitalWrite(TrigPin, LOW);   
      delayMicroseconds(2);
      digitalWrite(TrigPin, HIGH); 
      delayMicroseconds(10);
      digitalWrite(TrigPin, LOW);   
      float Fdistance = pulseIn(EchoPin, HIGH);  
      Fdistance= Fdistance/5.8/10;      
      Serial.print("F distance:");      
      Serial.println(Fdistance);        
      return Fdistance;
}
float detect_left_distance()
{
  int Val;
  IR=read_ir_range();
  delay(500); 
  //must return something to make it go left
}
//reading distance
float read_ir_range()
{
 float tmp;
  tmp=analogRead(A0);
  Serial.println(tmp);
  return tmp;
}

