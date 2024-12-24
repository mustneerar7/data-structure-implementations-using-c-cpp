#include <iostream>
#define MAPSIZE 10

struct node {
    int data;
    node* next;
};

node* table[MAPSIZE];

int hashFunc(int value){
    return value % MAPSIZE;
}

void addToTable(int value){
    int key = hashFunc(value);

    if(table[key] == NULL){
        table[key] = new node;
        table[key]->data = value;
        table[key]->next = NULL;
    } else {

        node* p = table[key];

        while(p->next != NULL)
            p = p->next;

        node* entry = new node;
        entry->data = value;
        entry->next = NULL;

        p->next = entry;
    }
}

void printTable(){
    for(int i=0; i<MAPSIZE; ++i){
        if(table[i] == NULL)
            std::cout << "[" << i << "] " << "NULL" << "\n";
        else {
            std::cout << "[" << i << "] ";

            node *p = table[i];
            while(p != NULL){

                std::cout << p->data << " -> ";

                if(p->next == NULL)
                    std::cout << "NULL";
                p = p->next;


            }

            std::cout << std::endl;
        }
    }
}


int main()
{

    for(int i=0; i <MAPSIZE; ++i)
        table[i] =  NULL;

    addToTable(5);
    addToTable(2);
    addToTable(1);
    addToTable(4);
    addToTable(7);
    addToTable(48);
    addToTable(15);
    addToTable(75);

    printTable();




    return 0;
}
