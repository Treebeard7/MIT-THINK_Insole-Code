#include <SoftwareSerial.h>
#include <Fsr31.h>

SoftwareSerial ble(0,1);
boolean transmitting;
String input = "";
String readValue;
int duration;
const int motordisk = 2;
int sfcounter = 0;
int pfcounter = 0;
boolean newData;

Fsr31 fsr_heel(7, 0, "Heel"); //I have not finalized the analog input pins
Fsr31 fsr_metleft(8, 0, "Left Metatarsel");
Fsr31 fsr_metright(9, 0, "Right Metatarsel");
Fsr31 fsr_toepad1(10, 0, "Big Toe");
Fsr31 fsr_toepad3(11, 0, "Middle Toe");
Fsr31 fsr_toepad4(12, 0, "Small Toe");
Fsr31 fsr_edgeleft(13, 0, "Left Edge");
Fsr31 fsr_edgeright (6, 0, "Right Edge");
Fsr31 fsr_edgetoepad1(5, 0, "Big Toe Tip");
Fsr31 fsr_edgetoepad3(4, 0, "Middle Toe Tip");
Fsr31 fsr_edgetoepad5(3, 0, "Small Toe Tip");




void setup() {
  while (! Serial) {delay(1);}
  Serial.begin(9600);
  ble.begin(9600);
  
  pinMode(motordisk, OUTPUT);
  Serial.println("DPN Insole Prototype");
  Serial.println("Testing v. 1");
  Serial.println("Please enter a command...");
  Serial.println();

  
}

void loop() {

    while (Serial.available()) {
    if (Serial.available()) {
      String str = Serial.readString();
     

      if (str.equalsIgnoreCase("begin"))
      {
       
        Serial.println("Enter duration (min.)");
        Serial.flush();
        delay(5000);
        beginMethod();

        if (newData == true) {
        duration = 6*(readValue.toInt());
        //duration =  duration*6;
        Serial.println(duration);
        newData=false;
        }
        
        for (int i = 1; i <= duration; i++) {    
          fsr_metleft.standardForce();
          fsr_metright.standardForce();
          fsr_toepad1.standardForce();
          fsr_toepad3.standardForce();
          fsr_toepad4.standardForce();
          fsr_edgeleft.peripheralForce();
          fsr_edgeright.peripheralForce();
          fsr_edgetoepad1.peripheralForce();
          fsr_edgetoepad3.peripheralForce();
          fsr_edgetoepad5.peripheralForce();
          fsr_edgetoepad3.counterTotal();
          delay(5000); 
               
        }

        //Serial.println(fsr_edgetoepad5.getCountertotal());
        Serial.flush();
      }

      if (str.equalsIgnoreCase("test sensation")) {
        delay(5000);
        testSensation();
        Serial.flush();
      }

      if (str.equalsIgnoreCase("stop")) 
      {
        exit(1);
      }
      
    }
  
  }
  
}

void testSensation () {
  Serial.println("Initiating Pulse Mechanism");
  delay(500);
  Serial.println();
  delay (3000);
  
  digitalWrite(motordisk, HIGH);
  Serial.println("ON");
  delay(1000);
  Serial.println();
  
  digitalWrite(motordisk, LOW);
  Serial.println("OFF");
  delay(1000);
  Serial.println();

  digitalWrite(motordisk, HIGH);
  Serial.println("ON");
  delay(1000);
  Serial.println();

  digitalWrite(motordisk, LOW);
  Serial.println("OFF");
  delay(1000);
  Serial.println();

   digitalWrite(motordisk, HIGH);
  Serial.println("ON");
  delay(1000);
  Serial.println();

  digitalWrite(motordisk, LOW);
  Serial.println("OFF");
  delay(1000);
  Serial.println();
  
  Serial.println("Pulse Mechanism Complete");
  Serial.flush();
  
}

void beginMethod() {
  if (Serial.available() > 0) {
    readValue = Serial.readString();
    newData = true;
  }
}
