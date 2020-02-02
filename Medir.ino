void leerSensores() {
  sensorI = sonarIzquierdo.ping_cm(); // estamos usando la libreria para leer sensores ultrasonicos
  sensorD = sonarDerecho.ping_cm();
  sensorF = sonarFrente.ping_cm();

  sensorIzquierdo = (sensorI + antiguoSensorI) / 2; //Promedio entre el antiguo valor y el actual del sensor
  sensorDerecho = (sensorD + antiguoSensorD) / 2;
  sensorFrente = (sensorF + antiguoSensorF) / 2;


  antiguoSensorI = sensorIzquierdo; // guardamos el promedio de las medidas
  antiguoSensorD = sensorDerecho;
  antiguoSensorF = sensorFrente;

}
