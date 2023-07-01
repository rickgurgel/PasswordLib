//bibliotecas utilizadas
#include <Keypad.h>
#include <EEPROM.h>

//funções externas da EEPROM
extern bool password_EEPROM_read (int address, char* passValue, int pass_length = 4);
extern bool password_EEPROM_write (char* passValue, int address,byte pass_length = 4, bool teste = true);
extern byte password_length_read (bool Admin = false);
extern byte password_counter_read (bool Admin = false);
extern byte add_error_counter(bool Admin = false, bool teste = true);
extern int password_EEPROM_address (bool Admin = false);

//funções externas da Password_functions
extern bool password_verify(char* password_INPUT,bool Admin = false);
extern void wrongPassword(bool Admin = false);
extern void rightPassword(bool Admin = false);
extern int password_length (bool Admin = false);
extern byte password_length_read (bool Admin = false);
extern byte password_counter_read (bool Admin = false);
extern int password_EEPROM_address_read (bool Admin = false);

//Cria um Objeto para o teclado
Keypad Teclado = Keypad( makeKeymap(hexaKeys), PinoLinha, PinoColuna, Linhas, Colunas); 

char* password;            //é o password digitado: não utiliza armazenamento da EEPROM         
byte contador_digitacao = 0;  //variável que conta os dígitos pressionados - deve ser zerada após digitação do comando/senha




void setup()
{
  Serial.begin(9600);
  Serial.println("setup do teste de biblioteca passwordlib");

  //reserva espeaço de memória para o password digitado
  password = (char*) malloc(sizeof(char)*8);
}

void loop(){
  char Valor = Teclado.getKey();

  if (Valor){
    Serial.println(Valor);
    digitacao(Valor,false);
  }
}

// função que servirá de base para criar o "constructor" da classe "passwordKeypad"
// argumento padrão: true - utiliza a EEPROM
// false - não utiliza EEPROM, apenas a memória RAM do arduino 
void passwordlib_begin(boolean useEEPROM = true){
  if (useEEPROM){
  // inicializa propriedades do objeto
    // propriedade paswordUserLength
    //caso o valor guardado para paswordUserLength da EEPROM no endereço escolhido na constante corespondente não esteja dentro dos limites estabelecidos
    //então ele inicializa com a menor quantidade possível: 4
    if (EEPROM.read(111)<4 || EEPROM.read(111)>8){
      passwordUserLength = 4;
      EEPROM.update(111,4);
      }
      else {passwordUserLength = EEPROM.read(111);}

    //propriedade errorCountUser
    //caso o valor guardado para errorCountUser da EEPROM - endereço escolhido da constante correspondente não esteja dentro dos limites estabelecidos
    //então zera o valor e atualiza a EEPROM para 0, senão carrega o valor guardado.
    if (EEPROM.read(USER_COUNTER_ADDRESS)<0 || EEPROM.read(USER_COUNTER_ADDRESS)>4){
      errorCountUser = 0;
      EEPROM.update(USER_COUNTER_ADDRESS,0);
      }
      else {errorCountUser = EEPROM.read(USER_COUNTER_ADDRESS);}  

    // propriedade paswordAdminLength
    //caso o valor guardado para paswordAdminLength da EEPROM no endereço escolhido na constante corespondente não esteja dentro dos limites estabelecidos
    //então ele inicializa com a menor quantidade possível: 4
    if (EEPROM.read(211)<4 || EEPROM.read(211)>8){
      passwordAdminLength = 4;
      EEPROM.update(211,4);
      }
      else {passwordUserLength = EEPROM.read(211);}

      //propriedade errorCountAdmin
      //caso o valor guardado para errorCountAdmin da EEPROM - endereço escolhido da constante correspondente não esteja dentro dos limites estabelecidos
      //então zera o valor e atualiza a EEPROM para 0, senão carrega o valor guardado.
      if (EEPROM.read(210)<0 || EEPROM.read(210)>4){
        errorCountAdmin = 0;
        EEPROM.update(210,0);
        }
        else {errorCountUser = EEPROM.read(210);}  
    }
    else {
      passwordUserLength = 4;
      errorCountUser = 0;
      passwordAdminLength = 4;
      errorCountAdmin = 0;
      errorCountUser = 0;
    }
}

void digitacao (char valor, bool admin) {
  int address; //valor do endereço da senha EEPROM 
  if (admin) address = 200;
  else address = 100;
  password [contador_digitacao] = valor;
  contador_digitacao++;
  if (contador_digitacao > 3) {
    password_verify(password,false); //verifica passord do usuário (teste)
    contador_digitacao = 0;
  }
   
  
}
