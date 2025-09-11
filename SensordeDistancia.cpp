const int trigger = 10;
const int echo = 11;
const int led = 9;
const int potenci = A0;

int medir() {
  float dist;
  digitalWrite(trigger, LOW);
  delayMicroseconds(5);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  dist = pulseIn(echo, HIGH);
  dist = dist / 58.0; // cm
  Serial.print("Distancia = ");
  Serial.print(dist);
  Serial.println(" cm");
  return dist;
}

int potenciometro() {
  int valor = analogRead(potenci);
  int mapped = map(valor, 0, 1023, 0, 255);
  Serial.println(mapped);
  return mapped;
}

void ligarLed(float dist, float maxDist) {
  dist = constrain(dist, 1, maxDist);

  // Ajusta a curva para ter mais contraste perceptível
  int brilho = map(dist, maxDist, 1, 0, 255);  
  brilho = constrain(brilho, 0, 255);

  // Aumenta a sensibilidade perceptiva
  brilho = pow(brilho / 255.0, 5) * 255; // curva exponencial (melhor percepção visual)

  analogWrite(led, brilho);
}

void setup() {
  Serial.begin(9600);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led, OUTPUT);
  pinMode(potenci, INPUT);
}

void loop() {
  float dist = medir();
  float valor = potenciometro();
  float distTotal = 50 + valor / 6.125; // de 10cm até ~50cm

  if (dist < distTotal) {
    ligarLed(dist, distTotal);
  } else {
    analogWrite(led, 0);
  }

  delay(200);
}