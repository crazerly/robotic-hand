#include <Servo.h>

const int servoPins[4]  = {3, 4, 5, 6};
const int sensorPins[4] = {A1, A2, A3, A4};
Servo servos[4];

int sensorMin[4];
int sensorMax[4];
int avgSensorVal[4] = {0,0,0,0};
int iter = 0;

void setup() {
  Serial.begin(9600);

  // Attach servos and initialise range of sensors
  for (int i = 0; i < 4; i++) {
    servos[i].attach(servoPins[i]);
    servos[i].write(0);


    int initial = analogRead(sensorPins[i]);
    sensorMax[i] = initial;
    sensorMin[i] = max(initial - 50, 0);

    delay(10);
  }
  // Allow time to stretch out hand
  delay(3000);
}

void loop() {
  // Get sensor readings for each finger
  for (int f = 0; f < 4; f++) {
    int val = analogRead(sensorPins[f]);

    Serial.print("Finger ");
    Serial.print(f + 1);
    Serial.print(": ");
    Serial.print(val);
    Serial.print("   ");

    val = constrain(val, sensorMin[f], sensorMax[f]);
    avgSensorVal[f] += val;
  }

  // Update servos very ten readings to smooth noise
  if (iter >= 9) {
    for (int f = 0; f < 4; f++) {
      int avg = avgSensorVal[f] / 10;
      int angle = map(avg, sensorMin[f], sensorMax[f], 0, 180);
      servos[f].write(180 - constrain(angle, 0, 180));
      avgSensorVal[f] = 0;
    }
    iter = 0;
  }

  iter = (iter + 1) % 10;

  Serial.println();
  delay(50);
}
