#include "Arduino.h"
#ifndef Fsr31_h
#define Fsr31_h

class Fsr31 {
 
 int countertotal = 0;

  public:
    Fsr31(int attachTo, int c, String a);
    int counter;
    String Name;
    int pin;
    void standardForce();
    void peripheralForce();
    void counterTotal();
    
};
   

#endif 
