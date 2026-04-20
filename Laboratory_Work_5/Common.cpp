#include <iomanip>

#include "Common.h"


int GetValue()
{
	int value;
	std::cout << " Введите значение:" << std::endl;
	std::cin >> value;

	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		std::cout << "Ошибка. Вам нужно ввести числа, подобные -1 до 6.\n";
		return GetValue();
	}

	return value;
}


void BinaryTreeMenu(BinaryTree* binaryTree)
{
	enum class Menu
	{
		Exit = 0,
		Add = 1,
		Remove = 2,
		FindElement = 3,
		FindMaxElement = 4,
		FindMinElement = 5,
	};

	int userChoose;
	bool endProgramm = false;
	int data;

	while (!endProgramm)
	{
		std::cout << "Бинарное дерево\n" << std::endl;
		ShowBinaryTree(binaryTree->Root, 3);

		std::cout << "\n 1 - Добавить элемент в дерево \n"
			<< " 2 - Удалить из формы\n"
			<< " 3 - Найти элемент\n"
			<< " 4 - Найти максимальное значение \n"
			<< " 5 - Найти минимальное значение \n"
			<< " 0 <- Вернуться обратно в главное меню\n"
			<< std::endl;

		int userChoose = GetValue();

		switch (static_cast<Menu>(userChoose))
		{
		case Menu::Add:
		{
			data = GetValue();

			AddElement(binaryTree->Root, data);
			break;
		}
		case Menu::Remove:
		{
			data = GetValue();
			bool success = true;

			RemoveElement(binaryTree->Root, data, success);
			if (!success)
			{
				std::cout << "Невозможно удаление. "
					<< "Элемент не содержит"
					<< std::endl;

				system("pause");
			}
			break;
		}
		case Menu::FindElement:
		{
			data = GetValue();

			if (!FindElement(binaryTree->Root, data))
			{
				std::cout << "Не найден(" << std::endl;
				system("pause");
				break;
			}

			std::cout << " Элемент в памяти: "
				<< FindElement(binaryTree->Root, data) << std::endl;

			system("pause");
			break;
		}
		case Menu::FindMaxElement:
		{
			if (!FindBiggestElement(binaryTree->Root))
			{
				std::cout << "Пустое дерево!" << std::endl;
				system("pause");
				break;
			}

			std::cout << " Максимальное значение адрес: "
				<< FindBiggestElement(binaryTree->Root)
				<< "( ЗНАЧЕНИЕ: " << FindBiggestElement(binaryTree->Root)->Data
				<< " )" << std::endl;


			system("pause");
			break;
		}
		case Menu::FindMinElement:
		{
			if (!FindSmallestElement(binaryTree->Root))
			{
				std::cout << "Empty tree!" << std::endl;
				system("pause");
				break;
			}

			std::cout << " Наименьшее значение адрес: "
				<< FindSmallestElement(binaryTree->Root)
				<< "( ЗНАЧЕНИЕ: " << FindSmallestElement(binaryTree->Root)->Data
				<< " )" << std::endl;

			system("pause");
			break;
		}
		case Menu::Exit:
		{
			endProgramm = true;
			break;
		}
		default:
		{
			std::cout << "Неизвестная команда. Используй одно из формы." << std::endl;
			system("pause");
			break;
		}
		}
		system("cls");
	}
}


void TreapMenu(TreapNode* node)
{
	enum class TreapMenu
	{
		Exit = 0,
		AddNotOptimized = 1,
		Add = 2,
		RemoveNotOptimized = 3,
		Remove = 4,
		Find = 5
	};

	int userInput;
	bool endProgramm = false;

	while (!endProgramm)
	{
		std::cout << "Декартово дерево\n" << std::endl;
		ShowTreap(node, 3);

		std::cout << "\n1 - Добавление (не оптимизировано)\n"
			<< "2 - Добавление \n"
			<< "3 - Удаление (не оптимизировано)\n"
			<< "4 - Удаление\n"
			<< "5 - Найти элемент\n"
			<< "0 <- Вернуться в главное меню\n" << std::endl;

		userInput = GetValue();

		switch (static_cast<TreapMenu>(userInput))
		{
		case TreapMenu::AddNotOptimized:
		{
			int key = GetValue();

			AddNotOptimized(node, key);
			break;
		}
		case TreapMenu::Add:
		{
			int key = GetValue();

			AddOptimized(node, key);
			break;
		}
		case TreapMenu::RemoveNotOptimized:
		{
			int key = GetValue();
			bool success = true;

			RemoveNotOptimized(node, key, success);
			if (!success)
			{
				std::cout << "Удаление невозможно. "
					<< "Элемента нет"
					<< std::endl;

				system("pause");
			}
			break;
		}
		case TreapMenu::Remove:
		{
			int key = GetValue();
			bool success = true;

			RemoveOptimized(node, key, success);

			if (!success)
			{
				std::cout << "Невозможно удаление. "
					<< "Элемента нет"
					<< std::endl;

				system("pause");
			}
			break;
		}
		case TreapMenu::Find:
		{
			int key = GetValue();

			if (!FindElement(node, key))
			{
				std::cout << "Элемент не найден" << std::endl;
				system("pause");
				break;
			}

			std::cout << "Элемент (ключ = " << key
				<< " ) с адресом в памяти:"
				<< FindElement(node, key) << std::endl;

			system("pause");
			break;
		}
		case TreapMenu::Exit:
		{
			endProgramm = true;
			break;
		}
		default:
		{
			std::cout << "Неизвестная команда. Используй одну из списка." << std::endl;
			system("pause");
			break;
		}
		}
		system("cls");
	}
}


void ShowTreap(TreapNode* node, int indent)
{
	if (node == nullptr)
	{
		return;
	}
	if (node->RightNode)
	{
		ShowTreap(node->RightNode, indent + 4);
	}
	if (indent)
	{
		std::cout << std::setw(indent) << ' ';
	}
	if (node->RightNode)
	{
		std::cout << " /\n" << std::setw(indent) << ' ';
	}

	std::cout << node->Key << "(" << node->Priority << ")" << "\n ";
	if (node->LeftNode)
	{
		std::cout << std::setw(indent) << ' ' << " \\\n";
		ShowTreap(node->LeftNode, indent + 4);
	}
}


void ShowBinaryTree(TreeNode* binaryTreeNode, int indent)
{
	if (binaryTreeNode == nullptr)
	{
		return;
	}
	if (binaryTreeNode->RightNode)
	{
		ShowBinaryTree(binaryTreeNode->RightNode, indent + 4);
	}
	if (indent)
	{
		std::cout << std::setw(indent) << ' ';
	}
	if (binaryTreeNode->RightNode)
	{
		std::cout << " /\n" << std::setw(indent) << ' ';
	}

	std::cout << binaryTreeNode->Data << "\n ";

	if (binaryTreeNode->LeftNode)
	{
		std::cout << std::setw(indent) << ' ' << " \\\n";
		ShowBinaryTree(binaryTreeNode->LeftNode, indent + 4);
	}
}