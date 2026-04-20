#include "Node.h"
#include "List.h"
#include <iostream>

int List::GetSize()
{ 
	return _size; 
}

List::List(int size)
{
	_size = size;

	for (int i = 0; i < size; ++i)
	{
		AddNode(new Node(0), _size);
	}
}

Node* List::GetHead()
{
	return _head;
}

Node* List::GetTail()
{
	return _tail;
}

Node* List::GetNodeByIndex(int index)
{
	if (index < 0 || index >= _size)
	{
		return nullptr;
	}

	Node* currentNode = _head;
	for (int i = 0; i < index; ++i)
	{
		if (currentNode == nullptr) return nullptr;
		currentNode = currentNode->GetNextNode();
	}
	return currentNode;
}

bool List::InsertAfter(int valueAfter, Node* node)
{
	if (node == nullptr)
	{
		return false;
	}

	// »щем индекс узла с заданным значением
	Node* current = _head;
	int index = 0;

	while (current != nullptr && current->GetData() != valueAfter) 
	{
		current = current->GetNextNode();
		index++;
	}

	if (current == nullptr)
	{
		return false;
	}

	// ¬ставл€ем на позицию index+1 (после найденного)
	return AddNode(node, index + 1);
}

bool List::AddNode(Node* node, int index)
{
	node->SetPreviousNode(nullptr);
	node->SetNextNode(nullptr);

	if (_size == 0)
	{
		_head = node;
		_tail = node;
	}

	else
	{
		if (index == 0)
		{
			node->SetNextNode(_head);
			_head->SetPreviousNode(node);
			_head = node;
		}
		else
		{
			if (index == _size)
			{
				node->SetPreviousNode(_tail);
				_tail->SetNextNode(node);
				_tail = node;
			}
			else
			{
				Node* current = GetNodeByIndex(index);
				if (current == nullptr)
				{
					return false;
				}

				node->SetPreviousNode(current->GetPreviousNode());
				node->SetNextNode(current);

				if (current->GetPreviousNode() != nullptr)
				{
					current->GetPreviousNode()->SetNextNode(node);
				}
			}
		}
	}

	_size++;
	return true;
}

bool List::RemoveNodeByIndex(int index)
{
	if (index < 0 || index >= _size || _size == 0)
		return false;

	Node* nodeToDelete = GetNodeByIndex(index);
	if (nodeToDelete == nullptr) return false;

	if (nodeToDelete->GetPreviousNode() != nullptr)
	{
		nodeToDelete->GetPreviousNode()->
			SetNextNode(nodeToDelete->GetNextNode());
	}
	else
	{
		_head = nodeToDelete->GetNextNode();
	}

	if (nodeToDelete->GetNextNode() != nullptr)
	{
		nodeToDelete->GetNextNode()->
			SetPreviousNode(nodeToDelete->GetPreviousNode());
	}
	else
	{
		_tail = nodeToDelete->GetPreviousNode();
	}

	delete nodeToDelete;
	_size--;
	return true;
}

void List::RemoveNodeByValue(int value)
{
	Node* current = _head;

	while (current != nullptr)
	{
		Node* nextNode = current->GetNextNode();

		if (current->GetData() == value)
		{
			if (current->GetPreviousNode() != nullptr)
			{
				current->GetPreviousNode()->SetNextNode(current->GetNextNode());
			}
			else
			{
				_head = current->GetNextNode();
			}

			if (current->GetNextNode() != nullptr)
			{
				current->GetNextNode()->SetPreviousNode(current->GetPreviousNode());
			}
			else
			{
				_tail = current->GetPreviousNode();
			}

			delete current;
			_size--;
		}

		current = nextNode;
	}
}

void List::Sort()
{
	// —ортировка пузырьком (оптимизированна€ дл€ двусв€зного списка)
	bool swapped;
	do
	{
		swapped = false;
		Node* current = _head;

		while (current != nullptr && current->GetNextNode() != nullptr)
		{
			if (current->GetData() > current->GetNextNode()->GetData())
			{
				// ћен€ем значени€ узлов (самый простой способ дл€ сортировки)
				int temp = current->GetData();
				current->SetData(current->GetNextNode()->GetData());
				current->GetNextNode()->SetData(temp);
				swapped = true;
			}
			current = current->GetNextNode();
		}
	}
	while (swapped);
}

Node* List::FindNodeByValue(int value)
{
	Node* searchNode = _head;
	
	for (int i = 0; i < _size; ++i)
	{
		if (searchNode->GetData() == value)
		{
			break;
		}
		else
		{
			if (searchNode->GetNextNode() != nullptr)
			{
				searchNode = searchNode->GetNextNode();
				if (searchNode->GetData() == value)
				{
					break;
				}
			}
			else
			{
				break;
			}
		}
	}

	return searchNode;
}

void List::Clean()
{
	Node* current = _head;
	for (int i = 0; i < _size; ++i)
	{
		Node* next = current->GetNextNode();
		delete current;
		current = next;
	}

	_head = nullptr;
	_tail = nullptr;
	_size = 0;
}