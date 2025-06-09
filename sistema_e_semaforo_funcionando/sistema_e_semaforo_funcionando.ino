#define vm1 D2
#define amrl1 D3
#define vd1 D4
#define vm2 D5
#define amrl2 D6
#define vd2 D7
String funcionarios[2] = { "yuri", "malu" };
String senhas[2] = { "123", "321" };
int msg = 0;
String clear = "";
int qual = 0;
unsigned long millisTarefa1 = millis();
unsigned long millisTarefa2 = millis();
bool resposta = false;
String tempClear;
int verde1 = 3000;
int amarelo1 = 1000;
int vermelho1 = 5000;
int verde2 = 3000;
int amarelo2 = 1000;
int vermelho2 = 5000;
int temp1 = verde1;
int temp2 = amarelo1;
int temp3 = vermelho1;
int temp4 = verde2;
int temp5 = amarelo2;
int temp6 = vermelho2;
String identidade;
String chave;
bool usuario = false;
bool senha = false;
bool autorizado = false;
String estado1 = "normal";
String estado2 = "normal";
String tempEstado = estado1;
void setup() {
  Serial.begin(9600);
  //millisegundos para segundos
  verde1 = verde1;
  amarelo1 = verde1 + amarelo1;
  vermelho1 = amarelo1 + vermelho1;
  vermelho2 = vermelho2;
  verde2 = vermelho2 + verde2;
  amarelo2 = verde2 + amarelo2;
}
void loop() {

  pinMode(vm1, OUTPUT);
  pinMode(vd1, OUTPUT);
  pinMode(amrl1, OUTPUT);
  pinMode(vd2, OUTPUT);
  pinMode(amrl2, OUTPUT);
  pinMode(vm2, OUTPUT);
  if (estado1 == "normal") {
    if ((millis() - millisTarefa1) < verde1) {
      digitalWrite(vm1, LOW);
      digitalWrite(vd1, HIGH);
    } else if ((millis() - millisTarefa1) < amarelo1 && (millis() - millisTarefa1) > verde1) {
      digitalWrite(amrl1, HIGH);
      digitalWrite(vd1, LOW);
    } else if ((millis() - millisTarefa1) < vermelho1 && (millis() - millisTarefa1) > amarelo1) {
      digitalWrite(amrl1, LOW);
      digitalWrite(vm1, HIGH);
    } else if (millis() - millisTarefa1 > vermelho1) {
      millisTarefa1 = millis();
      alteracao1();
    }
  } else if (estado1 == "oscilando") {
    if ((millis() - millisTarefa1) < temp2) {
      digitalWrite(amrl1, HIGH);
      digitalWrite(vd1, LOW);
      digitalWrite(vm1, LOW);
    } else if (millis() - millisTarefa1 < (temp2 + 1000)) {
      digitalWrite(amrl1, LOW);
    } else
      millisTarefa1 = millis();
    alteracao1();
  }
if (estado2 == "normal") {
  if ((millis() - millisTarefa2) < vermelho2) {
    digitalWrite(vm2, HIGH);
    digitalWrite(amrl2, LOW);
  } else if ((millis() - millisTarefa2) < verde2) {
    digitalWrite(vm2, LOW);
    digitalWrite(vd2, HIGH);
  } else if ((millis() - millisTarefa2) < amarelo2) {
    digitalWrite(amrl2, HIGH);
    digitalWrite(vd2, LOW);
  } else if ((millis() - millisTarefa2) > amarelo2) {
    millisTarefa2 = millis();
    digitalWrite(amrl2, LOW);
    alteracao2();
  }
} else if (estado2 == "oscilando") {
  if ((millis() - millisTarefa2) < temp5) {
    digitalWrite(amrl2, HIGH);
    digitalWrite(vd2, LOW);
    digitalWrite(vm2, LOW);
  } else if (millis() - millisTarefa2 < (temp5 + 1000)) {
    digitalWrite(amrl2, LOW);
  } else {
    millisTarefa2 = millis();
    alteracao2();
  }
}
if (autorizado) {
  sistema();
} else {
  if (Serial.available()) {
    if (clear != "prog") {
      clear = Serial.readString();
      clear.trim();
    }if (clear == "prog") {
      if (!usuario) {
        Serial.println("Digite o usuário");
        usuario = true;
      } else if (!senha) {
        identidade = Serial.readString();
        identidade.trim();
        Serial.println("Digite a senha");
        senha = true;
      } else if (senha && usuario) {
        chave = Serial.readString();
        chave.trim();
        for (int i = 0; i < sizeof funcionarios / sizeof funcionarios[0]; i++) {
          String n = funcionarios[i];
          Serial.println(n);
          Serial.print(identidade);
          Serial.print(chave);
          senha = false;
          usuario = false;
          clear = "";
          if (n == identidade && chave == senhas[i]) {
            autorizado = true;
            Serial.println("autorizado");
            clear = "";
          }
        }66666
      }
    }
  }
}
}
void sistema() {

  if (Serial.available()) {
    if (resposta == false) {
      if (clear == "prog") {
        clear = Serial.readString();
        clear.trim();
        qual = clear.toInt();
      } else {
        clear = Serial.readString();
        clear.trim();
      }
    }
    if (clear == "mostre") {
      Serial.println(clear);
      Serial.print(qual);
      Serial.println(" qual");
      Serial.print(temp1);
      Serial.println(" temp1");
      Serial.print(temp2);
      Serial.println(" temp2");
      Serial.print(temp3);
      Serial.println(" temp3");
      Serial.println(resposta);
      Serial.println(identidade);
      Serial.println(chave);
      Serial.println(estado1);
      Serial.println(estado2);
      Serial.println(tempEstado);
    }
    if (clear == "sair") {
      Serial.println("saindo do modo de configuração");
      autorizado = false;
      identidade = "";
      chave = "";
    }
    else if (clear == "prog" || tempClear == "prog") {
      Serial.print(qual);
      Serial.println(" qual");
      if (qual == 0) {
        Serial.println("Que led sera trocado?\nSemáforo 1\n 1-)Verde 2-)Amarelo 3-)Vermelho\n\nSemáforo 2\n 4-)Verde 5-)Amarelo 6-)Vermelho\n\nQual estado será trocado?\n7-)normal 8-)oscilando\n\n)Opções\n11-)Restaurar tempos 12-)Mostrar tempos 13-)Forçar\ndigite sair' para sair");
        tempClear = clear;
      }
      if (qual == 1) {
        if (resposta == false) {
          Serial.println("quantos segundos o sinal verde estará aberto?");
          resposta = true;
        } else {
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
        } else {
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
        } else {
          temp3 = Serial.parseInt() * 1000;
          Serial.print(temp3);
          Serial.println(" temp3");
          qual = 0;
          resposta = false;
          tempClear = "";
          clear = "";
        }
      }
      if (qual == 4) {
        if (resposta == false) {
          Serial.println("quantos segundos o sinal verde estará aberto?");
          resposta = true;
        } else {
          temp4 = Serial.parseInt() * 1000;
          Serial.print(temp4);
          Serial.println(" temp4");
          qual = 0;
          resposta = false;
          tempClear = "";
          clear = "";
        }
      }
        if (qual == 5) {
        if (resposta == false) {
          Serial.println("quantos segundos o sinal amarelo estará aberto?");
          resposta = true;
        } else {
          temp5 = Serial.parseInt() * 1000;
          Serial.print(temp5);
          Serial.println(" temp5");
          qual = 0;
          resposta = false;
          tempClear = "";
          clear = "";
        }
        }
        if (qual == 6) {
        if (resposta == false) {
          Serial.println("quantos segundos o sinal vermelho estará aberto?");
          resposta = true;
        } else {
          temp6 = Serial.parseInt() * 1000;
          Serial.print(temp6);
          Serial.println(" temp6");
          qual = 0;
          resposta = false;
          tempClear = "";
          clear = "";
        }
      }
      if (qual == 7) {
        Serial.println("Alterando para estado normal");
        tempEstado = "normal";
        qual = 0;
        resposta = false;
        tempClear = "";
        clear = "";
      }
      if (qual == 8) {
        Serial.println("Alterando para estado oscilando");
        tempEstado = "oscilando";
        qual = 0;
        resposta = false;
        tempClear = "";
        clear = "";
      }
      if (qual == 11) {
        Serial.println("Resturando tempos originais");
        temp1 = 44000;
        temp2 = 2000;
        temp3 = 50000;
        temp4 = 50000;
        temp5 = 2000;
        temp6 = 44000;
        qual = 0;
        resposta = false;
        tempClear = "";
        clear = "";
      }if (qual == 12) {
        Serial.println("TEMPOS");
        Serial.println("Semáforo 1");
        Serial.print((temp1/1000));
        Serial.println(" segundos no verde");
        Serial.print((temp2/1000));
        Serial.println(" segundos no amarelo");
        Serial.print((temp3/1000));
        Serial.println(" segundos no vermelho");
        Serial.println("\nSemáforo 2");
        Serial.print((temp4/1000));
        Serial.println(" segundos no verde");
        Serial.print((temp5/1000));
        Serial.println(" segundos no amarelo");
        Serial.print((temp6/1000));
        Serial.println(" segundos no vermelho");
        qual = 0;
        resposta = false;
        tempClear = "";
        clear = "";
      }
      if (qual == 13) {
        desligatudo();
        millisTarefa1 = millis();
        millisTarefa2 = millis();
        alteracao1();
        alteracao2();
        qual = 0;
        resposta = false;
        tempClear = "";
        clear = "";
      }
    }
  }
}

void desligatudo(){
  digitalWrite(vm1, LOW);
  digitalWrite(vd1, LOW);
  digitalWrite(amrl1, LOW);
  digitalWrite(vd2, LOW);
  digitalWrite(amrl2, LOW);
  digitalWrite(vm2, LOW);
}
void alteracao1() {
  verde1 = temp1;
  amarelo1 = verde1 + temp2;
  vermelho1 = amarelo1 + temp3;
  estado1 = tempEstado;
}
void alteracao2() {
  vermelho2 = temp6;
  verde2 = vermelho2 + temp4;
  amarelo2 = temp5 + verde2;
  estado2 = tempEstado;
}
