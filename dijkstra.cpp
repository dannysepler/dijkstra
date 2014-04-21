#include <iostream>
#include <fstream>

using namespace std;

int search(int board[][9], int current, int dest) {
	// dest is the number we want a path to
	// recursive!
	return 0;
}

void printBoard(int board[][9], int rows, int columns) {
	for (int j = 0; j < columns; j++) {
		for (int i = 0; i < rows; i++)
			cout << board[i][j] << " ";
		cout << endl;
	}
}

int main(int argc, char *argv[]) {

	//////////////// INITIAL DEFINITIONS
	int source, vertices, edges, temp;
	int board[3][9];
		// this will be populated by input file
		// three rows:	1) vertex 1
					//	2) vertex 2
					//	3) weight
	

	//////////////// READING TEXT FILE +
	//////////////// POPULATING ARRAY
	ifstream infile;
	infile.open("inputFile.txt");
	infile >> source >> vertices >> edges;
		// initial vars
	
	// generate board
	for (int j = 0; j < 9; j++)
		for (int i = 0; i < 3; i++)
			infile >> board[i][j];
		
	infile.close();

	// to print board --
	// printBoard(board, 3, edges);
	
	/////////////////// FINDING ROUTES

	return 0;
}