#define vm1 2
#define amrl1 3
#define vd1 4
#define vm2 5
#define amrl2 6
#define vd2 7
unsigned long millisTarefa1 = millis();
unsigned long millisTarefa2 = millis();
String qual = "";
int verde1 = 2;
int amarelo1 = 1;
int vermelho1 = 3;
int verde2 = 2;
int amarelo2 = 1;
int vermelho2 = 3;
void setup() {
  Serial.begin(9600);
  //millisegundos para segundos
  verde1 = verde1 *= 1000;
  amarelo1 = verde1 + (amarelo1 *= 1000);
  vermelho1 = amarelo1 + (vermelho1 *= 1000);
  vermelho2 = vermelho2 *= 1000;
  verde2 = vermelho2 + (verde2 *= 1000);
  amarelo2 = verde2 + (amarelo2 *= 1000);
}
void loop() {

  pinMode(vm1, OUTPUT);
  pinMode(vd1, OUTPUT);
  pinMode(amrl1, OUTPUT);
  pinMode(vd2, OUTPUT);
  pinMode(amrl2, OUTPUT);
  pinMode(vm2, OUTPUT);

  if ((millis() - millisTarefa1) < verde1) {
    digitalWrite(vm1, LOW);
    digitalWrite(vd1, HIGH);
  } else if ((millis() - millisTarefa1) < amarelo1 && (millis() - millisTarefa1) > verde1) {
    digitalWrite(amrl1, HIGH);
    digitalWrite(vd1, LOW);
  } else if ((millis() - millisTarefa1) < vermelho1 && (millis() - millisTarefa1) > amarelo1) {
    digitalWrite(amrl1, LOW);
    digitalWrite(vm1, HIGH);
  }

  if ((millis() - millisTarefa2) < vermelho2) {
    digitalWrite(vm2, HIGH);
    digitalWrite(amrl2, LOW);
  } else if ((millis() - millisTarefa2) < verde2 && (millis() - millisTarefa1) > vermelho2) {
    digitalWrite(vm2, LOW);
    digitalWrite(vd2, HIGH);
  } else if ((millis() - millisTarefa2) < amarelo2 && (millis() - millisTarefa1) > verde2) {
    digitalWrite(amrl2, HIGH);
    digitalWrite(vd2, LOW);
  } else if ((millis() - millisTarefa1) > amarelo2 && (millis() - millisTarefa1) > vermelho1) {
    millisTarefa1 = millis();
    millisTarefa2 = millis();
  }
  delay(10);

  /*if (Serial.available())
{
    if (qual == "")
    {
Serial.println("Que led sera trocado?\n1-)verde 2-)vermelho 3-)amarelo");
qual = Serial.readString();
Serial.println(qual);
    }
    else
    {
if (qual == "verde")
{
Serial.println("quantos segundos o sinal verde estará aberto?");
  if (Serial.available()){
  verde = (Serial.read() * 1000);
  }
}
else if (qual == "amarelo")
{
  if (Serial.available()){
  amarelo1 = (Serial.read() * 1000);
  }
Serial.println("quantos segundos o sinal amarelo estará aberto?");
}
else if (qual == "vermelho")
{
  if (Serial.available()){
  vermelho = (Serial.read() * 1000);
  }
Serial.println("quantos segundos o sinal vermelho estará aberto?");
  qual = "";
}
}*/
}
/*void loop() 
{
if((millis() - millisTarefa1) < 1000 && (millis() - millisTarefa1) > 0)
  {
    // Acende o led do pino 7
    digitalWrite(vm1, HIGH);
  	digitalWrite(vd2, HIGH);
  } 
  else if((millis() - millisTarefa1) < 2000 && (millis() - millisTarefa1) > 1000)
  {
    // Acende o led do pino 7
    digitalWrite(vd2, LOW);
  	digitalWrite(amrl2, HIGH);
  } 
  else if((millis() - millisTarefa1) < 3000 && (millis() - millisTarefa1) > 2000)
  {
    // Acende o led do pino 7
    digitalWrite(amrl2, LOW);
    digitalWrite(vm1, LOW);
    digitalWrite(vd1, HIGH);
    digitalWrite(vm2, HIGH);
  }
  else if((millis() - millisTarefa1) < 4000 && (millis() - millisTarefa1) > 3000)
  {
    // Acende o led do pino 7
    digitalWrite(vm1, HIGH);
  	digitalWrite(vd2, HIGH);
  } 
  else if((millis() - millisTarefa1) < 5000 && (millis() - millisTarefa1) > 4000)
  {
    // Acende o led do pino 7
    digitalWrite(vd1, LOW);
  digitalWrite(amrl1, HIGH);  
  }
  else if((millis() - millisTarefa1) > 5000)
  {
    millisTarefa1 = millis();
  }  
  desligatudo();
  pinMode(vm1, OUTPUT);
  pinMode(vd1, OUTPUT);
  pinMode(amrl1, OUTPUT);
  pinMode(vd2, OUTPUT);
  pinMode(amrl2, OUTPUT);
  pinMode(vm2, OUTPUT);
  if((millis() - millisTarefa1) < 3000)
  {
    // Acende o led do pino 7
  	digitalWrite(vm1, HIGH);
  	digitalWrite(vd2, HIGH);
  }else
  {
    // Apaga o led do pino 7
    digitalWrite(7,0);
  }
  if((millis() - millisTarefa1) < 5000)
  {
    // Acende o led do pino 7
  	digitalWrite(vd2, LOW);
  	digitalWrite(amrl2, HIGH);
  }else
  {
    // Apaga o led do pino 7
    digitalWrite(7,0);
  }
  if((millis() - millisTarefa1) < 8000)
  {
    // Acende o led do pino 7
  	digitalWrite(amrl2, LOW);
    digitalWrite(vm1, LOW);
    digitalWrite(vd1, HIGH);
    digitalWrite(vm2, HIGH);
  }else
  {
    // Apaga o led do pino 7
    digitalWrite(7,0);
  }
  if((millis() - millisTarefa1) < 11000)
  {
    // Acende o led do pino 7
  	digitalWrite(vd1, LOW);
  digitalWrite(amrl1, HIGH);
  }else
  {
    // Apaga o led do pino 7
    digitalWrite(7,0);
  }  
  digitalWrite(amrl1, LOW);
}
*/
void desligatudo() {
  digitalWrite(4, LOW);
  digitalWrite(2, LOW);
  digitalWrite(15, LOW);
  digitalWrite(16, LOW);
  digitalWrite(5, LOW);
  digitalWrite(17, LOW);
}
// // if (Serial.available())
// // {
// // Serial.println("Que led será trocado?\n1-)Verde 2-)Vermelho 3-)Amarelo");
// // String qual = Serial.readString();
// // if (qual = "verde")
// // {
// // Serial.println("quantos segundos o sinal verde estará aberto?");
// // int verde = (Serial.read() * 1000);
// // }
// // if (qual = "amarelo")
// // {
// // Serial.println("quantos segundos o sinal amarelo estará aberto?");
// // nt amarelo = (Serial.read() * 1000);
// // }
// // if (qual = "vermelho")
// // {
// // Serial.println("quantos segundos o sinal vermelho estará aberto?");
// // int vermelho = (Serial.read() * 1000);
// // }
