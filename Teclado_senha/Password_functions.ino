boolean verificar_senha (char password_EEPROM[8],char password_INPUT [8]) {
  
  for (int i=0;i<4;i++){
    if (password_EEPROM[i] == password_INPUT[i]){
      if (i==3) senha_correta();
      else senha_errada();
    }
  }
}

void senha_correta(){
    Serial.println("senha correta!");
  
}

void senha_errada(){
    Serial.print("senha errada!");
    Serial.println(++contador_erro);
}
