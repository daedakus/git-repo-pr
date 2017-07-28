#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

struct list {
	string value;
	list* prev;
	list* succ;
	list(const string &v, list* p = nullptr, list* s = nullptr) :value{ v }, prev{ p }, succ{ s } {}
};

list *insert(list *p, list *n) {
	if (p == nullptr) return n;
	if (n == nullptr) return p;
	n->succ = p;
	if (p->prev) p->prev->succ = n;
	n->prev = p->prev;
	p->prev = n;
	return n;
}
list *add(list *p, list*n) {
	if (p == nullptr) return n;
	if (n == nullptr) return p;
	n->prev = p;
	if (p->succ) {
		p->succ->prev = n;

		n->succ = p->succ;
	}
	p->succ = n;
	return n;
}
list *erase(list *p) {
	if (p == nullptr) return nullptr;
	if (p->succ) p->succ->prev = p->prev;
	if (p->prev) p->prev->succ = p->succ;
	return p->succ;
}
list *find(list *p, const string &s) {
	while (p) {
		if (p->value == s) return p;
		p = p->succ;
	}
	return nullptr;
}
list *advance(list *p, int num) {
	if (num > 0)
	{
		while (num--)
		{
			if (p->succ == nullptr) return nullptr;
			p = p->succ;
			num--;
		}
	}
	else if (num < 0) {
		while (num++) {
			if (p->prev == nullptr) return nullptr;
			p = p->prev;
		}
	}
	return p;
}
void print_all(list *p) {
	while (p)
	{
		cout << p->value << endl;
		p = p->succ;
	}
	cout << "___________" << endl;
}
int main() {
	const int size = 2;
	list *norse_gods = new list{ "Thor" };
	norse_gods = insert(norse_gods, new list{ " Odin" });
	norse_gods = insert(norse_gods, new list{ "Zeus" });
	norse_gods = insert(norse_gods, new list{ "Freia" });

	list *greek_gods = new list{ "Hera" };
	greek_gods = insert(greek_gods, new list{ "Mars" });


	list *p = find(greek_gods, "Mars");
	if (p) p->value = "Ares";

	p = find(norse_gods, "Zeus");
	if (p) {
		if (p == norse_gods) norse_gods = p->succ;
		erase(p);
		greek_gods = insert(greek_gods, p);
	}
	
	p = norse_gods;
	p = find(norse_gods, "Thor");
	
	
	p->succ = add(p, new list{ "Loki" });
	int i = 1;
	print_all(norse_gods);
	print_all(greek_gods);
	system("pause");
	return 0;
}