
int co2 = 700;
int direction = 100;

// false = Automatic mode
// true  = Manual potentiometer mode
bool manualMode = true;

void setup() {
  pinMode(4, OUTPUT);   // Green LED
  pinMode(5, OUTPUT);   // Yellow LED
  pinMode(2, OUTPUT);   // Red LED
  pinMode(18, OUTPUT);  // Buzzer
  pinMode(34, INPUT);   // Potentiometer

  Serial.begin(115200);
}

void loop() {

  // STEP 1: Select simulation mode

  if (manualMode) {
    int sensorValue = analogRead(34);

    // Convert potentiometer reading to simulated CO2
    co2 = map(sensorValue, 0, 4095, 400, 2000);

    Serial.println("MODE: MANUAL");
  }
  else {
    Serial.println("MODE: AUTOMATIC");
  }

  // STEP 2: Display simulated CO2

  Serial.print("Simulated CO2: ");
  Serial.print(co2);
  Serial.println(" ppm");

  // STEP 3: Check CO2 level

  if (co2 < 1000) {

    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(2, LOW);

    noTone(18);

    Serial.println("STATUS: NORMAL");
    Serial.println("ACTION: Continue monitoring.");
  }

  else if (co2 < 1500) {

    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(2, LOW);

    noTone(18);

    Serial.println("STATUS: VENTILATION ADVISED");
    Serial.println("SUGGESTIONS:");
    Serial.println("1. Open a window or door.");
    Serial.println("2. Allow fresh air into the room.");
  }

  else {

    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(2, HIGH);

    tone(18, 1000);

    Serial.println("STATUS: HIGH CO2");
    Serial.println("SUGGESTIONS:");
    Serial.println("1. Open windows and doors.");
    Serial.println("2. Turn on an exhaust fan.");
    Serial.println("3. Reduce crowding.");
    Serial.println("4. Take a break in fresh air.");
  }

  Serial.println("------------------------");

  // STEP 4: Buzzer beep timing

  delay(500);
  noTone(18);
  delay(500);

  // STEP 5: Automatic CO2 simulation

  if (!manualMode) {

    co2 = co2 + direction;

    if (co2 >= 2000) {
      direction = -100;
    }

    if (co2 <= 700) {
      direction = 100;
    }
  }
}
