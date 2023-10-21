
Ass4: Map.o Robot.o Game.o main.o
	g++ Map.o Robot.o Game.o main.o -o Ass4

Game.o: Game.cpp Game.h
	g++ -c Game.cpp Game.h

Robot.o: Robot.cpp Robot.h
	g++ -c Robot.cpp Robot.h
	
Map.o: Map.cpp Map.h
	g++ -c Map.cpp Map.h

main.o: main.cpp Map.h Game.h 
	g++ -c main.cpp Map.h Game.h 


clean:
	rm -f *.o Ass4
