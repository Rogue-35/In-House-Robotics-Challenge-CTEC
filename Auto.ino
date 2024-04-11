#include <PRIZM.h>    // Include PRIZM Library

PRIZM prizm;          // Instantiate an object named prizm

void setup() {
  prizm.setServoPositions(prizm.readServoPosition(1), 0, 0, 0, 0, 90,;


  prizm.PrizmBegin(); // Initiates the PRIZM controller - must be called in the setup of each PRIZM sketch
  const int wheelRadius = 0;//uknown in cm
  const int robotRadius = 0; //unknown in cm

  const long double PI = 3.14159265358979324;

  enum team{
    red = 1,
    blue = -1
  };
  //allows 1 code to work for both alliances
  int team = red /*or blue*/;

  enum arm{
    idek = 1, //we can only have 2 motors during auto so regardless of drive train we can't have a motored powered arm.
    hand = 4 //servo
  };

  enum drivetrain{
    Right = 2,  //motor
    Left = 1,   //motor
    center = 1, //servo
  };
}

// given a distance, converts to degrees
int distance(int distance){
  return round((360 * distance)/(wheelRadius * 2 * PI));
}

//given a direction, and a numebr of degrees, will turn that direction and that number of degrees (-1 turns right, 1 turns left)
void turn(int direction, int degrees){
  prizm.setMotorDegree(right, 100, distance((robotRadius * 2 * PI)/(360/degrees)) * direction);
  Prizm.setMotorDefree(left, 100, distance((robotRadius * 2 * PI)/(360/degrees)) * -direction);
  while (prizm.readMotorBusy(2) == 1 || prizm.readMotorBusy(3) == 1 {
    delay(1);
  }
  return 0
}


void loop() {
  while(prizm.readLineSensor(/*uknown*/) == 1){ //moves sideways until inline with bonus rack
    prizm.setServoSpeed(center,100);
  }
  //stop movement
  prizm.setServoSpeed(center,0);

  //lifts arm
    prizm.setServoPositions(prizm.readServoPosition(1),90, 90, 90, 90,prizm.readServoPosition(6));

  //moves forward to put arm above rack
  prizm.setMotorDegree(right, 100, distance(25));
  prizm.setMotorDegree(left, 100, distance(25));
  while (prizm.readMotorBusy(2) == 1 || prizm.readMotorBusy(3) == 1 {
    //do nothing
  }

  //releases fish
  prizm.setServoPosition(6, 0);

  //moves backwards so that arm is no longer above rack
  prizm.setMotorDegree(right, 100, distance(-25));
  prizm.setMotorDegree(left, 100, distance(-25));
  while (prizm.readMotorBusy(right) == 1 || prizm.readMotorBusy(left) == 1 {
    //do nothing
  }

  //lowers arm for better movement
  prizm.setServoPositions(prizm.readServoPosition(1),0, 0, 0, 0,prizm.readServoPosition(6));

  //moves sideways until in range of the hooks using ultrasonic
  while(prizm.readSonicSensorCM(/*uknown*/) <= 32){
      prizm.setServoSpeed(center,100);

  }
  //stop movement
  prizm.setServoSpeed(center,0);
  
  //turns 90 degrees to allow for alligment with hooks
  turn(team, 90);

  //moves sideways for alligment with hooks (will need to be manually calibrated)
    prizm.setServoSpeed(center,100);
    delay(/*something*/);
    prizm.setServoSpeed(center,0);
  
  //code for servos, raise arm
  prizm.setServoPositions(prizm.readServoPosition(1),90, 90, 90, 90,prizm.readServoPosition(6));

  //moves forwards until arm is above hooks
  prizm.setMotorDegree(right, 100, distance(25));
  prizm.setMotorDegree(left, 100, distance(25));
  while (prizm.readMotorBusy(right) == 1 || prizm.readMotorBusy(left) == 1 {
    //do nothing
  }

  //grabs 2 fish off the rack
  prizm.setServoPosition(6, 90);

  //moves backwards from rack
  prizm.setMotorDegree(right, 100, distance(-25));
  prizm.setMotorDegree(left, 100, distance(-25));
  while (prizm.readMotorBusy(right) == 1 || prizm.readMotorBusy(left) == 1 {
    //do nothing
  }

  //lowers arm
  prizm.setServoPositions(prizm.readServoPosition(1), 0, 0, 0, 0, prizm.readServoPosition(6));

  //code for either returning to the warehouse, or placing fish on drying rack. :)
}
