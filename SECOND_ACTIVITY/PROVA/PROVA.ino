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
const int ajuda = 1;
const int led1 = A0;
const int led2 = A1;
const int led3 = A2;
const int led4 = A3;
const int led5 = A4;
const int sirena = A5;

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

int state = 0;

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
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(sirena,OUTPUT);
  
}

void comprovar_estat(){
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
  delay(1000);
}

void leds(){
  for (int i=0; i<20 ;i++){
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
void loop() {
  
  switch (state){
    case 0: // no esta correcte la combinació
      digitalWrite(sirena, LOW);
      //Serial.println("Estat 0");
      digitalWrite(led1, LOW);
      comprovar_estat();
      if  (estado1a == LOW && estado1b == HIGH && estado2a == LOW && estado2b == HIGH && estado3a == LOW && estado3b == HIGH && estado4a == LOW && estado4b == HIGH && estado5a == LOW && estado5b == HIGH && estado6a == LOW && estado6b == HIGH || ajuda == LOW){
        state = 1;
      }else{
        state = 0;
      }
      break;     
    case 1: // acertada combinació
      //Serial.println("Estat 1");
      digitalWrite(sirena, HIGH);
      leds();      
      digitalWrite(sirena, LOW);
      state = 2;
      break;
    case 2: // ha acabat la sirena i els leds pero segueixen els pusladors al seu lloc, falta reiniciar
      //Serial.println("Estat 2");
      digitalWrite(sirena, LOW);
      comprovar_estat();
      if (estado1a == HIGH && estado1b == HIGH && estado2a == HIGH && estado2b == HIGH && estado3a == HIGH && estado3b == HIGH && estado4a == HIGH && estado4b == HIGH && estado5a == HIGH && estado5b == HIGH && estado6a == HIGH && estado6b == HIGH){
        state = 0;
      }else{
        state = 2;
      }
      break;
  }
}
