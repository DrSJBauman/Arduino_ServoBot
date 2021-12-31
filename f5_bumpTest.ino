//////////////
// bumpTest //
//////////////
/* Checks the HIGH/LOW status of the leaf switches mounted to the front of the bot
 *  as collision bumpers to prep the bot for an automatic change of path by reversing
 *  and turning in the direction opposite the bumped leaf switch.
 */

void bumpTest() {
  // Test bumper switches
  pbLeft = digitalRead(bumpL);
  pbRight = digitalRead(bumpR);

  if (pbLeft == HIGH) {         // If left bumper hit
    digitalWrite(ledPin, HIGH); // LED on
    Serial.println("Left bump, autosteering");
    slowReverse();
    delay(500);
    slowRight();
    delay(1000);
    digitalWrite(ledPin, LOW); // LED off
  }

  if (pbRight == HIGH) {        // If right bumper hit
    digitalWrite(ledPin, HIGH); // LED on
    Serial.println("Right bump, autosteering");
    slowReverse();
    delay(500);
    slowLeft();
    delay(1000);
    digitalWrite(ledPin, LOW); // LED off
  }
}
