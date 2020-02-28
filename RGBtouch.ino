
#include <Adafruit_NeoPixel.h>              //Version 1.3.4
#define PIN       2   // DIN Data in of RGBLED
#define NUMPIXELS 1   // how many RGBLED are there


Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int threshold = 40;
bool touch0detected = false;
bool touch3detected = false;
bool touch6detected = false;

void gotTouch0(){
 touch0detected = true;
}

void gotTouch3(){
 touch3detected = true;
}
void gotTouch6()
{
  touch6detected = true;
}

void setup() {
   pixels.begin();
  Serial.begin(115200);
  delay(1000); // give me time to bring up serial monitor
  Serial.println("ESP32 Touch Interrupt Test");
  touchAttachInterrupt(T0, gotTouch0, threshold);
  touchAttachInterrupt(T3, gotTouch3, threshold);
  touchAttachInterrupt(T6, gotTouch6, threshold);
}

void loop(){
  if(touch0detected){ 
    
    
    touch0detected = false;
    Serial.println("Touch 0 detected");
    pixels.setPixelColor(0, pixels.Color(255,0,0));
    pixels.show();
  }
  if(touch3detected){
   
    touch3detected = false;
     pixels.setPixelColor(0, pixels.Color(0,255,0));
    Serial.println("Touch 2 detected");
    pixels.show();
  }

  if(touch6detected){
   
    touch6detected = false;
    Serial.println("Touch 6 detected");
     pixels.setPixelColor(0, pixels.Color(0,0,255));
    pixels.show();
  }
}
