/**
 *PIR_Network.h - The Passive Infrared (PIR) Project from the Automation Lab at Brandeis University
 *Authored by Daniel Lay, the BIGGEST brain programmer at the automation lab (suck it Tim)
 */
#ifndef PIR_Network_h
#define PIR_Network_h
	
#include <Adafruit_NeoPixel.h>


class PIR_Network
{
	public:
		PIR_Network();					//constructor
		void cycle_PIR();													//cycles through all of the PIR sensors to check if there if one triggers
		void LED_all_on();													//turns all LED on
		void LED_all_off();													//turns all LED off
		int analog_read_out(int sensor);									//analog out for debugging
		bool check_move(int PIR_output);									//checks for movement from the PIR sensor
		void init(int sensor_array_address[], int num_of_sensors_in, int LED_pin);
		
	private:
		int *PIR_sensor_array;												//array of PIR sensors
		int num_of_sensors_g;
		Adafruit_NeoPixel strip;											//sets up the LED strip
		
		
		
		void LED_on(int sensor_number, char color);							//turns LED on sensor a certain color
		void LED_off(int sensor_number); 									//turns LED off at certain PIR sensor		
};

#endif