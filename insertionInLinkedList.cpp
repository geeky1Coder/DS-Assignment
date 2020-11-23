#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	Node* next;
	int data;
	Node(int x) {
		next = nullptr;
		data = x;
	}
};

void printList(Node* head) {
	while (head != nullptr) {
		cout << head->data << " ";
		head = head->next;
	}
}

Node* insertNode(Node** head, int data) {
	Node * new_node = new Node(data);
	new_node->next = *head;
	*head = new_node;
	return *head;
}
int main() {
	Node* head = nullptr;
	insertNode(&head, 11);
	insertNode(&head, 17);
	insertNode(&head, 4);
	printList(head);
	return 0;
}