# PasswordLib
	Biblioteca de gerenciamento de senhas para teclado matricial 4x4, para arduino.
#Objetivo: 
	Preparar uma biblioteca que utiliza um teclado Matricial 4x4 para digitação de senhas. Terá funções para ser capaz de ler/gravar senhas na memória EEPROM do Arduino e comparar com a digitação realizada.
# Bibliotecas utilizadas
	Utiliza como base as seguintes bibliotecas:
		- Keypad versão 3.1.1 (disponível para instalação no gerenciador de biblioteca do Arduino 1.8.19)


# Conceitos Básicos
	- senha de administrador - senha utilizada para recursos avançados de segurança
	- senha de usuário - senha normal de uso. A senha do administrador só será considerada correta para uso normal se não houver senha de usuário cadastrada.
	- bloqueio de teclado para usuário - o teclado passa a não mais aceitar a digitação de senha de usuário.
	- bloqueio de teclado para administrador - o teclado fica completamente inoperante para digitação de senhas ou comandos
	- tempo para "reset" de bloqueio de teclado - é o tempo para que o seistema volte automaticamente a aceitar novamente a digitação de senhas após um bloqueio de teclado


# Propriedade e Funções planejadas
    Irá aprimorar a classe keypad da biblioteca keypad. Nome sugerido: "passwordKeypad" 

	Vai herdar todas as características da classe keypad e incluir:
		- Propriedades novas: (ideias a aprimorar)
* int password_User - guarda endereço da EEPROM onde estará registrada a senha de usuário (default: 100)
* int password_Admin - guarda o endereço da EEPROM onde estará registrada a senha de administrador (default: 200)
* int errorCount - guarda o número de digitação de senhas erradas (inicial: 0)
* byte passwordLength - guarda o número de dígitos da senha (mínimo 4 dígitos - máximo 8 dígitos) (default: 4)
* char password [8] - guarda a senha digitada (mínimo 4 dígitos - máximo 8 dígitos)
* int resetMode - configura o modo de reset de bloqueio (0 - só com senha do administrador, 1 - por tempo ou senha do administrador) (Observação: caso erre várias vezes a senha do administrador, utiliza o bloqueio de tempo sempre)
* int resetTime - configura o tempo do reset de bloqueio em segundos (default: 600 ou seja 10 minutos)
* boolean userBlocked - guarda o status de "bloqueio de teclado" para usuário (default: false)
* boolean adminBlocked - guarda o status de "bloqueio de teclado" para administrador (default: false)

		- métodos novos (ideias a aprimorar)
* passwordUserWrite () - (método let) escreve o password no endereço informado (propriedade "passwordUser") 
* passwordUserRead () - (método get) lê a senha digitada no endereço informado (propriedade "passwordUser")
* passwordAdminWrite () - (método let) escreve o password no endereço informado (propriedade "passwordAdmin") 
* passwordAdminRead () - (método get) lê a senha digitada no endereço informado (propriedade "passwordAdmin")

* ErrorCountReset () - reseta o contador de erros (propriedade "errorcount")
* passwordReceive () - coloca o arduino no modo de receber senha (digitar "*" para retornar um dígito ou "#" para cancelar digitação)

* resetTimeWrite () - altera o tempo de bloqueio (mínimo 10 segundos - máximo 6000 ou 100 minutos) 
* resetTimeRead () - altera o tempo de bloqueio (mínimo 10 segundos - máximo 6000 ou 100 minutos)
* blockUserRemove () - desbloqeia a digitação , alteando a propriedade "userBlocked" para false (função utilizada para desbloquear o teclado utilizando um meio alternativo - tipo sofware próprio com bluetooth/ controle remoto/ leitor de cartão / etc) 
* blockAdminRemove () - bloqueia a digitação, alterando a propriedade "adminBlocked" para false (função utilizada para desbloquear o teclado utilizando um meio alternativo - tipo sofware próprio com bluetooth/ controle remoto/ leitor de cartão / etc) 
* blockUser () - desbloqeia a digitação , alteando a propriedade "userBlocked" para true (o bloqueio inicialmente pode ser automático por exemplo com erros de digitação ou remoto, por outros meios tipo bluetooth ou comando de teclado) 
* blockAdmin () - bloqueia a digitação, alterando a propriedade "adminBlocked" para True (o bloqueio inicialmente pode ser automático por exemplo com erros de digitação ou remoto, por outros meios tipo bluetooth ou comando de teclado) 
* passwordAdminReset - reseta o password de administrador para a "configuração de fábrica". O sistema solicitará nova senha e funcionará apenas quando for cadastrada.
* passwordUserReset - reseta o password de usuário para "configuração de fábrica". O sistema passará a funcionar apenas com a senha do administrador. 

