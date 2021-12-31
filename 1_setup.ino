//===============================================================================
//  Initialization
//===============================================================================
void setup() {
  // Initialize serial port speed for the serial terminal
  Serial.begin(9600);

  // Set appropriate pins to inputs
  pinMode(nesData, INPUT);
  pinMode(bumpL, INPUT);
  pinMode(bumpR, INPUT);
  pinMode(driveMode, INPUT);
  pinMode(echoPin, INPUT);
  pinMode(irPin, INPUT);

  // Set appropriate pins to outputs
  pinMode(nesClock, OUTPUT);
  pinMode(nesLatch, OUTPUT);
  pinMode(trigPin, OUTPUT);

  // Use the attach method to assign each object to a pin
  servoLeft.attach(LServoPin);
  servoRight.attach(RServoPin);
  servoFront.attach(FServoPin);

  // Set initial states
  digitalWrite(nesLatch, LOW);
  digitalWrite(nesClock, LOW);
}
