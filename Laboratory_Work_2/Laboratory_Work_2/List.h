#pragma once
#include "Node.h"

struct List
{
private:

	/// <summary>
	/// поле указателя начального узла
	/// </summary>
	Node* _head = nullptr;

	/// <summary>
	/// поле указателя конечного узла
	/// </summary>
	Node* _tail = nullptr;

	/// <summary>
	/// поле количества элементов в списке
	/// </summary>
	int _size;
public:
	int GetSize();

	/// <summary>
	/// Инициализация односвязного списка
	/// </summary>
	/// <param name="size">размер списка</param>
	List(int size);

	/// <summary>
	/// получение указателя на начальный узел
	/// </summary>
	/// <returns>указатель на начальный узел</returns>
	Node* GetHead();

	/// <summary>
	/// получение указателя на конечный узел
	/// </summary>
	/// <returns>указатель на конечный узел</returns>
	Node* GetTail();

	/// <summary>
	/// получение указателя узла по индексу
	/// </summary>
	/// <param name="index">индекс узла</param>
	/// <returns>указатель узла</returns>
	Node* GetNodeByIndex(int index);

	/// <summary>
	/// вставка узла после узла с заданным значением
	/// </summary>
	/// <param name="valueAfter">значение узла, после которого нужно вставить</param>
	/// <param name="node">новый узел для вставки</param>
	/// <returns>true - удалось вставить, false - узел с таким значением не найден</returns>
	bool InsertAfter(int valueAfter, Node* node);

	/// <summary>
	/// добавление узла на индексе
	/// </summary>
	/// <param name="node">новый узел</param>
	/// <param name="index">индекс добавления</param>
	/// <returns>true - удалось добавить элемент, а
	/// false - индекс выходит за диапазоны списка</returns>
	bool AddNode(Node* node, int index);

	/// <summary>
	/// удаление узла по индексу
	/// </summary>
	/// <param name="index">индекс узла</param>
	/// <returns>true - удалось удалить элемент, а
	/// false - индекс выходит за диапазоны списка</returns>
	bool RemoveNodeByIndex(int index);

	/// <summary>
	/// удаление узла по значению
	/// </summary>
	/// <param name="value">значение узла</param>
	void RemoveNodeByValue(int value);

	/// <summary>
	/// сортировка списка
	/// </summary>
	void Sort();

	/// <summary>
	/// поиск узла по значению
	/// </summary>
	/// <param name="value">значение возможного узла</param>
	/// <returns>узел, который найден</returns>
	Node* FindNodeByValue(int value);

	/// <summary>
	/// очистка списка от всех элементов
	/// </summary>
	void Clean();
};