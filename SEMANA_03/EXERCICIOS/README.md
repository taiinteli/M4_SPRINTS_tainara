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

// #define LEDred 2
// #define LEDgre 4 
// #define LEDyel 5 
// #define LEDpin 18
// #define buzzer 19 
//#define botao1 35
// int estadoled = 0;
int sensor = 1;
int sensore = 0; 
int min_sensor = 1; 
int max_sensor = 4095; 
int leitura = 0; 


void setup() {
 // pinMode(LEDred, OUTPUT);
 // pinMode(LEDgre, OUTPUT);
 // pinMode(LEDyel, OUTPUT);
 // pinMode(LEDpin, OUTPUT);
 // pinMode(buzzer, OUTPUT); 
 // pinMode(botao1, INPUT_PULLUP); 
  pinMode(sensor, INPUT);

  Serial.begin(115200);
}

void loop() {
  // digitalWrite(LEDred, HIGH);
  // tone(buzzer,293);  
  // delay(100); 
  // noTone(buzzer); 

  // digitalWrite(LEDred, LOW);
  // delay(100);  

  // digitalWrite(LEDgre, HIGH);
  // tone(buzzer,415);  
  // delay(100); 
  // noTone(buzzer); 

  // digitalWrite(LEDgre, LOW);
  // delay(100);

  // digitalWrite(LEDyel, HIGH);
  // tone(buzzer,622);  
  // delay(100); 
  // noTone(buzzer);   
  
  // digitalWrite(LEDyel, LOW);
  // delay(100);

  // digitalWrite(LEDpin, HIGH);
  // tone(buzzer,830);  
  // delay(100); 
  // noTone(buzzer); 

  // digitalWrite(LEDpin, LOW);
  // delay(100);

  sensore = analogRead(sensor);
  // print the sensor reading so you know its range
  Serial.println("ihuuuu:");
  Serial.println(sensore);
  // map the sensor reading to a range for the LED
  // analogWrite(sensor, map(sensor, 0, 1023, 0, 255));
  delay(100);

  // Serial.print("botao1");
  // if (digitalRead(botao1) == LOW) // Se o botão for pressionado
  // {
  //  estadoled = !estadoled; // troca o estado do LED
  // digitalWrite(estadoled);
  // while (digitalRead(botao1) == LOW);
  //  delay(100);
  // }
  // if(digitalRead(botao1) == LOW){
  //   delay(500);
  // digitalWrite(); } 
} 
void convertebinarios() { 

  map(leitura, min_sensor, max_sensor, 0, 15); 

  if(leitura == 1){
     analogWrite(Serial("0001"));
  }
}