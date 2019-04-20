#include "Arduino.h"
//#include "Fsr2.h"

Fsr::Fsr(int attachTo)
{
  pinMode(attachTo, INPUT);
  int pin = attachTo;
}

void Fsr2::standardForce() {
int fsrReading = analogRead(pin);
      if (fsrReading > 250) {
        this.counter++;
        this.countertotal++;
        Serial.println("All good");     //temporary action. Will replace with app command later
      } else {
      }
    }

void Fsr2::peripheralForce()  {
  int fsrReading1 = analogRead(pin);
      if (fsrReading1 > 250) {
        counter ++;
        countertotal++;
        Serial.println("Not good");
      }
}

void Fsr2::counterCheck(){

}
}

