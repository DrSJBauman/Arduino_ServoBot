void bumpTest() {
  // Test bumper switches
  pbLeft = digitalRead(bumpL);
  pbRight = digitalRead(bumpR);

  if (pbLeft == HIGH) {         // If left bumper hit
    Serial.println("Left bump, autosteering");
    slowReverse();
    delay(500);
    slowRight();
    delay(1000);
  }

  if (pbRight == HIGH) {        // If right bumper hit
    Serial.println("Right bump, autosteering");
    slowReverse();
    delay(500);
    slowLeft();
    delay(1000);
  }
}
