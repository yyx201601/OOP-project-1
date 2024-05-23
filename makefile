farm_simulator: main.o Animal.o Corn.o Wheat.o Farm.o Crop.o Inventory.o Player.o
	g++ -std=c++11 -o farm_simulator main.o Animal.o Corn.o Wheat.o Farm.o Crop.o Inventory.o Player.o


main.o: main.cpp Farm.h Crop.h Animal.h Player.h Inventory.h Wheat.h Corn.h
	g++ -std=c++11 -c main.cpp

Animal.o: Animal.cpp Animal.h
	g++ -std=c++11 -c Animal.cpp

Corn.o: Corn.cpp Corn.h 
	g++ -std=c++11 -c Corn.cpp

Wheat.o: Wheat.cpp Wheat.h
	g++ -std=c++11 -c Wheat.cpp

Farm.o: Farm.cpp Farm.h Wheat.h Corn.h
	g++ -std=c++11 -c Farm.cpp

Crop.o: Crop.cpp Crop.h
	g++ -std=c++11 -c Crop.cpp

Inventory.o: Inventory.cpp Inventory.h
	g++ -std=c++11 -c Inventory.cpp

Player.o: Player.cpp Player.h
	g++ -std=c++11 -c Player.cpp


clean:
	rm farm_simulator main.o Animal.o Corn.o Wheat.o Farm.o Crop.o Inventory.o Player.o