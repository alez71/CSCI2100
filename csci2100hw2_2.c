#include "stdio.h"
#include "stdlib.h"

int stringtomanyint(const char *str, char split, char **endptr)
{
    int temp = 0;
    temp = strtol(str, endptr, 10);
    if (*endptr != NULL) {
        if(**endptr == split){
            *endptr += 1;
        }
    }

    return temp;
}


int main(){

    int t = 0;
    char input[1000000] = "0";
    char* temp;
    char* end = NULL;
    char* string = input;
    fgets(input, sizeof(input), stdin);
    t = strtol(input, &temp, 10);
    int result[t];
    //for each test case
    for(int i=0;i<t;i++){
        int testsize = 0;
        if(testsize == 1){
            result[i] = 1;
            break;
        }
        int notincreasing = 0;
        int sametype = 0;
        fgets(input, sizeof(input), stdin);
        testsize = strtol(input, &temp, 10);

        //check if the number is already in non-decreasing form

        //get number input
        fgets(input, sizeof(input), stdin);
        int currentnum[testsize];
        end = NULL;
        string = input;
        for(int k=0;k<testsize;k++){
            currentnum[k] = stringtomanyint(string,' ',&end);
            string = end;
            //printf("%d, ",currentnum[k]);
        }
        //printf("\n");


        for(int j=1;j<testsize;j++){
            if(currentnum[j-1] > currentnum[j]){
                notincreasing = 1;
            }
        }
        
        //check if same type
        //get type input
        fgets(input, sizeof(input), stdin);
        int currenttype[testsize];
        end = NULL;
        string = input;
        for(int k=0;k<testsize;k++){
            currenttype[k] = stringtomanyint(string,' ',&end);
            string = end;
            //printf("%d, ",currenttype[k]);
        }
        //printf("\n");


        for(int j=1;j<testsize-1;j++){
            if(currenttype[j] != currenttype[j-1]){
                sametype = 0;
                break;
            }
            sametype = 1;
        }

        //printf("notinc = %d, same = %d\n",notincreasing,sametype);

        if(notincreasing && sametype){
            result[i] = 0;
        }else{
            result[i] = 1;
        }
    }

    for(int i=0;i<t;i++){
        if(result[i]){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    //system("pause");
}