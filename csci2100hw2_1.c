#include "stdio.h"
#include "stdlib.h"

int main(){

    struct student{
        struct student* frontstudent;
        int position;
        int leftmost;
        int rightmost;
        struct student* backstudent;
    };

    int n, m;
    char nchar[100000];
    char mchar[400000];
    char* temp;
    fscanf(stdin, "%s", nchar);
    n = strtol(nchar, &temp, 10);
    fscanf(stdin, "%s", mchar);
    m = strtol(mchar, &temp, 10);

    int swap;
    char swapchar[100000];
    struct student orginalpos[n];

    //intialize position
    for(int i=0;i<n;i++){
        orginalpos[i].position = orginalpos[i].leftmost = orginalpos[i].rightmost = i+1;
        if(i == 0){
            orginalpos[i].frontstudent = NULL;
            orginalpos[i].backstudent = &orginalpos[i+1];
        }else if(i == n-1){
            orginalpos[i].frontstudent = &orginalpos[i-1];
            orginalpos[i].backstudent = NULL;
        }else{
            orginalpos[i].frontstudent = &orginalpos[i-1];
            orginalpos[i].backstudent = &orginalpos[i+1];
        }
    }
    for(int i=0;i<m;i++){
        fscanf(stdin, "%s", swapchar);
        swap = strtol(swapchar, &temp, 10);
        struct student* ihatec = &orginalpos[swap-1];
        struct student* frontstudent = orginalpos[swap-1].frontstudent;
        struct student* backstudent = orginalpos[swap-1].backstudent;
        if(orginalpos[swap-1].frontstudent != NULL){

            ihatec->position --;
            frontstudent->position++;
            if(frontstudent->frontstudent != NULL){
                frontstudent->frontstudent->backstudent = &orginalpos[swap-1];
            }
            backstudent->frontstudent = frontstudent;

            ihatec->frontstudent = frontstudent->frontstudent;
            frontstudent->backstudent = ihatec->backstudent;
            frontstudent->frontstudent = &orginalpos[swap-1];
            ihatec->backstudent = frontstudent;

            if(ihatec->position < ihatec->leftmost){
                ihatec->leftmost = ihatec->position;
            }
            if(frontstudent->position > frontstudent->rightmost){
                frontstudent->rightmost = frontstudent->position;
            }
        }
    }

    for(int i=0;i<n;i++){
        printf("%d %d\n",orginalpos[i].leftmost,orginalpos[i].rightmost);
    }
}