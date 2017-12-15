all: table
	./table > Table.txt

table : Main.cpp Tablehachage.o 
	g++ Main.cpp -o table 

Tablehachage.o : Hachage.cpp Tableau.h
	g++ -c Hachage.cpp -o Tablehachage.o

clean : 
	rm -rf *.o

Mrpropper : clean
	rm -rf table