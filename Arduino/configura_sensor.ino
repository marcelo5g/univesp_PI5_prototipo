/******************************************************************************/

/*  Projeto de um sensor on-line para monitoramento de estacionamento usando Arduino */

/*  Configura sensor e LED */

/******************************************************************************/


//Configuração de Distancia Mínima em centimetros
int distancia = 0;


// Configurações do Sensor
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);


  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);


  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  pinMode(10, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop()
{
  distancia = 0.01723 * readUltrasonicDistance(6, 7);
  if (distancia <= 100) {
    digitalWrite(10, HIGH);
    digitalWrite(12, LOW);
  } else {
    digitalWrite(12, HIGH);
    digitalWrite(10, LOW);
  }
  delay(10); // Delay a little bit to improve simulation performance
}