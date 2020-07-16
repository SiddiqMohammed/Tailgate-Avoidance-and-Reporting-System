#include <TinyGPS++.h> // The TinyGPS++ object
TinyGPSPlus gps;


void loop(){
  while (Serial1.available() > 0){
    gps.encode(Serial1.read());
    if (gps.location.isUpdated()){
      
      //Speed in kilometers per hour (double)
      Serial.print("Speed in km/h = "); 
      Serial.println(gps.speed.kmph());
      
      if (gps.speed.kmph()<2.0)
      { 
        pingywingy();
      } 
      else{
        Serial.println("-");
      }
    }
  }
}
