all: testListeConteneurTDE_Positions

testListeConteneurTDE_Positions: testListeConteneurTDE_Positions.o Liste.o ConteneurTDE.o Position.o
	g++ -g testListeConteneurTDE_Positions.o Liste.o ConteneurTDE.o Position.o -o testListeConteneurTDE_Positions.exe

testListeConteneurTDE_Positions.o: testListeConteneurTDE_Positions.cpp Liste.h 
	g++ -g -c testListeConteneurTDE_Positions.cpp
	
ConteneurTDE.o: ConteneurTDE.cpp ConteneurTDE.h Item.h
	g++ -g -c ConteneurTDE.cpp
	
Liste.o: Liste.cpp Liste.h Item.h
	g++ -g -c Liste.cpp
	
Position.o: Position.cpp Position.h 
	g++ -g -c Position.cpp

