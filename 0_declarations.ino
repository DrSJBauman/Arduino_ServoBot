//===============================================================================
//  Header Files
//===============================================================================
#include <Servo.h>

//===============================================================================
//  Constants
//===============================================================================
// Here we have a bunch of constants that will become clearer when we look at the
// nesRead() function. Basically, we will use these contents to clear
// a bit. These are chosen according to the table in ServoBot_NES_Controller_vX.ino.
const short A_BUTTON         = 0;
const short B_BUTTON         = 1;
const short SELECT_BUTTON    = 2;
const short START_BUTTON     = 3;
const short UP_BUTTON        = 4;
const short DOWN_BUTTON      = 5;
const short LEFT_BUTTON      = 6;
const short RIGHT_BUTTON     = 7;

const short maxPosition = 135;  // Maximum angle to rotate the front turret servo
const short minPosition = 45;   // Minimum angle to rotate the front turret servo

// Create objects of the Servo class
Servo servoLeft;
Servo servoRight;
Servo servoFront;

//===============================================================================
//  Variables
//===============================================================================
byte nesRegister  = 0;    // We will use this to hold current button states
int pbLeft = 0;           // Var for left bump (high/low)
int pbRight = 0;          // Var for right bump (high/low)
int drvMode = 0;          // Var for drive mode (high/low)
unsigned int duration, inches, cm;  // Var for time and distance measured by ultrasonic sensor
bool turretUp = 0;        // Boolean to tell which direction front turret servo is moving
int servoPosition = 0;    // Var for front turret servo position (angle)
int prevPosition = 0;     // Var for comparing to previous front servo position
bool irStatus = 1;        // Boolean to tell the status of the IR detector.

//===============================================================================
//  Pin Declarations
//===============================================================================
//Inputs:
const short nesData = 7;        // The data pin for the NES controller
const short bumpL = 2;          // The input from left leaf switch bumper
const short bumpR = 3;          // The input from right leaf switch bumper
const short driveMode = 4;      // Input from the auto/manual drive mode switch
const short ledPin = 13;        // Built-in LED
const short echoPin = 12;       // Echo pin on the ultrasonic distance sensor.
const short irPin = A5;         // Data pin from the IR detector.

//Outputs:
const short nesClock = 5;       // The clock pin for the NES controller
const short nesLatch = 6;       // The latch pin for the NES controller
const short FServoPin = 8;      // The pin for the front turret servo motor
const short LServoPin = 9;      // The pin for the left servo motor
const short RServoPin = 10;     // The pin for the right servo motor
const short trigPin = 11;       // Trigger pin on the ultrasonic distance sensor
