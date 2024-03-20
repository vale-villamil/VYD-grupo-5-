const int pinRojo = D7;   
const int pinAzul = D8; 
const int pinVerde = D6;
void setup() {
  Serial.begin(9600);
  pinMode(pinRojo, OUTPUT);
  pinMode(pinVerde, OUTPUT);
  pinMode(pinAzul, OUTPUT);
}

void loop() {
  int valorP = analogRead(A0);
  Serial.print("Valor del potenciómetro: ");
  Serial.println(valorP);
  digitalWrite(pinRojo, HIGH);
  digitalWrite(pinVerde, LOW);
  digitalWrite(pinAzul, LOW);
  delay(valorP * 5);
  digitalWrite(pinRojo, HIGH);
  digitalWrite(pinVerde, LOW);
  digitalWrite(pinAzul, LOW);
  analogWrite(pinRojo, 200);
  analogWrite(pinVerde, 50);
  analogWrite(pinAzul, 0);
  delay(valorP * 2);
  digitalWrite(pinRojo, LOW);
  digitalWrite(pinVerde, HIGH);
  digitalWrite(pinAzul, LOW);
  delay(valorP * 3);
  digitalWrite(pinRojo, HIGH);
  digitalWrite(pinVerde, HIGH);
  digitalWrite(pinAzul, LOW);
  delay(valorP * 2);
  }
