machin.out : main.o Animal.o Attaque.o Lion.o Ours.o Pierre.o Wolf.o
	g++ -o machin.out main.o Animal.o Attaque.o Lion.o Ours.o Pierre.o Wolf.o

main.o : main.cpp 
	g++ -c main.cpp

Animal.o : Animal.cpp	
	g++ -c Animal.cpp

Attaque.o : Attaque.cpp 
	g++ -c Attaque.cpp 

Lion.o : Lion.cpp 
	g++ -c Lion.cpp

Ours.o : Ours.cpp 
	g++ -c Ours.cpp

Pierre.o : Pierre.cpp 
	g++ -c Pierre.cpp

Wolf.o : Wolf.cpp 
	g++ -c Wolf.cpp


