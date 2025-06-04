#define vm1 D2
#define amrl1 D3
#define vd1 D4
#define vm2 D5
#define amrl2 D6
#define vd2 D7
int msg = 0;
String clear = "";
int qual = 0;
unsigned long millisTarefa1 = millis();
unsigned long millisTarefa2 = millis();
bool resposta = false;
String tempClear;
int verde1 = 3;
int amarelo1 = 1;
int vermelho1 = 5;
int verde2 = 3;
int amarelo2 = 1;
int vermelho2 = 5;
int temp1 = verde1;
int temp2 = amarelo1;
int temp3 = vermelho1;
int temp4 = verde2;
int temp5 = amarelo2;
int temp6 = vermelho2;
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
    alteracao();
  }
  sistema();

  delay(10);
}


void sistema() {
  if (Serial.available()) 
  {
    if (resposta == false)
    {
      if (clear == "prog") {
      clear = Serial.readString();
  clear.trim();
      qual = clear.toInt();
    }
    else
    {
      clear = Serial.readString();
  clear.trim();
    }
    }    
  if (clear == "mostre") 
  {
    Serial.println(clear);
    Serial.print(qual);
    Serial.println(" qual");
    Serial.print(temp1);
    Serial.println(" temp1");
    Serial.print(temp2);
    Serial.println(" temp2");
    Serial.print(temp3);
    Serial.println(" temp3");
    Serial.print(resposta);
      
  }
  if (clear == "prog" || tempClear == "prog")
  {
    if (temp1 != 0 && temp2 != 0 && temp3 != 0 && temp4 != 0 && temp5 != 0 && temp6 != 0 && clear == "prog" && qual != 0) {
      Serial.println("Valores já confirmados, no final do ciclo serao alterados");
    }     
    
    Serial.print(qual);
    Serial.println(" qual");
    if (qual == 0) {
      Serial.println("Que led sera trocado?\n1-)Verde 2-)Amarelo 3-)Vermelho");
      tempClear = clear;
    } 
    if (qual == 1) {
      if (resposta == false) {
        Serial.println("quantos segundos o sinal verde estará aberto?");
        resposta = true;
      }  else {
        temp1 = Serial.parseInt() * 1000;
        Serial.print(temp1);
        Serial.println(" temp1");
        qual = 0;
        resposta = false;
        tempClear = "";
        clear = "";
      }
    } 
    if (qual == 2) {
      if (resposta == false) {
        Serial.println("quantos segundos o sinal amarelo estará aberto?");
        resposta = true;
      }  else {
        temp2 = Serial.parseInt() * 1000;
        Serial.print(temp2);
        Serial.println(" temp2");
        qual = 0;
        resposta = false;
        tempClear = "";
        clear = "";
      }
    } 
    if (qual == 3) {
      if (resposta == false) {
        Serial.println("quantos segundos o sinal vermelho estará aberto?");
        resposta = true;
      }  else {
        temp3 = Serial.parseInt() * 1000;
        Serial.print(temp3);
        Serial.println(" temp3");
        qual = 0;
        resposta = false;
        tempClear = "";
        clear = "";
      }
    }
  }
  }
  }

void alteracao() {
  if (temp1 != 0 || temp2 != 0 || temp3 != 0 || temp4 != 0 || temp5 != 0 || temp6 != 0) {
    verde1 = temp1;
    amarelo1 = verde1 + temp2;
    vermelho1 = amarelo1 + temp3;
    vermelho2 = temp6;
    verde2 = vermelho2 + temp5;
    amarelo2 = temp4 + amarelo2;
  }
}
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