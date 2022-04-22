#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>

typedef struct help{
    char* content;
    int orgin;
}help;

int m;

int iseven(int n){
    return n%2==0;
}

int compare(const void* voida, const void* voidb){
    help *a = (help*)voida;
    help *b = (help*)voidb;

    int fdiff = 0;
    for(int i=0;i<m;i++){
        if(a->content[i] != b->content[i]){
            fdiff = i;
            break;
        }
    }
    if(iseven(fdiff+1)){
        if(a->content[fdiff] > b->content[fdiff]){
                return -1; //smaller
            }else if(a->content[fdiff] < b->content[fdiff]){
                return 1; //bigger
                
        }
    }else{
        if(a->content[fdiff] < b->content[fdiff]){
                return -1; //smaller
            }else if(a->content[fdiff] > b->content[fdiff]){
                return 1; //bigger
        }
    }
    return 0;
}

void printarr(help* a, int n){
    for(int i=0;i<n;i++){
        puts(a[i].content);
        printf("str1\n");
    }
}

int main(){
    int n;
    char trash;
    scanf("%d",&n);
    scanf("%d",&m);
    //if it works, it aint bad
    scanf("%c",&trash);
    help ihatec[n];
    for(int i=0;i<n;i++){
        ihatec[i].content = malloc((m+1)*sizeof(char));
        fgets(ihatec[i].content, m+2, stdin);
        ihatec[i].content[m] = '\0';
        ihatec[i].orgin = i+1;
    }
    //printarr(ihatec,n);
    qsort(ihatec,n,sizeof(help), compare);
    for(int i=0;i<n;i++){
            printf("%d ",ihatec[i].orgin);
            //puts(ihatec[i].content);
            free(ihatec[i].content);
    }
    //system("pause");

}