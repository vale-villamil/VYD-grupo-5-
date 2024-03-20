#include <Arduino.h>
void setup() {

  Serial.begin(9600);
}
void loop() {
  int valor = analogRead(A0);
  float voltaje = valor * (5.0 / 1023.0);

  Serial.print(" Valor ADC: ");
  Serial.print(valor);
  Serial.print(", Voltaje: ");
  Serial.print(voltaje);
  Serial.print( " V");
  Serial.println();

  delay(500);
}
