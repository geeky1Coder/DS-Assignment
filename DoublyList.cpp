//Doubly Linked List
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	Node *next;
	Node *prev;
	int data;
	Node(int x) {
		prev = nullptr;
		next = nullptr;
		data = x;
	}
};

//5<->11<->4<->8<->7-->nullptr

int deleteNode(Node** head, int index) {
	if (index == 0) {
		Node* temp = *head;
		*head = (*head)->next;
		int x = temp->data;
		delete temp;
		return x;
	}
	else {
		Node*cur = *head;
		while (index != 0 && cur->next != nullptr) {
			cur = cur->next;
			index--;
		}
		Node*pre = cur->prev;
		pre->next = cur->next;
		if (cur->next) {
			cur->next->prev = cur->prev;
		}
		int x = cur->data;
		delete cur;
		return x;
	}
}

void insertNode(Node** head, int data, int index) {
	Node* new_node = new Node(data);

	if (index == 0) {
		new_node->next = *head;
		if (*head != nullptr) {
			(*head)->prev = new_node;
		}

		*head = new_node;
	}
	else {
		Node*cur = *head;
		while (index != 0 && cur->next != nullptr) {
			cur = cur -> next;
			index--;
		}
		Node*pre = cur->prev;
		pre->next = new_node;
		new_node->prev = pre;
		new_node->next = cur;
		cur->prev = new_node;
	}
}
void printDoublyList(Node *head) {
	while (head != nullptr) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}
int main() {
	Node* head = nullptr;
	insertNode(&head, 20, 0);
	insertNode(&head, 22, 0);
	printDoublyList(head);
	insertNode(&head, 24, 1);
	printDoublyList(head);
	insertNode(&head, 10, 1);
	printDoublyList(head);
	insertNode(&head, 12, 2);
	printDoublyList(head);
	deleteNode(&head, 0);
	deleteNode(&head, 0);
	printDoublyList(head);
	deleteNode(&head, 2);
	deleteNode(&head, 1);
	printDoublyList(head);
	return 0;
}