#include <iostream>

using namespace std;

struct Node {
	Node* previous;
	Node* next;
	int data;
};

class double_linked_list {
public:
	double_linked_list();
	double_linked_list(int data);
	bool add(int data);
	void vivod1();
	void vivod2();
	bool sort();
private:
	Node* first;
	Node* last;
};

double_linked_list::double_linked_list()
{
	first = nullptr;
	last = nullptr;
};

double_linked_list::double_linked_list(int data)
{
	Node* p = new Node{ nullptr, nullptr, data };
	first = p;
	last = p;
};

bool double_linked_list::add(int data)
{
	Node* p = new Node{ last, nullptr, data };
	last->next = p;
	last = p;
	return true;
};

void double_linked_list::vivod1()
{
	Node* a = first;
	while (a != nullptr)
	{
		cout << a->data << " ";
		a = a->next;
	}
	cout << endl;
};

void double_linked_list::vivod2()
{
	Node* a = last;
	while (a != nullptr)
	{
		cout<< a->data << " ";
		a = a->previous;
	}
	cout << endl;
};



bool double_linked_list::sort() 
{
	if (first == nullptr || first == last) return true;        // если в списке нет или 1 элемент, выходим

	Node* Pig1 = nullptr;	
	Node* Pig2 = nullptr;
	Node* kfirst = first;  
	Node* a = kfirst;
	int minn = kfirst->data;
	Node* min = kfirst;

	while (a != nullptr)
	{
		if (a->data < minn) { min = a; minn = a->data; };         // идем по списку с первого элемента и находим минимум
		a = a->next;
	}
	
	if (min->next == nullptr && kfirst->next->next == nullptr)         // если в списке 2 элемента и минимальный на конце, сортируем их и выходим
	{
		kfirst->next = nullptr;
		min->previous = nullptr;
		min->next = kfirst;
		kfirst->previous = min;
		first = min;
		last = kfirst;
		return true;
	}

	else

	if (min==kfirst && kfirst->next->next == nullptr) { return true; }     // если в списке 2 элемента и они в нужном порядке, выходим

	else

	if (min->next == nullptr) {
	(min->previous)->next = kfirst;
	(kfirst->next)->previous = min;
	min->next = kfirst->next;
	kfirst->previous = min->previous;
	min->previous = nullptr;
	kfirst->next = nullptr;
	first = min;
	last = kfirst;
	}
	
	else 
		
	if(min == kfirst) {}

	else

	if (kfirst->next == min) {
	min->next->previous = kfirst;
	kfirst->next = min->next;
	min->next = kfirst;
	kfirst->previous = min;
	min->previous = nullptr;
	first = min;
	}

	else

	{                                   
	(min->next)->previous = kfirst;
	(min->previous)->next = kfirst;
	(kfirst->next)->previous = min;
	Pig1 = kfirst->next;
	kfirst->next = min->next;
	kfirst->previous = min->previous;
	min->next = Pig1;
	min->previous = nullptr;
	first = min;
	}
	kfirst = min->next;
	bool t = true;

	while (t) {
		Pig1 = nullptr;
		Pig2 = nullptr;
        min = kfirst;
		minn = kfirst->data;
		a = kfirst;
		while (a != nullptr)
		{
			if (a->data < minn) { min = a; minn = a->data; };
			a = a->next;
		}
		
		if (min->next == nullptr && kfirst->next->next == nullptr)        
		{
			kfirst->previous->next = min;
            min->previous = kfirst->previous;
            min->next = kfirst;
            kfirst->previous = min;
			kfirst->next = nullptr;
			last = kfirst;
			return true;
		}

		else

		if (min == kfirst && kfirst->next->next == nullptr) {return true;}

		else

		if (min->next == nullptr) {
			(min->previous)->next = kfirst;
			(kfirst->next)->previous = min;
			(kfirst->previous)->next = min;
			Pig1 = kfirst->previous;
			kfirst->previous = min->previous;
			min->previous = Pig1;
			min->next = kfirst->next;
			kfirst->next = nullptr;
			last = kfirst;
		}

		else 
			
		if (min == kfirst) {}

		else

		if (kfirst->next == min) {           ///////////////////////////////////////
		kfirst->previous->next = min;
		min->next->previous = kfirst;
		kfirst->next = min->next;
		min->next = kfirst;
		min->previous = kfirst->previous;
		kfirst->previous = min;
		}

		else 
		{
		(kfirst->next)->previous = min;
		(kfirst->previous)->next = min;
		(min->next)->previous = kfirst;
		(min->previous)->next = kfirst;
		Pig1 = min->next;
		Pig2 = min->previous;
		min->next = kfirst->next;
		min->previous = kfirst->previous;
		first->next = Pig1;
		first->previous = Pig2;
		}
	kfirst = min->next;
	}
};

int main()
{
	double_linked_list b(58);
	b.add(27);
	b.add(42);
	b.add(1);
	b.add(13);
	b.add(58);
	b.vivod1();
	b.vivod2();
	b.sort();
	b.vivod1();
}
