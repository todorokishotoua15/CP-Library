main: Main.o Cars.o Game.o Lemon.o PingPong.o Spinner.o
	  g++ Main.o Cars.o Game.o Lemon.o PingPong.o Spinner.o -o main

Main.o: Main.cpp
		g++ -c Main.cpp

Cars.o: Cars.cpp
		g++ -c Cars.cpp

Game.o: Game.cpp
		g++ -c Game.cpp

Lemon.o: Lemon.cpp
		g++ -c Lemon.cpp

PingPong.o: PingPong.cpp
		g++ -c PingPong.cpp

Spinner.o: Spinner.cpp
		g++ -c Spinner.cpp

clean:
		rm *.o