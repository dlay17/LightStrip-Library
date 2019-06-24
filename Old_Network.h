/**
 *Old_Network.h - The Passive Infrared (PIR) Project from the Automation Lab at Brandeis University
 *Authored by Daniel Lay, the BIGGEST brain programmer at the automation lab (suck it Tim)
 */
#ifndef Old_Network.h
#define Old_Network.h
	
#include <Adafruit_NeoPixel.h>


class Old_Network
{
	public:
		Old_Network(int sensor_array[], int num_of_sensors_in, int LED_pin);					//constructor
		void cycle_PIR();													//cycles through all of the PIR sensors to check if there if one triggers
		void LED_all_on();													//turns all LED on
		void LED_all_off();													//turns all LED off
		int analog_read_out(int sensor);									//analog out for debugging
	private:
		int *PIR_sensor_array;												//array of PIR sensors
		int num_of_sensors_g;
		Adafruit_NeoPixel strip;											//sets up the LED strip
		
		
		bool check_move(int PIR_output);									//checks for movement from the PIR sensor
		void LED_on(int sensor_number, char color);							//turns LED on sensor a certain color
		void LED_off(int sensor_number); 									//turns LED off at certain PIR sensor		
};

#endif