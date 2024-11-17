#include <conio.h>
#include <iostream>

#include "Functions.h"

using namespace std;

void Insert(Tree& tree)
{
    system("cls");
    cout << "Enter a quantity of elements to add: ";

    unsigned int count = 0U;
    cin >> count;

    for (unsigned int i = 0U; i < count; ++i)
    {
        Node* temp = new Node;

        cout << endl << "Enter an english word " << i + 1 << endl;
        cin >> temp->GetEnglish();

        cout << endl << "Enter a russian word " << i + 1 << endl;
        cin >> temp->GetRussian();

        tree.Insert(temp);
    }
}

void Print(const Tree& tree)
{
    system("cls");

    tree.Print(tree.GetRoot());

    _getch();
}

void PrintMenu()
{
    char menu[] = "1. Insert node\n2. Remove node\n3. Print node\n4. Search node\n5.Show Most Popular Word\n6.Show Least Popular Word\n7. Exit\n";

    system("cls");

    cout << menu;
}

void Remove(Tree& tree)
{
    system("cls");
    cout << "Enter an english word to remove:" << endl;

    char buffer[15] = {};
    cin >> buffer;

    Node* node = tree.Search(tree.GetRoot(), buffer);

    tree.Remove(node);
}

void Search(const Tree& tree)
{
    system("cls");
    cout << "Enter an english word to search:" << endl;

    char buffer[15] = {};
    cin >> buffer;

    Node* node = tree.Search(tree.GetRoot(), buffer);

    if (node != nullptr)
    {
        cout << node->GetRussian();
    }
    else
    {
        cout << "Word not found" << endl;
    }

    _getch();
}

//Задание

void ShowMostPopularWord(const Tree& tree)
{
    system("cls");
    Node* mostPopular = tree.GetMostPopularWord();
    if (mostPopular)
    {
        cout << "Most popular word: " << mostPopular->m_english << " - " << mostPopular->m_russian
            << " (Accessed " << mostPopular->m_accessCounter << " times)" << endl;
    }
    else
    {
        cout << "No words found in the dictionary." << endl;
    }
    _getch();
}

void ShowLeastPopularWord(const Tree& tree)
{
    system("cls");
    Node* leastPopular = tree.GetLeastPopularWord();
    if (leastPopular)
    {
        cout << "Least popular word: " << leastPopular->m_english << " - " << leastPopular->m_russian
            << " (Accessed " << leastPopular->m_accessCounter << " times)" << endl;
    }
    else
    {
        cout << "No words found in the dictionary." << endl;
    }
    _getch();
}
