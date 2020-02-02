#include <NewPing.h>

#define distanciaMaxima 100
#define ENA 11
#define IN1 10
#define IN2 9
#define IN3 8
#define IN4 7
#define ENB 6
#define TriggerF 3
#define EchoF 2
#define TriggerI 5
#define EchoI 4
#define TriggerD 12
#define EchoD 13


//----------------------------Variabales para el control
float P = 1.2 ;
float D = 0.5 ;
float I = 0.6 ;
float antiguoErrorP ;
float totalError ;
int offset = 2  ;

//----------------------------------------------------

int toleranciaPared= 10;
//int toleranciaIzquierda = 10 ;
//int toleranciaDerecha = 10 ;
int toleranciaFrente = 10 ;

boolean paredFrente ;
boolean paredIzquierda ;
boolean paredDerecha ;
boolean primerGiro ;
boolean seguirParedDerecha ;
boolean seguirParedIzquierda ;

int velocidadBase= 80;
int velocidadDerecha;
int velocidadIzquierda;

NewPing sonarIzquierdo(TriggerI, EchoI, distanciaMaxima);
NewPing sonarDerecho(TriggerD, EchoD, distanciaMaxima);
NewPing sonarFrente(TriggerF, EchoF, distanciaMaxima);

unsigned int pingSpeed = 30; //Numero de medidas por segundo
unsigned long pingTimer;     

float antiguoSensorI,antiguoSensorD,antiguoSensorF,sensorI,sensorD,sensorF,sensorDerecho,sensorIzquierdo,sensorFrente;

void setup() {
  pinMode(ENA,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENB,OUTPUT);
  primerGiro = false ;
  seguirParedDerecha = false ;
  seguirParedIzquierda = false ;
  Serial.begin(115200);
}

void loop() {
  leerSensores();
  paredes();
  if ( primerGiro == false ) {  //si, el primer giro es falso entonces...   if(si)

    empezarPID(); //Empieza el control

  }
  else if (seguirParedIzquierda == true ) { //else (falso)  entonces si (seguir pared izquierda) es verdadero...
    PID(true) ;  //Activa el control PID
  }
  else if (seguirParedDerecha == true ) {
    PID(false) ;  //Desactiva el control PID
  }


  if (paredIzquierda  == true && paredDerecha  == false && paredFrente == true ) {
    PID(false) ;
    if ( primerGiro == false ) {
      primerGiro = true ;
      seguirParedDerecha = true ;
    }
  }
   if (paredIzquierda == false && paredDerecha == true && paredFrente == true ) {
    PID(true) ;
    if ( primerGiro == false ) {
      primerGiro = true ;
      seguirParedIzquierda = true ; 
    }
  }
  if (paredIzquierda == true && paredDerecha == true && paredFrente == true ) {
    girar(150);
  }
   if ( sensorIzquierdo <0 || sensorIzquierdo > 100 && sensorDerecho <0 || sensorDerecho > 100 && sensorFrente <0|| sensorFrente > 100 ) {
    pararRobot(); //Si medimos 0 o mayor a 100 cm en algun sensor paramos el robot
  }


}
