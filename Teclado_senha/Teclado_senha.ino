#include <Keypad.h>
#include <EEPROM.h>

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

int password_User;          //endereço EEPROM: 100
int errorCountUser = 0;     //endereço EEPROM: 110
byte passwordUserLength;    //endereço EEPROM: 111
int password_Admin;         //endereço EEPROM: 200
int errorCountAdmin;        //endereço EEPROM: 210
byte passwordAdminLength;   //endereço EEPROM: 211
char password [8];          
int resetMode;
int resetTime;
boolean userBlocked;
boolean adminBlocked;

//char senha_gravada[4] = "1234"; //trocar para EEPROM
//char senha_digitada[4] = "";
byte contador_digitacao = 0; 
//byte contador_erro = 0;

void setup()
{
  Serial.begin(9600);
  Serial.println("www.usinainfo.com.br");
  //caso o valor guardado para paswordUserLength da EEPROM - endereço: 110 - não esteja dentro dos limites estabelecidos
  if (EEPROM.read(111)<4 || EEPROM.read(111)>8){
    passwordUserLength = 4;
    EEPROM.update(111,4);
  }
  else {passwordUserLength = EEPROM.read(111);}

  //caso o valor guardado para errorCountUser da EEPROM - endereço: 110 - não esteja dentro dos limites estabelecidos
  //zera o valor e atualiza a EEPROM para 0, senão carrega o valor guardado.
  if (EEPROM.read(110)<0 || EEPROM.read(110)>4){
    errorCountUser = 0;
    EEPROM.update(111,0);
  }
  Else {errorCountUser = EEPROM.read(111);}
}

void loop(){
  char Valor = Teclado.getKey();

  if (Valor){
    Serial.println(Valor);
    digitacao(Valor,false);
  }
}

void digitacao (char valor, boolean admin) {
  int address //valor do endereço da senha EEPROM 
  if (admin) address = 200;
  Else address = 100;
  password [contador_digitacao] = valor;
  contador_digitacao ++;
  if (contador_digitacao > 3) {
    if (verificar_senha(password.EEPROM.read(address),password)) senha_correta();
    else senha_errada();
    contador_digitacao = 0;
  }
   
  
}
