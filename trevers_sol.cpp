#include <iostream>
#include <fstream>
#include <stddef.h>
using namespace std;



int main(){
	int startingVertex, numberOfVertices, numberOfEdges;
	ifstream infile;
	infile.open("inputFile.txt");
	infile >> startingVertex;
	infile >> numberOfVertices;
	infile >> numberOfEdges;
	//cout << "starting vertex: " << startingVertex << "\n";
	//cout << "number of vertices: " << numberOfVertices << "\n";
	//cout << "number of edges: " << numberOfEdges << "\n";
	int** edges = new int*[numberOfEdges];
	for (int i = 0; i < numberOfEdges; i++)
	{
		edges[i] = new int[numberOfEdges];
		for (int j = 0; j < numberOfEdges; j++)
			edges[i][j] = -1;
	}
	for (int i = 0; i < numberOfEdges; i++)
	{
		int starting, next, cost;
		infile >> starting;
		infile >> next;
		infile >> cost;
		//cout << "edge " << i << " is from " << starting << " to " << next << " and costs " << cost << "\n";
		edges[starting - 1][next - 1] = cost;
	}

	bool* pathsDetermined = new bool[numberOfVertices];
	int* d = new int[numberOfVertices];
	int* p = new int[numberOfVertices];


	d[0] = 0;
	for (int i = 1; i < numberOfVertices; i++)
	{
		d[i] = edges[0][i];
		//cout << " edge " << d[i];
		p[i] = 0;
	}

	pathsDetermined[0] = true;
	int numberOfPathsDetermined = 1;
	int currentVertex = 0;
	int smallestPath = -1;
	int addedCost = 0;
	int newVertex = 0;
	while (numberOfPathsDetermined < numberOfVertices)
	for (int j = 1; j < numberOfVertices; j++)
	{
		if (pathsDetermined[j] != true){
			if (edges[currentVertex][j] != -1 && ((addedCost + edges[currentVertex][j]) < d[j] || d[j] == -1))
			{
				d[j] = addedCost + edges[currentVertex][j];
				p[j] = currentVertex;
			}
		}


		if (pathsDetermined[j] != true && d[j] != -1)
		if (smallestPath == -1){
			smallestPath = d[j];
			newVertex = j;
		}
		else if (d[j] <= smallestPath)
			newVertex = j;

		if (j == numberOfVertices - 1)
		{
			currentVertex = newVertex;
			pathsDetermined[newVertex] = true;
			numberOfPathsDetermined++;
			addedCost = d[newVertex];
			smallestPath = -1;
		}
	}

	
	cout << "1 -> 1\n";

	for (int i = 1; i < numberOfVertices; i++)
	{
		int* vList = new int[numberOfVertices];
		int nextVertice = i;
		int verticeOut = i + 1;
		vList[0] = verticeOut;
		int vNum = 1;
		while (nextVertice != 0)
		{
			nextVertice = p[nextVertice];
			vList[vNum] = nextVertice + 1;
			vNum++;
		}
		cout << 1;
		for (int j = 1; j < vNum; j++)
			cout << " -> " << vList[vNum - 1 - j];
		cout << "\n";
	}
	
}

 int output(int* pArray, int index){

	int nextVertice = index;
	int verticeOut = index + 1;
	cout << verticeOut;
		nextVertice = pArray[index];
		if (nextVertice == 1)
			cout << "";
		else
			output(pArray, nextVertice);
		cout << " -> "  << nextVertice + 1;
		return 1;
	}