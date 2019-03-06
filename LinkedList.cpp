#include "LinkedList.h"

LinkedList::LinkedList()
{
	front = NULL;
}

LinkedList::~LinkedList()
{
	Clear();
}

void LinkedList::Insert(int index, int value)
{
	if (index == 0)
	{
		ListNode* oldFront = front;
		front = new ListNode(value);
		front->next = oldFront;
	}
	else
	{
		ListNode* current = front;
		for (int i = 0; i < index - 1; i++)
		{
			current = current->next;
		}
		ListNode* newNode = new ListNode(value);
		newNode->next = current->next;
		current->next = newNode;
	}
}

void LinkedList::Add(int value)
{
	if (front == NULL)
	{
		front = new ListNode(value);
	}
	else
	{
		ListNode* current = front;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new ListNode(value);
	}
}

void LinkedList::Clear()
{
	while (front != NULL)
	{
		Remove(0);
	}
}
void LinkedList::Remove(int index)
{
	ListNode* trash;

	if (isEmpty())
	{
		fprintf(stderr, "List is Empty.\n");
		exit(1);
	}
	else if (index == 0)
	{
		trash = front;
		front = front->next;
	}
	else
	{
		ListNode* current = front;
		for (int i = 0; i < index - 1; i++)
		{
			current = current->next;
		}
		trash = current->next;
		current->next = current->next->next;
	}
	delete trash;
}
void LinkedList::Set(int index, int value)
{
	ListNode* current = front;
	for (int i = 0; i < index; i++)
	{
		current = current->next;
	}
	current->item = value;
}

int LinkedList::Get(int index) const
{
	ListNode* current = front;
	for (int i = 0; i < index; i++)
	{
		current = current->next;
	}
	return current->item;
}

bool LinkedList::isEmpty() const
{
	return (front == NULL);
}

int LinkedList::size() const
{
	ListNode* current = front;
	int i = 0;

	while (current != NULL)
	{
		i += 1;
		current = current->next;
	}
	return i;
}

ostream& operator<<(ostream& os, LinkedList& list)
{
	int size = list.size();

	cout << '{';
	for (int i = 0; i < size; i++)
	{
		os << list.Get(i) << ", ";
	}
	cout << "}, size = " << size << endl;

	return os;
}

void Test(LinkedList& list)
{
	list.Add(0);
	list.Add(42);
	list.Add(111);
	list.Add(-5);
	list.Add(17);
	list.Add(444);
	list.Add(28);
	list.Add(7777);

	cout << list;

	list.Remove(2);
	cout << endl << list;
	list.Remove(list.size() - 1);
	cout << list;
	list.Remove(0);
	cout << list;

	list.Clear();
	cout << endl << list;
}