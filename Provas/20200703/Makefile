GCC = g++
GCC_FLAGS = -std=c++11 -I include
PROG_NAME = exerc

$(PROG_NAME): App.o Timing.o Date.o Diary.o Utils.o Message.o main.o
	$(GCC) $(GCC_FLAGS) -o $(PROG_NAME) App.o Timing.o Date.o Diary.o Utils.o Message.o main.o

main.o: src/main.cpp 
	$(GCC) $(GCC_FLAGS) -c src/main.cpp

Diary.o: src/Diary.cpp include/Diary.h
	$(GCC) $(GCC_FLAGS) -c src/Diary.cpp

Date.o: src/Date.cpp include/Date.h
	$(GCC) $(GCC_FLAGS) -c src/Date.cpp

App.o: src/App.cpp include/App.h
	$(GCC) $(GCC_FLAGS) -c src/App.cpp

Utils.o: src/Utils.cpp include/Utils.h
	$(GCC) $(GCC_FLAGS) -c src/Utils.cpp

Timing.o: src/Timing.cpp include/Timing.h
	$(GCC) $(GCC_FLAGS) -c src/Timing.cpp

Message.o: src/Message.cpp include/Message.h
	$(GCC) $(GCC_FLAGS) -c src/Message.cpp

clean:
	rm *.o $(PROG_NAME)