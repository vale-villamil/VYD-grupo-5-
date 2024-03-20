const int botonIngreso = D7;
const int botonEgreso = D1;
const int ledRojo = D5;
const int ledAzul = D6;
   int ingreso = 0;
   int salida = 0;
   int costo = 5000;

long int valor_recaudado = 0;
bool subida1, subida2;
   int cupos_disponibles = 8;
void setup() {
   pinMode(botonIngreso, INPUT);
   pinMode(botonEgreso, INPUT);
   pinMode(ledRojo, OUTPUT);
   pinMode(ledAzul, OUTPUT);
    Serial.begin(9800);
    Serial.println("CUPO MÁXIMO: 7");
}
void loop() {
ingreso = digitalRead(botonIngreso);
salida = digitalRead(botonEgreso);
if (ingreso == 1 && cupos_disponibles > 0 && subida1 == 0) {
cupos_disponibles = cupos_disponibles - 1;
    Serial.print("Cupos: ");
    Serial.print(cupos_disponibles);
    Serial.print("\tRecaudo = $");
    Serial.print(valor_recaudado);
    Serial.println(" COP");
delay(200);
}
subida1 = digitalRead(botonIngreso);
if (salida == HIGH && cupos_disponibles < 7 && subida2 == 0) {
cupos_disponibles = cupos_disponibles + 1;
valor_recaudado = valor_recaudado + 5000;
    Serial.print("Cupos: ");
    Serial.print(cupos_disponibles);
    Serial.print("\tRecaudo = $");
    Serial.print(valor_recaudado);
    Serial.println(" COP");
delay(200);
}
subida2 = digitalRead(botonEgreso);
if (cupos_disponibles > 0 && cupos_disponibles <= 7) {
      digitalWrite(ledRojo, LOW);
      digitalWrite(ledAzul, HIGH);
}
if (cupos_disponibles == 0) {
      digitalWrite(ledRojo, HIGH); // Cambiado de LOW a HIGH para encender el led rojo cuando no hay cupos disponibles
      digitalWrite(ledAzul, LOW); // Cambiado de HIGH a LOW para apagar el led azul cuando no hay cupos disponibles
}
delay(200);
}
