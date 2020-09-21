# PIR-Project
PIR Project by Daniel Lay

Goal:
The premise of this project is using simple binary PIR sensor to create a heat map of a room to predict movement patterns of the people within the room as well as making predictions of how many individuals are in a room at once. For the prototype, we are installing these sensors within the AutomationLab to get a better understanding on what users of the space prioritize so that we can taylor the space to fit user preference.

Problem:
Since we are using pushingbox.api, we have a push limit of 1000 requests per day as well as a max character limit of 1000. Since there are 1440 minutes in a day, we can get away with sending data every 2 minutes, making 720 pushes per day. However, this limits our ability to find grab detail as we are getting data every 2 seconds therefore we must find a way to gather data for those two minutes and compress it so that we remain under the 1000 character limit. For maximun granularity, the PIR sensor can log whether there is someone under them every 2 seconds, making a 60 bit string every 2 minutes. However, we have 13 sensors and if we were to handle this in a larger space, the amount of data that one can send increases exponentially.

Solution:
We need compression. We can treat each sensor as its own binary string independent of each other. Now we can compress the data from a 60 bit string of 1s and 0s, we can convert that into hexadecimal and concatenate all of the snesor data together before sending it through pushingbox.api and then run a decompression algorithm to get it back as the 60 bit string to see when the sensor was on or off. By converting from binary to hex, we are compressing by 400% and will allow us to send more data over with less characters used.
