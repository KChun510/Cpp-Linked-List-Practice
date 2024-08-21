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
	~Node(){
//		delete this->next; 
	}
};

class linkedList{
	Node* head;
public:
	linkedList(){head = NULL;};
	void insertNode(int); 
	void printList();
	void deleteNode(int);
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
		
	std::cout << temp->data << std::endl;
	
	
}

void linkedList::deleteNode(int location){
	location -= 1;
	// Everything starts from the head.
	// That why when we do a delete "temp", the actual node gets deleted.
	// Because it linked to our head object.
	Node* temp = head; 
	if ( head == NULL){
		std::cout << "Empty List";
		return;
	}
	// Delete the head
	if(location == -1){
		head = temp->next;
		delete temp;
	}

	
	for(int i = 0; i <= location; i++){
		Node* curr = temp;
		temp = temp->next;
		if(i == location & temp->next != NULL){
			curr->next = temp->next;
			delete temp; 
		}
		// Reached the end of link
		else if( i == location & temp->next == NULL){
			delete temp;
			
		}

	}

	
}


void dataGen(int max){	
	linkedList lnkList;
	for(int i = 0; i < max; i++){
		lnkList.insertNode(i);
	}
	lnkList.printList();
	lnkList.deleteNode(0);
	lnkList.deleteNode(3);
	lnkList.deleteNode(4);
	lnkList.printList();
	
}

//TO-DO: Write our delete Node method
int main(){
	dataGen(10);
	return 1;
}
