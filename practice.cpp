#include <iostream>


class Node{
public:
	int data;
	Node* next;
	
	Node(){
		data = 0;
		next = NULL;
	}
	Node(int data){
		this->data = data;
		this->next = NULL;
	}
};

class linkedList{
	Node* head;
public:
	linkedList(){head = NULL;};
	void insertNode(int); 
	void printList();
};

void linkedList::insertNode(int data){
	Node* newNode = new Node(data);
	//Meaning that the list is empty
	if(head == NULL){
		head = newNode;
		return;
	}
	// Start from the head, and traverse till the end	
	Node* temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	// The next node is null, so assn to newNode
	temp->next = newNode;
}
void linkedList::printList(){
	Node* temp = head;
	while(temp->next != NULL){
		std::cout << temp->data << " -> ";
		temp = temp->next;
	}
		
	std::cout << temp->data << " -> ";
	
	
}

void dataGen(int max){	
	linkedList lnkList;
	for(int i = 0; i < max; i++){
		lnkList.insertNode(i);
	}
	lnkList.printList();
	
}

//TO-DO: Write our delete Node method
int main(){
	dataGen(100);
	return 1;
}
