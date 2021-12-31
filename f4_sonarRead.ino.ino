///////////////
// sonarRead //
///////////////
/* Activates the ultrasonic sensor's trigger pin, awaits the echoed ultrasound pulse,  
 *  and returns the distance between the nearest measured object and the sensor in centimeters.*/

int sonarRead() {
  digitalWrite(trigPin, LOW);   // Ensure pin is low
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);  // Start ranging
  delayMicroseconds(10);        //  with 10 µs pulse to activate
                                //  the 8-cycle burst of 40 kHz ultrasound.
  digitalWrite(trigPin, LOW);   // End this pulse - 8-cycle burst should activate.

  duration = pulseIn(echoPin, HIGH);  // Read echo pulse
  // Total ping time is 1474 µs, so an object 10 inches away is 1474/74/2 = 10 in.
  inches = duration / 74 / 2;   // 1130 ft/s = 13560 in/s or 1 inch in 74 µs
  cm = duration / 29 / 2;       // Converts to cm instead of inches

  if (cm < 7) {         // If sensor detects object close-approaching
    Serial.println("Object within 7 cm.");
    Serial.println("Avoiding head-on collision by autosteering.");
    slowReverse();
    delay(500);
    slowRight();
    delay(500);
  }  
  return(cm);
}
