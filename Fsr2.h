#include "Arduino.h"
#ifndef Fsr2_h
#define Fsr2_h

class Fsr {
 
 int countertotal = 0;

  public:
    Fsr(int attachTo);
    const int pin;
    int counter = 0;
    void standardForce();
    void peripheralForce();
    
};
   

#endif 
