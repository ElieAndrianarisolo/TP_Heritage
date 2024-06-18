CPPFLAGS= -ansi -pedantic -Wall -std=c++11 -g

trajets : Main.o TrajetSimple.o Trajet.o Maillon.o ListeTrajets.o TrajetCompose.o Affichage.o Catalogue.o
	@echo "Edition des liens de trajets"
	g++ -o $@ $^

%.o : %.cpp %.h
	@echo "Compilation de $<"
	g++ -c $< $(CPPFLAGS)