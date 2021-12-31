/////////////////
// servoTurret //
/////////////////

/* This routine scans the front turret servo motor back and forth between 45 and 135 degrees
 *  by checking the servo position and comparing it to the previous servo position to
 *  determine whether to continue incrementing by 10 degrees in the same direction or to 
 *  switch directions.
 */

void servoTurret() {
  servoPosition = servoFront.read();  // Check front servo position
  //Serial.println(servoPosition);
  
  // If servo is rotating right and hasn't reached max position, continue
  if ((servoPosition >= prevPosition) && (servoPosition < maxPosition)) {
  servoFront.write(servoPosition + 10);
  prevPosition = servoPosition;
  }
  
  // If servo is rotating right and has reached max position, switch directions
  else if ((servoPosition > prevPosition) && (servoPosition >= maxPosition)) {
  servoFront.write(servoPosition - 10);
  prevPosition = servoPosition;
  }
  
  // If servo is rotating left and has reached min position, switch directions
  else if ((servoPosition < prevPosition) && (servoPosition <= minPosition)) {
  servoFront.write(servoPosition + 10);
  prevPosition = servoPosition;
  }
  
  // If servo is rotating left and hasn't reached min position, continue
  else if ((servoPosition < prevPosition) && (servoPosition > minPosition)) {
  servoFront.write(servoPosition - 10);
  prevPosition = servoPosition;
  }
  
  else {
  servoFront.write(90);
  prevPosition = servoPosition;
  }
}
