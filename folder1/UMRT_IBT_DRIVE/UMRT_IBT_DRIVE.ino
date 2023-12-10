#include <BluetoothSerial.h>

BluetoothSerial umrtibt;

int incoming;// received value will be stored as integer in this variable

#define RPWMR 12
#define RPWML 14
#define LPWMR 26
#define LPWML 27
#define PWM 18

void setup() {
  Serial.begin(115200);
  umrtibt.begin("umrtibt"); // Bluetooth device name
  pinMode(RPWMR, OUTPUT); 
  pinMode(RPWML, OUTPUT);
  pinMode(LPWMR, OUTPUT);
  pinMode(LPWML, OUTPUT);
  pinMode(PWM, OUTPUT);
}

void Forward(){
      //ROVER FORWARD DRIVE
      digitalWrite(RPWMR,HIGH);
      digitalWrite(RPWML,HIGH);
      digitalWrite(LPWMR,LOW);
      digitalWrite(LPWML,LOW);
      analogWrite(PWM,200);
      Serial.println ("rover will move Forward"); 
}
void Backward(){
  //Rover Reverse Drive
      digitalWrite(RPWMR,LOW);
      digitalWrite(RPWML,LOW);
      digitalWrite(LPWMR,HIGH);
      digitalWrite(LPWML,HIGH);
      analogWrite(PWM,200);
      Serial.println("Rover will run backward");
}
void Right(){
  //Rover right turn
      digitalWrite(LPWMR,HIGH);
      digitalWrite(RPWMR,LOW);
      digitalWrite(RPWML,HIGH);
      digitalWrite(LPWML,LOW);
      analogWrite(PWM,255);
      Serial.println("Rover will turn right");
}
void Left(){
  //rover left turn
      digitalWrite(RPWMR,HIGH);
      digitalWrite(LPWMR,LOW);
      digitalWrite(RPWML,LOW);
      digitalWrite(LPWML,HIGH);
      analogWrite(PWM,255);
      Serial.println("motor will turn left");
}
void Stop(){
  //Rover stop
      digitalWrite(RPWMR,LOW); 
      digitalWrite(RPWML,LOW);
      digitalWrite(LPWMR,LOW); 
      digitalWrite(LPWML,LOW);
      analogWrite(PWM,0);
      Serial.println("Rover will stop");

}
void loop() {
    if(umrtibt.available())
    {
      incoming=umrtibt.read();
      Serial.print("rceived:");
      Serial.println(incoming);

      if(incoming==83)
      {
        Stop();
         }
         
      if(incoming==70)
      {
        Forward();
        
      }
      if(incoming==66)
      {Backward();
      }
      if(incoming==82)
      {Right();
      }
      if(incoming==76)
      {
       Left();
      }
      if(incoming==68)
      {
      Stop();
      }

}
}
 
