#include <iostream>
#include "List.h"

using namespace std;

int main()
{
    cout << "Laboratory work #2 - Doubly Linked List" << endl;

    cout << "Current list:" << endl;

    List list(0);

    list.AddNode(new Node(55), 0);
    list.AddNode(new Node(7), 1);
    list.AddNode(new Node(1), 2);
    list.AddNode(new Node(3), 3);

    int size = list.GetSize();

    for (int i = 0; i < size; ++i)
    {
        Node* node = list.GetNodeByIndex(i);
        if (node != nullptr)
        {
            cout << node->GetData();
            if (i < size - 1)
            {
                cout << ", ";
            }
        }
    }

    cout << endl;
    cout << endl;

    cout << "Select the action you want to do:" << endl;
    cout << "1) Remove an element by index from a list\n" <<
        "2) Remove an element by value from a list\n" <<
        "3) Insert an element at the beginning\n" <<
        "4) Insert an element at the end\n" <<
        "5) Insert after a certain element\n" <<
        "6) Sort list\n" <<
        "7) Linear search for an element in a list\n" << endl;

    while (true)
    {
        size = list.GetSize();

        cout << "Your input: ";
        int numberTask = 0;
        cin >> numberTask;

        switch (numberTask)
        {
        case 1:
        {
            cout << "Remove an element by index from a list" << endl;

            int index = 0;
            cout << "Input number - index: ";
            cin >> index;

            bool isArrayRemoved = list.RemoveNodeByIndex(index);

            if (isArrayRemoved)
            {
                cout << "Removing completed" << endl;
            }
            else
            {
                cout << "Removing don't completed" << endl;
            }

            cout << "Current list:" << endl;
            for (int i = 0; i < size; ++i)
            {
                Node* node = list.GetNodeByIndex(i);
                if (node != nullptr)
                {
                    cout << node->GetData();
                    if (i < size - 1)
                    {
                        cout << ", ";
                    }
                }
            }
            cout << endl;
            break;
        }
        case 2:
        {
            cout << "Remove an element by value from a list" << endl;

            int value = 0;
            cout << "Input number - value: ";
            cin >> value;

            list.RemoveNodeByValue(value);

            cout << "Current list:" << endl;
            for (int i = 0; i < size; ++i)
            {
                Node* node = list.GetNodeByIndex(i);
                if (node != nullptr)
                {
                    cout << node->GetData();
                    if (i < size - 1)
                    {
                        cout << ", ";
                    }
                }
            }
            cout << endl;
            break;
        }
        case 3:
        {
            cout << "Insert an element at the beginning" << endl;

            int data = 0;
            cout << "Input data: ";
            cin >> data;
            cout << endl;

            bool isAdded = list.AddNode(new Node(data), 0);

            if (isAdded)
            {
                cout << "Adding completed" << endl;
            }
            else
            {
                cout << "Adding don't completed" << endl;
            }
            cout << endl;
            break;
        }
        case 4:
        {
            cout << "Insert an element at the end" << endl;

            int data = 0;
            cout << "Input data: ";
            cin >> data;
            cout << endl;

            bool isAdded = list.AddNode(new Node(data), 0);

            if (isAdded)
            {
                cout << "Adding completed" << endl;
            }
            else
            {
                cout << "Adding don't completed" << endl;
            }

            cout << "Current list:" << endl;
            for (int i = 0; i < size; ++i)
            {
                Node* node = list.GetNodeByIndex(i);
                if (node != nullptr)
                {
                    cout << node->GetData();
                    if (i < size - 1)
                    {
                        cout << ", ";
                    }
                }
            }
            cout << endl;
            break;
        }
        case 5:
        {
            cout << "Insert after a certain element" << endl;
            
            int data = 0;
            cout << "Input data: ";
            cin >> data;
            cout << endl;

            int certainElement = 0;
            cout << "Input number of certain element: ";
            cin >> certainElement;
            cout << endl;

            bool isInsert = list.InsertAfter(certainElement, new Node(data));
            
            cout << "Element: " << data << " inserted on " << isInsert << endl;

            break;
        }
        case 6:
        {
            cout << "Sort list" << endl;

            list.Sort();

            cout << "Sorting list:" << endl;

            for (int i = 0; i < size; ++i)
            {
                Node* node = list.GetNodeByIndex(i);
                if (node != nullptr)
                {
                    cout << node->GetData();
                    if (i < size - 1)
                    {
                        cout << ", ";
                    }
                }
            }
            cout << endl;

            break;
        }
        case 7:
        {
            cout << "Linear search for an element in a list" << endl;

            int searchingNumber = 0;
            cout << "Input searching number:";
            cin >> searchingNumber;
            cout << endl;

            Node* searchingNode = new Node(searchingNumber);

            cout << "searched Node:" << searchingNode << endl;

            break;
        }
        default:
        {
            cout << "Unknown command." << endl;
            break;
        }
        }
    }
}
