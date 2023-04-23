//Include BLE Mouse library

#include <BleMouse.h>

// RBG led pin definition

#define G 18
#define B 19
#define R 5

// definition for button connected to esp32

#define U_BUT 13
#define L_BUT 27
#define C_BUT 12
#define R_BUT 26
#define D_BUT 14
// BLEMOUSE gloal declaration

BleMouse bleMouse("smouse","Espressif", 65);

bool status = true;
void setup(){
  Serial.begin(115200);

pinMode(R, OUTPUT);
pinMode(G, OUTPUT);
pinMode(B, OUTPUT); 
pinMode(U_BUT, INPUT_PULLUP);
pinMode(L_BUT, INPUT_PULLUP);
pinMode(C_BUT, INPUT_PULLUP);
pinMode(R_BUT, INPUT_PULLUP);
pinMode(D_BUT, INPUT_PULLUP);

bleMouse.begin();

}
void loop()
{
if (bleMouse.isConnected())
{ 
  if (status == true)
  {
   digitalWrite(G, LOW);
   delay(3000);
   status = false;
   } 
   digitalWrite(G, HIGH);
   mouseconnected();
}

else
{notconnected();}

}

 void notconnected()
 {
  digitalWrite(R,LOW);
  delay(500);
  digitalWrite(R,HIGH);
  delay(500);
  
digitalWrite(B,HIGH);
digitalWrite(G,HIGH);
status=true;
  
  }

  void ScrollDelay(){
    delay(57.15);
  }

  void but_pressed(){
    digitalWrite(B,LOW);
  }
 
void mouseconnected()
{
  if (digitalRead(U_BUT) == 0)
  { 
    bleMouse.move(0, 0, 1);
   but_pressed(); 
   Serial.println("Scrolling UP");
  ScrollDelay();
  }
if (digitalRead(D_BUT)== 0)
   { bleMouse.move(0, 0, -1);
   but_pressed();
    Serial.println("Scrolling DOWN");
   ScrollDelay();
   } 
if (digitalRead(C_BUT) == 0)
 {
  bleMouse.click(MOUSE_LEFT);
  but_pressed();
   Serial.println("Centre Click");
   delay(250);
    }

if (digitalRead(L_BUT)== 0)
   { bleMouse.click(MOUSE_RIGHT);
   but_pressed(); 
   Serial.println("Left Click");
   delay(250);
   }

if (digitalRead(R_BUT)== 0)
 {  bleMouse.click(MOUSE_BACK);
   but_pressed();
   Serial.println("Right Click");
    delay(250);
  }
 else {
  digitalWrite(B,HIGH);
 }
}
