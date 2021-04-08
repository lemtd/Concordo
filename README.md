# Concordo

#

## Universidade Federal do Rio Grande do Norte (UFRN)
## Instituto Metrópole Digital (IMD)

<br />

### Disciplina: Linguagem de Programação I
### Professor: Isaac Franco Fernandes
### Aluna: Leticia Manuelle Tomaz Deodato (20180063452)

<br />
<br />

### 1. Sobre o projeto:
Concordo é um sistema espelhado no Discord e desenvolvido em C++ como projeto para a disciplina de Linguagem de Programação I do curso Bacharelado em Tecnologia da Informação da UFRN.
O código foi feito no REPL.it e possui 2 pastas separando os arquivos .cpp e .h, além dos arquivos makefile, script_comandos.txt, .gitignore e README.md:

- Pasta "src" possui 10 arquivos .cpp:
  - Concordo.cpp (arquivo com o código da função main);
  - Extra.cpp (arquivo contendo somente o código de funções adicionais);
  - User.cpp (arquivo com o código da classe User);
  - Message.cpp (arquivo com o código da classe Message);
  - Channel.cpp (arquivo com o código da classe base Channel);
  - Text.cpp (arquivo com o código da classe derivada Text);
  - Voice.cpp (arquivo com o código da classe derivada Voice);
  - Server.cpp (arquivo com o código da classe Server);
  - System.cpp (arquivo com o código da classe System);
  - Executor.cpp (arquivo com o código da classe Executor);

- Pasta "include" possui 9 arquivos .h:
  - Extra.h (arquivo de cabeçalho, possui a assinatura das funções adicionais);
  - User.h (arquivo de cabeçalho, possui a assinatura da classe User);
  - Message.h (arquivo de cabeçalho, possui a assinatura da classe Message);
  - Channel.h (arquivo de cabeçalho, possui assinatura da classe base Channel);
  - Text.h (arquivo de cabeçalho, possui o código da classe derivada Text);
  - Voice.h (arquivo de cabeçalho, possui o código da classe derivada Voice);
  - Server.h (arquivo de cabeçalho, possui o código da classe Server);
  - System.h (arquivo de cabeçalho, possui o código da classe System);
  - Executor.h (arquivo de cabeçalho, possui o código da classe Executor);

- makefile (arquivo de configuração que instrui o que o Make deve fazer);
- script_comandos.txt (comandos pré estabelecidos para usar ao compilar o programa);
- .gitignore;
- README.md.

#

### 2. Os itens desenvolvidos para o primeiro momento de entrega:
1. *quit*: método de saída do sistema (sem parâmetros)
    > Caso de teste: linha 07 do System.cpp

2. *create-server <email> <senha> <nome_usuario>*: método de criação do usuário, passando 03 strings como parâmetros e armazenando os dados no vector de usuário
    > Caso de teste: linha 12 do System.cpp

3. *login <email> <senha>*: método de conexão do usuário ao sistema, passando 02 strings como parâmetros e verificando a existência do usuário ao percorrer o vector de usuário
    > Caso de teste: linha 27 do System.cpp

4. *disconnect*: método de desconexão do usuário no sistema (sem parâmetros)
    > Caso de teste: linha 60 do System.cpp

5. *create-server <nome_servidor>*: método de criação de um servidor, passando 01 string como parâmetro e armazenando o dado no vector de servidores
    > Caso de teste: linha 75 do System.cpp

6. *set-server-desc <nome_servidor> <descrição>*: método de modificação da descrição de um servidor, passando 02 strings como parâmetros e verificando as permissões para tal ação
    > Caso de teste: linha 104 do System.cpp

7. *set-server-invite-code <nome_servidor> <código>*: método de alteração do código de convite de um servidor, passando 02 strings como parâmetros e verificando as permissões para tal ação
    > Caso de teste: linha 129 do System.cpp

8. *list-servers*: método de listagem dos servidores disponíveis, percorrendo o vector de servidores (sem parâmetros)
    > Caso de teste: linha 154 do System.cpp

9. *remove <nome_servidor>*: método de remoção de um servidor, passando 01 string como parâmetro e verificando a permissão para tal ação
    > Caso de teste: linha 176 do System.cpp

10. *enter-server <nome_servidor> <código>*: método de conexão de um usuário a um servidor, passando 02 strings como parâmetro e verificando as permissões para tal ação
    > Caso de teste: linha 201 do System.cpp

11. *leave-server*: método de desconexão do usuário no servidor conectado atualmente (sem parâmetros)
    > Caso de teste: linha 243 do System.cpp

12. *list-participants*: método de listagem dos participantes do servidor, percorrendo o vector de servidores e logo em seguida o vector de IDS dos participantes (sem parâmetros)
    > Caso de teste: linha 253 do System.cpp

#

