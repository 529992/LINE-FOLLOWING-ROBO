// Motor control pins
int motorA1 = 2;
int motorA2 = 3;
int motorB1 = 4;
int motorB2 = 5;
int ENA = 9;
int ENB = 10;

// IR sensor pins
int ir1 = 6;
int ir2 = 7;
int ir3 = 8;  // Center sensor
int ir4 = A0;
int ir5 = A1;

// PID constants
float Kp = 25.0; // Proportional gain
float Ki = 0.0;  // Integral gain (Start with 0, adjust if needed)
float Kd = 15.0; // Derivative gain

// Speed control
int baseSpeed = 150;  // Base speed of the motors
float error = 0;
float previousError = 0;
float integral = 0;
int maxSpeed = 255;  // Maximum PWM value

void setup() {
  // Set motor pins as output
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Set IR sensor pins as input
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);
  pinMode(ir5, INPUT);
}

void loop() {
  // Read sensor values
  int s1 = digitalRead(ir1);  // Leftmost sensor
  int s2 = digitalRead(ir2);
  int s3 = digitalRead(ir3);  // Center sensor
  int s4 = digitalRead(ir4);
  int s5 = digitalRead(ir5);  // Rightmost sensor

  // Calculate error based on sensor values
  error = calculateError(s1, s2, s3, s4, s5);

  // Calculate PID values
  float proportional = error;
  integral += error;  // Accumulate the integral term
  float derivative = error - previousError;
  previousError = error;

  // PID output
  float PIDvalue = (Kp * proportional) + (Ki * integral) + (Kd * derivative);

  // Adjust motor speeds based on the PID value
  int leftSpeed = constrain(baseSpeed + PIDvalue, 0, maxSpeed);
  int rightSpeed = constrain(baseSpeed - PIDvalue, 0, maxSpeed);

  // Move the motors with the calculated speeds
  moveMotors(leftSpeed, rightSpeed);
}

float calculateError(int s1, int s2, int s3, int s4, int s5) {
  // Assign weights to sensors
  int weights[5] = {-2, -1, 0, 1, 2};  // Negative means left, positive means right

  // Calculate weighted average error
  float weightedSum = (s1 * weights[0]) + (s2 * weights[1]) + (s3 * weights[2]) + (s4 * weights[3]) + (s5 * weights[4]);
  float totalActiveSensors = s1 + s2 + s3 + s4 + s5;

  // If no sensor detects the line, return previous error (keep going with the previous direction)
  if (totalActiveSensors == 0) {
    return previousError;
  }

  // Calculate the actual error
  float error = weightedSum / totalActiveSensors;
  return error;
}

void moveMotors(int leftSpeed, int rightSpeed) {
  // Move left motor
  if (leftSpeed > 0) {
    digitalWrite(motorA1, HIGH);
    digitalWrite(motorA2, LOW);
    analogWrite(ENA, leftSpeed);
  } else {
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, HIGH);
    analogWrite(ENA, -leftSpeed);
  }

  // Move right motor
  if (rightSpeed > 0) {
    digitalWrite(motorB1, HIGH);
    digitalWrite(motorB2, LOW);
    analogWrite(ENB, rightSpeed);
  } else {
    digitalWrite(motorB1, LOW);
    digitalWrite(motorB2, HIGH);
    analogWrite(ENB, -rightSpeed);
  }
}
