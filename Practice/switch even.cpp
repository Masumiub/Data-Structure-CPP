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


void switchEvens(Node* root1, Node* root2) {
	Node* curr = root1;
    Node* curr2 = root2;

    while(curr!=NULL && curr2!=NULL){
        if(curr->data%2==0 && curr2->data%2==0){
            int data= curr->data;
            curr->data = curr2->data;
            curr2->data = data;
        }

        curr = curr->next;
        curr2 = curr2->next;

    }
}

int main() {
	Node *root1 = NULL, *root2 = NULL, *root = NULL;

	insertNewNode(&root1, 2);
	insertNewNode(&root1, 4);
	insertNewNode(&root1, 3);
	insertNewNode(&root1, 7);
    insertNewNode(&root1, 8);
	insertNewNode(&root1, 4);
	insertNewNode(&root1, 6);
	insertNewNode(&root1, 12);
	insertNewNode(&root1, 22);
	insertNewNode(&root1, 10);

	insertNewNode(&root2, 66);
	insertNewNode(&root2, 55);
	insertNewNode(&root2, 16);
	insertNewNode(&root2, 43);
	insertNewNode(&root2, 22);
	insertNewNode(&root2, 90);
	insertNewNode(&root2, 39);
	insertNewNode(&root2, 44);
    //insertNewNode(&root2, 66);
    //insertNewNode(&root2, 55);

    //mystery(root1, root2);
	//root = generateNewLinkedList(root1, root2);
    //merge_list(root1, root2);

    switchEvens(root1, root2);
	printLinkedList(root1);
	cout<< endl;
	printLinkedList2(root2);
//cout<< endl;cout<< endl;

	return 0;
}
