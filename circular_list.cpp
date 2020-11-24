//Circular Linked List
#include <bits/stdc++.h>
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

void insertNode(Node**head, int data, int index) {
	Node* new_node = new Node(data);
	if (*head == nullptr) {
		*head = new_node;
		new_node->next = *head;
	}
	else if (index == 0) {
		new_node->next = *head;
		Node* cur = *head;

		while (cur->next != *head) {
			cur = cur->next;
		}
		cur->next = new_node;
		*head = new_node;
	}
	else {
		Node*cur = *head;
		Node*pre = nullptr;
		while (index != 0 && cur->next != *head) {
			pre = cur;
			cur = cur->next;
			index--;
		}
		if (cur->next == *head) {
			cur->next = new_node;
			new_node->next = *head;
		}
		else {
			pre->next = new_node;
			new_node->next = cur;
		}
	}
}

int deleteNode(Node** head, int index) {
	if (*head == nullptr) {
		return INT_MIN;
	}
	Node*cur = *head;
	if (index == 0) {
		int data = (*head)->data;

		while (cur->next != *head) {
			cur = cur->next;
		}

		cur->next = (*head)->next;
		delete *head;
		*head = cur->next;
		return data;
	}
	else {
		Node*pre = nullptr;

		while (index != 0 && cur->next != *head) {
			pre = cur;
			cur = cur->next;
			index--;
		}

		pre->next = cur->next;
		int data = cur->data;
		delete cur;
		return data;
	}
}
void printCircularList(Node* head) {
	Node*cur = head;
	while (head != nullptr ) {
		cout << head->data << " ";
		if (head->next != nullptr && head->next == cur) {
			break;
		}
		head = head->next;
	}
	cout << endl;
}
int main() {
	Node*head = nullptr;
	//Inserting At Start
	insertNode(&head, 12, 0);
	insertNode(&head, 15, 0);
	printCircularList(head);
	insertNode(&head, 18, 2);
	printCircularList(head);
	insertNode(&head, 11, 3);
	printCircularList(head);
	insertNode(&head, 5, 1);
	printCircularList(head);
	deleteNode(&head, 12);  //Will delete last element before head node
	deleteNode(&head, 0);
	deleteNode(&head, 0);

	printCircularList(head);
	return 0;
}