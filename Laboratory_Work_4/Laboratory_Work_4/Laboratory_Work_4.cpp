#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iomanip>
#include "Dictionary.h"

using namespace std;

/// <summary>
/// Получение числового ввода от пользователя
/// </summary>
/// <param name="prompt">Сообщение для пользователя</param>
/// <returns>Введенное число</returns>
int GetNumberInput(const string& prompt)
{
    int value;
    cout << prompt;
    cin >> value;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(10000, '\n');
        return -1;
    }
    cin.ignore(10000, '\n');
    return value;
}

/// <summary>
/// Отображение состояния словаря
/// </summary>
/// <param name="dict">Ссылка на словарь</param>
void DisplayDictionaryState(Dictionary& dict)
{
    cout << "\n4 лабораторная работа - хэш таблица" << endl;
    cout << "Пар ключ-значение: " << dict.GetSize() << endl;
    cout << "Вместимость таблицы: " << dict.GetCapacity() << endl;
    cout << "Коэффициент заполнения: " << dict.GetLoadFactor() * 100 << "%" << endl;
    cout << "\n" << endl;
}

/// <summary>
/// Отображение состояния хеш-таблицы
/// </summary>
/// <param name="dict">Ссылка на словарь</param>
void DisplayHashTableState(Dictionary& dict)
{
    vector<string> tableInfo;
    vector<string> tableContent;

    dict.GetTableState(tableInfo, tableContent);

    cout << "\nсостояние хэш-таблицы" << endl;

    for (int i = 0; i < tableInfo.size(); i++)
    {
        cout << tableInfo[i] << endl;
    }

    cout << "\nСодержимое таблицы (все ячейки):" << endl;
    for (int i = 0; i < tableContent.size(); i++)
    {
        cout << tableContent[i] << endl;
    }
    cout << "\n" << endl;
}

/// <summary>
/// Отображение процесса вычисления хеша
/// </summary>
/// <param name="dict">Ссылка на словарь</param>
/// <param name="key">Ключ для расчета хеша</param>
void DisplayHashCalculation(Dictionary& dict, string& key)
{
    cout << "\nВЫЧИСЛЕНИЕ ХЕША ДЛЯ КЛЮЧА: \"" << key << "\"" << endl;

    vector<string> hashSteps;
    dict.GetHashCalculation(key, hashSteps);

    for (int i = 0; i < hashSteps.size(); i++)
    {
        cout << hashSteps[i] << endl;
    }
}

/// <summary>
/// Добавление случайных элементов
/// </summary>
/// <param name="dict">Ссылка на словарь</param>
/// <param name="count">Количество элементов</param>
void AddRandomElements(Dictionary& dict, int count)
{
    srand(static_cast<int>(time(nullptr)));

    cout << "\nДобавление " << count << " случайных элементов:" << endl;
    cout << "\n" << endl;

    for (int i = 0; i < count; ++i)
    {
        int keyNum = rand() % 1000;
        int valNum = rand() % 10000;
        string key = "key" + to_string(keyNum);
        string value = "val" + to_string(valNum);

        cout << "\nЭлемент " << (i + 1) << ":" << endl;
        dict.Add(key, value);
    }
}

/// <summary>
/// Главное меню программы
/// </summary>
/// <param name="dict">Ссылка на словарь</param>
void ShowMainMenu(Dictionary& dict)
{
    cout << "МЕНЮ СЛОВАРЯ НА ХЕШ-ТАБЛИЦЕ" << endl;

    DisplayDictionaryState(dict);

    cout << endl << "Выберите действие:" << endl;
    cout << "1. Добавить пару ключ-значение" << endl;
    cout << "2. Удалить по ключу" << endl;
    cout << "3. Найти по ключу" << endl;
    cout << "4. Показать хеш для ключа" << endl;
    cout << "5. Показать состояние словаря" << endl;
    cout << "6. Показать состояние хеш-таблицы" << endl;
    cout << "7. Добавить случайные элементы" << endl;
    cout << "0. Выход" << endl;
    cout << endl << "Выберите действие: ";
}

/// <summary>
/// Точка входа в программу
/// </summary>
/// <returns>Код завершения программы</returns>
int main()
{
    setlocale(LC_ALL, "Ru");

    Dictionary dict;
    int choice;

    do {
        ShowMainMenu(dict);
        choice = GetNumberInput("");

        switch (choice) {
        case 1: {
            cout << "1) Добавление пары ключ-значение" << endl;
            cout << "\n" << endl << endl;

            string key, value;
            cout << "Введите ключ: ";
            getline(cin, key);
            cout << "Введите значение: ";
            getline(cin, value);

            bool result = dict.Add(key, value);
            cout << endl << (result ? "Пара успешно добавлена" : "Дубликат, не добавлено") << endl;

            cout << endl << "Состояние после добавления:" << endl;
            DisplayDictionaryState(dict);
            DisplayHashTableState(dict);
            cout << endl;
            break;
        }

        case 2: {
            cout << "2) Удаление по ключу" << endl;
            cout << "\n" << endl << endl;

            string key;
            cout << "Введите ключ для удаления: ";
            getline(cin, key);

            bool result = dict.Remove(key);
            cout << endl << (result ? "Ключ удален" : "Ключ не найден") << endl;

            cout << endl << "Состояние после удаления:" << endl;
            DisplayDictionaryState(dict);
            DisplayHashTableState(dict);
            cout << endl;
            break;
        }

        case 3: {
            cout << "3) Поиск по ключу" << endl;
            cout << "\n" << endl << endl;

            string key;
            cout << "Введите ключ для поиска: ";
            getline(cin, key);

            string result = dict.Find(key);
            if (!result.empty()) {
                cout << endl << "Найдено: " << key << " -> " << result << endl;
            }
            else {
                cout << endl << "Ключ не найден" << endl;
            }

            cout << endl << "Состояние после поиска:" << endl;
            DisplayDictionaryState(dict);
            DisplayHashTableState(dict);
            cout << endl;
            break;
        }

        case 4: {
            cout << "4) Вычисление хэша для ключа" << endl;
            cout << "\n" << endl << endl;

            string key;
            cout << "Введите ключ: ";
            getline(cin, key);

            DisplayHashCalculation(dict, key);
            cout << endl;
            break;
        }

        case 5: {
            cout << "5) Состояние словаря" << endl;
            cout << "\n" << endl << endl;
            DisplayDictionaryState(dict);
            cout << endl;
            break;
        }

        case 6: {
            cout << "6) Состояние хэш-таблицы" << endl;
            cout << "\n" << endl << endl;
            DisplayHashTableState(dict);
            cout << endl;
            break;
        }

        case 7: {
            cout << "7) Добавление случайных элементов" << endl;
            cout << "\n" << endl << endl;

            DisplayDictionaryState(dict);
            cout << endl;

            int count = GetNumberInput("Сколько элементов добавить: ");
            if (count > 0) {
                AddRandomElements(dict, count);
                cout << endl << "Состояние после добавления:" << endl;
                DisplayDictionaryState(dict);
                DisplayHashTableState(dict);
            }
            cout << endl;
            break;
        }

        case 0: {
            cout << "Программа завершена." << endl;
            cout << endl;
            break;
        }

        default:
        {
            if (choice != -1) {
                cout << "Неизвестная команда. Попробуйте снова." << endl;
                cout << endl;
            }
            break;
        }
        }

    } while (choice != 0);

    return 0;
}