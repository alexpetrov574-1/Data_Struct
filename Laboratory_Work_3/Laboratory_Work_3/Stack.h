#pragma once

#include "Node.h"

class Stack
{
private:
    /// <summary>
    /// Указатель на вершину стека.
    /// </summary>
    Node* _top;

    /// <summary>
    /// Максимальная вместимость стека.
    /// </summary>
    int _capacity;

    /// <summary>
    /// Текущее количество элементов в стеке.
    /// </summary>
    int _currentSize;

    /// <summary>
    /// Проверяет, является ли стек полным проверки заполненности.
    /// </summary>
    bool isFullInternal();

public:
    /// <summary>
    /// Конструктор стека.
    /// Создает пустой стек с заданной вместимостью.
    /// </summary>
    Stack(int startCapacity);

    /// <summary>
    /// Деструктор стека.
    /// Освобождает всю память, занятую элементами стека.
    /// </summary>
    ~Stack();

    /// <summary>
    /// Добавляет элемент на вершину стека.
    /// </summary>
    /// <param name="value">Значение для добавления в стек</param>
    bool Push(int value);

    /// <summary>
    /// Извлекает элемент с вершины стека.
    /// Удаляет элемент из стека и возвращает его значение.
    /// </summary>
    int Pop();

    /// <summary>
    /// Просматривает элемент на вершине стека без его извлечения.
    /// </summary>
    bool Peek(int& value);

    /// <summary>
    /// Проверяет, является ли стек пустым.
    /// </summary>
    bool IsEmpty();

    /// <summary>
    /// Проверяет, является ли стек полным.
    /// </summary>
    bool IsFull();

    /// <summary>
    /// Получает текущее количество элементов в стеке.
    /// </summary>
    int GetSize();

    /// <summary>
    /// Получает максимальную вместимость стека.
    /// </summary>
    int GetCapacity();

    /// <summary>
    /// Очищает стек, удаляя все элементы.
    /// Память всех элементов освобождается, стек становится пустым.
    /// </summary>
    void Clear();

    /// <summary>
    /// Отображает содержимое стека.
    /// Элементы выводятся от вершины к основанию.
    /// </summary>
    void Show();
};