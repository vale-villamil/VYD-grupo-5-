bool A,B,C,D,W,X,Y,Z;
void setup () {
pinMode (D1,INPUT);// ENTRADA LED INTERNO //
pinMode (D2,INPUT);// ENTRADA LED AZUL //
pinMode (D3,INPUT);// ENTRADA LED ROJO //
pinMode (D5,INPUT);// ENTRADA DEL BUZZER//
pinMode (D4,OUTPUT);// SALIDA //
pinMode (D6,OUTPUT);// SALIDA //
pinMode (D7,OUTPUT);// SALIDA //
pinMode (D8,OUTPUT);// SALIDA //

} 
void loop() {
  A=digitalRead (D1);
  B=digitalRead (D2);
  C=digitalRead (D3);
  D=digitalRead (D5);

 W=!A&&!C&&D||B&&D||B&&C||A&&C;
 digitalWrite(D4,!W);

 X=!A&&!C&&D||A&&B&&C||C&&!D||A&&!D;
 digitalWrite(D6,X);

 Y=A&&!C&&!D||!A&&B&&D||B&&C&&D||!A&&C&&D||!B&&C&&!D;
 digitalWrite(D7,Y);

 Z=C&&D||!A&&B&&C||A&&B&&!C||A&&!B&&!D;
 digitalWrite(D8,Y);
}
