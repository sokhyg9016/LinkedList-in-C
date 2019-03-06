#pragma once
#pragma warning(disable:4996)
#include<stdlib.h>
#include<iostream>

using namespace std;

typedef int element;
typedef struct ListNode
{
	element item;
	ListNode* next;

	ListNode(element item = 0, ListNode* next = NULL)
	{
		this->item = item;
		this->next = next;
	}
}ListNode;

class LinkedList
{
private:
	ListNode * front;
public:
	LinkedList();
	~LinkedList();

	void Insert(int index, int value);
	void Add(int value);
	void Clear();
	void Remove(int index);
	void Set(int index, int value);
	int Get(int index) const;
	bool isEmpty() const;
	int size() const;

	friend ostream& operator<<(ostream& os, LinkedList& list);
};

void Test(LinkedList& list);