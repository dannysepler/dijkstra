go: dijkstra.cpp
	g++ -o d dijkstra.cpp
	./d

clean:
	rm d

tar: Makefile dijkstra.cpp inputFile.txt
	tar -cvf SeplerD_63109305 Makefile dijkstra.cpp inputFile.txt

lose-tar: SeplerD_63109305
	rm -Rf SeplerD_63109305