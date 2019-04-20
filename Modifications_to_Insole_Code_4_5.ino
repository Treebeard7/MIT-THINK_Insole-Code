#include <SoftwareSerial.h>
#include <Fsr.h>

SoftwareSerial ble(0,1);
boolean transmitting;
String input = "";
String readValue;
int duration;
const int motordisk = 2;
int sfcounter = 0;
int pfcounter = 0;
boolean newData;

Fsr fsr_heel(7); //I have not finalized the analog input pins
Fsr fsr_metleft(8);
Fsr fsr_metright(9);
Fsr fsr_toepad1(10);
Fsr fsr_toepad3(11);
Fsr fsr_toepad4(12);
Fsr fsr_edgeleft(13);
Fsr fsr_edgeright (6);
Fsr fsr_edgetoepad1(5);
Fsr fsr_edgetoepad3(4);
Fsr fsr_edgetoepad5(3);




void setup() {
  Serial.begin(9600);
  
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
        
        for (int i = 0; i <= duration; i++) {    
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
  delay(500);
  Serial.println();
  delay(1000);
  Serial.println("OFF");
  delay(500);
  Serial.println();
  digitalWrite(motordisk, LOW);
  Serial.println("ON");
  delay(500);
  Serial.println();
  delay(1000);
  Serial.println("OFF");
  delay(500);
  Serial.println();
  digitalWrite(motordisk, HIGH);
  Serial.println("ON");
  delay(500);
  Serial.println();
  delay(1000);
  Serial.println("OFF");
  delay(500);
  Serial.println();
  digitalWrite(motordisk, LOW);
  Serial.println("ON");
  delay(500);
  Serial.println();
  delay(1000);
  Serial.println("Pulse Mechanism Complete");
  Serial.flush();
  
}

void beginMethod() {
  if (Serial.available() > 0) {
    readValue = Serial.readString();
    newData = true;
  }
}

