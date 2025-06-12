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
int tempVar;
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

  DeclaracaoPinos();
  if (estado1 == "normal") {
    FuncionamentoNormalSemaforo1();
  } else if (estado1 == "oscilando") {
    FuncionamentoOscilandoSemaforo1();
  }
  if (estado2 == "normal") {
    FuncionamentoNormalSemaforo2();
  } else if (estado2 == "oscilando") {
    FuncionamentoOscilandoSemaforo2();
  }
  if (autorizado) {
    Sistema();
  } else {
    Autenticacao();
  }
}
void Sistema() {
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
      Depurar();
    } else if (clear == "prog" || tempClear == "prog") {
      Serial.print(qual);
      Serial.println(" qual");
      if (qual == 0) {
        Serial.println("Que led sera configurado?\nSemáforo 1\n1-)Verde 2-)Vermelho\n\nSemáforo 2\n3-)Verde 4-)Vermelho\n\n5-)Amarelo\n\nQual estado será trocado?\n6-)normal 7-)oscilando\n\n)Opções\n8-)Confimar 9-)Restaurar tempos 10-)Mostrar tempos\n 11-)Forçar 12-)sair 13-)Sincronizar 14-)Instruções");
        tempClear = clear;
      }
      if (qual == 1) {
        AlterarVerde1();
      }
      if (qual == 2) {
        AlterarVermelho1();
      }
      if (qual == 3) {
        AlterarVerde2();
      }
      if (qual == 4) {
        AlterarVermelho2();
      }
      if (qual == 5) {
        AlterarAmarelo();
      }
      if (qual == 6) {
        EstadoNormal();
      }
      if (qual == 7) {
        EstadoOscilando();
      }
      if (qual == 8) {
        Confirmar();
      }
      if (qual == 9) {
        RestaurarTempos();
      }
      if (qual == 10) {
        MostrarValores();
      }
      if (qual == 11) {
        Forcar();
      }
      if (qual == 12) {
        Sair();
      }
      if (qual == 13) {
        Sincronizar();
      }      
      if (qual == 14){
        Instrucoes();
        }
      }
    }
  }


