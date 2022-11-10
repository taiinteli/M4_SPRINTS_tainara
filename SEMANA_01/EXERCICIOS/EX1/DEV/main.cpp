#include <iostream>
#include <string>
using namespace std;
/*
1 -  Faça uma função que recebe uma certa medida e ajusta ela percentualmente entre dois valores mínimo e máximo e retorna esse valor
*/
// Resposta: 

#include <iostream>
#include <string>
using namespace std;

// valor a ser calculado em porcentagm. é necessário saber o tipo do programa. pensar no tipo da função com a saida é flot 

// transformação linear 

float converteSensor(float Medida, float Min, float Max){ // repectivamente usando os valores das linhas 27, 29 e 31

  float valorEsperado = (Medida - Min)/(Max - Min); // utilizano transformação linear para calcular o valor esperado 
    
  return valorEsperado; 

}

int main(){
  cout << "Teste Ex 1" << endl;
	cout << converteSensor(100,100,400) << endl;
  valor esperado: 0
	cout << converteSensor(400,100,400) << endl;
  valor esperado: 1
	cout << converteSensor(250,100,400) << endl;
  valor esperado: 0.5
} 

// ----------------------------------------------------------
/*
2 - Faça uma função que simule a leitura de um sensor lendo o valor do teclado ao final a função retorna este valor
*/
// Reposta: 
#include <iostream>
#include <string>
using namespace std;

 int leComando(){
   int ordem; 
     cin >> ordem;
     if (ordem != 0 && ordem !=1){
       cout << "Comando não recebido, tente novamente." << endl; // caso o input for algo diferete de zero ou um, o programa responderá dessa maneira 
       return ordem; 
       } else {
       return ordem; 
    }
}

int main(){
  cout << "Digite o comando (0 ou 1):"; 
	int cmd = leComando();
	cout << "Comando recebido: " << cmd << endl;
}
// ----------------------------------------------------------
/*
3 - Faça uma função que armazena uma medida inteira qualquer em um vetor fornecido. Note que como C não possui vetores nativos da linguagem, lembre-se que você precisa passar o valor máximo do vetor assim como a última posição preenchida.
Evite também que, por acidente, um valor seja escrito em uma área de memória fora do vetor
*/

//Resposta: 
#include <iostream>
#include <string>
using namespace std;

int insereVetor(int elemento, int valorMax, int lastPos, int Vetor[]){
  Vetor[lastPos +1 ] = elemento; 
  
  if(lastPos +1 >= valorMax){


    cout << "Erro: valor máximo: " << valorMax << "lastPos + 1 (indice):" << valorMax << endl;

    
  }

  return 0;
  
  } 

int main(){
  int valorMax = 10;
  int lastPos = -1;
  int Numbers[valorMax];
  insereVetor(9, valorMax, lastPos, Numbers);
  lastPos = lastPos + 1;
  insereVetor(8, valorMax, lastPos, Numbers);
  lastPos = lastPos + 1;
  insereVetor(7, valorMax, lastPos, Numbers);
  lastPos = lastPos + 1;
  insereVetor(6, valorMax, lastPos, Numbers);
  lastPos = lastPos + 1;
  insereVetor(5, valorMax, lastPos, Numbers);
  lastPos = lastPos + 1;
  insereVetor(4, valorMax, lastPos, Numbers);
  lastPos = lastPos + 1;
  insereVetor(3, valorMax, lastPos, Numbers);
  lastPos = lastPos + 1;
  insereVetor(2, valorMax, lastPos, Numbers);
  lastPos = lastPos + 1;
  insereVetor(1, valorMax, lastPos, Numbers);
  lastPos = lastPos + 1;
  insereVetor(0, valorMax, lastPos, Numbers);
  lastPos = lastPos + 1;
  insereVetor(100, valorMax, lastPos, Numbers);
  // valor esperado: mensagem de erro "Erro: valorMax: 10, lastPos + 1 (indice): 10"
  cout << Numbers[0] << endl; // valor esperado: 9
  cout << Numbers[1] << endl; // valor esperado: 8
  cout << Numbers[2] << endl; // valor esperado: 7
  cout << Numbers[3] << endl; // valor esperado: 6
  cout << Numbers[4] << endl; // valor esperado: 5
  cout << Numbers[5] << endl; // valor esperado: 4
  cout << Numbers[6] << endl; // valor esperado: 3
  cout << Numbers[7] << endl; // valor esperado: 2
  cout << Numbers[8] << endl; // valor esperado: 1
  cout << Numbers[9] << endl; // valor esperado: 0
  
}

