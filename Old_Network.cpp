/**
 *Old_Network.h - The Passive Infrared (PIR) Project from the Automation Lab at Brandeis University
 *Authored by Daniel Lay, the BIGGEST brain programmer at the automation lab
 */

#include <Arduino.h>
#include "Old_Network.h"
#include "Adafruit_NeoPixel.h"

//Constructor for the Old_Network
Old_Network::Old_Network(int sensor_array_address[], int num_of_sensors_in, int LED_pin){
	num_of_sensors_g = num_of_sensors_in;
	strip = Adafruit_NeoPixel(num_of_sensors_in, LED_pin, NEO_GRB + NEO_KHZ800);
	
	PIR_sensor_array = sensor_array_address;
	
	for(int i =0; i<num_of_sensors_g;i++){
		pinMode(*(PIR_sensor_array+i), INPUT);
	}
	strip.begin();
	strip.show(); // Initialize all pixels to 'off'
}

bool Old_Network::check_move(int PIR_Read){
	if(PIR_Read>600){           
		return true;
	}
	return false;
}

void Old_Network::LED_on(int LED, char color){
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

void Old_Network::LED_off(int LED){
	strip.setPixelColor(LED, 0, 0, 0);
}

//cycles through each PIR sensor to check that it is moving
void Old_Network::cycle_PIR(void){
	for(int i = 0;i<num_of_sensors_g;i++){
		//checks for the PIR sensor is active: if so, on, else off
		if(analogRead(*(PIR_sensor_array+i))>600){
			LED_on(*(PIR_sensor_array+i), 'r');
		}else{
			LED_off(*(PIR_sensor_array+i));
		}
	}
	strip.show();
}

int Old_Network::analog_read_out(int sensor){
	return analogRead(*(PIR_sensor_array+sensor));
}

void Old_Network::LED_all_on(void){
	for(int i = 0;i<num_of_sensors_g;i++){
		LED_on(*(PIR_sensor_array+i), 'r');
	}
	strip.show();
}

void Old_Network::LED_all_off(void){
	for(int i = 0;i<num_of_sensors_g;i++){
		LED_off(*(PIR_sensor_array+i));
	}
	strip.show();
}
	
	
	