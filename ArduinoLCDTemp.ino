#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN1 2  // Connect DHT22 Sensor 1 to pin 2
#define DHTPIN2 3  // Connect DHT22 Sensor 2 to pin 3
#define DHTPIN3 4  // Connect DHT22 Sensor 3 to pin 4
#define DHTPIN4 5  // Connect DHT22 Sensor 4 to pin 5
#define DHTPIN5 6  // Connect DHT22 Sensor 5 to pin 6
#define DHTPIN6 7  // Connect DHT22 Sensor 6 to pin 7
#define DHTPIN7 8  // Connect DHT22 Sensor 7 to pin 8
#define DHTPIN8 9  // Connect DHT22 Sensor 8 to pin 9
#define DHTPIN9 10 // Connect DHT22 Sensor 9 to pin 10
#define DHTPIN10 11 // Connect DHT22 Sensor 10 to pin 11

#define DHTTYPE DHT22  // Specify DHT22 type

DHT dht1(DHTPIN1, DHTTYPE);
DHT dht2(DHTPIN2, DHTTYPE);
DHT dht3(DHTPIN3, DHTTYPE);
DHT dht4(DHTPIN4, DHTTYPE);
DHT dht5(DHTPIN5, DHTTYPE);
DHT dht6(DHTPIN6, DHTTYPE);
DHT dht7(DHTPIN7, DHTTYPE);
DHT dht8(DHTPIN8, DHTTYPE);
DHT dht9(DHTPIN9, DHTTYPE);
DHT dht10(DHTPIN10, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 20, 4); // Set the LCD address to 0x27 for a 20x4 size

void setup() {
  Serial.begin(9600);
  lcd.init();                      // Initialize the LCD
  lcd.backlight();                 // Turn on the backlight
  dht1.begin();
  dht2.begin();
  dht3.begin();
  dht4.begin();
  dht5.begin();
  dht6.begin();
  dht7.begin();
  dht8.begin();
  dht9.begin();
  dht10.begin();
}

void loop() {
  displaySensorData("Sensor 1", dht1);
  delay(5000); // Pause for 5 seconds before moving to the next sensor
  displaySensorData("Sensor 2", dht2);
  delay(5000);
  displaySensorData("Sensor 3", dht3);
  delay(5000);
  displaySensorData("Sensor 4", dht4);
  delay(5000);
  displaySensorData("Sensor 5", dht5);
  delay(5000);
  displaySensorData("Sensor 6", dht6);
  delay(5000);
  displaySensorData("Sensor 7", dht7);
  delay(5000);
  displaySensorData("Sensor 8", dht8);
  delay(5000);
  displaySensorData("Sensor 9", dht9);
  delay(5000);
  displaySensorData("Sensor 10", dht10);
  delay(5000);
}

void displaySensorData(String sensorName, DHT &sensor) {
  float temperature = sensor.readTemperature(true); // Convert to Fahrenheit
  float humidity = sensor.readHumidity();

  // Update the LCD display
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(centerText(sensorName));
  lcd.setCursor(0, 1);
  lcd.print("Temp :     ");
  lcd.print(temperature, 1);
  lcd.print(" F");
  lcd.setCursor(0, 2);
  lcd.print("Hum  :     ");
  lcd.print(humidity, 1);
  lcd.print("%");

  // Send data over serial
  Serial.print(sensorName);
  Serial.print(",Temperature:");
  Serial.print(temperature);
  Serial.print(",Humidity:");
  Serial.println(humidity);

  delay(200); // Delay to stabilize LCD display (adjust as needed)
}

String centerText(String text) {
  int padding = (20 - text.length()) / 2;
  String centeredText = " ";
  for (int i = 0; i < padding; i++) {
    centeredText += " ";
  }
  centeredText += text;
  return centeredText;
}
