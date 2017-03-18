juego: main.o BTree.o BTreeNode.o BTreePrinter.o
	g++ main.o BTree.o BTreeNode.o BTreePrinter.o -o game
main.o:	main.cpp BTree.h BTreeNode.h BTreePrinter.h
	g++ -c main.cpp
BTree.o:	BTree.cpp BTree.h BTreePrinter.h
	g++ -c BTree.cpp
BTreeNode.o:	BTreeNode.cpp BTreeNode.h BTree.h BTreePrinter.h
	g++ -c BTreeNode.cpp
BTreePrinter.o:	BTreePrinter.cpp BTreePrinter.h BTree.h