void setup() {
 pinMode(D8,OUTPUT);
 pinMode(D3,INPUT);
}

void loop() {
  digitalWrite(D8,LOW);
  while(digitalRead(D3)==HIGH){
    delay(200);
  }
  digitalWrite(D8,HIGH) ;
  while(digitalRead(D3)==LOW) {
    delay(200);
  }
}
