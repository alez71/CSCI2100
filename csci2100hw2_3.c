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

void printarr(help* arr[], int len){
    for(int i=0;i<len;i++){
        printf("arrpos=");
        puts(arr[i]->content);
    }
}


void merge(help* arr, int left, int mid, int right){
    int i,j,k;
    int n1 = mid-left+1;
    int n2 = right-mid;
    help l[n1],r[n2];


    for(i=0;i<n1;i++){
        l[i] = arr[left+i];
    }


    for(j=0;j<n2;j++){
        r[j] = arr[mid+1+j];
    }
    i=j=0;
    k=left;
    while(i<n1 && j<n2){
        if(issmaller(l[i].content,r[j].content)){
            arr[k] = l[i];
            i++;
        }else{
            arr[k] = r[j];
            j++;
        }
        k++;
    }

    while (i<n1){
        arr[k] = l[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = r[j];
        j++;
        k++;
    }

}

void mergesort(help* arr, int left, int right){
    if(left < right){
        int mid = (left+right)/2;
        mergesort(arr, left, mid);
        mergesort(arr, mid+1, right);
        merge(arr, left, mid, right);
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
        orginal[i].content = malloc(m*sizeof(char));
        fgets(orginal[i].content, sizeof(orginal[i].content),stdin);
        //printf("input=");
        //puts(orginal[i].content);
        orginal[i].orgin = i+1;
        //printf("input=");
        //puts(result[i]->content);
    }

    mergesort(orginal, 0, n-1);
    for(int i=0;i<n;i++){
        printf("%d ",orginal[i].orgin);
        //puts(orginal[i].content);
        free(orginal[i].content);
    }
    //system("pause");
}