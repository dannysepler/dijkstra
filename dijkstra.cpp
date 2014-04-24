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
void printpath(vector<int> path) {
	int count = 0;
	
    for (int i : path) {
    	if (!count) cout << i << ": ";
    	else if (count == 1) cout << i;
  		else cout << " -> " << i;
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



/////////// ALGORITHMIC FUNCTIONS
/*
vector<int> search(int board[][9], vector<int> path, 
	int current, int dest, int row ) {
	// 	details:
	// 		dest is the # we want a path to
	//		current is the # we are on
	//		row is the # row that we are on
	// 		should return the value so far

	// base case
	if ( current == dest ) {
		path.push_back(current);
		return path;
	}

	// recursive case
	current = board[2][row];
	path[0] += board[3][row];
		// cout << "\tvalue is now " << path[0] << endl;
	path.push_back( current );
		// 	cout << "\tpath is now ";
		//	printpath(path);
	vector<int> temp;

	for (int j = 0; j < 2; j++) {
		if ( board[2][j] == end ) {
			temp = search(board, path, current, end, j);
			
			if ( temp[0] < path[0] ) {
				path = temp;
			}
		}
	}



	return path;
}
*/

void find(int board[][9], int start, int end) {
	// recursively uses search() to compare the distances
	
	/////////// initializing vector
	vector<int> path; 
	path.push_back(0); 		// this first value will be the 
							// cost function
	path.push_back(start);
	
	vector<int> temp; 		// for comparing

	/////////// the loop
	for (int j = 0; j < 2; j++) {
		if ( board[2][j] == end ) {
			cout << "found match for " << end << " on row " << j << endl;

			//temp = search(board, path, start, end, j);
			
			//if ( temp[0] < path[0] ) {
			//	path = temp;
			//}
		}
	}
}

/*
//////////////// MAKE ADJANCY MATRIX
int adjancyMatrix( int[][6] board ) {
	int(*) matrix[6] = new int[6][6];

	// initialize it as blank
	for (int i = 0; i < 6; i++ )
		for (int j = 0; j < 6; j++ )
			matrix[i][j] = 0;

	// now fill in
	int a, b, val;

	for (int j = 0; j < 9; j++) {
		// get
		a = board[0][j];
		b = board[1][j];
		val = board[2][j];

		// post
		matrix[a][b] = matrix[b][a] = val;
	}

	// awesome! now we....
	return matrix;
}
*/

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
	
	///////////////////////////////
	// matrix stuff

	int matrix[6][6];

	for (int i = 0; i < 6; i++ )
		for (int j = 0; j < 6; j++ )
			matrix[i][j] = 0;

	// now fill in
	int a, b, val;

	for (int j = 0; j < 9; j++) {
		a = board[0][j] - 1; // get
		b = board[1][j] - 1;
		val = board[2][j];

		matrix[a][b] = matrix[b][a] = val; // post
	}

	// to print matrix
	printMatrix( matrix );	cout << endl;
	///////////////////////////////

	
	/////////////////// FINDING ROUTES
	//for (int i = 1; i < 5; i++)
	//	find( board, 1, i );
	
	/////////////////// DONE!
	//cout << endl;
	return 0;
}