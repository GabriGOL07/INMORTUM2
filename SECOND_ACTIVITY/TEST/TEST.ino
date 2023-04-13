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

const int sirena = A5;
const int led1 = A0;
const int led2 = A1;
const int led3 = A2;
const int led4 = A3;
const int led5 = A4;
void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(sirena, OUTPUT);
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

void leds(){
  for (int i=0; i<5 ;i++){
    digitalWrite(led1, HIGH);
    delay(100);
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    delay(100);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    delay(100);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
    delay(100);
    digitalWrite(led4, LOW);
    digitalWrite(led5, HIGH);
    delay(100);
    digitalWrite(led5, LOW);
  }
}

void principi(){
  digitalWrite(sirena, LOW);
}

void loop() {
  principi();
  digitalWrite(sirena, HIGH);
  delay(5000);
  digitalWrite(sirena, LOW);
  Serial.print("ep");
  delay(5000);
  
 
}
