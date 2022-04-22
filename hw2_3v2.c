#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

typedef struct help{
    char* content;
    int orgin;
}help;

int iseven(int n){
    return n%2 == 0;
}

int issmaller(char* str1, char* str2){
    int fdiff;
    int len = strlen(str1)-1;
    //printf("str1=");
    //puts(str1);
    //printf("str2=");
    //puts(str2);
    //printf("len=%d\n",len);
    for(int i=0;i<len;i++){
        if(str1[i] != str2[i]){
            fdiff = i;
            break;
        }
    }
    //printf("diff=%d\n",fdiff);
    int even = iseven(fdiff+1);
    //printf("even = %d\n",even);
    if(even && str1[fdiff] > str2[fdiff]){
        //printf("1\n");
        return 1;
    }
    if(!(even) && str1[fdiff] < str2[fdiff]){
        //printf("1\n");
        return 1;
    }
    return 0;
}

void printarr(help* arr, int len){
    for(int i=0;i<len;i++){
        printf("arrpos=");
        puts(arr[i].content);
    }
}


void merge(help* mainarr, help* arr1, help* arr2, int n1, int n2){
    int p1=0, p2=0,p=0;
    
    //printf("merging\n");
    //printf("arr1=\n");
    //printarr(arr1,n1);
    //printf("arr2=\n");
    //printarr(arr2,n2);

    while(p1<n1 && p2<n2){
        if(issmaller(arr1[p1].content, arr2[p2].content)){
            //printf("smaller");
            //puts(arr1[p1].content);
            mainarr[p++] = arr1[p1++];
        }else{
            //printf("smaller");
            //puts(arr2[p2].content);
            mainarr[p++] = arr2[p2++];
        }

    }
    while (p1<n1){
        mainarr[p++] = arr1[p1++];
    }
    while (p2<n2){
        mainarr[p++] = arr2[p2++];
    }
}

void divide(help* mainarr, help* arr1, help* arr2, int n1, int n2){
    for(int i=0;i<n1;i++){
        arr1[i] = mainarr[i];
    }
    for(int i=0;i<n2;i++){
        arr2[i] = mainarr[i+n1];
    }
}

void mergesort(help* arr, int n){
    int n1, n2;
    help* arr1, *arr2;
    if(n>1){
        n1 = n/2;
        n2 = n-n1;
        arr1 = (help*)malloc(n1*sizeof(help));
        arr2 = (help*)malloc(n2*sizeof(help));
        divide(arr, arr1,arr2,n1,n2);
        mergesort(arr1,n1);
        mergesort(arr2,n2);
        merge(arr,arr1,arr2,n1,n2);
        free(arr1);
        free(arr2);
    }
}


int main(){
    int n,m;
    char trash;
    scanf("%d",&n);
    scanf("%d",&m);
    //if it works, it aint bad
    scanf("%c",&trash);
    help orginal[n];
    for(int i=0;i<n;i++){
        orginal[i].content = malloc((m+1)*sizeof(char));
        fgets(orginal[i].content, sizeof(orginal[i].content),stdin);
        //printf("input=");
        //puts(orginal[i].content);
        orginal[i].orgin = i+1;
    }

    mergesort(orginal, n);
    for(int i=0;i<n;i++){
        printf("%d ",orginal[i].orgin);
        //puts(orginal[i].content);
        free(orginal[i].content);
    }
    //system("pause");
}