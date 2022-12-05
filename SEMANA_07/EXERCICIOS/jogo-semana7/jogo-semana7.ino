#include <WiFi.h>
    #include <WiFiAP.h>
    #include <WebServer.h>
    /* INCLUDE ESP2SOTA LIBRARY */
    #include <ESP2SOTA.h>
    const char* ssid = "Tainara"; // nome da rede
    const char* password = "senhadatai"; // senha da rede de conexão
    
    #define BUZZER 10
    #define LED 18
    
    WebServer server(80);
    // Conteúdo HTML da página inicial
    String home() {
      String conteudoHTML = "<!DOCTYPE html>";
      conteudoHTML += "<html lang=\"en\">";
      conteudoHTML += "<head>";
      conteudoHTML += "<meta charset=\"UTF-8\">";
      conteudoHTML += "<meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">";
      conteudoHTML += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">";
      conteudoHTML += "<title>Joguinho das Cores</title> <!-- título da página -->";
      conteudoHTML += "<!-- estilização da página -->";
      conteudoHTML += "<style> ";
      conteudoHTML += "* {";
      conteudoHTML += "margin: 0;";
      conteudoHTML += "box-sizing: border-box;";
      conteudoHTML += "}";
      conteudoHTML += "/* caractéristicas visuais do conteúdo da página  */";
      conteudoHTML += "body { ";
      conteudoHTML += "height: 100vh;";
      conteudoHTML += "background-color: purple;";
      conteudoHTML += "display: flex;";
      conteudoHTML += "justify-content: center;";
      conteudoHTML += "align-items: center;";
      conteudoHTML += "color: #fff;";
      conteudoHTML += "}";
      conteudoHTML += "/* caractéristicas do CSS do jogo*/";
      conteudoHTML += ".container {";
      conteudoHTML += "display: flex;";
      conteudoHTML += "flex-direction: column;";
      conteudoHTML += "width: 100vw;";
      conteudoHTML += "height: 30vh;";
      conteudoHTML += "align-items: center;";
      conteudoHTML += "justify-content: space-evenly;";
      conteudoHTML += "}";
      conteudoHTML += "/* caractéristicas do dropdrwan que irá selecionar a quantidade de vezes que as cores irão repetir */";
      conteudoHTML += "input { ";
      conteudoHTML += "border: none;";
      conteudoHTML += "outline: none;";
      conteudoHTML += "padding: 10px;";
      conteudoHTML += "width: 200px;";
      conteudoHTML += "border-radius: 10px;";
      conteudoHTML += "}";
      conteudoHTML += "select {";
      conteudoHTML += "padding: 10px;";
      conteudoHTML += "border-radius: 10px;";
      conteudoHTML += "}";
      conteudoHTML += "/* caractéristicas do botão inicar*/";
      conteudoHTML += "button { ";
      conteudoHTML += "padding: 10px;";
      conteudoHTML += "border-radius: 10px;";
      conteudoHTML += "outline: none;";
      conteudoHTML += "border: none;";
      conteudoHTML += "margin-left: 5px;";
      conteudoHTML += "box-shadow: 2px 2px 2px #333;";
      conteudoHTML += "}";
      conteudoHTML += "button:hover {";
      conteudoHTML += "transition: 0.4s;";
      conteudoHTML += "background-color: deeppink;";
      conteudoHTML += "color: #fff;";
      conteudoHTML += "}";
      conteudoHTML += "</style>";
      conteudoHTML += "</head>";
      conteudoHTML += "<body> <!-- conteúdo da tela incial -->";
      conteudoHTML += "<div class=\"container\">";
      conteudoHTML += "<!-- título dao dropdawn do botão -->";
      conteudoHTML += "<label style=\"font-size:40px\">Quantidade de cores</label> ";
      conteudoHTML += "<div style=\"display: flex;\">";
      conteudoHTML += "<select>";
      conteudoHTML += "<!-- opções de quantidade de vezes que será possível ser repetido de 1 a 9 de acordo com o que for selecionado-->";
      conteudoHTML += "<option>1</option> ";
      conteudoHTML += "<option>2</option>";
      conteudoHTML += "<option>3</option>";
      conteudoHTML += "<option>4</option>";
      conteudoHTML += "<option>5</option>";
      conteudoHTML += "<option>6</option>";
      conteudoHTML += "<option>7</option>";
      conteudoHTML += "<option>8</option>";
      conteudoHTML += "<option>9</option>";
      conteudoHTML += "</select>";
      conteudoHTML += "<!-- botão iniciar do jogo -->";
      conteudoHTML += "<button onclick=\"teste()\">Iniciar</button>  ";
      conteudoHTML += "</div>";
      conteudoHTML += "</div>";
      conteudoHTML += "<script>";
      conteudoHTML += "/* função que pegará a quantidade selecionada no dropdawn e*/";
      conteudoHTML += "function teste() { ";
      conteudoHTML += "let quantidade = document.querySelector('select').value;";
      conteudoHTML += "sessionStorage.setItem('quantidade', quantidade);";
      conteudoHTML += "document.location = '/player-1';";
      conteudoHTML += "}";
      conteudoHTML += "</script>";
      conteudoHTML += "</body>";
      conteudoHTML += "</html>";
      return conteudoHTML;
    }
    /* Conteúdo HTML da página do Jogador 1 */
    String player1() {
      String conteudoHTML = "<!DOCTYPE html>";
      conteudoHTML += "<html lang=\"en\">";
      conteudoHTML += "<head>";
      conteudoHTML += "<meta charset=\"UTF-8\">";
      conteudoHTML += "<meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">";
      conteudoHTML += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">";
      conteudoHTML += "<!-- título da página -->";
      conteudoHTML += "<title>Jogo das Cores - Jogador 1</title> ";
      conteudoHTML += "<!--estilização da página -->";
      conteudoHTML += "<style> ";
      conteudoHTML += "* {";
      conteudoHTML += "margin: 0;";
      conteudoHTML += "}";
      conteudoHTML += ".container {";
      conteudoHTML += "width: 100vw;";
      conteudoHTML += "height: 100vh;";
      conteudoHTML += "display: flex;";
      conteudoHTML += "flex-direction: column;";
      conteudoHTML += "justify-content: center;";
      conteudoHTML += "align-items: center;";
      conteudoHTML += "background-color: #000;";
      conteudoHTML += "}";
      conteudoHTML += "/*  estilização da página */";
      conteudoHTML += ".buttons {";
      conteudoHTML += "width: 70%;";
      conteudoHTML += "height: 70%;";
      conteudoHTML += "display: grid;";
      conteudoHTML += "grid-template-columns: 1fr 1fr;";
      conteudoHTML += "grid-template-rows: 1fr 1fr;";
      conteudoHTML += "}";
      conteudoHTML += "button {";
      conteudoHTML += "margin: 5px;";
      conteudoHTML += "border-radius: 16px;";
      conteudoHTML += "opacity: 0.3;";
      conteudoHTML += "}";
      conteudoHTML += "#button-1 {";
      conteudoHTML += "background-color: yellow;";
      conteudoHTML += "}";
      conteudoHTML += "#button-2 {";
      conteudoHTML += "background-color: red;";
      conteudoHTML += "}";
      conteudoHTML += "#button-3 {";
      conteudoHTML += "background-color: blue;";
      conteudoHTML += "}";
      conteudoHTML += "#button-4 {";
      conteudoHTML += "background-color: green;";
      conteudoHTML += "}";
      conteudoHTML += "h2 {";
      conteudoHTML += "color: #fff;";
      conteudoHTML += "margin-bottom: 30px;";
      conteudoHTML += "}";
      conteudoHTML += "</style>";
      conteudoHTML += "</head>";
      conteudoHTML += "<!-- conteúdo da página do jogador 1 -->";
      conteudoHTML += "<body onload=\"runGame()\"> ";
      conteudoHTML += "<div class=\"container\">";
      conteudoHTML += "<h2>Vez do jogador 1!</h2>";
      conteudoHTML += "<div class=\"buttons\">";
      conteudoHTML += "<!-- botões das cores amarelo  = botaõ 1 , vermelho = botão 2, azul = botão 3 e verde = botão 4 -->";
      conteudoHTML += "<button onclick=\"tentativa(this.id)\" id=\"button-1\" disabled></button>";
      conteudoHTML += "<button onclick=\"tentativa(this.id)\" id=\"button-2\" disabled></button>";
      conteudoHTML += "<button onclick=\"tentativa(this.id)\" id=\"button-3\" disabled></button>";
      conteudoHTML += "<button onclick=\"tentativa(this.id)\" id=\"button-4\" disabled ></button>";
      conteudoHTML += "</div>";
      conteudoHTML += "</div>";
      conteudoHTML += "<script>";
      conteudoHTML += "var progress = [];";
      conteudoHTML += "var count = 0;";
      conteudoHTML += "function sleep(ms) {";
      conteudoHTML += "/* função assíncrona que fazer uma contagem em milisegundos para ter um funcionamento de representação de um \"timer\" */ ";
      conteudoHTML += "return new Promise(resolve => setTimeout(resolve, ms)); ";
      conteudoHTML += "}";
      conteudoHTML += "async function tentativa(id) {";
      conteudoHTML += "id = id[id.length-1];";
      conteudoHTML += "if (id == progress[count]) {";
      conteudoHTML += "document.querySelector(`#button-${id}`).style.opacity = 1;";
      conteudoHTML += "await sleep(500);";
      conteudoHTML += "document.querySelector(`#button-${id}`).style.opacity = 0.2;";
      conteudoHTML += "count++;";
      conteudoHTML += "if (progress[count] == 99) {";
      conteudoHTML += "await sleep(1000);";
      conteudoHTML += "document.location = '/player-2';";
      conteudoHTML += "}";
      conteudoHTML += "}";
      conteudoHTML += "else {";
      conteudoHTML += "document.querySelector('body').innerHTML = '<div style=\"width:100vw; height: 100vh; display: flex; justify-content: center; align-items: center;\"><h2 style=\"color: #000;\">Errou!</h2></div>';";
      conteudoHTML += "await sleep(1000);";
      conteudoHTML += "document.location = '/home';";
      conteudoHTML += "}";
      conteudoHTML += "}";
      conteudoHTML += "if (count == progress.length-1) {";
      conteudoHTML += "console.log('acabou');";
      conteudoHTML += "}";
      conteudoHTML += "/* função responsável por repetição das cores correspondente do dropdawn selecionado */";
      conteudoHTML += "async function runGame() { ";
      conteudoHTML += "/*  pega o valor do dropdawn e repete a quantidade de vezes das cores */";
      conteudoHTML += "let quantidade = sessionStorage.getItem('quantidade'); ";
      conteudoHTML += "for (n = 0; n < quantidade; n++) {";
      conteudoHTML += "/* sorteio de um valor entre 0 e 1, depois multiplica por 4 e arredonda para definir o relacionamento entre cores e botões */";
      conteudoHTML += "let valor = Math.ceil(Math.random()*4); ";
      conteudoHTML += "progress.push(valor);";
      conteudoHTML += "}";
      conteudoHTML += "for (n of progress) {";
      conteudoHTML += "console.log(n);";
      conteudoHTML += "await sleep(500); ";
      conteudoHTML += "document.querySelector(`#button-${n}`).style.opacity = 1;";
      conteudoHTML += "/* intervalo de tempo entre a reposta das cores selecionadas */ ";
      conteudoHTML += "await sleep(500); ";
      conteudoHTML += "document.querySelector(`#button-${n}`).style.opacity = 0.2; /* caractéristicas da opacidade das cores do botões */";
      conteudoHTML += "}";
      conteudoHTML += "progress.push(99);";
      conteudoHTML += "document.querySelector(`#button-1`).removeAttribute('disabled');";
      conteudoHTML += "document.querySelector(`#button-2`).removeAttribute('disabled');";
      conteudoHTML += "document.querySelector(`#button-3`).removeAttribute('disabled');";
      conteudoHTML += "document.querySelector(`#button-4`).removeAttribute('disabled');";
      conteudoHTML += "}";
      conteudoHTML += "</script>";
      conteudoHTML += "</body>";
      conteudoHTML += "</html>";
      return conteudoHTML;
    }
    /* Conteúdo HTML da página do Jogador 2 */
    String player2() {
      String conteudoHTML = "<!DOCTYPE html>";
      conteudoHTML += "<html lang=\"en\">";
      conteudoHTML += "<head>";
      conteudoHTML += "<meta charset=\"UTF-8\">";
      conteudoHTML += "<meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">";
      conteudoHTML += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">";
      conteudoHTML += "<!-- título da página -->";
      conteudoHTML += "<title>Jogo das Cores - Jogador 2</title> ";
      conteudoHTML += "<!--estilização da página -->";
      conteudoHTML += "<style> ";
      conteudoHTML += "* {";
      conteudoHTML += "margin: 0;";
      conteudoHTML += "}";
      conteudoHTML += ".container {";
      conteudoHTML += "width: 100vw;";
      conteudoHTML += "height: 100vh;";
      conteudoHTML += "display: flex;";
      conteudoHTML += "flex-direction: column;";
      conteudoHTML += "justify-content: center;";
      conteudoHTML += "align-items: center;";
      conteudoHTML += "background-color: #000;";
      conteudoHTML += "}";
      conteudoHTML += "/*  estilização da página */";
      conteudoHTML += ".buttons {";
      conteudoHTML += "width: 70%;";
      conteudoHTML += "height: 70%;";
      conteudoHTML += "display: grid;";
      conteudoHTML += "grid-template-columns: 1fr 1fr;";
      conteudoHTML += "grid-template-rows: 1fr 1fr;";
      conteudoHTML += "}";
      conteudoHTML += "button {";
      conteudoHTML += "margin: 5px;";
      conteudoHTML += "border-radius: 16px;";
      conteudoHTML += "opacity: 0.3;";
      conteudoHTML += "}";
      conteudoHTML += "#button-1 {";
      conteudoHTML += "background-color: yellow;";
      conteudoHTML += "}";
      conteudoHTML += "#button-2 {";
      conteudoHTML += "background-color: red;";
      conteudoHTML += "}";
      conteudoHTML += "#button-3 {";
      conteudoHTML += "background-color: blue;";
      conteudoHTML += "}";
      conteudoHTML += "#button-4 {";
      conteudoHTML += "background-color: green;";
      conteudoHTML += "}";
      conteudoHTML += "h2 {";
      conteudoHTML += "color: #fff;";
      conteudoHTML += "margin-bottom: 30px;";
      conteudoHTML += "}";
      conteudoHTML += "</style>";
      conteudoHTML += "</head>";
      conteudoHTML += "<!-- conteúdo da página do jogador 1 -->";
      conteudoHTML += "<body onload=\"runGame()\"> ";
      conteudoHTML += "<div class=\"container\">";
      conteudoHTML += "<h2>Vez do jogador 2!</h2>";
      conteudoHTML += "<div class=\"buttons\">";
      conteudoHTML += "<!-- botões das cores amarelo  = botaõ 1 , vermelho = botão 2, azul = botão 3 e verde = botão 4 -->";
      conteudoHTML += "<button onclick=\"tentativa(this.id)\" id=\"button-1\" disabled></button>";
      conteudoHTML += "<button onclick=\"tentativa(this.id)\" id=\"button-2\" disabled></button>";
      conteudoHTML += "<button onclick=\"tentativa(this.id)\" id=\"button-3\" disabled></button>";
      conteudoHTML += "<button onclick=\"tentativa(this.id)\" id=\"button-4\" disabled ></button>";
      conteudoHTML += "</div>";
      conteudoHTML += "</div>";
      conteudoHTML += "<script>";
      conteudoHTML += "var progress = [];";
      conteudoHTML += "var count = 0;";
      conteudoHTML += "function sleep(ms) {";
      conteudoHTML += "/* função assíncrona que fazer uma contagem em milisegundos para ter um funcionamento de representação de um \"timer\" */ ";
      conteudoHTML += "return new Promise(resolve => setTimeout(resolve, ms)); ";
      conteudoHTML += "}";
      conteudoHTML += "async function tentativa(id) {";
      conteudoHTML += "id = id[id.length-1];";
      conteudoHTML += "if (id == progress[count]) {";
      conteudoHTML += "document.querySelector(`#button-${id}`).style.opacity = 1;";
      conteudoHTML += "await sleep(500);";
      conteudoHTML += "document.querySelector(`#button-${id}`).style.opacity = 0.2;";
      conteudoHTML += "count++;";
      conteudoHTML += "if (progress[count] == 99) {";
      conteudoHTML += "await sleep(1000);";
      conteudoHTML += "document.location = '/end';";
      conteudoHTML += "}";
      conteudoHTML += "}";
      conteudoHTML += "else {";
      conteudoHTML += "document.querySelector('body').innerHTML = '<div style=\"width:100vw; height: 100vh; display: flex; justify-content: center; align-items: center;\"><h2 style=\"color: #000;\">Errou!</h2></div>';";
      conteudoHTML += "await sleep(1000);";
      conteudoHTML += "document.location = '/home';";
      conteudoHTML += "}";
      conteudoHTML += "}";
      conteudoHTML += "if (count == progress.length-1) {";
      conteudoHTML += "console.log('acabou');";
      conteudoHTML += "}";
      conteudoHTML += "/* função responsável por repetição das cores correspondente do dropdawn selecionado */";
      conteudoHTML += "async function runGame() { ";
      conteudoHTML += "/*  pega o valor do dropdawn e repete a quantidade de vezes das cores */";
      conteudoHTML += "let quantidade = sessionStorage.getItem('quantidade'); ";
      conteudoHTML += "for (n = 0; n < quantidade; n++) {";
      conteudoHTML += "/* sorteio de um valor entre 0 e 1, depois multiplica por 4 e arredonda para definir o relacionamento entre cores e botões */";
      conteudoHTML += "let valor = Math.ceil(Math.random()*4); ";
      conteudoHTML += "progress.push(valor);";
      conteudoHTML += "}";
      conteudoHTML += "for (n of progress) {";
      conteudoHTML += "console.log(n);";
      conteudoHTML += "await sleep(500); ";
      conteudoHTML += "document.querySelector(`#button-${n}`).style.opacity = 1;";
      conteudoHTML += "/* intervalo de tempo entre a reposta das cores selecionadas */ ";
      conteudoHTML += "await sleep(500); ";
      conteudoHTML += "document.querySelector(`#button-${n}`).style.opacity = 0.2; /* caractéristicas da opacidade das cores do botões */";
      conteudoHTML += "}";
      conteudoHTML += "progress.push(99);";
      conteudoHTML += "document.querySelector(`#button-1`).removeAttribute('disabled');";
      conteudoHTML += "document.querySelector(`#button-2`).removeAttribute('disabled');";
      conteudoHTML += "document.querySelector(`#button-3`).removeAttribute('disabled');";
      conteudoHTML += "document.querySelector(`#button-4`).removeAttribute('disabled');";
      conteudoHTML += "}";
      conteudoHTML += "</script>";
      conteudoHTML += "</body>";
      conteudoHTML += "</html>";
      return conteudoHTML;
    }
    
    /* Conteúdo da página final */
    String end() {
    
    String conteudoHTML = "<!DOCTYPE html>";
    conteudoHTML += "<html lang=\"en\">";
    conteudoHTML += "<head>";
    conteudoHTML += "<meta charset=\"UTF-8\">";
    conteudoHTML += "<meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">";
    conteudoHTML += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">";
    conteudoHTML += "<title>Fim</title>";
    conteudoHTML += "<style>";
    conteudoHTML += "* {";
    conteudoHTML += "margin: 0;";
    conteudoHTML += "}";
    conteudoHTML += "body {";
    conteudoHTML += "display: flex;";
    conteudoHTML += "width: 100vw;";
    conteudoHTML += "height: 100vh;";
    conteudoHTML += "justify-content: center;";
    conteudoHTML += "align-items: center;";
    conteudoHTML += "color: #fff;";
    conteudoHTML += "background-color: #000;";
    conteudoHTML += "}";
    conteudoHTML += ".container {";
    conteudoHTML += "height: 30%;";
    conteudoHTML += "display: flex;";
    conteudoHTML += "flex-direction: column;";
    conteudoHTML += "align-items: center;";
    conteudoHTML += "justify-content: center;";
    conteudoHTML += "}";
    conteudoHTML += "a {";
    conteudoHTML += "padding: 10px;";
    conteudoHTML += "border-radius: 10px;";
    conteudoHTML += "background-color: #fff;";
    conteudoHTML += "text-decoration: none;";
    conteudoHTML += "margin-top: 40px    ;";
    conteudoHTML += "color: #000;";
    conteudoHTML += "}";
    conteudoHTML += "</style>";
    conteudoHTML += "</head>";
    conteudoHTML += "<body>";
    conteudoHTML += "<div class=\"container\">";
    conteudoHTML += "<h2>Fim de jogo!</h2>";
    conteudoHTML += "<a href=\"/home\">Início</a>";
    conteudoHTML += "</div>";
    conteudoHTML += "</body>";
    conteudoHTML += "</html>";
    
    return conteudoHTML;
    }
    
    void setup(void) {
    /* Definição do LED e BUZZER como saídas */
      pinMode(LED, OUTPUT); 
      pinMode(BUZZER, OUTPUT);  
      Serial.begin(115200);
      WiFi.mode(WIFI_AP);
      WiFi.softAP(ssid, password); 
      delay(1000);
      IPAddress IP = IPAddress (10, 10, 10, 1);
      IPAddress NMask = IPAddress (255, 255, 255, 0);
      WiFi.softAPConfig(IP, IP, NMask);
      IPAddress myIP = WiFi.softAPIP();
      Serial.print("AP IP address: ");
      Serial.println(myIP);
      /* SETUP YOR WEB OWN ENTRY POINTS */
      /* Setando a url /home para a page do player-1 */
      server.on("/player-1", HTTP_GET, []() {
        tone(BUZZER, 700, 500);
        digitalWrite(LED, HIGH);
        delay(500);
        digitalWrite(LED, LOW);
        server.sendHeader("Connection", "close");
        server.send(200, "text/html", player1());
      });
      /* Setando a url /home para a page do player-2 */
      server.on("/player-2", HTTP_GET, []() {
        /* Toca o buzzer na frequência 700 por 1 segundo ao entrar nesta url */
        tone(BUZZER, 700, 500);
        /* Liga o led por 0,5 segundo ao entrar na url */
        digitalWrite(LED, HIGH);
        delay(500);
        digitalWrite(LED, LOW);
        server.sendHeader("Connection", "close");
        server.send(200, "text/html", player2());
      });
      /* Setando a url /home para a home page */
        server.on("/home", HTTP_GET, []() {
        server.sendHeader("Connection", "close");
        server.send(200, "text/html", home()); 
      });
      
        server.on("/end", HTTP_GET, []() {
        server.sendHeader("Connection", "close");
        server.send(200, "text/html", end());
        /* Toca o buzzer na frequência 700 por 1 segundo ao entrar nesta url */
        tone(BUZZER, 700, 1000);
        /* Liga o led por 0,5 segundo ao entrar na url */
        digitalWrite(LED, HIGH);
        delay(500);
        digitalWrite(LED, LOW);
    
      });
      /* INITIALIZE ESP2SOTA LIBRARY */
      ESP2SOTA.begin(&server);
      server.begin();
    }
    void loop(void) {
      /* HANDLE UPDATE REQUESTS */
      server.handleClient();
      /* YOUR LOOP CODE HERE */
      delay(5);
    }