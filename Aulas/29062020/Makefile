GCC = g++
GCC_FLAGS = -std=c++11
PROG_NAME = exerc

$(PROG_NAME): App.o Time.o Date.o Diary.o Utils.o Message.o main.o
	$(GCC) $(GCC_FLAGS) -o $(PROG_NAME) App.o Time.o Date.o Diary.o Utils.o Message.o main.o

main.o: main.cpp
	$(GCC) $(GCC_FLAGS) -c main.cpp

Diary.o: Diary.cpp
	$(GCC) $(GCC_FLAGS) -c Diary.cpp

Date.o: Date.cpp
	$(GCC) $(GCC_FLAGS) -c Date.cpp

App.o: App.cpp
	$(GCC) $(GCC_FLAGS) -c App.cpp

Utils.o: Utils.cpp
	$(GCC) $(GCC_FLAGS) -c Utils.cpp

Time.o: Time.cpp
	$(GCC) $(GCC_FLAGS) -c Time.cpp

Message.o: Message.cpp
	$(GCC) $(GCC_FLAGS) -c Message.cpp
