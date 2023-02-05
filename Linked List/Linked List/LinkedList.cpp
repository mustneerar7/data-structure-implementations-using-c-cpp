#include <iostream>

using namespace std;

// basic node structure
struct node{
    int info;
    node *next;
};

// external head of linked list
node *list = NULL;

// inserts value to front
void insertFront(int val){
    node *p;

    if(list == NULL){
        p = new node;
        p->info = val;
        p->next = NULL;

        list = p;
    }
    else{
        p = new node;
        p->info = val;
        p->next = list;

        list = p;
    }
}

// removes value from front
int removeFront(){
    struct node *p;
    int temp = 0;

    if (list == NULL){
        cout << "list is empty\n";
    }
    else{
        p = list;

        list = p->next;
        temp = p->info;

        delete p;
    }
    return temp;
}

// inserts values to rear
void insertRear(int val){
    node *p;
    node *q;

    p = list;

    if (list == NULL){
        p = new node;
        p->info = val;
        p->next = NULL;

        list = p;
    }
    else{

        while(p->next != NULL)
            p = p->next;

        q = new node;
        q->info = val;
        q->next = NULL;

        p->next = q;
    }
}

// removes value from rear
int removeRear(){
    node *p;
    node *q;

    int temp = 0;

    p = list;

    if(list == NULL){
        cout << "list is empty\n";
    }
    else if(p->next == NULL){
        temp = p->info;
        delete p;
    }
    else{

        while(p->next != NULL){
            q = p;
            p = p->next;
        }
        q->next = NULL;
        temp = p->info;

        delete p;
    }
    return temp;
}

// inserts value at a specific position
void insert(int val, int position){
    node *p;

    if(list == NULL){
        p = new node;
        p->info = val;
        p->next = NULL;

        list = p;
    }
    else{
        node *q;
        p = list;

        while(p != NULL){
            if(p->info == position){
                q = new node;
                q->info = val;
                q->next = p->next;

                p->next = q;
            }
            p = p->next;
        }
    }
}

// removes specific value from list
void remove(int val){
    node *p;
    node *q;

    p = list;
    q = list;

    if (list == NULL){
        cout << "list is empty\n";
    }
    else{
        while(p->info != val){
            q = p;
            p = p->next;
        }
        
        q->next = p->next;

        delete p;
    }
}

// displays the list
void display(){
    node *p;
    p = list;

    if(p == NULL){
        cout << "list is empty";
    }

    while(p != NULL){
        cout << p->info << ' ';
        p = p->next;
    }
    cout << endl;
}

// counts the number of nodes
int countNodes(){
    node *p;
    p = list;

    int i = 0;
    while(p != NULL){
        ++i;
        p = p->next;
    }

    return i;
}

int main(void){

    insertFront(5);                 // 5

    insertRear(6);                  // 5, 6
    insertRear(8);                  // 5, 6, 8

    insert(7, 6);                   // 5, 6, 7, 8

    display();                      // 5, 6, 7, 8
    cout << countNodes() << endl;   // 4

    remove(7);                      // 5, 6, 8
    remove(6);                      // 5, 8

    display();                       // 5, 8
    cout << countNodes() << endl;    // 2

    removeRear();                    // 5
    removeFront();                   //
    removeRear();                    // list is empty

    display();                       // list is empty
}