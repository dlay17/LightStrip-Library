/**
 *LightStrip.h - The Passive Infrared (PIR) Project from the Automation Lab at Brandeis University
 *Authored by Daniel Lay, the BIGGEST brain programmer at the automation lab (suck it Tim)
 */
#ifndef LightStrip_h
#define LightStrip_h
	
#include <Adafruit_NeoPixel.h>


class LightStrip
{
	public:
		LightStrip(int PIR_sensor[], int num_of_sensors);					//constructor
		void cycle_PIR();													//cycles through all of the PIR sensors to check if there if one triggers
	private:
		int PIR_sensor[];													//array of PIR sensors
		int num_of_sensors;
		Adafruit_NeoPixel strip;											//sets up the LED strip
		
		
		bool check_move(int PIR_output);									//checks for movement from the PIR sensor
		void LED_on(int sensor_number, char color);							//turns LED on sensor a certain color
		void LED_off(int sensor_number); 									//turns LED off at certain PIR sensor		
};

#endif