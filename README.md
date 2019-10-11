# PIR-Project
PIR Project by Daniel Lay only (not tim)

Since we are using pushingbox.api, we have a push limit of 1000 requests per day. Therefore we have 2 options:
1) Since there are 1440 minutes in a day, we can send data every 2 minutes, making 720 pushes per day. However, this limits our ability to find grab detail as we are getting data every 2 seconds.
In actuality, we can get away with sending 1 bit for every seconds
Given that we are already sending char and our character limit 
