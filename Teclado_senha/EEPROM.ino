//EEPROM.write(address, value);
//address – posição da memória que será escrito, é um inteiro entre 0 e 1023  (UNO);
//value -  valor a ser armazenado inteiro entre 0 e 255 (um único byte).

//value = EEPROM.read(address);
//address – posição da memória que será lido, é um inteiro entre 0 e 1023  (UNO);
//value -  valor do endereço da EEPROM é um inteiro entre 0 e 255 (um único byte).

//#include <EEPROM.h>

byte* password_EEPROM_read (int address){
  static byte passValue[4];
  for (int i=0;i<4;i++){
    passValue[i] = EEPROM.read(address);
  }
  return (passValue); 
}

void password_EEPROM_write (int address, byte passValue[4]){
  for (int i=0;i<4;i++){
     EEPROM.read(address) = passValue[i];
  }
  return (passValue); 
}
