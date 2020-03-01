all:		Graph	BFS_Directed

Graph:		Graph.o
		g++  Graph.o	-o Graph

Graph.o:	Graph.cpp
		g++ -c Graph.cpp

BFS_Directed:		BFS_Directed.o
		g++  BFS_Directed.o	-o BFS_Directed

BFS_Directed.o:	BFS_Directed.cpp
		g++ -c BFS_Directed.cpp

clean:		
		rm -f *.o Graph
		rm -f *.o BFS_Directed
