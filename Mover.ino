//Control de direccion
void mover(int velocidadI, int velocidadD){
    Serial.print("Izquierda:");
    Serial.println(velocidadI);
    Serial.print("Derecha:");
    Serial.println(velocidadD);
    if (velocidadI < 0) {
      velocidadI = map(velocidadI , 0 , -255, 0, 255);
      analogWrite(ENA,velocidadI);
      digitalWrite(IN3,LOW);
      digitalWrite(IN4,HIGH);
    }
    else{
      analogWrite(ENA,velocidadI);
      digitalWrite(IN3,HIGH);
      digitalWrite(IN4,LOW);
    }
    if (velocidadD < 0) {
      velocidadD = map(velocidadD , 0 , -255, 0, 255);
      analogWrite(ENB,velocidadD);
      digitalWrite(IN1,HIGH);
      digitalWrite(IN2,LOW);
    }
    else{
      analogWrite(ENB,velocidadD);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2,HIGH);
    }
}

void girar(int tiempo){
      analogWrite(ENB,velocidadBase);
      analogWrite(ENA,velocidadBase);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2,HIGH);
      digitalWrite(IN3,LOW);
      digitalWrite(IN4,HIGH);
      delay(tiempo);
}

void pararRobot(){
  analogWrite(ENA,0);
  analogWrite(ENB,0);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  Serial.println("stop");
}
