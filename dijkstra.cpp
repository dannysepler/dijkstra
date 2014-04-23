// DANNY SEPLER
// 6310-9305
// COP3530 SP 14
// Homework 6

/////////// INITIAL DECLARATIONS
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

////////// FUNCTION TO PRINT
void printpath(vector<int> path) {
	int count = 0;
	
    for (int i : path) {
    	if (!count) cout << path << ": ";
    	else if (count == 1) cout << path;
  		else cout << " -> " << path;
    }	

    cout << endl;

}


/////////// RECURSIVE FUNCTION
vector<int> search(int board[][9], vector<int> path, int current, int dest, int val ) {
	// 	details:
	// 		dest is the # we want a path to
	// 		should return the value so far

	// base case
	if ( current == dest ) {
		path.push_back(current);
		return path;
	}

	/*
	int count = 0;
	for (int j = 0; j < 9; j++)
		// search for all twos
		if ( board[2][j] == end ) 
			count++;

	if (count == 1) 
	*/

	return 0;
}

//////////// ITERATES FOR EACH LINE OF OUTPUT
void find(int board[][9], int start, int end) {
	// recursively uses search() to compare the distances
	
	/////////// initializing vector
	vector<int> path; 
	path.push_back(0); // this first value will be the cost function
	path.push_back(start);

	/////////// the loop
	for (int j = 0; j < 9; j++) {
		// search for all twos
		if ( board[2][j] == end ) {
		}
	}




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
	
	cout << endl; // to look clean

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
	printBoard(board, 3, edges); cout << endl;

	/////////////////// FINDING ROUTES
	for (int i = 1; i < 2; i++)
		find( board, 1, i );
	
	/////////////////// DONE!
	cout << endl;
	return 0;
}