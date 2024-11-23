void calibrateir();  // Declaration of the calibrateIR function

const int PWM1 = 7; // Control pwm for left motor (m1)
const int IN1 = 1; // Control pin 1 for left motor (m1)
const int IN2 = 0; // Control pin 2 for left motor (m1)
const int PWM2 = 6; // Control pwm for right motor (m2)
const int IN3 = 2; // Control pin 1 for right motor (m2)
const int IN4 = 3; // Control pin 2 for right motor (m2)

// Variables to store the min, max, and threshold values for each IR sensor
int minA0, maxA0, thresholdA0;
int minA1, maxA1, thresholdA1;
int minA2, maxA2, thresholdA2;
int minA3, maxA3, thresholdA3;
int minA4, maxA4, thresholdA4;
int minA5, maxA5, thresholdA5;
int minA6, maxA6, thresholdA6;
int minA7, maxA7, thresholdA7;

int valueA0, valueA1, valueA2, valueA3, valueA4, valueA5, valueA6, valueA7;
int CV0, CV1, CV2, CV3, CV4, CV5, CV6, CV7;

// Variable to calculate the error
long error = 0;

int speedvalue = 200;
int Ldown = 0;
int Rdown = 0;
int Rerror = 0;
int Lerror = 0;

int m1;
int m2;

void setup() {
  Serial.begin(115200);
  pinMode(PWM1, OUTPUT);
  pinMode(PWM2, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  calibrateir();       // Calibrate IR sensors  
  }

void loop() {
  // Call the function to read and assign analog values
  readir();
  Serial.print("error: ");
  Serial.println(error);
  delay(500);

 
  if (error > 0) {
    int Rerror = error;
    int Rdown = map(Rerror, 0, 20000, 0, 200);
    int m1 = 200;
    int m2 = 200 - Rdown;
    Serial.print(m1);
    Serial.print('\t');
    Serial.print(m2);
    Serial.print('\t');
    Serial.println(Rdown);
    
  }else{
    int Lerror = error*-1;
    int Ldown = map(Lerror, 0, 20000, 0, 200);
    int m1 = 200 - Ldown;
    int m2 = 200;
    Serial.print(m1);
    Serial.print('\t');
    Serial.print(m2);
    Serial.print('\t');
    Serial.println(Ldown);
  }


  mdrive(m1, m2);
}
