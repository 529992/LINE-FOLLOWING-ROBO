// Function to drive motors forward
void mdrive(int m1, int m2) {
  // Control the left motor (m1)
  digitalWrite(IN1, LOW);   // Set IN1 to LOW for forward motion
  analogWrite(PWM1, m1);    // Set PWM1 to m1 for speed control
  digitalWrite(IN2, HIGH);  // Set IN2 to HIGH for forward motion

  // Control the right motor (m2)
  digitalWrite(IN3, LOW);   // Set IN3 to LOW for forward motion
  analogWrite(PWM2, m2);    // Set PWM2 to m2 for speed control
  digitalWrite(IN4, HIGH);  // Set IN4 to HIGH for forward motion
}
