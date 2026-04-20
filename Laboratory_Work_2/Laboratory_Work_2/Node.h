#pragma once

/// <summary>
/// Структура узла
/// </summary>
struct Node 
{
private:
	/// <summary>
	/// Данные
	/// </summary>
	int _data;
	
	/// <summary>
	/// Следующий узел
	/// </summary>
	Node* _nextNode;

	/// <summary>
	/// Предыдущий узел
	/// </summary>
	Node* _previousNode;

public:

	/// <summary>
	/// Инициализация узла без значения
	/// </summary>
	Node();

	/// <summary>
	/// Инициализация узла
	/// </summary>
	/// <param name="value">значение в узле</param>
	Node(int value);

	/// <summary>
	/// получение данных в узле
	/// </summary>
	/// <returns>данное в узле</returns>
	int GetData();

	/// <summary>
	/// установка данных в узле
	/// </summary>
	/// <param name="data">данное в узле</param>
	void SetData(int data);

	/// <summary>
	/// получение следующего узла
	/// </summary>
	/// <returns>следующий узел</returns>
	Node* GetNextNode();

	/// <summary>
	/// установка следующего узла
	/// </summary>
	/// <param name="node">следующий узел</param>
	void SetNextNode(Node* node);

	/// <summary>
	/// получение предыдущего узла
	/// </summary>
	/// <returns>предыдущий узел</returns>
	Node* GetPreviousNode();

	/// <summary>
	/// установка предыдущего узла
	/// </summary>
	/// <param name="node">предыдущий узел</param>
	void SetPreviousNode(Node* node);
};