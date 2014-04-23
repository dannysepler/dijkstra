go: dijkstra.cpp
	g++ -o executable dijkstra.cpp
	./executable

clean:
	rm executable

tar: Makefile dijkstra.cpp inputFile.txt
	tar -cvf SeplerD_63109305 Makefile dijkstra.cpp inputFile.txt

lose-tar: SeplerD_63109305
	rm -Rf SeplerD_63109305