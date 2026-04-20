#pragma once

/// <summary>
/// Узел стека
/// </summary>
class Node
{
private:
	/// <summary>
	/// Данные узла
	/// </summary>
	int _data;

	/// <summary>
	/// Следующий узел
	/// </summary>
	Node* _next;
public:
	/// <summary>
	/// Создание структуры узла
	/// </summary>
	/// <param name="data">данные узла</param>
	Node(int data);

	/// <summary>
	/// Освобождение памяти
	/// </summary>
	~Node();

	/// <summary>
	/// Получение данных узла
	/// </summary>
	/// <returns>данное узла</returns>
	int GetData();

	/// <summary>
	/// Возвращение следующего узла
	/// </summary>
	/// <returns>следующий узел</returns>
	Node* GetNext();

	/// <summary>
	/// Установка следующего узла
	/// </summary>
	/// <param name="node">следующий узел</param>
	void SetNext(Node* node);
};