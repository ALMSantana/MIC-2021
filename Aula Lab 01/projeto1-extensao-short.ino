void setup() {

  attachInterrupt(digitalPinToInterrupt(interruptPin), funcao, CHANGE);
}

void funcao() {
   //aqui algo vai acontecer quando o pino interropido perceber um evento
}
