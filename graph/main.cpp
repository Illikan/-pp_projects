#include "graph.h"
#include <iostream>

using namespace std;

int main() {

	setlocale(LC_ALL, "ru");

	Graph a;
	Node n0("n0"), n1("n1"), n2("n2"), n3("n3"), n4("n4"), n5("n5"), n6("n6");
	a.addNode(&n0);
	a.addNode(&n1);
	a.addNode(&n2);
	a.addNode(&n3);
	a.addNode(&n4);
	a.addNode(&n5);
	a.addNode(&n6);
	a.addEdge(&n0, &n1, 5);
	a.addEdge(&n0, &n2, 8);
	a.addEdge(&n1, &n3, 12);
	a.addEdge(&n1, &n5, 9);
	a.addEdge(&n2, &n5, 4);
	a.addEdge(&n2, &n6, 2);
	a.addEdge(&n3, &n4, 3);
	a.addEdge(&n3, &n5, 6);
	a.addEdge(&n2, &n4, 8);
	a.addEdge(&n6, &n4, 7);

	cout << "Graph: " << endl;
	for (node_iterator it = a.begin(); it != a.end(); it++) {
		cout << (*it)->getName() << "  conected to:   ";
		for (node_iterator itn = (*it)->nb_begin(); itn != (*it)->nb_end(); itn++)
			cout << (*itn)->getName() << " ";
		cout << endl;
	}

	Dijkstra Dijkstra(a);
	Way way = Dijkstra.shortestWay(&n0, &n5);
	cout << way << endl;

	Graph b;
	b.addNode(&n0);
	b.addNode(&n1);
	b.addNode(&n2);
	b.addNode(&n3);
	b.addNode(&n4);
	b.addNode(&n5);
	b.addNode(&n6);
	b.addEdge(&n0, &n1);
	b.addEdge(&n0, &n2);
	b.addEdge(&n1, &n3);
	b.addEdge(&n1, &n5);
	b.addEdge(&n2, &n5);
	b.addEdge(&n2, &n6);
	b.addEdge(&n3, &n4);
	b.addEdge(&n3, &n5);
	b.addEdge(&n2, &n4);
	b.addEdge(&n6, &n4);


	node_iterator buff = b.begin();
	buff++;

	
	cout << "BFS: ";
	BFS bfs(b);

	for (node_iterator it = buff; it != b.end(); it++) {
		if (bfs.connected(&n0, *it))
			cout << (*it)->getName() << " ";
	}

	buff = b.begin();
	buff++;
    cout << endl;
	cout << "DFS: ";
	DFS dfs(b);

	for (node_iterator it = buff; it != b.end(); it++) {
		if (dfs.connected(&n0, *it))
			cout << (*it)->getName() << " ";
	}
	cout << endl;

	return 0;
}