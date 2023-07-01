// aqui serão colocadas as funções finalizadas específicas da classe
// exemplo: todas as funções get e let das propriedades
// dados iniciais do teclado 4x4
// funções de teste
//todos os métodos

//endereços reservados da EEPROM:
//há endereços da EEPROM que serão utilizados pelo sistema, 
//utilizados para guardas informações importantes que não devem ser perdidas caso haja uma falha no suprimento de energia.
const int USER_PASSWORD_ADDRESS = 100; //endereço 100 a 107 (oito posições reservadas) para a senha do usuário
const int USER_COUNTER_ADDRESS = 110;  //endereço da EEPROM para guardar a contagem de erro para a senha do usuário
const int USER_PASSWORD_LENGTH = 120;  //endereço da EEPROM para guardar o número de caracteres da senha de usuário
const int USER_RESET_TIMEOUT = 130;    //endereço que guarda o tempo em segundos para o desbloqueio por tempo da digitação errada da senha do usuário 
const int USER_BLOCKED = 140;        //endereço que guarda a informação que a senha do usuário está bloqueada
const int ADMIN_PASSWORD_ADDRESS = 200; //endereço 200 a 207 (oito posições reservadas) para a senha do administrador
const int ADMIN_COUNTER_ADDRESS = 210;  //endereço da EEPROM para guardar a contagem de erro para a senha do administrador
const int ADMIN_PASSWORD_LENGTH = 220; //endereço da EEPROM para guardar o número de caracteres da senha do administrador
const int ADMIN_RESET_TIMEOUT = 230;    //endereço que guarda o tempo em segundos para o desbloqueio por tempo da digitação errada da senha do administrador 
const int ADMIN_BLOCKED = 240;        //endereço que guarda a informação que a senha do administrador está bloqueada

//valores iniciais das variáveis para teste
int password_User = "1234";    //endereço EEPROM: USER_PASSWORD_ADDRESS
int errorCountUser = 0;        //endereço EEPROM: USER_COUNTER_ADDRESS
byte passwordUserLength = 4;   //endereço EEPROM: USER_PASSWORD_LENGTH
int UserResetTimeout = 10;     //endereço EEPROM: USER_RESET_TIMEOUT
int password_Admin ="ABCD";    //endereço EEPROM: ADMIN_PASSWORD_ADDRESS
int errorCountAdmin = 0;       //endereço EEPROM: ADMIN_COUNTER_ADDRESS
byte passwordAdminLength = 4;  //endereço EEPROM: ADMIN_PASSWORD_LENGTH
int AdminResetTimeout = 10;    //endereço EEPROM: ADMIN_RESET_TIMEOUT
int UserResetMode = false;     //endereço EEPROM: USER_RESET_MODE
boolean userBlocked = false;   //endereço EEPROM: USER_BLOCKED
boolean adminBlocked = false;  //endereço EEPROM: ADMIN_BLOCKED

const byte Linhas = 4; //4 Linhas do teclado matricial
const byte Colunas = 4; //4 Colunas do teclado matricial

byte PinoLinha[Linhas] = {
  9, 8, 7, 6}; //Pinos que serao conectados as linhas do teclado
byte PinoColuna[Colunas] = {
  5, 4, 3, 2}; //Pinos que serao conectados as colunas do teclado

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

//método inicial - "init()" - verifica se há configuração guardada - se não tiver reseta todas as variáveis de controle
//a verificação se dá lendo o primeiro endereço de memória "0", "1" e "2": se for o número "2","3" e "4", é que o sistema foi inicializado;
//senão, inicializa todas as variáveis de controle com valores padrão
//os valores padrão são os seguintes

void init(byte pinoLinha1 = 9,byte pinoLinha1 = 8,byte pinoLinha1 = 7,byte pinoLinha1 = 6,byte pinoColuna1 = 5,byte pinoColuna1 = 4,byte pinoColuna1 = 3,byte pinoColuna1 = 2){
  if ((EEPROM.read(0)='2')&&(EEPROM.read(1)='3')&&(EEPROM.read(2)='4')){
    
  }
  else {
    EEPROM.update(0,'2');
    EEPROM.update(1,'3');
    EEPROM.update(2,'4');
    
  }
}

char get_password_User_Char(byte posicao) { //posicao - indica a posição inicial do 
  
}
