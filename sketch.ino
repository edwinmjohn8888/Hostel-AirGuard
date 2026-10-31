
int co2 = 700;
int direction = 100;

void setup() {
  pinMode(4, OUTPUT);  // Green LED
  pinMode(5, OUTPUT);  // Yellow LED
  pinMode(2, OUTPUT);  // Red LED
  pinMode(18, OUTPUT); // Buzzer

  Serial.begin(115200);
}

void loop() {
  Serial.print("Simulated CO2: ");
  Serial.print(co2);
  Serial.println(" ppm");

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
    Serial.println("ACTION: Open a window or door.");
  }
  else {
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(2, HIGH);

    tone(18, 1000);

    Serial.println("STATUS: HIGH CO2");
    Serial.println("ACTION: Open windows and doors.");
    Serial.println("ACTION: Turn on an exhaust fan.");
    Serial.println("ACTION: Reduce crowding.");
  }

  Serial.println("------------------------");

  delay(500);
  noTone(18);
  delay(500);

  co2 = co2 + direction;

  if (co2 >= 2000) {
    direction = -100;
  }

  if (co2 <= 700) {
    direction = 100;
  }
}
