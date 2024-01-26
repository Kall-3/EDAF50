#include <iostream>
#include "list.h"

using std::cout;
using std::endl;

List::List()
{
    this->first = new Node(0, NULL);
}

List::~List()
{
    // Introduction of destruction error, miss first Node
    // Node* curr = this->first->next;
    Node* curr = this->first;

    while (curr != NULL)
    {
        cout << "delete ";
        Node* next_node = curr->next;
        delete curr;
        curr = next_node;
    }
    cout << endl;
}

bool List::exists(int d) const
{
    Node* curr = this->first->next;

    while (curr != NULL)
    {
        if (curr->value == d)
        {
            return true;
        }
        curr = curr->next;
    }
	return false;
}

int List::size() const
{
    int size = 0;
    Node* curr = this->first->next;

    for( ; curr; curr = curr->next)
    {
        size += 1;
    }
	return size;
}

bool List::empty() const
{
	return this->first->next == NULL;
}

void List::insertFirst(int d)
{
    Node* new_node = new Node(d, this->first->next);
    this->first->next = new_node;
}

void List::remove(int d, DeleteFlag df)
{
    if (this->first->next == NULL)
    {
        return;
    }

    Node* curr = this->first->next;
    Node* prev = this->first;

    while (curr != NULL)
    {
        if (df == List::DeleteFlag::GREATER && curr->value > d)
        {
            prev->next = curr->next;
            delete curr;
            return;
        }
        if (df == List::DeleteFlag::EQUAL && curr->value == d)
        {
            prev->next = curr->next;
            delete curr;
            return;
        }
        if (df == List::DeleteFlag::LESS && curr->value < d)
        {
            prev->next = curr->next;
            delete curr;
            return;
        }

        prev = curr;
        curr = curr->next;
    }
}

void List::print() const
{
    Node* curr = this->first->next;

    cout << "List:";
    for( ; curr; curr = curr->next)
    {
        cout << " " << curr->value;
    }
    cout << endl;
}

