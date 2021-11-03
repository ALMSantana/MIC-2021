float distanciaCm = 0;
int GPIO_TRIGGER = 10;
int GPIO_ECHO = 11;
int GPIO_LED = 2;
float LIMITE_DISTANCIA = 30.0;

float lerSensorUltrassonico(int triggerPin, int echoPin){
  pinMode(triggerPin, OUTPUT);  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(20);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);

  return pulseIn(echoPin, HIGH);
}

void alterarLED(int ledPin, int estadoLed){
	digitalWrite(ledPin, estadoLed);
}

void notificarDistancia(int ledPin, float distancia){
  if(distancia <= LIMITE_DISTANCIA){
  	alterarLED(ledPin, true);
  }
}

void setup(){
  Serial.begin(9600);

}

void loop(){ 
  distanciaCm = 0.01723 * lerSensorUltrassonico(GPIO_TRIGGER, GPIO_ECHO);
  notificarDistancia(GPIO_LED, distanciaCm);
  
  Serial.print(distanciaCm);
  Serial.println("cm");
  delay(100); // Wait for 100 millisecond(s)
}