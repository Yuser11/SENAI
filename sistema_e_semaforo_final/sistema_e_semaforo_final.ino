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
bool confirmado1 = false;
bool confirmado2 = false;
bool sair = false;
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

  declaracaoPinos();
  if (estado1 == "normal") {
    funcionamentoNormalSemaforo1();
  } else if (estado1 == "oscilando") {
    funcionamentoOscilandoSemaforo1();
  }
  if (estado2 == "normal") {
    funcionamentoNormalSemaforo2();
  } else if (estado2 == "oscilando") {
    funcionamentoOscilandoSemaforo2();
  }
  if (autorizado) {
    sistema();
  } else {
    autenticacao();
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
      depurar();
    } else if (clear == "prog" || tempClear == "prog") {
      Serial.print(qual);
      Serial.println(" qual");
      if (qual == 0) {
        Serial.println("Que led sera trocado?\nSemáforo 1\n 1-)Verde 2-)Amarelo 3-)Vermelho\n\nSemáforo 2\n4-)Verde 5-)Amarelo 6-)Vermelho\n\nQual estado será trocado?\n7-)normal 8-)oscilando\n\n)Opções\n9-)Confimar 10-)Restaurar tempos 11-)Mostrar tempos12-)Forçar 13-)sair");
        tempClear = clear;
      }
      if (qual == 1) {
        alterarVerde1();
      }
      if (qual == 2) {
        alterarAmarelo1();
      }
      if (qual == 3) {
        alterarVermelho1();
      }
      if (qual == 4) {
        alterarVerde2();
      }
      if (qual == 5) {
        alterarAmarelo2();
      }
      if (qual == 6) {
        alterarVermelho2();
      }
      if (qual == 7) {
        estadoNormal();
      }
      if (qual == 8) {
        estadoOscilando();
      }
      if (qual == 9) {
        Serial.println("Confirmado");
        confirmado1 = true;
        confirmado2 = true;
        qual = 0;
        resposta = false;
        tempClear = "";
        clear = "";
      }
      if (qual == 10) {
        restaurarTempos();
      }
      if (qual == 11) {
        mostrarValores();
      }
      if (qual == 12) {
        forcar();
      }
      if (qual == 13) {
        if (!confirmado1) {
          if (!sair) {
            Serial.println("Sair sem confirmar?");
            sair = true;
            qual = 0;
            resposta = false;
            tempClear = "";
            clear = "";
          } else {
            Serial.println("saindo do modo de configuração");
            autorizado = false;
            identidade = "";
            chave = "";
            qual = 0;
            resposta = false;
            tempClear = "";
            clear = "";
          }
        } else {
          Serial.println("saindo do modo de configuração");
          autorizado = false;
          identidade = "";
          chave = "";
          qual = 0;
          sair = false;
          tempClear = "";
          clear = "";
        }
      }
    }
  }
}

void alterarVerde1() {
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
void alterarAmarelo1() {
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
void alterarVermelho1() {
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
void alterarVerde2() {
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
void alterarAmarelo2() {
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
void alterarVermelho2() {
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
void estadoNormal() {
  Serial.println("Alterando para estado normal");
  tempEstado = "normal";
  qual = 0;
  resposta = false;
  tempClear = "";
  clear = "";
}
void estadoOscilando() {
  Serial.println("Alterando para estado oscilando");
  tempEstado = "oscilando";
  qual = 0;
  resposta = false;
  tempClear = "";
  clear = "";
}
void restaurarTempos() {
  Serial.println("Resturando tempos originais");
  temp1 = 42000;
  temp2 = 2000;
  temp3 = 45000;
  temp4 = 45000;
  temp5 = 2000;
  temp6 = 42000;
  qual = 0;
  resposta = false;
  tempClear = "";
  clear = "";
}
void mostrarValores() {
  Serial.println("TEMPOS");
  Serial.println("Semáforo 1");
  Serial.print((temp1 / 1000));
  Serial.println(" segundos no verde");
  Serial.print((temp2 / 1000));
  Serial.println(" segundos no amarelo");
  Serial.print((temp3 / 1000));
  Serial.println(" segundos no vermelho");
  Serial.println("\nSemáforo 2");
  Serial.print((temp4 / 1000));
  Serial.println(" segundos no verde");
  Serial.print((temp5 / 1000));
  Serial.println(" segundos no amarelo");
  Serial.print((temp6 / 1000));
  Serial.println(" segundos no vermelho");
  qual = 0;
  resposta = false;
  tempClear = "";
  clear = "";
}
void forcar() {
  Serial.println("Valores sendo alterado agora");
  confirmado1 = true;
  confirmado2 = true;
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
void desligatudo() {
  digitalWrite(vm1, LOW);
  digitalWrite(vd1, LOW);
  digitalWrite(amrl1, LOW);
  digitalWrite(vd2, LOW);
  digitalWrite(amrl2, LOW);
  digitalWrite(vm2, LOW);
}
void alteracao1() {
  if (confirmado1) {
    verde1 = temp1;
    amarelo1 = verde1 + temp2;
    vermelho1 = amarelo1 + temp3;
    estado1 = tempEstado;
    confirmado1 = false;
  }
}
void alteracao2() {
  if (confirmado2) {
    vermelho2 = temp6;
    verde2 = vermelho2 + temp4;
    amarelo2 = temp5 + verde2;
    estado2 = tempEstado;
    confirmado2 = false;
  }
}
void depurar() {
  Serial.println(clear);
  Serial.print(qual);
  Serial.println(" qual");
  Serial.print(temp1);
  Serial.println(" temp1");
  Serial.print(temp2);
  Serial.println(" temp2");
  Serial.print(temp3);
  Serial.println(" temp3");
  Serial.print(temp4);
  Serial.println(" temp4");
  Serial.print(temp5);
  Serial.println(" temp5");
  Serial.print(temp6);
  Serial.println(" temp6");
  Serial.println(resposta);
  Serial.println(identidade);
  Serial.println(chave);
  Serial.println(estado1);
  Serial.println(estado2);
  Serial.println(tempEstado);
}
void declaracaoPinos() {
  pinMode(vm1, OUTPUT);
  pinMode(vd1, OUTPUT);
  pinMode(amrl1, OUTPUT);
  pinMode(vd2, OUTPUT);
  pinMode(amrl2, OUTPUT);
  pinMode(vm2, OUTPUT);
}
void funcionamentoNormalSemaforo1() {
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
}
void funcionamentoOscilandoSemaforo1() {
  if ((millis() - millisTarefa1) < temp2) {
    digitalWrite(amrl1, HIGH);
    digitalWrite(vd1, LOW);
    digitalWrite(vm1, LOW);
  } else if (millis() - millisTarefa1 < (temp2 + 1000)) {
    digitalWrite(amrl1, LOW);
  } else {
    millisTarefa1 = millis();
    alteracao1();
  }
}
void funcionamentoNormalSemaforo2() {
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
}
void funcionamentoOscilandoSemaforo2() {
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
void autenticacao() {
  if (Serial.available()) {
    if (clear != "prog") {
      clear = Serial.readString();
      clear.trim();
    }
    if (clear == "prog") {
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
        }
      }
    }
  }
}
