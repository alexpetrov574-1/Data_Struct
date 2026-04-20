#pragma once

#include <string>
#include <vector>

using namespace std;

class HashTable;

/// <summary>
/// Класс Dictionary для работы со словарем на основе хеш-таблицы
/// </summary>
class Dictionary
{
private:
    /// <summary>
    /// Внутренняя хэш таблица.
    /// </summary>
    HashTable* hashTable;

public:
    /// <summary>
    /// Конструктор словаря
    /// </summary>
    /// <param name="initialCapacity">Начальная вместимость таблицы</param>
    Dictionary(int initialCapacity = 8);

    /// <summary>
    /// Деструктор словаря
    /// </summary>
    ~Dictionary();

    /// <summary>
    /// Добавление пары ключ-значение в словарь
    /// </summary>
    /// <param name="key">Ключ для добавления</param>
    /// <param name="value">Значение для добавления</param>
    bool Add(string& key, string& value);

    /// <summary>
    /// Удаление элемента по ключу
    /// </summary>
    /// <param name="key">Ключ для удаления</param>
    bool Remove(string& key);

    /// <summary>
    /// Поиск значения по ключу
    /// </summary>
    /// <param name="key">Ключ для поиска</param>
    string Find(string& key);

    /// <summary>
    /// Показывает процесс вычисления хеша для ключа
    /// </summary>
    /// <param name="key">Ключ для расчета хеша</param>
    /// <param name="hashSteps">Вектор для сохранения шагов хеширования</param>
    void GetHashCalculation(string& key, vector<string>& hashSteps);

    /// <summary>
    /// Получить текущее количество пар ключ-значение
    /// </summary>
    int GetSize();

    /// <summary>
    /// Получить вместимость хеш-таблицы
    /// </summary>
    int GetCapacity();

    /// <summary>
    /// Получить коэффициент заполнения таблицы
    /// </summary>
    /// <returns>Коэффициент заполнения (size/capacity)</returns>
    double GetLoadFactor();

    /// <summary>
    /// Получить состояние хеш-таблицы в виде строк
    /// </summary>
    /// <param name="tableInfo">Информация о таблице</param>
    /// <param name="tableContent">Содержимое таблицы</param>
    void GetTableState(vector<string>& tableInfo, vector<string>& tableContent);
};