/**
 *LightStrip.h - The Passive Infrared (PIR) Project from the Automation Lab at Brandeis University
 *Authored by Daniel Lay, the BIGGEST brain programmer at the automation lab (suck it Tim)
 */

#include <Arduino.h>
#include "LightStrip.h"
#include "Adafruit_NeoPixel.h"

//Constructor for the LightStrip
LightStrip::LightStrip(int PIR_sensor[], int num_of_sensors){
	strip = Adafruit_NeoPixel(num_of_sensors, LED_pin, NEO_GRB + NEO_KHZ800);
	
	PIR_sensor = PIR_sensor[];	
	num_of_sensors = num_of_sensors;
}

bool LightStrip::check_move(int PIR_output){
	if(PIR_output>600){           
		return true;
	}else{
		return false;
	}
}

void LightStrip::LED_on(int LED, char color){
	switch(color){
		case 'r':
			strip.setPixelColor(LED, 255, 0, 0);
			break;
		case 'o':
			strip.setPixelColor(LED, 225, 165, 0);
			break;
		case 'y':
			strip.setPixelColor(LED, 255, 225, 0);
			break;
		case 'g':
			strip.setPixelColor(LED, 0, 225, 0);
			break;
		case 'b':
			strip.setPixelColor(LED, 0, 0, 255);
			break;
		case 'i':
			strip.setPixelColor(LED, 0, 0, 128);
			break;
		case 'v':
			strip.setPixelColor(LED, 128, 0, 128);
			break;
		default:
			strip.setPixelColor(LED, 255, 255, 255);
			break;
	}
}	

void LightStrip::LED_off(int LED){
	strip.setPixelColor(LED, 0, 0, 0);
}

//cycles through each PIR sensor to check that it is moving
void LightStrip::cycle_PIR(void){
	for(int i = 0;i<num_of_PIR;i++){
		//checks for the PIR sensor is active: if so, on, else off
		if(check_move(PIR_sensor[i])){
			LED_on(i, 'r');
		}else{
			LED_off(i);
		}
	}	
}