### 3. Para compilar o programa:
- Terminal do REPL.it:
    - Extrair o arquivo .zip;
    - Acessar o site <repl.it>;
    - Fazer login;
    - Criar um projeto em C++;
    - No menu de arquivos, adicionar ao projeto a pasta que foi extraída;
    - Aceitar a opção de substituição do arquivo "main.cpp";
    - Selecionar a opção "Shell" (encontra-se na parte superior do terminal, ao lado de "Console");
    - Utilizar o comando "make run" no terminal para rodar o arquivo makefile que irá compilar o programa sem o script_comandos.txt;
    - Caso queira utilizar o script, utilizar comando "make" seguido de "./Concordo < script_comandos.txt".

- Terminal do Linux (considerando ter o g++ instalado):
    - Salvar o arquivo .zip dentro da pasta Documentos;
    - Extrair o arquivo .zip;
    - Abrir o terminal;
    - Utilizar o comando "ls" no terminal para listar as pastas;
    - Utilizar o comando "cd Documentos" no terminal para acessar a pasta Documentos;
    - Utilizar o comando "cd Concordo" no terminal para acessar a pasta do Concordo;
    - Utilizar o comando "make run" no terminal para rodar o arquivo makefile que irá compilar o programa sem o script_comandos.txt;
    - Caso queira utilizar o script, utilizar comando "make" seguido de "./Concordo < script_comandos.txt".

#

### 4. Roteiro:
- Ao rodar pela primeira vez o programa, o usuário deverá utilizar qualquer dos seguintes comandos:
    > quit<br />
    > create-user <email> <senha> <nome><br />
    > login <email> <senha><br />
    > disconnect<br />
    > create-server <nome_servidor><br />
    > set-server-desc <nome_servidor> "<descrição>"<br />
    > set-server-invite-code <nome_servidor> <código convite><br />
    > list-servers<br />
    > remove <nome_servidor><br />
    > enter-server <nome_servidor> <código convite><br />
    > leave-server<br />
    > list-participants

- Enviando no terminal o comando "*quit*", o usuário irá selecionar a opção de saída do Concordo:
    > quit<br />
    > Saindo do Concordo

- Enviando no terminal o comando "*create-user <email> <senha> <nome>*", o usuário irá selecionar a opção de criar um usuário no sistema:
    > create-user leticiamanuelletd@gmail.com senha Leticia Manuelle<br />
    > Usuário criado

- Caso o usuário tente criar um novo usuário com um e-mail já utilizado, o sistema retornará a seguinte mensagem:
    > create-user leticiamanuelletd@gmail.com senha Leticia Deodato<br />
    > Usuário já existe!

- Caso o usuário tente criar um novo usuário sem preencher alguns dos campos requeridos, o sistema retornará a seguinte mensagem:
    > create-user leticiamanuelletd@gmail.com senha<br />
    > Preencha todos os campos obrigatórios para poder concluir o cadastro

- Enviando no terminal o comando "*login <email> <senha>*", o usuário irá selecionar a opção de se conectar no sistema:
    > login leticiamanuelletd@gmail.com senha<br />
    > Logado como leticiamanuelletd@gmail.com

- Caso o usuário erre o e-mail ou a senha ao tentar logar, o sistema retornará a seguinte mensagem:
    > login leticiamtd@gmail.com senha<br />
    > Senha ou usuário inválidos!

    > login leticiamanuelletd@gmail.com senhaErrada<br />
    > Senha ou usuário inválidos!

- Enviando no terminal o comando "*disconnect*", o usuário irá selecionar a opção de se desconectar do Concordo:
    > disconnect<br />
    > Desconectando usuário leticiamanuelletd@gmail.com

- Caso o usuário já esteja desconectado, o sistema retornará a seguinte mensagem:
    > disconnect<br />
    > Não está conectado

- Enviando no terminal o comando "*create-server <nome_servidor>*", o usuário irá selecionar a opção de criar um servidor:
    > create-server Amigos<br />
    > Servidor criado

- Caso já exista um servidor com esse nome, o sistema retornará a seguinte mensagem:
    > create-server Faculdade<br />
    > Servidor com esse nome já existe

- Caso o usuário não preencha o nome do servidor que quer criar, o sistema retornará a seguinte mensagem:
    > create-server<br />
    > Preencha todos os campos obrigatórios para poder criar o Servidor

- Caso o usuário não esteja logado ao tentar criar o servidor, o sistema retornará a seguinte mensagem:
    > create-server Amigos<br />
    > Usuário precisa estar logado para poder criar um Servidor

- Enviando no terminal o comando "*set-server-desc <nome_servidor> "<descrição>"*", o usuário irá selecionar a opção de modificar a descrição de um servidor:
    > set-server-desc Amigos "Pessoal do colégio"<br />
    > Descrição do servidor 'Amigos' modificada!

- Caso o usuário tenha digitado o nome do servidor errado, o sistema retornará a seguinte mensagem:
    > set-server-desc AMIGOS "Pessoal do colégio"<br />
    > Servidor 'AMIGOS' não encontrado

