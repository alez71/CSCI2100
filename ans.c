#include <stdio.h>
#include <string.h>
int compare(int alb, char arr1[alb+1],char arr2[alb+1]){
    for(int k = 0; k<alb;k++){
        if(k%2==0){
            if(arr1[k] < arr2[k]){
                return 1; //smaller
            }else if(arr1[k] > arr2[k]){
                return 0; //bigger
            }
        }else{
            if(arr1[k] > arr2[k]){
                return 1; //smaller
            }else if(arr1[k] < arr2[k]){
                return 0; //bigger
            }
        }
    }
    //all equal
    return 1;
}
 
int partition(int set, int alb, char data[set][alb+1], int n, int output[set]){
    int lh = 1, rh;
    int tempnum;
    char pivot[alb+1], temp[alb+1];
    strcpy(pivot, data[0]);
    int pivotnum = output[0];
    rh = n - 1;
 
    do{
        while( lh < rh && compare(alb, pivot, data[rh])){
            rh--;
        }
        while(lh < rh && compare(alb, data[lh], pivot)){
            lh++;
        }
 
        if(lh != rh){
 
            /*strcpy(temp, data[lh]);
            strcpy(data[lh], data[rh]);
            strcpy(data[rh], temp);*/
            tempnum = output[lh];
            output[lh] = output[rh];
            output[rh] = tempnum;
            strcpy(temp , data[lh]);
            strcpy(data[lh],data[rh]);
            strcpy(data[rh], temp);
        }
 
    }while(lh != rh);
 
    if(compare(alb, pivot, data[lh])){
        return 0;
    }
 
    output[0] = output[lh];
    output[lh] = pivotnum;
    strcpy(data[0], data[lh]);
    strcpy(data[lh], pivot);
 
    return lh;
}
 
void quickSort(int set, int alb, char data[set][alb+1], int n, int output[set]){
    int p;
    if(n >1){
        p = partition(set, alb, data, n, output);
        quickSort(set, alb, data, p, output);
        quickSort(set, alb, data+p+1, n-p-1, output+p+1);
    }
    return;
}
 
int main(){
    int set=0, alb=0;
    char temp;
    scanf("%d %d", &set, &alb);
    char data[set][alb+1];
    int output[set];
 
    for(int i = 0; i < set; i++ ){
        scanf("%s", data[i]);
        output[i] = i;
    }
 
    quickSort(set, alb, data, set, output);
 
    for(int k = 0; k < set; k++ ){
        printf("%d ", output[k] + 1);
        //printf("%s\n", data[k]);
    }
    return 0;
}
  	