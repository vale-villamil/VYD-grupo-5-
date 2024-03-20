#include <SoftwareSerial.h>

// Definición de variables
int Cupos = 10;
int Valor_cupo = 5000;
int Total_recaudado = 0;

// Definición de pines
#define PIN_BOTON_INGRESO 2
#define PIN_BOTON_EGRESO 3
#define PIN_LED_VERDE 4
#define PIN_LED_ROJO 5

// Definición del puerto serie simulado
SoftwareSerial Serial1(PIN_BOTON_INGRESO, PIN_BOTON_EGRESO);

void setup() {
  // Inicializar las variables
  Cupos = 10;
  Valor_cupo = 5000;
  Total_recaudado = 0;

  // Configurar los pines
  pinMode(PIN_BOTON_INGRESO, INPUT);
  pinMode(PIN_BOTON_EGRESO, INPUT);
  pinMode(PIN_LED_VERDE, OUTPUT);
  pinMode(PIN_LED_ROJO, OUTPUT);

  // Inicializar el puerto serie simulado
  Serial1.begin(9600);

  // Activar las interrupciones
  attachInterrupt(digitalPinToInterrupt(PIN_BOTON_INGRESO), ISR_ingreso, FALLING);
  attachInterrupt(digitalPinToInterrupt(PIN_BOTON_EGRESO), ISR_egreso, FALLING);
}

void loop() {
  // Mostrar el estado del parqueadero
  if (Cupos > 0) {
    digitalWrite(PIN_LED_VERDE, HIGH);
    digitalWrite(PIN_LED_ROJO, LOW);
  } else {
    digitalWrite(PIN_LED_VERDE, LOW);
    digitalWrite(PIN_LED_ROJO, HIGH);
  }
}

void ISR_ingreso() {
  // Decrementar la variable Cupos
  Cupos--;

  // Mostrar un mensaje en el puerto serie
  Serial1.println("Vehículo ingresado correctamente");

  // Si el parqueadero está lleno, mostrar un mensaje
  if (Cupos == 0) {
    Serial1.println("Parqueadero lleno");
  }
}

void ISR_egreso() {
  // Incrementar la variable Cupos
  Cupos++;

  // Mostrar un mensaje en el puerto serie
  Serial1.println("Vehículo egresado correctamente");

  // Calcular el valor a pagar
  int valor_a_pagar = Valor_cupo;

  // Sumar el valor a pagar al total recaudado
  Total_recaudado += valor_a_pagar;

  // Mostrar el valor total recaudado en el puerto serie
  Serial1.print("Total recaudado: ");
  Serial1.println(Total_recaudado);
}
