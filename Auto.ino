#include <math.h>
#include <PRIZM.h>    // Include PRIZM Library

PRIZM prizm;          // Instantiate an object named prizm




void setup() {

  prizm.PrizmBegin(); // Initiates the PRIZM controller - must be called in the setup of each PRIZM sketch
  int wheelRadius = //uknown in cm;
  int robotRadius = //unknown in cm;

  int team = 1 // or -1

  int pi = 3.14159;

  //motor 2 is right
  //motor 3 is left
  //motor 1 is sideways
}
int distance(int distance){
  return round((360 * distance)/(wheelRadius * 2 * pi));
}
void turn(int direction, int degrees){
  prizm.setMotorDegree(2, 100, distance((robotRadius * 2 * pi)/(360/degrees)) * direction);
  Prizm.setMotorDefree(3, 100, distance((robotRadius * 2 * pi)/(360/degrees)) * -direction);
}

void loop() {
  while(//code for line sensor){
    prizm.setMotorSpeed(1, 255);
  }
  prizm.setMotorDegree(2, 100, distance(25)))
  prizm.setMotorDegree(3, 100, distance(25))
  while (prizm.readMotorBusy(2) == 1 || prizm.readMotorBusy(3) == 1 {
    //do nothing
  }

  //code for servos, lift arm, release grasp

  prizm.setMotorDegree(2, 100, distance(-25))
  prizm.setMotorDegree(3, 100, distance(-25));
  while (prizm.readMotorBusy(2) == 1 || prizm.readMotorBusy(3) == 1 {
    //do nothing
  }

  //code for servos, lower arm

  prizm.setMotorDegree(1, 100, distance(//needs to be calculated by determining how far the robot went forawrd, and how much further it needs to go to get to ~ 325cm));

  turn(team, 90);

  prizm.setMotorDegree(1, 100, 40) //maybe 50


  //code for servos, raise arm

  prizm.setMotorDegree(2, 100, distance(25)))
  prizm.setMotorDegree(3, 100, distance(25))
  while (prizm.readMotorBusy(2) == 1 || prizm.readMotorBusy(3) == 1 {
    //do nothing
  }

  //code for servos, grab

  prizm.setMotorDegree(2, 100, distance(-25))
  prizm.setMotorDegree(3, 100, distance(-25));
  while (prizm.readMotorBusy(2) == 1 || prizm.readMotorBusy(3) == 1 {
    //do nothing
  }

  //lower arm


  //code for either returning to the warehouse, or placing fish on drying rack. :)
}