- Caso o usuário não seja o dono/administrador do servidor em que está tentando modificar a descrição, o sistema retornará a seguinte mensagem:
    > set-server-desc Amigos "Pessoal do colégio"<br />
    > Você não pode alterar a descrição de um servidor que não foi criado por você

- Caso o usuário não esteja logado, o sistema retornará a seguinte mensagem:
    > set-server-desc Amigos "Pessoal do colégio"<br />
    > Usuário precisa estar logado para poder modificar a descrição de um servidor

- Enviando no terminal o comando "*set-server-invite-code <nome_servidor> <código>*", o usuário irá selecionar a opção de modificar o código de convite de um servidor:
    > set-server-invite-code Amigos colegio2017<br />
    > Código de convite do servidor 'Amigos' modificado!

- Caso o servidor possua já um código de convite e o usuário deseje retirá-lo, o sistema retornará a seguinte mensagem:
    > set-server-invite-code AMIGOS<br />
    > Código de convite do servidor 'Amigos' removido!

- Caso o usuário digite o nome do servidor errado, o sistema retornará a seguinte mensagem:
    > set-server-invite-code Amigos colegio<br />
    > Servidor 'Amigos' não encontrado

- Caso o usuário não seja o dono/administrador do servidor em que está tentando modificar o código de convite, o sistema retornará a seguinte mensagem:
    > set-server-invite-code Amigos colegio<br />
    > Você não pode alterar o código de convite de um servidor que não foi criado por você

- Caso o usuário não esteja logado, o sistema retornará a seguinte mensagem:
    > set-server-invite-code Amigos colegio<br />
    > Usuário precisa estar logado para poder modificar o código de convite para o servidor

- Enviando no terminal o comando "*list-servers*", o usuário irá selecionar a opção de listar todos os servidores disponíveis no sistema:
    > list-servers<br />
    > Amigos<br />
    > "Pessoal do colégio"<br />
    > colegio<br />
    > Faculdade<br />
    > "Colegas de turma"<br />
    > Servidor aberto<br />
    > Lista de servidores finalizada

- Enviando no terminal o comando "*remove <nome_servidor>*", o usuário irá selecionar a opção de remover um servidor do sistema:
    > remove Amigos<br />
    > Servidor 'Amigos' removido

- Caso o usuário digite o nome do servidor errado, o sistema retornará a seguinte mensagem:
    > remove Amigos<br />
    > Servidor 'Amigos' não encontrado

- Caso o usuário não seja o dono/administrador do servidor que está tentando remover, o sistema retornará a seguinte mensagem:
    > remove Amigos<br />
    > Você não é o dono do servidor 'Amigos'

- Caso o usuário não esteja logado, o sistema retornará a seguinte mensagem:
    > remove Amigos<br />
    > Usuário precisa estar logado para poder remover servidores do sistema

- Enviando no terminal o comando "*enter-server <nome_servidor> <código>*", o usuário irá selecionar a opção de entrar/se conectar a um servidor do sistema:
    > enter-server Amigos colegio<br />
    > Entrou no servidor com sucesso

- Caso o usuário utilize o código errado para entrar no servidor, o sistema retornará a seguinte mensagem:
    > enter-server Amigos colegio2017<br />
    > Servidor requer código de convite

- Caso o usuário digite o nome do servidor errado, o sistema retornará a seguinte mensagem:
    > enter-server AMIGOS colegio<br />
    > Servidor 'AMIGOS' não encontrado

- Caso o usuário não esteja logado, o sistema retornará a seguinte mensagem:
    > enter-server Amigos colegio<br />
    > Usuário precisa estar logado para poder acessar os servidores do sistema

- Enviando no terminal o comando "*leave-server*", o usuário irá selecionar a opção de sair/se desconectar de um servidor do sistema:
    > leave-server<br />
    > Saindo do servidor 'Amigos'

- Caso o usuário não esteja conectado a nenhum servidor, o sistema retornará a seguinte mensagem:
    > leave-server<br />
    > Usuário não está conectado a nenhum servidor

- Enviando no terminal o comando "*list-participants*", o usuário irá selecionar a opção de listar os participantes do servidor em que está conectado:
    > list-participants<br />
    > Leticia<br />
    > Manuelle<br />
    > Felipe<br />
    > Gilberto<br />
    > Lista de participantes do servidor finalizada

#

### 5. Limitações do programa:
Entrega I:
Não há limitações.

#

### 6. Limitações minhas:
Entrega I:
Encontrei dificuldade na funcionalidade *enter-server* ao tentar implementar o acesso ao vector de IDS de participantes de um servidor, por esse motivo deixei esse mesmo vector como público em sua classe.<br />
Além disso, ao colocar o arquivo para compilar com o makefile, apareceram alguns erros com relação a algumas funcionalidades adicionais, que posteriormente não foram mais utilizadas. Ainda assim, o professor indicou o que era e aonde era o erro e me ajudou a corrigí-lo.

#

### 7. Considerações finais:
O código precisa ser organizado de melhor forma futuramente.
