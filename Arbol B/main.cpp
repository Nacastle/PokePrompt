#include <iostream>
#include "BTree.h"
#include "BTreeNode.h"
#include "BTreePrinter.h"
using namespace std;

int main()
{
	//BTree t(3);
	//t.insert(10);
	//t.insert(20);
	//t.insert(5);
	//t.insert(6);
	//t.insert(12);
	//t.insert(30);
	//t.insert(7);
	//t.insert(17);


	BTreePrinter printer;
	BTree t(2);

	srand(29324);

	for (unsigned i = 1; i <= 10; ++i)
	{
		int p = rand() % 100;
		std::cout << "\ninsertando... " << p << "...\n\n";
		t.insert(p);
		printer.print(t);
	}

	/*
	cout << "Arbol construido es " << endl;
	t.traverse();

	cout << endl;
	t.remove(17);
	cout << "Traversal del arbol despues de borrar 17" << endl;
	t.traverse();
	cout << endl;

	cout << endl;
	int k = 6;
	cout << "el numero: " << k;
	(t.search(k) != NULL)? cout << "\nPresente" << endl : cout << "\nNo esta Presente" << endl;

	k = 15;
	cout << "el numero: " << k;
	(t.search(k) != NULL)? cout << "\nPresente" << endl : cout << "\nNo esta Presente" << endl;
	*/

	return 0;
}