
all: kek

kek: sqrt_solver.o tester.o main.o user_commands.o
	g++ sqrt_solver.o tester.o main.o user_commands.o -o main

main.o: main.cpp
	g++ main.cpp -c main.o

tester.o: tester.cpp tester.hpp
	g++ tester.cpp -c tester.o

sqrt_solver.o: sqrt_solver.cpp sqrt_solver.hpp
	g++ sqrt_solver.cpp -c sqrt_solver.o

user_commands.o: user_commands.cpp user_commands.hpp
	g++ user_commands.cpp -c user_commands.o

clean:
	rm -f sqrt_solver.o tester.o main.o user_commands.o main
