// pch.cpp: plik źródłowy odpowiadający wstępnie skompilowanemu nagłówkowi, niezbędny do powodzenia kompilacji

#include "pch.h"
#include<iostream>
#include<ctime>
#include<cstdlib>
#include <cstdio>

using namespace std;
extern int n;//extern-pozwolenie temu plikowi na dostęp do globalnych zmiennyh z pliku main
extern string cr, cl, cp;
extern Node *root;
void print(int tab[])//wyświetlanie tablicy 
{
	for (int i = 0; i < n; i++)
	{
		cout << tab[i] << " ";
	}
	cout << endl << endl;
}
void ascending(int tab[])//generator tablicy rosnącej
{
	int pom = 0;
	tab[0] = rand() % 100;
	for (int i = 1; i < n; i++)
	{
		pom = rand() % 10;
		tab[i] = tab[i - 1] + pom;
	}
}
class Node//deklaracja klasy node
{
public:
	int key;
	Node *left;
	Node *right;
	int height;
};
int height(Node *N)//funkcja zwracająca wysokośc danego node
{
	if (N == NULL)
		return 0;
	return N->height;
}
int max(int a, int b)//funkcja zwracającą większą spośród dwóch liczb 
{							//używana jest póżniej do balansowania drzewa
	return (a > b) ? a : b;
}

Node* newNode(int key)
{
	Node* node = new Node();
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1; // new node is initially 
					  // added at leaf  
	return(node);
}
Node *rightRotate(Node *y)//,,przekręcanie w prawo" funkcja potrzebna do balansowania drzewa
{
	Node *x = y->left;
	Node *T2 = x->right;

	// Perform rotation  
	x->right = y;
	y->left = T2;

	// Update heights  
	y->height = max(height(y->left),
		height(y->right)) + 1;
	x->height = max(height(x->left),
		height(x->right)) + 1;

	// Return new root  
	return x;
}
Node *leftRotate(Node *x)//analogicznie jak wyżej tylko że w lewo
{
	Node *y = x->right;
	Node *T2 = y->left;

	// Perform rotation  
	y->left = x;
	x->right = T2;

	// Update heights  
	x->height = max(height(x->left),
		height(x->right)) + 1;
	y->height = max(height(y->left),
		height(y->right)) + 1;

	// Return new root  
	return y;
}
int getBalance(Node *N)//funkcja zwraca różnicę wysokości prawego i lewego podrzewa
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}
Node* insert(Node* node, int key)//dodawanie nowego elementu
{
	/* 1. Perform the normal BST insertion */
	if (node == NULL)
		return(newNode(key));

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else // Equal keys are not allowed in BST  
		return node;

	/* 2. Update height of this ancestor node */
	node->height = 1 + max(height(node->left),
		height(node->right));

	/* 3. Get the balance factor of this ancestor
		node to check whether this node became
		unbalanced */
	int balance = getBalance(node);

	// If this node becomes unbalanced, then  
	// there are 4 cases  

	// Left Left Case  
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	// Right Right Case  
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	// Left Right Case  
	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case  
	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	/* return the (unchanged) node pointer */
	return node;
}
// A utility function to print preorder  
// traversal of the tree.  
void preOrder(Node *root)
{
	if (root != NULL)
	{
		cout << root->key << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}
void print_tree(string sp, string sn, Node *v)//funkcja wywietlająca graficzną
{											//reprezentację struktury drzewa 
	string s;								//w miejsce sp i sn wstawić ""
	if (v)
	{
		s = sp;
		if (sn == cr)
			s[s.length() - 2] = ' ';
		print_tree(s + cp, cr, v->right);
		s = s.substr(0, sp.length() - 2);
		cout << s << sn << (v->key) << endl;

		s = sp;
		if (sn ==cl) s[s.length() - 2] = ' ';
		print_tree(s + cp, cl, v->left);


	}
}
void tablica()
{
	
	int *tab1 = new int[n];
	ascending(tab1);
	cout << "Twoja tablica: " << endl;
	print(tab1);
	for (int i = 0; i < n; i++)
		root = insert(root, tab1[i]);
	cout << "Twoje drzewo" << endl;
	print_tree("", "", root);
}