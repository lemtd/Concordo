# Compila todos os arquivos e gera o executável
all: create_dir Concordo

# Cria pasta para armazenar os arquivos objetos
create_dir:
	mkdir -p bin

bin/Extra.o: src/Extra.cpp
	g++ src/Extra.cpp -Iinclude -O0 -g -Wall -ansi -pedantic -std=c++11 -c -o bin/Extra.o

bin/User.o: src/User.cpp
	g++ src/User.cpp -Iinclude -O0 -g -Wall -ansi -pedantic -std=c++11 -c -o bin/User.o

bin/Message.o: src/Message.cpp
	g++ src/Message.cpp -Iinclude -O0 -g -Wall -ansi -pedantic -std=c++11 -c -o bin/Message.o

bin/Channel.o: src/Channel.cpp
	g++ src/Channel.cpp -Iinclude -O0 -g -Wall -ansi -pedantic -std=c++11 -c -o bin/Channel.o

bin/Text.o: src/Text.cpp bin/Channel.o bin/Message.o
	g++ src/Text.cpp -Iinclude -O0 -g -Wall -ansi -pedantic -std=c++11 -c -o bin/Text.o

bin/Voice.o: src/Voice.cpp bin/Message.o
	g++ src/Voice.cpp -Iinclude -O0 -g -Wall -ansi -pedantic -std=c++11 -c -o bin/Voice.o

bin/Server.o: src/Server.cpp
	g++ src/Server.cpp -Iinclude -O0 -g -Wall -ansi -pedantic -std=c++11 -c -o bin/Server.o

bin/System.o: src/System.cpp bin/User.o bin/Server.o
	g++ src/System.cpp -Iinclude -O0 -g -Wall -ansi -pedantic -std=c++11 -c -o bin/System.o

bin/Executor.o: src/Executor.cpp bin/System.o
	g++ src/Executor.cpp -Iinclude -O0 -g -Wall -ansi -pedantic -std=c++11 -c -o bin/Executor.o

bin/Concordo.o: src/Concordo.cpp bin/Extra.o bin/User.o bin/Message.o bin/Channel.o bin/Text.o bin/Voice.o bin/Server.o bin/System.o bin/Executor.o
	g++ src/Concordo.cpp -Iinclude -O0 -g -Wall -ansi -pedantic -std=c++11 -c -o bin/Concordo.o

Concordo: bin/Extra.o bin/User.o bin/Message.o bin/Channel.o bin/Text.o bin/Voice.o bin/Server.o bin/System.o bin/Executor.o bin/Concordo.o
	g++ bin/*.o -Iinclude -O0 -g -Wall -ansi -pedantic -std=c++11 -o Concordo

# Executa o programa
run: all
	./Concordo

# Apaga a pasta de arquivos objetos e o executável
clean:
	rm -rf bin Concordo