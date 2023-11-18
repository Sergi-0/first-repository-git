#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};

class linkedlist {
public:
	linkedlist();
	linkedlist(int data);
	~linkedlist();
	bool add_element(int data);
	bool find_element(int data);
	bool insert_element(int data, int pos);
	bool delete_element(int pos);

private:
	Node* first;
	Node* last;
};

linkedlist::linkedlist()
{
	first = nullptr;
	last = nullptr;
};

linkedlist::~linkedlist()
{
	if (first == nullptr) {}
	else
		if (first == last) { delete first; }
		else
		{
			Node* a = first;
			Node* b = first->next;
			while (a != nullptr)
			{
				delete a;
				a = b;
				b = a->next;
				if (b == nullptr) { delete a; break; }
			}
		}
};

linkedlist::linkedlist(int data)
{
	Node* nd = new Node{ data, nullptr };
	first = nd;
	last = nd;
};

bool linkedlist::add_element(int data)
{
	Node* nd = new Node{ data, nullptr };
	if (last == nullptr) { first = nd; last = nd; }
	else { last->next = nd; last = nd; }
	return true;
};

bool linkedlist::find_element(int data)
{
	Node* a = first;
	while (a != nullptr)
	{
		if (a->data == data) return true;
		a = a->next;
	}
	return false;
};

bool linkedlist::insert_element(int data, int pos)
{
	int l = 0;
	Node* c = first;
	while (c != nullptr)
	{
		++l;
		c = c->next;
	}

	if (pos <= l)
	{
		Node* b = nullptr;
		if (pos == 0) { Node* nd = new Node{ data, first }; first = nd; }
		Node* a = first;
		int k = 1;
		while (k != pos)
		{
			++k;
			a = a->next;
		}
		b = a->next;
		Node* nd = new Node{ data, b };
		a->next = nd;
		return true;
	}
	else return false;
}

bool linkedlist::delete_element(int pos)
{
	if (pos == 0) { Node* a = first->next; delete first; first = a; return true; }
	else
	{
		Node* e = nullptr;
		int k = 1;
		Node* b = first;
		while (k != pos)
		{
			++k;
			b = b->next;
		}
		e = (b->next)->next;
		delete b->next;
		b->next = e;
		return true;
	}
	return false;
};

int main()
{
	linkedlist lst;
	lst.add_element(2);
	lst.add_element(6);
	lst.add_element(5);
	cout << lst.insert_element(7, 2);
	cout << lst.find_element(7);
	lst.delete_element(2);
	cout << lst.find_element(7);
}