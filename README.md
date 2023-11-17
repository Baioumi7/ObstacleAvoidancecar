# ObstacleAvoidancecar


This project was done on Eclipse IDE using the gcc compiler and simulation is done on Proteus.

1) After power on and initialization, the program asks the user for the direction of rotation, the default direction is right, and the user is given a 5 seconds window to choose between left or right direction by pressing the push button once to toggle the direction.

2) After the 5 seconds window, the program waits 2 seconds, then the program starts to read the distance from the ultrasonic sensor, and based on the distance between the car and the nearest obstacle it takes decisions.

3) If the distance is more than 70cm, the car moves forward at 30% speed, and after 5 seconds, it increases the speed to 50%

4) If the distance is between 30cm and 70cm, the car will move forward at 30% speed

5) If the distance is between 20cm and 30cm, the car rotates 90 degrees to left/right, based on the default direction chosen by user at the start of the application, if the distance is still between 20cm and 30cm, the car will keep rotating until it finds a passable route

6) If the distance is lower than 20cm, the car moves backward at 30% speed until the distance is more than 20cm, then it takes a decision based on that distance.
