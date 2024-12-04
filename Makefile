# Regra principal: compila e executa os testes
all: testa_velha
	./testa_velha

# Compila o executável principal com suporte a cobertura
testa_velha: velha.o testa_velha.o catch_amalgamated.o
	g++ -std=c++17 -Wall -ftest-coverage -fprofile-arcs velha.o testa_velha.o catch_amalgamated.o -o testa_velha

# Verificação de erros e avisos com cpplint
cpplint: testa_velha.cpp   velha.cpp velha.hpp
	cpplint   --exclude=catch_amalgamated.hpp  --exclude=catch_amalgamated.cpp testa_velha.cpp velha.cpp velha.hpp

# Compila o objeto velha.o com suporte a cobertura
velha.o: velha.cpp velha.hpp
	g++ -std=c++17 -Wall -ftest-coverage -fprofile-arcs -c velha.cpp

# Compila o objeto testa_velha.o com suporte a cobertura
testa_velha.o: testa_velha.cpp
	g++ -std=c++17 -Wall -ftest-coverage -fprofile-arcs -c testa_velha.cpp

# Compila o objeto catch_amalgamated.o com suporte a cobertura
catch_amalgamated.o: catch_amalgamated.cpp
	g++ -std=c++17 -Wall -ftest-coverage -fprofile-arcs -c catch_amalgamated.cpp

# Executa os testes
test: testa_velha
	./testa_velha

# Gera a cobertura de código usando gcov
gcov: testa_velha
	./testa_velha
	gcov velha.cpp testa_velha.cpp catch_amalgamated.cpp

# Verificação de erros e avisos com cppcheck
cppcheck:
	cppcheck --enable=warning testa_velha.cpp velha.cpp velha.hpp

# Limpeza de arquivos gerados
clean:
	rm -rf *.o *.gc* testa_velha