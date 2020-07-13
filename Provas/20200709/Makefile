GCC = g++
GCC_FLAGS = -std=c++11 -I include
PROG_NAME = exerc

$(PROG_NAME): produto.o estabelecimento.o cliente.o main.o
	$(GCC) $(GCC_FLAGS) -o $(PROG_NAME) produto.o estabelecimento.o cliente.o main.o

main.o: src/main.cpp 
	$(GCC) $(GCC_FLAGS) -c src/main.cpp

cliente.o: src/cliente.cpp include/cliente.h
	$(GCC) $(GCC_FLAGS) -c src/cliente.cpp

estabelecimento.o: src/estabelecimento.cpp include/estabelecimento.h
	$(GCC) $(GCC_FLAGS) -c src/estabelecimento.cpp

produto.o: src/produto.cpp include/produto.h
	$(GCC) $(GCC_FLAGS) -c src/produto.cpp

clean:
	rm *.o $(PROG_NAME)