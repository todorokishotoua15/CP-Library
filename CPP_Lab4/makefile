main: FlightSimple.o GameConsole.o RandomWalk.o Main.o
	  g++ FlightSimple.o GameConsole.o RandomWalk.o Main.o

Main.o: Main.cpp
		g++ -c Main.cpp

FlightSimple.o: FlightSimple.cpp
		g++ -c FlightSimple.cpp

GameConsole.o: GameConsole.cpp
		g++ -c GameConsole.cpp

RandomWalk.o: RandomWalk.cpp
		g++ -c RandomWalk.cpp

clean:
		rm *.o