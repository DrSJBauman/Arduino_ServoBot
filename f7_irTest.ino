////////////
// irTest //
////////////
/* Checks the HIGH/LOW status of the Sharp GP2Y0D810 IR Detector mounted on the back
 *  of the bot to avoid potential rear collisions.
 *  The 810 version of the sensor has a factory-defined 10 cm limit within which the
 *  sensor will trigger a toggle from LOW to HIGH (or vice versa) and will light a red LED.
 */

bool irTest() {
  // Test IR sensor status
  irStatus = digitalRead(irPin);
  //Serial.println(irStatus, DEC);
  
  if (irStatus == 0){
    stopRobot();
    Serial.println("Object detected within 10 cm of rear IR sensor.");
    Serial.println("Stopping reverse motion to avoid rear collision.\n");
  }
  return(irStatus);
}
