This is a project for Embedded C at West University of Timisoara
Creator: Beze Robert

Things needed:
-1xArduino uno r3 board
-1xBreadboard
-2xLed's (one green, one red)
-3xResistors(2x150ohm, 1x220ohm)
-1xHC-SR04 ultrasonic sensor
-1xPassive buzzer

The setup is in schematics.png: led resistors: 150omh, passive buzzer resistor: 220ohm

This little project allows you to monitor how much time you spend sitting in a chair at your desk.
The distance can be changed: #define dist 100. I let it be 1meter because the sensor can interfere with other things at smaller distances.
Also the timer can be changed by altering the if with variable "timer" (default it's 1500 seconds)
When you sit in a place for more than ~30 minutes, the green LED will turn off, then the red LED will turn on and the buzzer will make noise until
you increase the distance between you and the sensor by atleast 1 meter.

