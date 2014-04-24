// DANNY SEPLER
// 6310-9305
// COP3530 SP 14
// Homework 6

/////////// INITIAL DECLARATIONS
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

////////// PRINT FUNCTIONS
void printpath( int path[] ) {
	cout << path[0] << ": ";

	int i = 1;
	while ( path[i] ) {
		if (i == 1) cout << path[i];
		else cout << " -> " << path[i];
		i++;
	}
	cout << endl;
}

void printBoard(int board[][9], int rows, int columns) {
	for (int j = 0; j < columns; j++) {
		for (int i = 0; i < rows; i++) 
			cout << board[i][j] << " ";
		cout << endl;
	}
}

void printMatrix( int matrix[][6] ) {
	for ( int i = 0; i < 6; i++ ) {
		for ( int j = 0; j < 6; j++ ) {
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
}



///////////////////////// ALGORITHMIC FUNCTIONS
void recurse( int matrix[][6], int end, int current ) {

}

void findVec( int matrix[][6], int end ) {
	//cout << "on try " << end << endl;
	/////////// initializing path
	end--; // remember we're using array notation
	int path[10];
	for (int i = 0; i < 10; i++) 
		path[i] = 0;
			// first slot = cost. every other 
			// slot is the path it takes

	path[1] = 1; // every path starts with 1

	if (end == 0) {
		path[1] = path[2] = 1;
		// { 0, 1, 1 }
		printpath( path );
		return;
	}

	// case: there's a straight path
	// and the way is lower than any other
	// possibilities in that row
	if ( matrix[0][end] ) {
		//cout << "took 2nd if" << endl;
		for (int i = 1; i < 6; i++) {
			if ( matrix[i][end] > matrix[0][end]) break;

			path[0] = matrix[0][end];
			path[2] = ++end; // switch out of array notation
			printpath( path );
			return;
		}
	}

}

//////////////// MAIN FUNCTION
int main(int argc, char *argv[]) {	
	//////////////// INITIAL DEFINITIONS
	int source, vertices, edges, temp;
	//int** board;
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
			//infile >> *( *( board + i) + j);
			//infile >> **board;
		
	infile.close();


	// to print board --
	// printBoard(board, 3, edges); cout << endl;
	
	///////////////////////////////////////////////
	// matrix stuff

	int matrix[6][6];

	for (int i = 0; i < 6; i++ )
		for (int j = 0; j < 6; j++ )
			matrix[i][j] = 0;

	// now fill in the matrix
	int a, b, val;

	for (int j = 0; j < 9; j++) {
		a = board[0][j] - 1; // get
		b = board[1][j] - 1;
		val = board[2][j];

		matrix[a][b] = matrix[b][a] = val; // post
	}

	// to print matrix
	// printMatrix( matrix );	cout << endl;
	/////////////////////////////////////////////////


	/////////////////////////////////////// FINDING ROUTES
	for (int i = 1; i < 3; i++)
	//	find( board, 1, i );
		findVec( matrix, i );

	////////////////////////////////////////	DONE!
	cout << endl;
	return 0;
}