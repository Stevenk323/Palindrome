#include <iostream>
#include <string>
using namespace std;

class stack {
private:
	struct node{
		char letter;
		node* next;
	};
	node* top;
	node* curr;
public:
	stack() {
		top = NULL;
		curr = NULL;
	}
	void addStack(char);
	string print();
	void clear();
};

void stack::addStack(char data) {
	node* n = new node;
	n->letter = data;
	n->next = NULL;
	if (top == NULL){
		top = n;
	}
	else
	{
		n->next = top;
		top = n;
	}
}

string stack::print() {
	string word;
	curr = top;
	while (curr != NULL) {
		//cout << curr->letter;
		word = word + curr->letter;
		curr = curr->next;
	}
	return word;
}

void stack::clear() {
	curr = top;
	node* temp = curr;
	while (top != NULL)
	{
		curr = curr->next;
		top = curr;
		delete temp;
		temp = curr;
	}
}

int main()
{
	stack a;
	string backward, forward;
	while(true) {
		cout << "Type in a word to find if it is a Palindrome or 0 to exit" << endl;
		cin >> forward;
		if (forward == "0")
			break;
			for (int i = 0; i < forward.length(); i++)
				a.addStack(forward[i]);

			backward = a.print();

			if (backward == forward)
				cout << forward << " is a Palindrome!" << endl;
			else
				cout << forward << " is not a Palindrome!" << endl;
			a.clear();
	}
	cout << "Done" << endl;
	system("pause");
	return 0;
}