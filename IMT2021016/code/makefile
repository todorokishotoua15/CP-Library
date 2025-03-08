main: LibSys.o Items.o ItemTypes.o library.o
	  g++ LibSys.o Items.o ItemTypes.o library.o

library.o: library.cpp
		g++ -c library.cpp

LibSys.o: LibSys.cpp
		g++ -c LibSys.cpp

Items.o: Items.cpp
		g++ -c Items.cpp

ItemTypes.o: ItemTypes.cpp
		g++ -c ItemTypes.cpp

clean:
		rm *.o