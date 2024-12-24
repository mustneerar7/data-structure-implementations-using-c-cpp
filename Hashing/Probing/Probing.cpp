#include <iostream>
#include "math.h"
#define MAPSIZE 10

int table[MAPSIZE];
int fillCount = 0;

int hashFunc(int value){
    return value % MAPSIZE;
}

void addToTable(int value) {

    if(fillCount == MAPSIZE){
        std::cout << "Table is full.\n";
        return;
    }

    int key  = hashFunc(value);

    int i = 1;
    while(table[key] != -1){
        key = hashFunc(value + (i*i));
        ++i;
    }
    table[key] = value;
    ++fillCount;
}


int main()
{
    for(int i=0; i<MAPSIZE; ++i)
        table[i] = -1;

    addToTable(5);
    addToTable(15);
    addToTable(25);
    addToTable(2);
    addToTable(1);
    addToTable(4);
    addToTable(7);
    addToTable(8);
    addToTable(9);
    addToTable(12);
    addToTable(19);

    for(int i=0; i< MAPSIZE; ++i)
        std::cout << table[i] << "\n";

    return 0;
}
