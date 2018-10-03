all: testConteneurTDE_Positions

testConteneurTDE_Positions: testConteneurTDE_Positions.o ConteneurTDE.o Position.o
	g++ -g testConteneurTDE_Positions.o ConteneurTDE.o Position.o -o testConteneurTDE_Positions.exe

testConteneurTDE_Positions.o: testConteneurTDE_Positions.cpp ConteneurTDE.h 
	g++ -g -c testConteneurTDE_Positions.cpp
	
ConteneurTDE.o: ConteneurTDE.cpp ConteneurTDE.h Item.h
	g++ -g -c ConteneurTDE.cpp
	
Position.o: Position.cpp Position.h 
	g++ -g -c Position.cpp


