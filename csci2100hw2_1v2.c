#include "stdio.h"
#include "stdlib.h"

int main(){

    typedef struct student{
        int orginpos;
        int position;
        int leftmost;
        int rightmost;
    }student;

    int n, m;
    char nchar[1000];
    char mchar[1000];
    char* temp;
    fscanf(stdin, "%s", nchar);
    n = strtol(nchar, &temp, 10);
    fscanf(stdin, "%s", mchar);
    m = strtol(mchar, &temp, 10);

    student* orginpos[n];
    student currentpos[n];

    for(int i=0;i<n;i++){
        currentpos[i].orginpos = currentpos[i].position = currentpos[i].leftmost = currentpos[i].rightmost = i+1;
        orginpos[i] = &currentpos[i]; 
    }

    int swap;
    char swapchar[1000];

    for(int i=0;i<m;i++){
        fscanf(stdin, "%s", swapchar);
        swap = strtol(swapchar, &temp, 10);

        if(orginpos[swap-1]->position - 1 != 0){
            //get swap orgin current position
            int swaporgin = orginpos[swap-1]->position -1;
            //get swap target orginal position for future use
            int swaptarget = currentpos[swaporgin-1].orginpos -1;

            //changing position value
            currentpos[swaporgin].position--;
            currentpos[swaporgin-1].position++;

            //swaping
            student temp = currentpos[swaporgin];
            currentpos[swaporgin] = currentpos[swaporgin-1];
            currentpos[swaporgin-1] = temp;

            //matching correct current position to orgin value postion
            orginpos[swap-1] = &currentpos[swaporgin-1];
            orginpos[swaptarget] = &currentpos[swaporgin];

            if(orginpos[swap-1]->leftmost > orginpos[swap-1]->position){
                orginpos[swap-1]->leftmost = orginpos[swap-1]->position;
            }
            if(orginpos[swaptarget]->rightmost < orginpos[swaptarget]->position){
                orginpos[swaptarget]->rightmost = orginpos[swaptarget]->position;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        printf("%d %d\n",orginpos[i]->leftmost, orginpos[i]->rightmost);
    }
}