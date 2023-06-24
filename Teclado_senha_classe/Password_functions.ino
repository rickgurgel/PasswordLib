
bool password_verify(char* password_INPUT,bool Admin = false) {
  int i; //variável auxiliar
  char* password_EEPROM; //guarda o passord a ser comparado 
  int pass_address;
  byte pass_length; // guarda o tamanho do password
  if (Admin) {
    pass_length = EEPROM.read(ADMIN_PASSWORD_LENGTH);
    pass_address = EEPROM.read(ADMIN_PASSWORD_ADDRESS);
    }
    else{
      pass_length = EEPROM.read(USER_PASSWORD_LENGTH);
      pass_address = EEPROM.read(USER_PASSWORD_ADDRESS);
      }
  //recebe o valor 
  password_EEPROM_read(pass_address,*password_EEPROM,pass_length);   
  
  for (int i=0;i<4;i++){
    if (password_EEPROM[i] != password_INPUT[i]){
      wrongPassword();
      return false;
      }
      else {
        if (i==3) {
          rightPassword();
        }
      }
    }
}

void rightPassword(bool Admin = false){
  Serial.println("senha correta!");
  
}

void wrongPassword(bool Admin = false){
    Serial.print("senha errada!");
    Serial.println(add_error_counter(Admin));
}



//função que lê o tamanho do password guardado na EEPROM 
byte password_length (bool Admin = false, bool test ){
  byte pass_length;
  if (Admin) {
      if (!test) pass_length = EEPROM.read(ADMIN_PASSWORD_LENGTH);
      else pass_length = 
    }
    else{
         pass_length = EEPROM.read(USER_PASSWORD_LENGTH);
      }
   return (pass_length);
}
