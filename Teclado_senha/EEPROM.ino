//EEPROM.write(address, value);
//address – posição da memória que será escrito, é um inteiro entre 0 e 1023  (UNO);
//PassValue é o ponteiro que recebe o endereço da variável que vai receber o valor da EEPROM lido
//pass_length -  tamanho da área de memória a ser lida. No caso da senha, é de 4 a 8. (caso não seja informado, é 4)

//value = EEPROM.read(address);
//address – posição da memória que será lido, é um inteiro entre 0 e 1023  (UNO);
//value -  valor do endereço da EEPROM é um inteiro entre 0 e 255 (um único byte).

//#include <EEPROM.h>


unsigned int EEPROM_int_read (int address){
  Serial.println("nLendo numero da memoria EEPROM... ");
  
  Serial.print("Lendo parte 1 : ");
  int parte1 = EEPROM.read(address);
  Serial.println(parte1);
  
  Serial.print("Lendo parte 2 : ");  
  int parte2 = EEPROM.read(address + 1);
  Serial.println(parte2);
  
  Serial.print("Valor original : ");
  int valor_original = (parte1 * 256) + parte2;
  Serial.println(valor_original);
}

//PassValue é o ponteiro que recebe o endereço da variável que vai receber o valor da EEPROM lido
bool password_EEPROM_read (int address, char* passValue, int pass_length = 4){
  if (pass_length<0 || pass_length>8){
    for (int i=0;i<pass_length;i++){
      passValue[i] = EEPROM.read(address);
    }
    return (true);  
  }
  else return (false); 
}

byte password_length_read (bool Admin = false){
  byte pass_length;
  if (Admin) {
       pass_length = EEPROM.read(ADMIN_PASSWORD_LENGTH);
    }
    else pass_length = EEPROM.read(USER_PASSWORD_LENGTH);
  if (pass_length<4 || pass_length>8){
      pass_length = 4;
    }
  return (pass_length);
}

byte password_counter_read (bool Admin = false){
  byte pass_counter;
  int address;
  if (Admin) {
    address = ADMIN_COUNTER_ADDRESS;
    pass_counter = EEPROM.read(address);
    }
    else {
      address = USER_COUNTER_ADDRESS;
      pass_counter = EEPROM.read(address);
    }
  if (pass_counter<0 || pass_counter>3){
      pass_counter = 0;
      EEPROM.update(address,0);
    }
  return (pass_counter);
}

int password_EEPROM_address_read (bool Admin = false){
  int pass_address;
  if (Admin) {
    pass_address = EEPROM_int_read (ADMIN_PASSWORD_ADDRESS);
    }
    else{
      pass_address = EEPROM_int_read (USER_PASSWORD_ADDRESS);
      }
   return (pass_address);
}

//gravar um password 
bool password_EEPROM_write (char* passValue, bool Admin = false, bool teste = true){
  if (pass_length<0 || pass_length>8){
   }
   return (false);
  }
  else {
    for (int i=0;i<pass_length;i++){
      if (!teste) {
        EEPROM.update(address + i, passValue[i]);
        delay (10); //necessário dar um tempo antes de gravar a próxima posição
      }
      else {
        Serial.print("não gravado na EEPROM - teste: ");
        if (i == 0) {
          Serial.print("endereço: ");
          }
        Serial.print(passValue[i]);
      }
  }
   Serial.println();
   return (true);
}

// grava valor inteiro na EEPROM
void EEPROM_int_write (int address, unsigned int numero) {
  Serial.print("Gravando numero na memoria EEPROM : ");
  Serial.println(numero);
  
  //Grava a primeira parte do numero em endereco1
  EEPROM.update(address, numero/256);
  Serial.print("Parte 1 : ");
  Serial.println(numero/256);
  
  //Grava a segunda parte do numero em endereco2
  EEPROM.update(address + 1, numero%256);
  Serial.print("Parte 2 : ");
  Serial.println(numero%256);    
}

byte add_error_counter(bool Admin = false, bool teste = true){
  byte error_counter;
  if (teste) {
    if (Admin) {
      error_counter = errorCountAdmin+1;
      }
      else{
        error_counter = errorCountUser+1;
        }
    return(error_counter);
  }
  else {
    if (Admin) {
      error_counter = EEPROM_int_read (ADMIN_COUNTER_ADDRESS)+1;
      EEPROM.update (ADMIN_COUNTER_ADDRESS, error_counter)
      }
      else{
        error_counter = EEPROM_int_read (USER_COUNTER_ADDRESS)+1;
        EEPROM.update (USER_COUNTER_ADDRESS, error_counter)
        }
    return(error_counter);
  }
}
