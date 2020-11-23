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
	cout << endl;
}
//index=2;
//2->4->5->9->10
Node* insertNode(Node** head, int data , int index) {
	Node * new_node = new Node(data);
	if (index == 0) {
		new_node->next = *head;
		*head = new_node;
	}
	else {
		Node* cur = *head;
		Node*prev = cur;
		while (index != 0 && cur != nullptr) {
			prev = cur;
			cur = cur->next;
			index--;
		}
		prev->next = new_node;
		new_node->next = cur;
	}
	return *head;
}

int deleteNode(Node** head, int index) {
	if (*head == nullptr) {
		return -1;
	}
	if (index == 0) {
		int data = ((*head)->data);
		Node*nex = ((*head)->next);
		*head = nex;
		return data;
	}
	else {
		Node*cur = *head;
		Node*prev = cur;
		while (index != 0 && cur != nullptr) {
			prev = cur;
			cur = cur->next;
			index--;
		}
		if (cur == nullptr) {
			return -1;
		}
		prev->next = cur->next;
		return cur->data;
	}
}
int main() {
	Node* head = nullptr;
	insertNode(&head, 11, 0);
	insertNode(&head, 17, 0);
	insertNode(&head,  4, 0);
	insertNode(&head,  8, 4);
	printList(head);
	deleteNode(&head, 2);
	deleteNode(&head, 0);
	deleteNode(&head, 1);
	printList(head);
	return 0;
}