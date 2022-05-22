#include <bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	Node* next;
};

void insertNewNode(Node** root, int item) {
	Node *ptr, *temp;
	temp = new Node;
	temp->data = item;
	temp->next = NULL;

	if (*root == NULL) {
		*root = temp;
    }else {
		ptr = *root;
		while (ptr->next != NULL) {
			ptr = ptr->next;
        }
		ptr->next = temp;
	}
}

void printLinkedList(Node* root1) {
	while (root1 != NULL) {
		cout << root1->data << " -> ";
		root1 = root1->next;
	}
	cout << "NULL" << endl;
}

void printLinkedList2(Node* root2) {
	while (root2 != NULL) {
		cout << root2->data << " -> ";
		root2 = root2->next;
	}
	cout << "NULL" << endl;
}

void mystery(Node*& root1, Node*& root2)
{
    Node* curr1 = root1;
    while(root2 != NULL){
        if(curr1->next == NULL){
            curr1->next = root2;
            root2 = NULL;
        }
        else if(root2->data < curr1->next->data){
            Node* temp2 = root2;
            root2 = root2->next;
            temp2->next  = curr1->next;
            curr1->next = temp2;
        }
        else{
            curr1 = curr1->next;
        }
    }

}

Node* generateNewLinkedList(Node* root1, Node* root2) {
	Node *ptr1 = root1, *ptr2 = root2;
	Node* root = NULL;

	while (ptr1 != NULL) {
		int currentMax = ((ptr1->data < ptr2->data) ? ptr2->data : ptr1->data);

		if (root == NULL) {
			Node* temp = new Node;
			temp->data = currentMax;
			temp->next = NULL;
			root = temp;
		}else {
			insertNewNode(&root, currentMax);
		}

		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}

	return root;
}

void merge_list(Node* root1, Node* root2){
    Node* curr= root1;
    while(curr->next!=NULL){
        curr= curr->next;
    }
    curr->next = root2;
    root2 = NULL;
}


void con(Node* root1, Node* root2){

    //cout<< root1->data<< endl;
    cout<< root2->data<< endl;
    if(root1==NULL){
        root1= root2;
    }
        root2 = NULL;
}

int main() {
	Node *root1 = NULL, *root2 = NULL, *root = NULL;

	insertNewNode(&root1, 1);
	insertNewNode(&root1, 3);
	insertNewNode(&root1, 5);
	insertNewNode(&root1, 7);

	insertNewNode(&root2, 2);
	insertNewNode(&root2, 4);
	insertNewNode(&root2, 6);
	//insertNewNode(&root2, 8);
    //insertNewNode(&root2, 66);
    //insertNewNode(&root2, 55);

    //mystery(root1, root2);
	//root = generateNewLinkedList(root1, root2);
    merge_list(root1, root2);
	printLinkedList(root1);
	cout<< endl;
	printLinkedList2(root2);

	return 0;
}
