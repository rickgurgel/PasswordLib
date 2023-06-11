/*********************************
 ***Autor: Leonardo Dalla Porta****
 ***********25/05/2014*************
 *************Atenção**************
 ***O Codigo esta livre para uso,**
 *desde que seja mantida sua fonte* 
 ********e seu autor.**************
 ********Faça um bom uso***********
 ******Att. Equipe UsinaInfo*******
 *********************************/

#include <Keypad.h>

const byte Linhas = 4; //4 Linhas
const byte Colunas = 4; //4 Colunas

//Define o caractere para cada tecla
char hexaKeys[Linhas][Colunas] = {
  {
    '1','2','3','A'  }
  ,
  {
    '4','5','6','B'  }
  ,
  {
    '7','8','9','C'  }
  ,
  {
    '*','0','#','D'  }
};

byte PinoLinha[Linhas] = {
  9, 8, 7, 6}; //Pinos que serao conectados as linhas do teclado
byte PinoColuna[Colunas] = {
  5, 4, 3, 2}; //Pinos que serao conectados as colunas do teclado

//Cria um Objeto para o teclado
Keypad Teclado = Keypad( makeKeymap(hexaKeys), PinoLinha, PinoColuna, Linhas, Colunas); 

char senha_gravada[4] = "1234"; //trocar para EEPROM
char senha_digitada[4] = "";
byte contador_digitacao = 0; 
byte contador_erro = 0;

void setup()
{
  Serial.begin(9600);
  Serial.println("www.usinainfo.com.br");
  for (int i=2;i<10;i++) pinMode(i,INPUT);
}

void loop(){
  char Valor = Teclado.getKey();

  if (Valor){
    Serial.println(Valor);
    digitacao(Valor);
  }
}

void digitacao (char valor) {
  senha_digitada [contador_digitacao] = valor;
  contador_digitacao ++;
  if (contador_digitacao > 3) {
    if (verificar_senha()) senha_correta();
    else senha_errada();
    contador_digitacao = 0;
  }
   
  
}

boolean verificar_senha () {
  for (int i=0;i<4;i++){
    if (senha_gravada[i] == senha_digitada[i]){
      if (i==3) senha_correta();
      else senha_errada();
    }
  }
}

void senha_correta(){
    Serial.println("senha coreta!");
  
}

void senha_errada(){
    Serial.print("senha errada!");
    Serial.println(++contador_erro);
}
