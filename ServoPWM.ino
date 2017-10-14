#include <Servo.h> 
Servo servoALI;
Servo servoBLI; 

int ALI = 6;
int BLI = 5;
int BHI = 8;
int AHI = 7;
int Disable = 4;

void setup() { 
    servoALI.attach(ALI); 
    servoBLI.attach(BLI);
    pinMode(BHI, OUTPUT);
    pinMode(AHI, OUTPUT);
    pinMode(Disable, OUTPUT);
}
void loop(){ 
   digitalWrite(Disable, LOW);
    //PWM na BLI
   digitalWrite(AHI, HIGH);
   digitalWrite(BHI, LOW);
   servoALI.write(0);
   for (int i=0; i<=360; i++) //rozpędzanie silnika
   {
    servoBLI.write(i); 
    delay(20);
   }
   delay(2000);
   for (int i=360; i>=0; i--) //zwalnianie silnika
   {
    servoBLI.write(i); 
    delay(20);
   }
   delay(2000);
 /*   //PWM na ALI
   digitalWrite(AHI, HIGH);
   digitalWrite(BHI, HIGH);
   servoBLI.write(0);
   for (int i=0; i<=180; i++) //rozpędzanie silnika
   {
    servoALI.write(i); 
    delay(20);
   }
   delay(500);
   for (int i=180; i>=0; i--) //zwalnianie silnika
   {
    servoALI.write(i); 
    delay(20);
   }  */
}
