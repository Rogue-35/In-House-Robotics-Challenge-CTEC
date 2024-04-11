#include <math.h>
#include <PRIZM.h>    // Include PRIZM Library

PRIZM prizm;          // Instantiate an object named prizm

void setup() {

  prizm.PrizmBegin(); // Initiates the PRIZM controller - must be called in the setup of each PRIZM sketch
  int wheelRadius = //uknown in cm;
  int robotRadius = //unknown in cm;

  enum team{
    red = 1
    blue = -1
  }
  int team = red /*or blue*/;

  const double pi = 3.14159;


  enum motor{
    Right = 2,
    Left = 3,
    Center = 1,
  };

}

// given a distance, converts to degrees
int distance(int distance){
  return round((360 * distance)/(wheelRadius * 2 * pi));
}

//given a direction, and a numebr of degrees, will turn that direction and that number of degrees (-1 turns right, 1 turns left)
void turn(int direction, int degrees){
  prizm.setMotorDegree(right, 100, distance((robotRadius * 2 * pi)/(360/degrees)) * direction);
  Prizm.setMotorDefree(left, 100, distance((robotRadius * 2 * pi)/(360/degrees)) * -direction);
}


void loop() {
  while(/*code for line sensor*/){ //moves sideways until inline with bonus rack
    prizm.setMotorSpeed(center, 255);
  }

  //code for servos, lifts arm

  //moves forward to put arm above rack
  prizm.setMotorDegree(right, 100, distance(25)))
  prizm.setMotorDegree(left, 100, distance(25))
  while (prizm.readMotorBusy(2) == 1 || prizm.readMotorBusy(3) == 1 {
    //do nothing
  }

  //releases fish
  //code for servos, release grasp

  //moves backwards so that arm is no longer above rack
  prizm.setMotorDegree(right, 100, distance(-25))
  prizm.setMotorDegree(left, 100, distance(-25));
  while (prizm.readMotorBusy(right) == 1 || prizm.readMotorBusy(left) == 1 {
    //do nothing
  }

  //lowers arm for better movement
  //code for servos, lower arm

  //moves sideways until in range of the hooks (may use ultrasonic)
  prizm.setMotorDegree(center, 100, distance(//needs to be calculated by determining how far the robot went forawrd, and how much further it needs to go to get to ~ 325cm));

  //turns 90 degrees to allow for alligment with hooks
  turn(team, 90);

  //moves sideways for alligment with hooks (will need to be manually calibrated)
  prizm.setMotorDegree(center, 100, 40) //maybe 50

  //code for servos, raise arm

  //moves forwards until arm is above hooks
  prizm.setMotorDegree(right, 100, distance(25)))
  prizm.setMotorDegree(left, 100, distance(25))
  while (prizm.readMotorBusy(right) == 1 || prizm.readMotorBusy(left) == 1 {
    //do nothing
  }

  //grabs 2 fish off the rack
  //code for servos, grab

  //moves backwards from rack
  prizm.setMotorDegree(right, 100, distance(-25))
  prizm.setMotorDegree(left, 100, distance(-25));
  while (prizm.readMotorBusy(right) == 1 || prizm.readMotorBusy(left) == 1 {
    //do nothing
  }

  //lowers arm
  //code for servo, lower arm


  //code for either returning to the warehouse, or placing fish on drying rack. :)
}
