#include <DHT11.h>


#define DHTPIN D4
#define DHTTYPE DHT11

const int pinVerde = D8;
const int constant = -1;
int x = 0;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
  pinMode(pinVerde, OUTPUT);
}

void loop() {
  int valorP = analogRead(A0) - 570;
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (Serial.available() > 0) {
    x = Serial.parseInt();
    Serial.readStringUntil('\n');
  }

  Serial.print("referencia: ");
  Serial.println(x);
  Serial.print("Humedad: ");
  Serial.print(humidity);
  Serial.print("%\t");
  Serial.print("Temperatura: ");
  Serial.print(temperature);
  Serial.println("°C");

  int rest = x - int(temperature);
  int mult = rest * constant * 10;
  int mappedValue = map(mult, -100, 30, 0, 255);
  int mappluxes = map(valorP, 10, 1024, 0, 2650);

  Serial.print("multiplicacio: ");
  Serial.println(mult);
  Serial.print("valor led: ");
  Serial.println(mappedValue);
  Serial.print("luxes");
  Serial.println(mappluxes);
  Serial.print("fotocelda: ");
  Serial.println(valorP);
  delay(3000);

  analogWrite(pinVerde, mappedValue);
}
