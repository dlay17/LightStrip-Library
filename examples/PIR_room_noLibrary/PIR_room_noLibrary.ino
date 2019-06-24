  #include <Adafruit_NeoPixel.h>
  #define LED_pin1 12
  #define LED_pin2 11
  #define LED_pin3 10

  int PIR1[] = {A0,A1,A2,A3};
  int PIR2[] = {A4,A5,A6,A7};
  int PIR3[] = {A8,A9,A10,A11};

   Adafruit_NeoPixel rgb1(4, LED_pin1, NEO_GRB + NEO_KHZ800);
  Adafruit_NeoPixel rgb2 = Adafruit_NeoPixel(4, LED_pin2, NEO_GRB + NEO_KHZ800);
  Adafruit_NeoPixel rgb3 = Adafruit_NeoPixel(4, LED_pin3, NEO_GRB + NEO_KHZ800);
   

void setup() {
  for(int i = 0; i < 4; i++){
    pinMode(PIR1[i],INPUT);
    pinMode(PIR2[i],INPUT);
    pinMode(PIR3[i],INPUT);
  }

  rgb1.begin();
  rgb2.begin();
  rgb3.begin();
  rgb1.show();
  rgb2.show();
  rgb3.show();
}

void loop() {
  for(int i = 0; i < 4; i++){
    checkMove1(i ,PIR1[i]);
    checkMove2(i, PIR2[i]);
    checkMove3(i, PIR3[i]);
  }
  rgb1.show();
  rgb2.show();
  rgb3.show();
}

void checkMove1(int PIR, int PIR_pin){
   if((analogRead(PIR_pin))>600){          
    rgb1.setPixelColor(PIR, 255, 0, 255);
   }else{
    rgb1.setPixelColor(PIR, 0, 0, 0);
  }
}
void checkMove2(int PIR, int PIR_pin){
   if((analogRead(PIR_pin))>600){          
    rgb2.setPixelColor(PIR, 255, 0, 255);
   }else{
    rgb2.setPixelColor(PIR, 0, 0, 0);
  }
}
void checkMove3(int PIR, int PIR_pin){
   if((analogRead(PIR_pin))>600){          
    rgb3.setPixelColor(PIR, 255, 0, 255);
   }else{
    rgb3.setPixelColor(PIR, 0, 0, 0);
  }
}
