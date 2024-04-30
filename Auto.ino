#include <PRIZM.h>    // Include PRIZM Library

PRIZM prizm;          // Instantiate an object named prizm

void setup() {
    prizm.setServoPositions(prizm.readServoPosition(1), 0, 0, 0, 0, 90, ;


    prizm.PrizmBegin(); // Initiates the PRIZM controller - must be called in the setup of each PRIZM sketch
    const double WHEELRADIUS = 10.13;//uknown in cm
    const double ROBOTRADIUS = 0; //unknown in cm

    const long double PI = 3.14159265358979324;

    enum team {
        red = 1,
        blue = -1
    };
    //allows 1 code to work for both alliances
    int team = red /*or blue*/;

    enum arm {
        HAND = 4 //servo
    };

    enum drivetrain {
        RIGHT = 2,  //motor
        LEFT = 1,   //motor
        CENTER = 1 //servo
    };

    enum sensors {
        LINE = 1,
        DISTANCE = 2
    };
}

// given a distance, converts to degrees
double distance(double distance) {
    return round((360 * distance) / (WHEELRADIUS * 2 * PI));
}

void loop() {
    while (prizm.readLineSensor(LINE) == 1) { //moves sideways until inline with bonus rack
        prizm.setServoSpeed(CENTER, 100);
    }
    //stop movement
    prizm.setServoSpeed(CENTER, 0);

    //moves forward to put arm above rack
    prizm.setMotorDegree(RIGHT, 100, distance(30.48));
    prizm.setMotorDegree(LEFT, 100, distance(30.48));
    while (prizm.readMotorBusy(2) == 1 || prizm.readMotorBusy(3) == 1 {
        //do nothing
    }

    //releases fish
    prizm.setServoPosition(HAND, 0);

    //moves backwards so that arm is no longer above rack
    prizm.setMotorDegree(RIGHT, 100, distance(-96.52));
    prizm.setMotorDegree(LEFT, 100, distance(-96.52));
    while (prizm.readMotorBusy(RIGHT) == 1 || prizm.readMotorBusy(LEFT) == 1 {
        //do nothing
    }

}
