
#include "pch.h"
#include<iostream>
#include<ctime>
#include<cstdlib>
#include <cstdio>
#include<string>
#include<sstream>//dzieki temu można przekształcać liczby zapisane w stringu na int

using namespace std;
int n = 0;
string cr, cl, cp;//zmienne znakowe do funkcji print_tree, nie dotykać !
Node *root = NULL;
int main()
{
	srand(time(NULL));
	//przypisywanie konkretnych znaków potrzebnych do wyświetlenia drzewa, nie dotykać !
	cr = cl = cp = "  ";
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;
	for (; ; )
	{

		cout << endl << "Co chcesz zrobic" << endl;
		cout << "1) Dodanie elementu do drzewa" << endl;
		cout << "2) Wyszukiwanie elementu z wyświetlanie ścieżki" << endl;
		cout << "3) Przeglądanie drzewa a)inorder b)preorder c)postorder" << endl;
		cout << "4) Tworzenie drzewa z posortowanej tablicy" << endl;
		cout << "5) Usuwanie dowolnego elementu" << endl;
		cout << "6) Usuwanie drzewa postorder" << endl;
		cout << "7) Zakoncz" << endl;
		cout << "8) Wyswietl drzewo" << endl;
		char x;
		int a;
		string b;
		cin >> x;
		while (x < 49 || x>56)
		{
			cout << "Wybierz opcje z menu powyżej" << endl;
			cin >> x;
		}
		switch (x)
		{
		case '1':
			cout << "Podaj liczby, aby zakonczyc wybierz x" << endl;
			for (; ; )
			{
				cin >> b;
				if ((b[0] == 'x') || (b[0] == 'X'))
					break;
				else
				{
					istringstream iss(b); //zamieniam liczbę, która została wczytana jako string
					iss >> a;			//na format liczbowy int
					root=insert(root, a);
				}
			}
			print_tree("", "", root);


			break;
			/*case '2':
				break;*/
			case '3':
				cin >> x;
				switch (x)
				case 'a':
                    inOrder(root);
                    cout << endl;
					break;
				case 'b':
					preOrder(root);
					cout << endl;
					break;
				case 'c':
                    postOrder(root);
                    cout << endl;
					break;


				break;
		case '4':
			//GENEROWANIE CIAGU
			cout << "Podaj ile elementow ma miec dana tablica: ";
			cin >> n;
			tablica();
			break;
			
		case '5':
			//USUSWANIE DOWOLNEGO ELEMENTU
			int key;
			cout<<"Podaj wartosc elementu jaki chcesz usunac: ";
			cin>>key;
			deleteNode(root, key);
			break;
				
		case '6':
			//USUSWANIE DRZEWA POSTORDER
			deletePostOrder(root);
			break;
			/*
			case '7':
				break;*/
			case '8':
				print_tree("", "", root);
				break; 

		}




	}
	
	getchar();//dwa getchary na końcu programu ponieważ używam visual studio i konsola zamyka się
	getchar();//w momencie zakończenia programu, w związku z czym nie mogę zobaczyć wyniku
	return 0;


}
