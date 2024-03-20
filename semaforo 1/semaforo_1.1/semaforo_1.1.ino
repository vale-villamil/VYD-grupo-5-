const int pinRojo = D7;   
const int pinAzul = D8; 
const int pinVerde = D6;
void setup() {

  pinMode(pinRojo, OUTPUT);
  pinMode(pinVerde, OUTPUT);
  pinMode(pinAzul, OUTPUT);
  pinMode(D3, INPUT);
  pinMode(D2, INPUT);
}

void loop() {
  if (digitalRead(D3)== LOW) {
    while(true){
    digitalWrite(pinRojo, LOW);
    digitalWrite(pinVerde, LOW);
    digitalWrite(pinAzul, LOW);
    delay(5000);
    }
  }
  if (digitalRead(D2)==LOW){
    for(int x = 0; x < 100; x++){
    digitalWrite(pinRojo, LOW);
    digitalWrite(pinVerde, LOW);
    digitalWrite(pinAzul, LOW);
    delay(500);
    digitalWrite(pinRojo, HIGH);
    digitalWrite(pinVerde, HIGH);
    digitalWrite(pinAzul, LOW);
    delay(500);
    }
  }  
    digitalWrite(pinRojo, HIGH);
    digitalWrite(pinVerde, LOW);
    digitalWrite(pinAzul, LOW);
    delay(5000);
    digitalWrite(pinRojo, HIGH);
    digitalWrite(pinVerde, LOW);
    digitalWrite(pinAzul, LOW);
    digitalWrite(pinRojo, HIGH);
    analogWrite(pinVerde, 128);
    digitalWrite(pinAzul, LOW);
    delay(1000);
    digitalWrite(pinRojo, LOW);
    digitalWrite(pinVerde, HIGH);
    digitalWrite(pinAzul, LOW);
    delay(3000);
    digitalWrite(pinRojo, HIGH);
    digitalWrite(pinVerde, HIGH);
    digitalWrite(pinAzul, LOW);
    delay(1000);
}
