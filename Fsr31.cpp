#include "Arduino.h"
#include "Fsr31.h"

Fsr31::Fsr31(int attachTo, int c, String a)
{
  pinMode(attachTo, INPUT);
  pin = attachTo;
  counter = c;
  Name = a;
}

void Fsr31::standardForce() {
int fsrReading = analogRead(pin);
      if (fsrReading > 250) {
        Serial.print(".");  
      }  
      else {
        counter++;
        countertotal++;
      } 
      if (counter >= 5) {
       Serial.println("WARNING! Incorrect foot positioning at ");
       Serial.print(Name);
       counter = 0;
      } else {
      }
    }

void Fsr31::peripheralForce()  {
  int fsrReading1 = analogRead(pin);
      if (fsrReading1 > 250) {
        counter++;
        countertotal++;
      } else {
        Serial.print(".");
      }
      if (counter >= 5) {
       Serial.println("WARNING! Dangerous Foot-Shoe Friction at ");
       Serial.print(Name);
       counter = 0;
      } else {
      }
      }
void Fsr31::counterTotal() {
  if (countertotal >= 10) {
        Serial.println("WARNING! Please recorrect overall foot positioning.");
        countertotal = 0;
      }
}
   
