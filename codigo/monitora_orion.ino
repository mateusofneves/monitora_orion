#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

// OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &Wire,
  -1
);

// DHT22
#define DHTPIN 15
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

// Sensores
#define LDR_PIN 34
#define CORRENTE_PIN 35

void setup() {

  Serial.begin(115200);

  dht.begin();

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("Erro OLED");
    while(true);
  }

  display.clearDisplay();
  display.setTextColor(WHITE);

}

void loop() {

  // Temperatura
  float temperatura = dht.readTemperature();

  // Luminosidade
  int luminosidade = analogRead(LDR_PIN);

  // Corrente simulada
  int leituraPot = analogRead(CORRENTE_PIN);

  float corrente = map(leituraPot, 0, 4095, 0, 100) / 10.0;

  // Verificação de alertas
  bool alerta = false;

  if (temperatura < 18 || temperatura > 30)
    alerta = true;

  if (luminosidade < 1000 || luminosidade > 3500)
    alerta = true;

  if (corrente > 8.0)
    alerta = true;

  // OLED
  display.clearDisplay();

  display.setTextSize(1);

  display.setCursor(0,0);
  display.println("CAPSULA ORION");

  display.setCursor(0,15);
  display.print("Temp: ");
  display.print(temperatura,1);
  display.println(" C");

  display.setCursor(0,28);
  display.print("Luz: ");
  display.println(luminosidade);

  display.setCursor(0,41);
  display.print("Corr: ");
  display.print(corrente,1);
  display.println(" A");

  display.setCursor(0,54);

  if(alerta)
    display.println("STATUS: ALERTA");
  else
    display.println("STATUS: OK");

  display.display();

  // Serial Monitor
  Serial.println("===== CAPSULA ORION =====");
  Serial.print("Temperatura: ");
  Serial.println(temperatura);

  Serial.print("Luminosidade: ");
  Serial.println(luminosidade);

  Serial.print("Corrente: ");
  Serial.println(corrente);

  if(alerta)
    Serial.println("STATUS: ALERTA");
  else
    Serial.println("STATUS: OK");

  Serial.println("------------------------");

  delay(2000);
}
