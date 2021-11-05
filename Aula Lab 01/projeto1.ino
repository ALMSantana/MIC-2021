
float distanciaCm = 0;
int GPIO_TRIGGER = 10;
int GPIO_ECHO = 11;
int GPIO_LED = 3;
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


void notificarDistancia(int ledPin, float distancia){
  if(distancia <= LIMITE_DISTANCIA && distancia != 0){
  	alterarLED(GPIO_LED, HIGH);
  }
}

void setup(){
  Serial.begin(9600);
  pinMode(GPIO_LED, OUTPUT);
  digitalWrite(GPIO_LED, LOW);
}

void loop(){ 
  distanciaCm = 0.01723 * lerSensorUltrassonico(GPIO_TRIGGER, GPIO_ECHO);
  notificarDistancia(GPIO_LED, distanciaCm);
  
  Serial.print(distanciaCm);
  Serial.println("cm");
  delay(1000); // Wait for 100 millisecond(s)
}

void alterarLED(int ledPin, int estadoLed){
	digitalWrite(ledPin, estadoLed);
}
