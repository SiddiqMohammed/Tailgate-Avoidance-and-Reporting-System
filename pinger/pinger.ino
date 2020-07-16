// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------
#include <NewPing.h>
#define TRIGGER_PIN  39  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     43  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 400 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.



int a=0;
int pingywingy() {
                delay(1000);   // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("Distance: ");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range) //Newping.h Pinger changed from 29000
  Serial.println("cm");
  if (sonar.ping_cm()<50){
    a = a+1;
    Serial.print(a );
    Serial.print("\n");

    if (a==7){
      
       myCAMSaveToSDFile();
  
      Serial.print("*****TAILGATER IDENTIFIED******** .PICTURE TAKEN");
      Serial.print("\n");
      Serial.print(a);
      a=0;}
 
  }
  else{a=0;} 
 
  
  Serial.print("-------------");
}
