
#include <Servo.h> 

 
Servo rightservo;
Servo leftservo;

int pos = 0;    
int leftsensor = 1; 
int rightsensor = 1;

void forward(){ 
  rightservo.write(83);  
  leftservo.write(97); 
}

void back(){
  rightservo.write(97);
  leftservo.write(83);
}

void leftback(){
  rightservo.write(95);
  leftservo.write(95);
}

void rightback(){
  rightservo.write(85);
  leftservo.write(85);
}

void setup() 
{ 
  rightservo.attach(7);
  leftservo.attach(6);
  Serial.begin(9600);
  pinMode(5,INPUT);
  pinMode(4,INPUT);
} 
 
 
void loop() {
 leftsensor = digitalRead(5);
 rightsensor = digitalRead(4);

 Serial.print(" leftsensor:  ");
 Serial.print(leftsensor);
 Serial.print(" rightsensor:  ");
 Serial.print(rightsensor);
 Serial.println("  ");

 if (leftsensor == 1 && rightsensor == 1){
  back();
  delay(100);
 }
 else if ((rightsensor == 1)&&(leftsensor == 0)){
  rightback();
  delay(1250);
 }
 else if ((leftsensor == 1)&&(rightsensor == 0)){
  leftback();
  delay(1250);
 }
 else{
  forward();
  delay(75);
 } 
}

