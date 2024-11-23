// Function to read and assign values from analog pins and calculate error
void readir() {
  // Read the values from the analog pins
  valueA0 = analogRead(A0);
  valueA1 = analogRead(A1);
  valueA2 = analogRead(A2);
  valueA3 = analogRead(A3);
  valueA4 = analogRead(A4);
  valueA5 = analogRead(A5);
  valueA6 = analogRead(A6);
  valueA7 = analogRead(A7);

  // Check if each value is greater than its threshold and assign CV values
  CV0 = (valueA0 > thresholdA0) ? 1 : 0;
  CV1 = (valueA1 > thresholdA1) ? 1 : 0;
  CV2 = (valueA2 > thresholdA2) ? 1 : 0;
  CV3 = (valueA3 > thresholdA3) ? 1 : 0;
  CV4 = (valueA4 > thresholdA4) ? 1 : 0;
  CV5 = (valueA5 > thresholdA5) ? 1 : 0;
  CV6 = (valueA6 > thresholdA6) ? 1 : 0;
  CV7 = (valueA7 > thresholdA7) ? 1 : 0;

  // Calculate the error based on the CV values
  error = ((-10000 * CV7) + (-2000 * CV6) + (-500 * CV5) + (-100 * CV4) +
           (100 * CV3) + (500 * CV2) + (2000 * CV1) + (10000 * CV0));

  // Adjust the error if only the last IRs (A0, A1, A6, A7) are triggered
  if ((CV0 == 1 && CV1 == 0 && CV2 == 0 && CV3 == 0 && CV4 == 0 && CV5 == 0 && CV6 == 0 && CV7 == 0) ||  // Only A0 active
      (CV0 == 0 && CV1 == 1 && CV2 == 0 && CV3 == 0 && CV4 == 0 && CV5 == 0 && CV6 == 0 && CV7 == 0) ||  // Only A1 active
      (CV0 == 0 && CV1 == 0 && CV2 == 0 && CV3 == 0 && CV4 == 0 && CV5 == 0 && CV6 == 1 && CV7 == 0) ||  // Only A6 active
      (CV0 == 0 && CV1 == 0 && CV2 == 0 && CV3 == 0 && CV4 == 0 && CV5 == 0 && CV6 == 0 && CV7 == 1)) {  // Only A7 active
    error *= 2; // Increase the error by 1.5 times when the line is on the last two IRs
  }

  // Adjust the error if both of the outermost sensors (A0, A1, A6, A7) are triggered
  if ((CV0 == 1 && CV1 == 1 && CV2 == 0 && CV3 == 0 && CV4 == 0 && CV5 == 0 && CV6 == 0 && CV7 == 0) ||  // A0 and A1 active
      (CV0 == 0 && CV1 == 0 && CV2 == 0 && CV3 == 0 && CV4 == 0 && CV5 == 0 && CV6 == 1 && CV7 == 1)) {  // A6 and A7 active
    error *= 1.5; // Double the error when both outermost sensors are triggered
  }
}
