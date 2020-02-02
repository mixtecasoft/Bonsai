//--------------------------- Deteccion de paredes--------------------------------//

void paredes() {
  if ( sensorIzquierdo < toleranciaPared ) {
    paredIzquierda = true ;
  }
  else {
    paredIzquierda = false ;
  }

  if ( sensorDerecho < toleranciaPared ) {
    paredDerecha = true ;
  }
  else {
    paredDerecha = false ;

  }
  if ( sensorFrente < toleranciaFrente) {
    paredFrente = true ;
  }
  else {
    paredFrente = false ;
  }
}
