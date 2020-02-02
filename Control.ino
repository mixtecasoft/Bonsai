//--------------------------------- control ---------------------------------//

void empezarPID() {

  float errorP = sensorIzquierdo - sensorDerecho ;
  float errorD = errorP - antiguoErrorP;
  float errorI = (2.0 / 3.0) * errorI + errorP ;
  totalError = P * errorP + D * errorD + I * errorI ;
  antiguoErrorP = errorP ;
  velocidadDerecha = velocidadBase + totalError ;
  velocidadIzquierda = velocidadBase - totalError ;
  mover(velocidadDerecha,velocidadIzquierda);

}


//----------------------------- Control para seguir la pared -------------------------------//

void PID( boolean izquierda ) {

  if (izquierda == true ) {

    float errorP = sensorIzquierdo - sensorDerecho - offset ;
    float errorD = errorP - antiguoErrorP;
    float errorI = (2.0 / 3) * errorI + errorP ;
    totalError = P * errorP + D * errorD + I * errorI ;
    antiguoErrorP = errorP ;
    velocidadDerecha = velocidadBase + totalError ;
    velocidadIzquierda = velocidadBase - totalError ;
    mover(velocidadDerecha,velocidadIzquierda);

  }
  else {

    float errorP = sensorIzquierdo - sensorDerecho + offset ;
    float errorD = errorP - antiguoErrorP;
    float errorI = (2.0 / 3) * errorI + errorP ;
    totalError = P * errorP + D * errorD + I * errorI ;
    antiguoErrorP = errorP ;
    velocidadDerecha  = velocidadBase + totalError ;
    velocidadIzquierda  = velocidadBase - totalError ;
    mover(velocidadDerecha,velocidadIzquierda);
  }

}
