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
  pinMode(ajuda,INPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(sirena,OUTPUT);
  pinMode(1,OUTPUT);
  
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
  //Serial.print(estat_ajuda);
}

void leds(){
  for (int i=0; i<20;i++){
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
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(sirena,LOW);
  delay(10000);
  while(1){
    
  switch (state){
    
    case 0: // no esta correcte la combinació
      digitalWrite(sirena, LOW);
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led5, LOW);     
      //Serial.println("Estat 0");
      comprovar_estat();
      if (estat_ajuda == LOW){
        state = 1;
      }else if  (estado1a == LOW && estado1b == HIGH && estado2a == HIGH && estado2b == HIGH && estado3a == HIGH && estado3b == HIGH && estado4a == HIGH && estado4b == LOW && estado5a == LOW && estado5b == HIGH && estado6a == LOW && estado6b == HIGH){
        state = 1;
      }else{
        state = 0;
      }
      break;     
    case 1: // acertada combinació
      //Serial.println("Estat 1");
      state = 2;
      digitalWrite(sirena, HIGH);
      leds();      
      digitalWrite(sirena, LOW);
      
      break;
    case 2: // ha acabat la sirena i els leds pero segueixen els pusladors al seu lloc, falta reiniciar
      //Serial.println("Estat 2");
      digitalWrite(sirena, LOW);
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led5, LOW);
      comprovar_estat();
      if (estado1a == LOW && estado1b == HIGH && estado2a == HIGH && estado2b == HIGH && estado3a == HIGH && estado3b == HIGH && estado4a == LOW && estado4b == HIGH && estado5a == LOW && estado5b == HIGH && estado6a == HIGH && estado6b == LOW){
        state = 0;
        digitalWrite(led1,HIGH);
        digitalWrite(led2,HIGH);
        digitalWrite(led3,HIGH);
        digitalWrite(led4,HIGH);
        digitalWrite(led5,HIGH);
        delay(1000);
        digitalWrite(led1,LOW);
        digitalWrite(led2,LOW);
        digitalWrite(led3,LOW);
        digitalWrite(led4,LOW);
        digitalWrite(led5,LOW);
      }else{
        state = 2;
      }
      break;
  }
  }
}
