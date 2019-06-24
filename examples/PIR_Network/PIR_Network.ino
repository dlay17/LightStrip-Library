  #include <Adafruit_NeoPixel.h>
  #include <PIR_Playground.h>
  #define LED_pin1 9
  

  int PIR1[] = {A1,A2,A0};
  int num_of_sensors_in =3;
  
  PIR_Playground PIR;
   

void setup() {
  
  PIR.init(PIR1, 3, 9);
 /* Serial.begin(9600);
  while(!Serial){}
  int num_of_sensors_g = num_of_sensors_in;
  Serial.print("this:");
  Serial.println(num_of_sensors_g);*/
}

void loop() {
  PIR.cycle_PIR();
}
