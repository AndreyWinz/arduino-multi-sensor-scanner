#include <DHT.h>
#include <SoftwareSerial.h>

// ---------------- Sensor Pins ----------------
#define CLAP_PIN 2
#define IR_OBS_PIN 3
#define DHT_PIN 4
#define LINE_L 5
#define LINE_M 6
#define LINE_R 7
#define TOUCH_PIN 8
#define HW477_PIN 12

#define DHTTYPE DHT11

// ---------------- Bluetooth (HC-05) ----------------
SoftwareSerial BT(10, 11); // RX, TX

DHT dht(DHT_PIN, DHTTYPE);

// ---------------- Setup ----------------
void setup() {
  Serial.begin(9600);  
  BT.begin(38400);     // HC-05 default AT mode speed

  pinMode(CLAP_PIN, INPUT);
  pinMode(IR_OBS_PIN, INPUT);
  pinMode(LINE_L, INPUT);
  pinMode(LINE_M, INPUT);
  pinMode(LINE_R, INPUT);
  pinMode(TOUCH_PIN, INPUT);

  dht.begin();

  Serial.println("Arduino Multi-Sensor Scanner Started...");
  Serial.println("Relaying via CP2102 @ 9600 baud\n");
}

// =====================================================
// ---------------- SENSOR TEST FUNCTIONS --------------
// =====================================================

void testClap() {
  int val = digitalRead(CLAP_PIN);
  Serial.print("Clap Sensor: ");
  Serial.println(val == HIGH ? "Sound/Clap Detected" : "No Clap");
}

void testObstacle() {
  int val = digitalRead(IR_OBS_PIN);
  Serial.print("IR Obstacle Sensor: ");
  Serial.println(val == LOW ? "Obstacle Detected" : "Clear");
}

void testDHT11() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  Serial.print("DHT11: ");
  if (isnan(h) || isnan(t)) {
    Serial.println("Sensor Not Found / Read Error");
    return;
  }

  Serial.print("Temp: ");
  Serial.print(t);
  Serial.print(" °C  Humidity: ");
  Serial.print(h);
  Serial.println(" %");
}

void testLineTracker() {
  int ls = digitalRead(LINE_L);
  int ms = digitalRead(LINE_M);
  int rs = digitalRead(LINE_R);

  Serial.print("Line Tracker (L M R): ");
  Serial.print(ls);
  Serial.print(" ");
  Serial.print(ms);
  Serial.print(" ");
  Serial.println(rs);
}

void testTouch() {
  int val = digitalRead(TOUCH_PIN);
  Serial.print("Touch Sensor: ");
  Serial.println(val == HIGH ? "Touched" : "Not Touched");
}

void testHW477() {
  int val = digitalRead(HW477_PIN);
  Serial.print("HW-477 (Digital): ");
  Serial.println(val);
}

void testHC05() {
  Serial.print("HC-05: ");

  BT.print("AT\r\n");
  delay(200);

  if (BT.available()) {
    String r = BT.readString();
    Serial.print("Response: ");
    Serial.println(r);
  } else {
    Serial.println("No Response / Not Found");
  }
}

// =====================================================
// ---------------- MAIN LOOP --------------------------
// =====================================================

void loop() {

  Serial.println("=== Checking Sensors ===");

  testClap();
  delay(300);

  testObstacle();
  delay(300);

  testDHT11();
  delay(300);

  testLineTracker();
  delay(300);

  testTouch();
  delay(300);

  testHW477();
  delay(300);

  testHC05();
  delay(500);

  Serial.println("========================\n");
  delay(1500);
}
