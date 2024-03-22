#include <iostream>

using namespace std;


class Node {
public:
	int data;
	Node * next;
	Node(int data, Node* next) {
		this->data = data;
		this->next = next;
	}
};
class Stack {
private:
	Node* top;
public:
	Stack() {
		this->top = nullptr;
	}
	
	void ShowList() {
		if (top == nullptr) return;
		Node* tempp = top;
		while (tempp->next != nullptr) {
			cout << tempp->data << "->";
			tempp = tempp ->next;
		}
		cout << tempp->data << "->";
	}

	void push(int data) {
		Node *newNode = new Node(data, nullptr);
		Node* temp = top;
		if(top == nullptr) {
			top = newNode;
			return;
		}
		top=newNode;
		top->next = temp;
	}
	void pop() {
		if (top == nullptr) {
			return;
		}
		else if (top->next== nullptr) {
			top = nullptr;
			return;
		}
		Node* temp = top;
		top = top->next;
		delete temp;
	}

	
	bool isEmpty() {
		if (top == nullptr) return true;
		return false;
	}
	int Stack_size() {
		if (top == nullptr) return 0;

		int node_Counter = 0;
		Node* temp = top;
		while (temp->next != nullptr) {
			node_Counter++;
			temp = temp->next;
		}
		return node_Counter+1;
	}
};
int main() {
	Stack mystack;
	mystack.push(6);
	mystack.push(56);
	mystack.push(34);
	mystack.pop();
	mystack.Stack_size();
	mystack.isEmpty();
	mystack.ShowList();
	return 0;
}

