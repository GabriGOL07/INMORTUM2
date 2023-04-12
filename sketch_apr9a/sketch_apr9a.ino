const int interruptor1a = 2;
const int interruptor1b = 3;
const int interruptor2a = 4;
const int interruptor2b = 5;
const int interruptor3a = 6;
const int interruptor3b = 7;
const int interruptor4a = 8;
const int interruptor4b = 9;
const int interruptor5a = 10;
const int interruptor5b = 11;
const int interruptor6a = 12;
const int interruptor6b = 13;
const int ajuda = 0;


int estado1a;
int estado1b;
int estado2a;
int estado2b;
int estado3a;
int estado3b;
int estado4a;
int estado4b;
int estado5a;
int estado5b;
int estado6a;
int estado6b;
int estat_ajuda;

void setup() {
  Serial.begin(9600);
  pinMode(interruptor1a, INPUT_PULLUP);
  pinMode(interruptor1b, INPUT_PULLUP);
  pinMode(interruptor2a, INPUT_PULLUP);
  pinMode(interruptor2b, INPUT_PULLUP);
  pinMode(interruptor3a, INPUT_PULLUP);
  pinMode(interruptor3b, INPUT_PULLUP);
  pinMode(interruptor4a, INPUT_PULLUP);
  pinMode(interruptor4b, INPUT_PULLUP);
  pinMode(interruptor5a, INPUT_PULLUP);
  pinMode(interruptor5b, INPUT_PULLUP);
  pinMode(interruptor6a, INPUT_PULLUP);
  pinMode(interruptor6b, INPUT_PULLUP);
  pinMode(ajuda,INPUT_PULLUP);
}

void loop() {
  estado1a = digitalRead(interruptor1a);
  estado1b = digitalRead(interruptor1b);
  estado2a = digitalRead(interruptor2a);
  estado2b = digitalRead(interruptor2b);
  estado3a = digitalRead(interruptor3a);
  estado3b = digitalRead(interruptor3b);
  estado4a = digitalRead(interruptor4a);
  estado4b = digitalRead(interruptor4b);
  estado5a = digitalRead(interruptor5a);
  estado5b = digitalRead(interruptor5b);
  estado6a = digitalRead(interruptor6a);
  estado6b = digitalRead(interruptor6b);
  estat_ajuda = digitalRead(ajuda);
  Serial.print("Interruptor 1a: ");
  Serial.println(estado1a);
  Serial.print("Interruptor 1b: ");
  Serial.println(estado1b);
  Serial.print("Interruptor 2a: ");
  Serial.println(estado2a);
  Serial.print("Interruptor 2b: ");
  Serial.println(estado2b);
  Serial.print("Interruptor 3a: ");
  Serial.println(estado3a);
  Serial.print("Interruptor 3b: ");
  Serial.println(estado3b);
  Serial.print("Interruptor 4a: ");
  Serial.println(estado4a);
  Serial.print("Interruptor 4b: ");
  Serial.println(estado4b);
  Serial.print("Interruptor 5a: ");
  Serial.println(estado5a);
  Serial.print("Interruptor 5b: ");
  Serial.println(estado5b);
  Serial.print("Interruptor 6a: ");
  Serial.println(estado6a);
  Serial.print("Interruptor 6b: ");
  Serial.println(estado6b);
  Serial.print("Interruptor ajuda: ");
  Serial.println(estat_ajuda);
  delay(3000);
}
