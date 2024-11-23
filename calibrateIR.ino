// Function to calibrate IR sensors
void calibrateir() {
  // Initialize min and max values with extreme values
  minA0 = maxA0 = analogRead(A0);
  minA1 = maxA1 = analogRead(A1);
  minA2 = maxA2 = analogRead(A2);
  minA3 = maxA3 = analogRead(A3);
  minA4 = maxA4 = analogRead(A4);
  minA5 = maxA5 = analogRead(A5);
  minA6 = maxA6 = analogRead(A6);
  minA7 = maxA7 = analogRead(A7);

  // Read values multiple times to find min and max
  for (int i = 0; i < 100; i++) {  // Adjust the number of iterations as needed
    int valueA0 = analogRead(A0);
    int valueA1 = analogRead(A1);
    int valueA2 = analogRead(A2);
    int valueA3 = analogRead(A3);
    int valueA4 = analogRead(A4);
    int valueA5 = analogRead(A5);
    int valueA6 = analogRead(A6);
    int valueA7 = analogRead(A7);

    // Update min and max values for each IR sensor
    minA0 = min(minA0, valueA0);
    maxA0 = max(maxA0, valueA0);

    minA1 = min(minA1, valueA1);
    maxA1 = max(maxA1, valueA1);

    minA2 = min(minA2, valueA2);
    maxA2 = max(maxA2, valueA2);

    minA3 = min(minA3, valueA3);
    maxA3 = max(maxA3, valueA3);

    minA4 = min(minA4, valueA4);
    maxA4 = max(maxA4, valueA4);

    minA5 = min(minA5, valueA5);
    maxA5 = max(maxA5, valueA5);

    minA6 = min(minA6, valueA6);
    maxA6 = max(maxA6, valueA6);

    minA7 = min(minA7, valueA7);
    maxA7 = max(maxA7, valueA7);

    delay(10); // Small delay to stabilize readings (can be adjusted)
  }

  // Calculate threshold values
  thresholdA0 = (minA0 + maxA0) / 2;
  thresholdA1 = (minA1 + maxA1) / 2;
  thresholdA2 = (minA2 + maxA2) / 2;
  thresholdA3 = (minA3 + maxA3) / 2;
  thresholdA4 = (minA4 + maxA4) / 2;
  thresholdA5 = (minA5 + maxA5) / 2;
  thresholdA6 = (minA6 + maxA6) / 2;
  thresholdA7 = (minA7 + maxA7) / 2;

  // Print the min, max, and threshold values for debugging
  Serial.print("min A0: ");
  Serial.print(minA0);
  Serial.print("        max A0: ");
  Serial.print(maxA0);
  Serial.print("       Threshold A0: ");
  Serial.println(thresholdA0);
  
  Serial.print("min A0: ");
  Serial.print(minA1);
  Serial.print("       max A0: ");
  Serial.print(maxA1);
  Serial.print("       Threshold A1: ");
  Serial.println(thresholdA1);

  Serial.print("minA2 A0: ");
  Serial.print(minA2);
  Serial.print("       maxA2 A0: ");
  Serial.print(maxA2);
  Serial.print("       Threshold A2: ");
  Serial.println(thresholdA2);

  Serial.print("minA3 A0: ");
  Serial.print(minA3);
  Serial.print("       maxA3 A0: ");
  Serial.print(maxA3);
  Serial.print("       Threshold A3: ");
  Serial.println(thresholdA3);

  Serial.print("minA4 A0: ");
  Serial.print(minA4);
  Serial.print("       maxA4 A0: ");
  Serial.print(maxA4);
  Serial.print("       Threshold A4: ");
  Serial.println(thresholdA4);

  Serial.print("minA5 A0: ");
  Serial.print(minA5);
  Serial.print("       maxA5 A0: ");
  Serial.print(maxA5);
  Serial.print("       Threshold A5: ");
  Serial.println(thresholdA5);

  Serial.print("minA6 A0: ");
  Serial.print(minA6);
  Serial.print("       maxA6 A0: ");
  Serial.print(maxA6);
  Serial.print("       Threshold A6: ");
  Serial.println(thresholdA6);

  Serial.print("minA7 A0: ");
  Serial.print(minA7);
  Serial.print("       maxA7 A0: ");
  Serial.print(maxA7);
  Serial.print("Threshold A7: ");
  Serial.println(thresholdA7);
}
