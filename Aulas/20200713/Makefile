GCC = g++
GCC_FLAGS = -std=c++11 -I include
PROG_NAME = exerc

$(PROG_NAME): empresa.o funcionario.o main.o
	$(GCC) $(GCC_FLAGS) -o $(PROG_NAME) empresa.o funcionario.o main.o

main.o: main.cpp 
	$(GCC) $(GCC_FLAGS) -c main.cpp

cliente.o: funcionario.cpp funcioanrio.h
	$(GCC) $(GCC_FLAGS) -c funcionario.cpp

estabelecimento.o: empresa.cpp empresa.h
	$(GCC) $(GCC_FLAGS) -c empresa.cpp

clean:
	rm *.o $(PROG_NAME)
