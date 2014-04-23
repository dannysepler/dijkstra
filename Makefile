go: dijkstra.cpp
	g++ -o executable dijkstra.cpp
	./executable

gomac: dijkstra.cpp
	clang++ -std=c++11 -stdlib=libc++ dijkstra.cpp
	./a.out

clean:
	rm executable

cleanmac:
	rm a.out

tar: Makefile dijkstra.cpp inputFile.txt
	tar -cvf SeplerD_63109305 Makefile dijkstra.cpp inputFile.txt

lose-tar: SeplerD_63109305
	rm -Rf SeplerD_63109305