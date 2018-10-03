all: testFileConteneurTD_Positions

testFileConteneurTD_Positions: testFileConteneurTD_Positions.o File.o ConteneurTD.o Position.o
	g++ -g testFileConteneurTD_Positions.o File.o ConteneurTD.o Position.o -o testFileConteneurTD_Positions.exe

testFileConteneurTD_Positions.o: testFileConteneurTD_Positions.cpp File.h 
	g++ -g -c testFileConteneurTD_Positions.cpp
	
File.o: File.cpp File.h Item.h 
	g++ -g -c File.cpp
	
ConteneurTD.o: ConteneurTD.cpp ConteneurTD.h Item.h
	g++ -g -c ConteneurTD.cpp
	
Position.o: Position.cpp Position.h 
	g++ -g -c Position.cpp
