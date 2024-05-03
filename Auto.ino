#include <PRIZM.h>  // Include PRIZM Library
#include <math.h>

PRIZM prizm;                       // Instantiate an object named prizm
const double WHEELRADIUS = 10.13;  //uknown in cm
const double ROBOTRADIUS = 0;      //unknown in cm

const double pi = M_PI;

enum team {
  red = 1,
  blue = -1
};
//allows 1 code to work for both alliances
int team = blue;

enum arm {
  HAND = 1  //servo
};

enum drivetrain {
  RIGHT = 2,  //motor
  LEFT = 1,   //motor
  CENTER = 1  //servo
};

enum sensors {
  LINE = 2,
};
bool h = true;

void setup() {
  prizm.PrizmBegin();  // Initiates the PRIZM controller - must be called in the setup of each PRIZM sketch
  prizm.setMotorInvert(RIGHT, 1);
  prizm.setServoPosition(HAND, 180);
  prizm.resetEncoders();
}

// given a distance, converts to degrees
double distance(double distance) {
  prizm.resetEncoders();

  return (360 * distance) / (WHEELRADIUS * 2 * pi);
}

void loop() {
  
  if (prizm.readLineSensor(LINE) == 1 && h) {  //moves sideways until inline with bonus rack
    prizm.setCRServoState(CENTER, 100 * team);
    return;
  } else {
    h = false;
  }

  //stop movement
  prizm.setCRServoState(CENTER, 0);
  prizm.setMotorTargets(100, prizm.readEncoderDegrees(LEFT) + distance(200.48), 100, prizm.readEncoderDegrees(RIGHT) + distance(200.48));
  //moves forward to put arm above rack

  while (prizm.readMotorBusy(RIGHT) == 1 || prizm.readMotorBusy(LEFT) == 1);
  delay(1000);

  //releases fish
  prizm.setServoPosition(HAND, 0);
  delay(1000);

  //moves backwards so that arm is no longer above rack
  prizm.setMotorTargets(100, prizm.readEncoderDegrees(LEFT) + distance(-760.48), 100, prizm.readEncoderDegrees(RIGHT) + distance(-760.48));
  while (prizm.readMotorBusy(RIGHT) == 1 || prizm.readMotorBusy(LEFT) == 1);
  prizm.setServoPosition(HAND, 180);
  delay(1000);
  prizm.PrizmEnd();
}
