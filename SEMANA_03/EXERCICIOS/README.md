# EXERCÍCIOS
Vamos montar um instrumento musical? Crie um circuito com 4 LEDs, um buzzer e um LDR (sensor de luminosidade).
Os valores lidos pelo sensor LDR devem ser convertidos para uma contagem de até 4 dígitos binários, que por sua vez corresponderão aos 4 LEDs.
Complemente o circuito com:
1-Buzzer, que deverá tocar algo diferente para cada valor da contagem binária
2-Dois botões (push button):
-Um dos botões deve armazenar um valor binário lido pelo LDR em um vetor (dica: acenda os LEDs e toque o som correspondente no momento do armazenamento)
-O outro botão deve exibir nos LEDs, em sequência, todos os valores armazenados no vetor anterior e, ao mesmo tempo, tocar seu respectivo som através do buzzer. Após a leitura de todos os valores armazenados, o vetor deve ser esvaziado.

Lembre-se de seguir os passos:

1-Crie uma simulação no Wokwi
2-Programe a simulação no Wokwi
3-Transfira seu projeto para o circuito físico (protoboard, esp32) utilizando a IDE do Arduino para programar o ESP.

Resposta: 
#define LEDred 2
#define LEDgre 42
#define LEDyel 40
#define LEDwhite 0
#define buzzer 19
#define botao1 5
#define botao2 6
int sensor = 10;
int posicao = -1;  // var auxíliar

const int quantidade = 100;       // quantos binário eu quero salvar
int numeros[quantidade * 4];      // cada binário com quatro dígitos
int binario[4] = { 0, 0, 0, 0 };  // cada vez que rodar ele vai converter o valor para binários
int cofre[quantidade];            // guarda a frequência dos números
int frequencias[16] = { 10, 273, 546, 819, 1092, 1363, 1638, 1911, 2184, 2457, 2730, 3003, 3276, 3539, 3822, 4049 };
int valoresSalvos[200];

void addlista(int decimal) {  // alterar o valor de uma variavél, função void nao retorna nada
  if (posicao + 1 >= 200) {
    Serial.println("ERRO: limite de valores atingido");
  } else {
    valoresSalvos[posicao + 1] = decimal;
    posicao++;
  }
}
int conversorValue(int valor) {  // dividir o 4095

  return valor / 273;
}

void convertebinarios(int valor) {

  for (int i = 3; i >= 0; i--) {
    binario[i] = valor % 2;
    valor = valor / 2;
  }
}

void acendeEToca(int decimal) {
  convertebinarios(decimal);
  digitalWrite(LEDred, binario[0]); // convertendo pde decimal para binário, acendendo e tocando conforme os valores de 1 e 0 

  digitalWrite(LEDgre, binario[1]);

  digitalWrite(LEDyel, binario[2]);

  digitalWrite(LEDwhite, binario[3]);
  tone(buzzer, frequencias[decimal]); 
  delay(500);
  tone(buzzer, 0);
  digitalWrite(LEDred, LOW);
  digitalWrite(LEDgre, LOW);
  digitalWrite(LEDyel, LOW);
  digitalWrite(LEDwhite, LOW);
}

void tocaTudo() {  // reproduz o que foi feito no primeiro botão 
  for (int i = 0; i <= posicao; i++) {
    acendeEToca(valoresSalvos[i]);
    delay(300);
  }
  posicao = -1;
}

void setup() {
  pinMode(LEDred, OUTPUT);
  pinMode(LEDgre, OUTPUT);
  pinMode(LEDyel, OUTPUT);
  pinMode(LEDwhite, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(sensor, INPUT);
  pinMode(botao1, INPUT);
  pinMode(botao2, INPUT);
}

int lastState = LOW;
int playState = LOW;
void loop() {
  if (digitalRead(botao1) == HIGH && lastState == LOW) {
    addlista(conversorValue(analogRead(sensor)));
    acendeEToca(conversorValue(analogRead(sensor)));
    lastState = HIGH;
  } else if (digitalRead(botao1) == LOW && lastState == HIGH) {
    lastState = LOW;
  }

  if (digitalRead(botao2) == HIGH && playState == LOW) { 
    tocaTudo();
    playState = HIGH;
  } else if (digitalRead(botao2) == LOW && playState == HIGH) {
    playState = LOW;
  }
}