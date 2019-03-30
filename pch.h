// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln

#ifndef PCH_H
#define PCH_H

#include<iostream>
#include<ctime>
#include<cstdlib>
#include <cstdio>
#include<string>
using namespace std;
void print(int tab[]);	//wyświetla tablice
void ascending(int tab[]);//generator tablicy rosnącej
int max(int a, int b);	//zraca większą spośród dwóch liczb
class Node;				//klasa node jest podstawą drzewa
Node* newNode(int key);
int height(Node *N);	//zwraca wysokość danego node
Node *rightRotate(Node *y);//do balansowania drzewa
Node *leftRotate(Node *x);//tak samo
int getBalance(Node *N);//tak samo
Node* insert(Node* node, int key);//odpowiada a dodawanie drzewa
// A utility function to print preorder  
// traversal of the tree.  
void preOrder(Node *root);
void inOrder(Node *root);
void postOrder(Node *root);
void print_tree(string sp, string sn, Node *v);//wyświtla gaficzną reprezentacje drzewa
void tablica();

Node * minValueNode(Node* node);
Node* deleteNode( Node* root, int key);
/* Recursive function to delete a node with given key 
from subtree with given root. It returns root of the modified subtree. */
void deletePostOrder(Node* node);

#endif //PCH_H
