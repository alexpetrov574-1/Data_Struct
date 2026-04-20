#include <iostream>﻿

#include "Dictionary.h"
#include "HashTable.h"

using namespace std;


/// <summary>
/// Конструктор словаря
/// </summary>
/// <param name="initialCapacity">Начальная вместимость таблицы</param>
Dictionary::Dictionary(int initialCapacity)
{
    hashTable = new HashTable(initialCapacity);
}

/// <summary>
/// Деструктор словаря
/// </summary>
Dictionary::~Dictionary()
{
    delete hashTable;
}

/// <summary>
/// Добавление пары ключ-значение в словарь
/// </summary>
/// <param name="key">Ключ для добавления</param>
/// <param name="value">Значение для добавления</param>
bool Dictionary::Add(string& key, string& value)
{
    return hashTable->Insert(key, value);
}

/// <summary>
/// Удаление элемента по ключу
/// </summary>
/// <param name="key">Ключ для удаления</param>
bool Dictionary::Remove(string& key)
{
    return hashTable->Remove(key);
}

/// <summary>
/// Поиск значения по ключу
/// </summary>
/// <param name="key">Ключ для поиска</param>
string Dictionary::Find(string& key)
{
    return hashTable->Search(key);
}

/// <summary>
/// Показывает процесс вычисления хэша для ключа
/// </summary>
/// <param name="key">Ключ для расчета хэша</param>
/// <param name="hashSteps">Вектор для сохранения шагов хэширования</param>
void Dictionary::GetHashCalculation(string& key, vector<string>& hashSteps)
{
    hashTable->GetHashProcess(key, hashSteps);
}

/// <summary>
/// Получить текущее количество пар ключ-значение
/// </summary>
int Dictionary::GetSize()
{
    return hashTable->GetSize();
}

/// <summary>
/// Получить вместимость хеш-таблицы
/// </summary>
int Dictionary::GetCapacity()
{
    return hashTable->GetCapacity();
}

/// <summary>
/// Получить коэффициент заполнения таблицы
/// </summary>
/// <returns>Коэффициент заполнения (size/capacity)</returns>
double Dictionary::GetLoadFactor()
{
    return hashTable->GetLoadFactor();
}

/// <summary>
/// Получить состояние хеш-таблицы в виде строк
/// </summary>
/// <param name="tableInfo">Информация о таблице</param>
/// <param name="tableContent">Содержимое таблицы</param>
void Dictionary::GetTableState(vector<string>& tableInfo, vector<string>& tableContent)
{
    hashTable->GetTableState(tableInfo, tableContent);
}