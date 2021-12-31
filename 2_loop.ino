//===============================================================================
//  Main
//===============================================================================
void loop() {
  // This function call will return the states of all NES controller's register
  // in a nice 8 bit variable format. Remember to refer to the table and
  // constants above for which button maps where!
  nesRegister = nesRead();

  // Check the auto/manual drive mode switch to determine which loop code to utilize
  drvMode = digitalRead(driveMode);
  if (drvMode == HIGH) {          // Auto drive mode toggled ON = HIGH

    slowForward();                // Start forward automatically
    servoTurret();                // Run turret servo scanning routine   

    // Test ultrasonic sensor distance
    Serial.print("Ultrasonic read distance = ");
    Serial.print(sonarRead(), DEC); // Show ultrasonic sensor distance in Serial Monitor
    Serial.print(" cm");
    Serial.println();

    // Test bumper switches
    bumpTest();
  }

  else {                          // Auto drive mode toggled OFF = LOW
    // Manual drive mode condition:
  
    // This function call will return the states of all NES controller's register
    // in a nice 8 bit variable format. Remember to refer to the table and
    // constants in ServoBot_NES_Controller_vX.ino for which button maps where!
    nesRegister = nesRead();

    // If A + directional button press
    /* I just had the wild idea to make this functionality something like a way to control the 
     *  front turret servo manually. Left and right can rotate the turret. What about up and down?
     *  And if I'm driving this thing around, is there a way to get it to output this distance data anyway?
     *  I could put a screen on it that displays the data...
     */
    if (bitRead(nesRegister, A_BUTTON) == 0 && bitRead(nesRegister, UP_BUTTON) == 0) {   
      //slowForward();
      Serial.println("A + UP");
    } else if (bitRead(nesRegister, A_BUTTON) == 0 && bitRead(nesRegister, DOWN_BUTTON) == 0) {
      //slowReverse();
      Serial.println("A + DOWN");
    } else if (bitRead(nesRegister, A_BUTTON) == 0 && bitRead(nesRegister, RIGHT_BUTTON) == 0) {
      //slowRight();
      Serial.println("A + RIGHT");
    } else if (bitRead(nesRegister, A_BUTTON) == 0 && bitRead(nesRegister, LEFT_BUTTON) == 0) {
      //slowLeft();
      Serial.println("A + LEFT");
    }

  // If Up button press
  else if (bitRead(nesRegister, UP_BUTTON) == 0) {   
      forward();                     // Run the forward motion routine
      Serial.println("UP");
  }

  // If Start button press
  else if (bitRead(nesRegister, START_BUTTON) == 0) {   
      Serial.println("START");
  }

  // If Select button press
  else if (bitRead(nesRegister, SELECT_BUTTON) == 0) {   
      Serial.println("SELECT");
  }

  // If B button press
  else if (bitRead(nesRegister, B_BUTTON) == 0) {   
      Serial.println("B");
      //if (bitRead(nesRegister, UP_BUTTON) == 0 && bitRead(nesRegister, LEFT_BUTTON) == 0) {
        //may need to set up a Up && Turn command that does something like this and then
        //use B or A for a slower turn option or something...
      //}
  }

  // If A button press
  else if (bitRead(nesRegister, A_BUTTON) == 0) {   
      Serial.println("A");
  }

  // If no button press
  else if (nesRegister == 255) {    
      stopRobot();            // Run the stop motion routine
  }

  // Slight delay before we debug what was pressed so we don't spam the
  // serial monitor.
  delay(50);
}
