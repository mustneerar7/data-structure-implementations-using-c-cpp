/***************************************
    DOUBLY LINKED LIST
    --------------------------------
    Implementation of doubly 
	linked list in C++.
 **************************************/

#include <iostream>

using namespace std;

// Structure of node
struct node {
	int info;
	node* prev;
	node* next;
};

// Prototypes
void insert(int x);
void insert_rear(int x);
void insert_specific(int position, int x);
void delete_front();
void delete_rear();
void delete_specific(int x);


// Global linked list
node *linked_list = NULL;

// Inserts value in front of linked list
void insert(int x){
	node* p;

	if(linked_list == NULL){
		p = new node;
		p->info = x;

		p->prev = NULL;
		p->next = NULL;

		linked_list = p;
	} else {
		
		p = new node;
		p->info = x;

		p->next = linked_list;
		p->prev = NULL;
		
		linked_list = p;

		(p->next)->prev = p;
	}
}

// Deletes value from front
void delete_front(){
	
	if(linked_list == NULL)
		cout << "list is empty.\n";
	else {	
		node *p = linked_list;
		linked_list = p->next;

		delete p;
	}
}

// Inserts value from rear
void insert_rear(int x){
	
	if(linked_list == NULL){
		node* p = new node;
		p->info = x;

		p->next = NULL;
		p->prev = NULL;

		linked_list = p;
	}
	else{	
		node *p = linked_list;
		while(p->next != NULL)
			p = p->next;

		node *q = new node;
		q->info = x;

		q->next = NULL;
		q->prev = p;
		p->next = q;
	}
}

// Inserts value at specific position
void insert_specific(int position, int x){
	
	if(linked_list == NULL){
		node* p = new node;
		p->info = x;

		p->prev = NULL;
		p->next = NULL;

		linked_list = p;
	} else {

		node* p = linked_list;
		while(p->info != position)
			p = p->next;

		node* q = new node;
		q->info = x;

		q->next = p->next;
		q->prev = p->prev;

		(p->next)->prev = q;
		
		p->next = q;
	}
}

// Displays the linked list
void display_list(){
	node* p = linked_list;

	while(p != NULL){
		cout << p->info << " ";
		p = p->next;
	}
	cout << endl;
}

// Deletes node from specific position
void delete_specific(int x){

	if(linked_list == NULL)
		cout << "List is empty.\n";
	else {
		node *p = linked_list;
		while(p->info != x)
			p = p->next;

		(p->prev)->next = p->next;
		(p->next)->prev = p->prev;

		delete p;
	}
}

// Deletes value from the end of linked list
void delete_rear(){

	if (linked_list == NULL)
		cout << "list is empty.";
	else {
		node* p = linked_list;
		while(p->next != NULL)
			p = p->next;

		(p->prev)->next = NULL;
		delete p;
	}
}

int main(){

	insert(5);
	insert(6);
	insert(7);
	display_list();

	delete_front();
	display_list();

	insert_rear(8);
	insert_rear(9);
	display_list();

	insert_specific(8, 10);
	display_list();

	delete_specific(8);
	display_list();

	delete_rear();
	display_list();

	return 0;
}
