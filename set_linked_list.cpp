#include <iostream>
#include <fstream>

#define max 100

struct node {
	int data;
	node* next;
	node(int value): data(value), next(NULL){}
};

class set {
public:
	node* head;
	int length;
	bool mark[max];

	set():head(NULL), length(0) {}
	~set() { delete head; }

	void printf() { for (node* p = head; p != NULL; p = p->next) std::cout << p->data << " ";}

	void add(int value) {
		node* nnode = new node(value);
		if (head == NULL) {
			head = nnode;
			mark[value] = true;
			length++;
			return;
		}
		if (mark[value] == false) {
			node* p = head;
			while (p->next != NULL) {
				p = p->next;
			}
			p->next = nnode;
			mark[value] = true;
			length++;
		}
	}
	
	void remove(int value) {
		if (head->data == value) {
			node* save = head;
			head = head->next;
			delete save;
			return;
		}
		node* pb = head;
		node* p = head->next;
		int i = 1;
		while (p->data != value) {
			if (i == length) return;
			pb = p;
			p = p->next;
			i++;
		}
		pb->next = p->next;
		delete p;
		length--;
	}

	set intersection(const set& other_set) {
		set result;
		for (node* p1 = head; p1 != NULL; p1 = p1->next) 
			for (node* p2 = other_set.head; p2 != NULL; p2 = p2->next) 
				if (p1->data == p2->data) 
					result.add(p1->data);				
		return result;
	}

	set uni(const set& other_set) {
		set result;
		bool mark1[max] = { false };
		for (node* p1 = head; p1 != NULL; p1 = p1->next) {
			result.add(p1->data);
			mark1[p1->data] = true;
		}
		for (node* p2 = other_set.head; p2 != NULL; p2 = p2->next) 
			if (mark1[p2->data] == false) result.add(p2->data);
		return result;
	}
private:
};

int main() {
	set s;
	s.add(1);
	s.add(2);
	s.add(3);
	s.add(4);
	
	set x;
	x.add(3);
	x.add(4);
	x.add(5);
	x.add(6);
	set result = s.intersection(x);
	//set result = s.uni(x);
	result.printf();
}