void Instrucoes(){
  Serial.println("O verde deve estar aceso por 20 a 40 segundos");
  Serial.println("O amarelo deve estar aceso por 3 a 5 segundos, caso precise");
  Serial.println("O vermelho deve estar aceso por 20 a 80 segundos");
}
void Sincronizar(){
  Serial.println("Sincronizando");
  temp6 = temp1 + temp2;
  temp3 = temp4 + temp5;
  qual = 0;
  resposta = false;
  tempClear = "";
  clear = "";
}
void Sair(){
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
void Confirmar(){
  Serial.println("Confirmado");
  confirmado1 = true;
  confirmado2 = true;
  qual = 0;
  resposta = false;
  tempClear = "";
  clear = "";
}
void AlterarVerde1() {
  if (resposta == false) {
    Serial.println("quantos segundos o sinal verde estará aberto?");
    resposta = true;
  } else {
    tempVar = Serial.parseInt() * 1000;
    if (tempVar > 20000 &&tempVar <40000){
    temp1 = tempVar;
    tempVar = 0;
    Serial.print(temp1);
    Serial.println(" temp1");
    }else{
      Serial.println("O valor deve ser entre 20 e 40 segundos");
    }    
    qual = 0;
    resposta = false;
    tempClear = "";
    clear = "";
  }
}
void AlterarVermelho1() {
  if (resposta == false) {
    Serial.println("quantos segundos o sinal vermelho estará aberto?");
    resposta = true;
  } else {
    tempVar = Serial.parseInt() * 1000;
    if (tempVar > 20000 &&tempVar <80000){
    temp3 = tempVar;
    tempVar = 0;
    Serial.print(temp3);
    Serial.println(" temp3");
    }else{
      Serial.println("O valor deve ser entre 20 e 80 segundos");
    }    
    qual = 0;
    resposta = false;
    tempClear = "";
    clear = "";
  }
}
void AlterarVerde2() {
  if (resposta == false) {
    Serial.println("quantos segundos o sinal verde estará aberto?");
    resposta = true;
  } else {
    tempVar = Serial.parseInt() * 1000;
    if (tempVar > 20000 &&tempVar <40000){
    temp4 = tempVar;
    tempVar = 0;
    Serial.print(temp4);
    Serial.println(" temp4");
    }else{
      Serial.println("O valor deve ser entre 20 e 40 segundos");
    }    
    qual = 0;
    resposta = false;
    tempClear = "";
    clear = "";
  }
}
void AlterarAmarelo() {
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
void AlterarVermelho2() {
  if (resposta == false) {
    Serial.println("quantos segundos o sinal vermelho estará aberto?");
    resposta = true;
  } else {
    tempVar = Serial.parseInt() * 1000;
    if (tempVar > 20000 &&tempVar <80000){
    temp6 = tempVar;
    tempVar = 0;
    Serial.print(temp6);
    Serial.println(" temp6");
    }else{
      Serial.println("O valor deve ser entre 20 e 80 segundos");
    }
    qual = 0;
    resposta = false;
    tempClear = "";
    clear = "";
  }
}
void EstadoNormal() {
  Serial.println("Alterando para estado normal");
  tempEstado = "normal";
  qual = 0;
  resposta = false;
  tempClear = "";
  clear = "";
}
void EstadoOscilando() {
  Serial.println("Alterando para estado oscilando");
  tempEstado = "oscilando";
  qual = 0;
  resposta = false;
  tempClear = "";
  clear = "";
}
void RestaurarTempos() {
  Serial.println("Resturando tempos originais");
  temp1 = 40000;
  temp2 = 4000;
  temp3 = 45000;
  temp4 = 45000;
  temp5 = 4000;
  temp6 = 40000;
  qual = 0;
  resposta = false;
  tempClear = "";
  clear = "";
}
void MostrarValores() {
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
void Forcar() {
  Serial.println("Valores sendo alterado agora");
  confirmado1 = true;
  confirmado2 = true;
  Desligatudo();
  millisTarefa1 = millis();
  millisTarefa2 = millis();
  Alteracao1();
  Alteracao2();
  qual = 0;
  resposta = false;
  tempClear = "";
  clear = "";
}
void Desligatudo() {
  digitalWrite(vm1, LOW);
  digitalWrite(vd1, LOW);
  digitalWrite(amrl1, LOW);
  digitalWrite(vd2, LOW);
  digitalWrite(amrl2, LOW);
  digitalWrite(vm2, LOW);
}
void Alteracao1() {
  if (confirmado1) {
    verde1 = temp1;
    amarelo1 = verde1 + temp2;
    vermelho1 = amarelo1 + temp3;
    estado1 = tempEstado;
    confirmado1 = false;
  }
}
void Alteracao2() {
  if (confirmado2) {
    vermelho2 = temp6;
    verde2 = vermelho2 + temp4;
    amarelo2 = temp5 + verde2;
    estado2 = tempEstado;
    confirmado2 = false;
  }
}
void Depurar() {
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
void DeclaracaoPinos() {
  pinMode(vm1, OUTPUT);
  pinMode(vd1, OUTPUT);
  pinMode(amrl1, OUTPUT);
  pinMode(vd2, OUTPUT);
  pinMode(amrl2, OUTPUT);
  pinMode(vm2, OUTPUT);
}
void FuncionamentoNormalSemaforo1() {
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
    Alteracao1();
  }
}
void FuncionamentoOscilandoSemaforo1() {
  if ((millis() - millisTarefa1) < temp2) {
    digitalWrite(amrl1, HIGH);
    digitalWrite(vd1, LOW);
    digitalWrite(vm1, LOW);
  } else if (millis() - millisTarefa1 < (temp2 + 1000)) {
    digitalWrite(amrl1, LOW);
  } else {
    millisTarefa1 = millis();
    Alteracao1();
  }
}
void FuncionamentoNormalSemaforo2() {
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
    Alteracao2();
  }
}
void FuncionamentoOscilandoSemaforo2() {
  if ((millis() - millisTarefa2) < temp5) {
    digitalWrite(amrl2, HIGH);
    digitalWrite(vd2, LOW);
    digitalWrite(vm2, LOW);
  } else if (millis() - millisTarefa2 < (temp5 + 1000)) {
    digitalWrite(amrl2, LOW);
  } else {
    millisTarefa2 = millis();
    Alteracao2();
  }
}
void Autenticacao() {
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
            Serial.println("Antes de fazer alterações, veja as intruções");
          }
        }
      }
    }
  }
}
