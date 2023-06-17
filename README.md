# PasswordLib
	Biblioteca de gerenciamento de senhas para teclado matricial 4x4, para arduino.
# Objetivo: 
	Preparar uma biblioteca que utiliza um teclado Matricial 4x4 para digitação de senhas. Terá funções para ser capaz de ler/gravar senhas na memória EEPROM do Arduino e comparar com a digitação realizada.
# Bibliotecas utilizadas
	Utiliza como base as seguintes bibliotecas:

		- Keypad versão 3.1.1 (disponível para instalação no gerenciador de biblioteca do Arduino 1.8.19)


# Conceitos Básicos
	* senha de administrador - senha utilizada para recursos avançados de segurança
	* senha de usuário - senha normal de uso. A senha do administrador só será considerada correta para uso normal se não houver senha de usuário cadastrada.
	* bloqueio de teclado para usuário - o teclado passa a não mais aceitar a digitação de senha de usuário.
	* bloqueio de teclado para administrador - o teclado fica completamente inoperante para digitação de senhas ou comandos
	* tempo para "reset" de bloqueio de teclado - é o tempo para que o seistema volte automaticamente a aceitar novamente a digitação de senhas após um bloqueio de teclado


# Propriedade e Funções planejadas
    Irá aprimorar a classe keypad da biblioteca keypad. Nome sugerido: "passwordKeypad" 

	Vai herdar todas as características da classe keypad e incluir:

		- Propriedades novas: (ideias a aprimorar)
* int password_User - guarda endereço da EEPROM onde estará registrada a senha de usuário (default: 100)
* int errorCountUser - guarda o número de digitação errada de senha de usuário (inicial: 0)
* byte passwordUserLength - guarda o número de dígitos da senha de usuário (mínimo 4 dígitos - máximo 8 dígitos) (default: 4)

* int password_Admin - guarda o endereço da EEPROM onde estará registrada a senha de administrador (default: 200)
* int errorCountAdmin - guarda o número de digitação errada da senha de administrador (inicial: 0)
* byte passwordAdminLength - guarda o número de dígitos da senha do administrador (mínimo 4 dígitos - máximo 8 dígitos) (default: 4)

* char password [8] - guarda a senha digitada (mínimo 4 dígitos - máximo 8 dígitos)
* int resetMode - configura o modo de reset de bloqueio (0 - só com senha do administrador, 1 - por tempo ou senha do administrador) (Observação: caso erre várias vezes a senha do administrador, utiliza o bloqueio de tempo sempre)
* int resetTime - configura o tempo do reset de bloqueio em segundos (default: 600 ou seja 10 minutos)
* boolean userBlocked - guarda o status de "bloqueio de teclado" para usuário (default: false)
* boolean adminBlocked - guarda o status de "bloqueio de teclado" para administrador (default: false)

		- métodos novos (ideias a aprimorar)
* passwordUserWrite () - (método let) escreve o password no endereço informado (propriedade "passwordUser") 
* passwordUserRead () - (método get) lê a senha digitada no endereço informado (propriedade "passwordUser")
* passwordUserReset() - reseta o password de usuário para "configuração de fábrica". O sistema passará a funcionar apenas com a senha do administrador. 
* PasswordUserVerify() - verifica se a propriedade "password" é igual ao retornado pelo método "passwordUserRead ()"  
* ErrorCountUserReset () - reseta o contador de erros de digitação da senha de usuário (propriedade "errorcountUser" = 0)
* blockUser () - desbloqeia a digitação , alteando a propriedade "userBlocked" para true (o bloqueio inicialmente pode ser automático por exemplo com erros de digitação ou remoto, por outros meios tipo bluetooth ou comando de teclado) 
* blockUserRemove () - desbloqeia a digitação , alteando a propriedade "userBlocked" para false (função utilizada para desbloquear o teclado utilizando um meio alternativo - tipo sofware próprio com bluetooth/ controle remoto/ leitor de cartão / etc) 

* passwordAdminWrite () - (método let) escreve o password no endereço informado (propriedade "passwordAdmin") 
* passwordAdminRead () - (método get) lê a senha digitada no endereço informado (propriedade "passwordAdmin")
* PasswordAdminVerify() - verifica se a propriedade "password" é igual ao retornado pelo método "passwordAdminRead ()"  
* passwordAdminReset() - reseta a senha de usuário para "configuração de fábrica". O sistema só passará a funcionar após o cadastro da nova senha do administrador.
* ErrorCountAdminReset () - reseta o contador de erros da senha de administrador(propriedade "errorcountAdmin" = 0)
* blockAdmin () - bloqueia a digitação, alterando a propriedade "adminBlocked" para True (o bloqueio inicialmente pode ser automático por exemplo com erros de digitação ou remoto, por outros meios tipo bluetooth ou comando de teclado) 
* blockAdminRemove () - bloqueia a digitação, alterando a propriedade "adminBlocked" para false (função utilizada para desbloquear o teclado utilizando um meio alternativo - tipo sofware próprio com bluetooth/ controle remoto/ leitor de cartão / etc) 

* passwordReceive () - coloca o arduino no modo de receber senha, ou seja, receber a propriedade "passwordLength" dígitos e incluir na propriedade "password" (digitar "*" para retornar um dígito ou "#" para cancelar digitação)

* resetTimeWrite () - altera o tempo de bloqueio (mínimo 10 segundos - máximo 6000 ou 100 minutos) 
* resetTimeRead () - altera o tempo de bloqueio (mínimo 10 segundos - máximo 6000 ou 100 minutos)
