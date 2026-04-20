#include <iostream>
#include <locale>

#include "BinaryTree.h"
#include "Common.h"

using namespace std;


enum class StartMenu
{
	Exit		= 0,
	BinaryTree	= 1,
	Treap		= 2
};


int main()
{
	int numberOfStruct;
	
	setlocale(LC_ALL, "");

	while (true)
	{
		cout << "1 - Бинарное дерево \n"
			 << "2 - Декартово дерево\n"
			 << "0 - Выход\n" 
		     << "Выбрать команду:" << endl;

		numberOfStruct = GetValue();

		switch (static_cast<StartMenu>(numberOfStruct))
		{
			case StartMenu::BinaryTree:
			{
				BinaryTree* binaryTree = new BinaryTree;
				InitTree(binaryTree);
				BinaryTreeMenu(binaryTree);
				DeleteTree(binaryTree->Root);
				break;
			}
			case StartMenu::Treap:
			{
				Treap* treap = new Treap;
				InitTreap(treap);
				TreapMenu(treap->Root);
				DeleteTreap(treap->Root);
				break;
			}
			case StartMenu::Exit:
			{
				return 0;
			}
			default:
			{
				cout << "Неизвестная команда! Попробуйте еще раз" << endl;
				system("pause");
				break;
			}
		}
		system("cls");
	}
	return 0;
}