 #include <Arduino.h>

   const int pinRojo = D1; 
   const int pinAmarillo = D2; 
   const int pinVerde = D3; 
   const int pinBotonParo = D5; 
   const int pinBotonMantenimiento = D6; 

   const unsigned long duracionRojo = 5000;
   const unsigned long duracionRojoAmarillo = 1000;
   const unsigned long duracionVerde = 3000;
   const unsigned long duracionAmarillo = 1000;
   const unsigned long duracionParpadeoAmarillo = 500;
 
   enum EstadoSemaforo {
     ROJO,
     ROJO_AMARILLO,
     VERDE,
     AMARILLO,
     PARPADEO_AMARILLO
};
   EstadoSemaforo estadoActual = ROJO;

   unsigned long tiempoInicio;
   bool botonParoPresionado = false;
   void setup() {
     pinMode(pinRojo, OUTPUT);
     pinMode(pinAmarillo, OUTPUT);
     pinMode(pinVerde, OUTPUT);
     pinMode(pinBotonParo, INPUT_PULLUP);
     pinMode(pinBotonMantenimiento, INPUT_PULLUP);
     digitalWrite(pinRojo, LOW); 
     digitalWrite(pinAmarillo,LOW);
     digitalWrite(pinVerde, LOW);
   tiempoInicio = millis();
 }
   void loop() {

     if (digitalRead(pinBotonParo) == LOW) {botonParoPresionado = true;
}

     if (digitalRead(pinBotonParo) == LOW) {
      botonParoPresionado = true;
     }
      
   }
      switch (estadoActual) {
       case ROJO:
         digitalWrite(pinRojo, HIGH);
         digitalWrite(pinAmarillo, LOW);
         digitalWrite(pinVerde, LOW);
         if (millis() - tiempoInicio >= duracionRojo) {
           estadoActual = ROJO_AMARILLO;
           tiempoInicio = millis();
         }
         break;
       case ROJO_AMARILLO:
         digitalWrite(pinRojo, LOW);
         digitalWrite(pinAmarillo, LOW);
         digitalWrite(pinVerde, HIGH);
         if (millis() - tiempoInicio >= duracionRojoAmarillo) {
           estadoActual = VERDE;
           tiempoInicio = millis();
         }
         break;
       case VERDE:
          digitalWrite(pinRojo, LOW);
          digitalWrite(pinAmarillo, LOW);
          digitalWrite(pinVerde, HIGH);
          if (millis() - tiempoInicio >= duracionVerde) {
          estadoActual = AMARILLO;
          tiempoInicio = millis();
         }
         break;
      case AMARILLO:
        digitalWrite(pinRojo, LOW);
        digitalWrite(pinAmarillo, HIGH);
        digitalWrite(pinVerde, LOW);
       if (millis() - tiempoInicio >= duracionAmarillo) {
       estadoActual = botonantenimientoPresionado ? PARPADEO_AMARILLO : ROJO;
       tiempoInicio = millis();
        }
        break;
     case PARPADEO_AMARILLO:
     if (millis() - tiempoInicio >= duracionParpadeoAmarillo) {
      digitalWrite(pinAmarillo, !digitalRead(pin amarillo));
      tiempoInicio = millis();
       }
       break;
  }
}
