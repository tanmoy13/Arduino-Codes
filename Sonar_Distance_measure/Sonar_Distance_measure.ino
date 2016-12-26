#define trigger 8
#define echo 7
 
 
float time=0,distance=0;
 
void setup()
{

 pinMode(trigger,OUTPUT);
 pinMode(echo,INPUT);
 pinMode(13,OUTPUT);
  pinMode(53,OUTPUT);
 Serial.begin(9600);
 delay(2000);
}
 
void loop()
{

 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 digitalWrite(trigger,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 time=pulseIn(echo,HIGH);
 distance=time*340/20000;
Serial.print("Distance = ");
Serial.print(distance);
Serial.print("cm\n");
if(distance<=30.0)
{
  digitalWrite(53,HIGH);
  digitalWrite(13,LOW);
}
else
{
  digitalWrite(13,HIGH);
  digitalWrite(53,LOW);
}
 delay(1000);
}