// ----------------------------------------------------------
/*
4 - Faça duas funções que recebem um vetor com 4 posições que contém o valor da distância de um pequeno robô até cada um dos seus 4 lados.
A primeira função deve retornar a direção de maior distância ("Direita", "Esquerda", "Frente", "Tras") e a segunda função deve retornar esta maior distância.
*/
// Resposta: 
#include <iostream>
#include <string>
using namespace std;
string dirMaiorDist(int Vetor[]){ // distâncias
  
  string direcao; 
  // comparações dos valores entre os vetores
  
  if (Vetor[0] > Vetor[1] && Vetor[0] > Vetor[2] && Vetor[0] > Vetor [3]){
    direcao = "direita";
    return direcao; 
  }
  else if (Vetor[1] > Vetor[0] && Vetor[1] > Vetor[2] && Vetor [1] > Vetor[3]){
    direcao = "esquerda";
    return direcao; 
  }
  if (Vetor[2] > Vetor[0] && Vetor[2] > Vetor[1] && Vetor[2] > Vetor [3]){
    direcao = "frente";
    return direcao; 
  }
   if (Vetor[3] > Vetor[0] && Vetor[3] > Vetor[1] && Vetor[3] > Vetor [2]){
    direcao = "trás";
    return direcao; 
  }

  return "None";  

}


int maiorDist(int Vetor[]){ // valor inteiro

  int maior = -1; 
  
  for (int i = 0; i <= 3; i++) {
     if (Vetor[i] > maior){
     maior = Vetor[i]; 
     }
   } 
  
  return maior;

}


// ----------------------------------------------------------
// 5 - Faça uma função que pergunta ao usuário se ele deseja continuar o mapeamento e retorna verdadeiro ou falso
//Resposta: 
int continuar(){
  int number; 
  cout << "Digite 1 para parar ";
  cin >> number;
  if (number != 1){
    return 0; 
  } else { 
    return number; 
  }
   
  
}

int main(){
  int parar = 0;
  while (parar == 0){
    parar = continuar();
  }

// ----------------------------------------------------------
/*
6 - Escreva uma função que vai "dirigindo" virtualmente um robô e através de 4 sensores em cada um dos 4 pontos do robo ("Direita", "Esquerda", "Frente", "Tras").
A cada passo, ele verifica as distâncias aos objetos e vai mapeando o terreno para uma movimentação futura.
Ele vai armazenando estas distancias em um vetor fornecido como parâmetro e retorna a ultima posicao preenchida do vetor.
Esta função deve ir lendo os 4 sensores até que um comando de pare seja enviado.
Para simular os sensores e os comandos de pare, use as funções já construídas nos ítens anteriores e em um looping contínuo até que um pedido de parada seja enviado pelo usuário.
A função final deve utilizar as funções declaradas acima para ler os sensores e o movimento do robô e no final percorrer o vetor e mostrar o movimento a cada direção na maior distância a cada movimento.
*/ 

int maxVetor = maxv;
	int *vetorMov = v;
	int posAtualVetor = 0;
	int dirigindo = 1;		
	while(dirigindo){		
		int medida = leituraSensor();
		medida = converteSensor(medida,0,830);
		posAtualVetor = armazenaValor(vetorMov,maxVetor,posAtualVetor,medida);
		dirigindo = leComando();		
	}
	return posAtualVetor;
}


// O trecho abaixo irá utilizar as funções acima para ler os sensores e o movimento
// do robô e no final percorrer o vetor e mostrar o movimento a cada direção baseado 
// na maior distância a cada movimento

void percorre(int *v,int tamPercorrido){	

	int *vetorMov = v;
	int maiorDir = 0;

for(int i = 0; i< tamPercorrido; i+=4){
		char *direcao = direcaoMenorCaminho(&(vetorMov[i]),&maiorDir);
		printf("Movimentando para %s distancia = %i\n",direcao,maiorDir);
	}
}

int main(int argc, char** argv) {
	int maxVetor = 100;
	int vetorMov[maxVetor*4];
	int posAtualVet = 0;
	
	posAtualVet = dirige(vetorMov,maxVetor);
	percorre(vetorMov,posAtualVet);
	
	return 0;
}
