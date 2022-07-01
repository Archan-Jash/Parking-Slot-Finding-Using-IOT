#include <SoftwareSerial.h>

SoftwareSerial nodemcu(2,3);

int parking1_slot1_ir_s = 4; // parking slot1 infrared sensor connected with pin number 4 of arduino
int parking1_slot2_ir_s = 5;
int parking1_slot3_ir_s = 6;

int parking2_slot1_ir_s = 7;
int parking2_slot2_ir_s = 8;
int parking2_slot3_ir_s = 9;
int l1=10;
int l2=11;
int l3=12;
int l4=13;
int l5=A1;
int l6=A2;


String sensor1; 
String sensor2; 
String sensor3; 
String sensor4; 
String sensor5; 
String sensor6; 


String cdata =""; // complete data, consisting of sensors values

void setup()
{
Serial.begin(9600); 
nodemcu.begin(9600);

pinMode(parking1_slot1_ir_s, INPUT);
pinMode(parking1_slot2_ir_s, INPUT);
pinMode(parking1_slot3_ir_s, INPUT);

pinMode(parking2_slot1_ir_s, INPUT);
pinMode(parking2_slot2_ir_s, INPUT);
pinMode(parking2_slot3_ir_s, INPUT);

pinMode(l1,OUTPUT);
pinMode(l2,OUTPUT);
pinMode(l3,OUTPUT);
pinMode(l4,OUTPUT);
pinMode(l5,OUTPUT);
pinMode(l6,OUTPUT);
}

void loop()
{

p1slot1(); 
p1slot2();
p1slot3(); 

p2slot1();
p2slot2();
p2slot3();

  
  
   cdata = cdata + sensor1 +"," + sensor2 + ","+ sensor3 +","+ sensor4 + "," + sensor5 + "," + sensor6 +","; // comma will be used a delimeter
   Serial.println(cdata); 
   nodemcu.println(cdata);
   delay(1000); // 100 milli seconds
   cdata = ""; 
digitalWrite(parking1_slot1_ir_s, HIGH); 
digitalWrite(parking1_slot2_ir_s, HIGH); 
digitalWrite(parking1_slot3_ir_s, HIGH);

digitalWrite(parking2_slot1_ir_s, HIGH);
digitalWrite(parking2_slot2_ir_s, HIGH);
digitalWrite(parking2_slot3_ir_s, HIGH);
}


void p1slot1() // parkng 1 slot1
{
  if( digitalRead(parking1_slot1_ir_s) == LOW) 
  {
    digitalWrite(l1,HIGH);
  sensor1 = "255";
 delay(50); 
  } 
if( digitalRead(parking1_slot1_ir_s) == HIGH)
{
  digitalWrite(l1,LOW);
  sensor1 = "0";  
 delay(50);  
}

}

void p1slot2() // parking 1 slot2
{
  if( digitalRead(parking1_slot2_ir_s) == LOW) 
  {
    digitalWrite(l2,HIGH);
  sensor2 = "255"; 
  delay(50); 
  }
if( digitalRead(parking1_slot2_ir_s) == HIGH)  
  {
    digitalWrite(l2,LOW);
  sensor2 = "0";  
 delay(50);
  } 
}


void p1slot3() // parking 1 slot3
{
  if( digitalRead(parking1_slot3_ir_s) == LOW) 
  {
    digitalWrite(l3,HIGH);
  sensor3 = "255"; 
  delay(50); 
  }
if( digitalRead(parking1_slot3_ir_s) == HIGH)  
  {
    digitalWrite(l3,LOW);
  sensor3 = "0";  
 delay(50);
  } 
}


// now for parking 2

void p2slot1() // parking 1 slot3
{
  if( digitalRead(parking2_slot1_ir_s) == LOW) 
  {
    digitalWrite(l4,HIGH);
  sensor4 = "255"; 
  delay(50); 
  }
if( digitalRead(parking2_slot1_ir_s) == HIGH)  
  {
    digitalWrite(l4,LOW);
  sensor4 = "0";  
 delay(50);
  } 
}


void p2slot2() // parking 1 slot3
{
  if( digitalRead(parking2_slot2_ir_s) == LOW) 
  {
    digitalWrite(l5,HIGH);
  sensor5 = "255"; 
  delay(50); 
  }
if( digitalRead(parking2_slot2_ir_s) == HIGH)  
  {
    digitalWrite(l5,LOW);
  sensor5 = "0";  
 delay(50);
  } 
}


void p2slot3() // parking 1 slot3
{
  if( digitalRead(parking2_slot3_ir_s) == LOW) 
  {
    digitalWrite(l6,HIGH);
  sensor6 = "255"; 
  delay(50); 
  }
if( digitalRead(parking2_slot3_ir_s) == HIGH)  
  {
    digitalWrite(l6,LOW);
  sensor6 = "0";  
 delay(50);
  } 
}
