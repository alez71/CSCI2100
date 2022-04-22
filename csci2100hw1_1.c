#include "stdio.h"
#include "stdlib.h"


int isclosingbacket(char backet){
    if(backet == '>' || backet == '}' || backet == ']' || backet == ')'){
        return 1;
    }else return 0;
};

int NoMatchOpening(char openbacket, char closebacket){
    switch (openbacket){
        case '<':
            if(closebacket == '>'){return 0;};break;
        case '[':
            if(closebacket == ']'){return 0;};break;
        case '{':
            if(closebacket == '}'){return 0;};break;
        case '(':
            if(closebacket == ')'){return 0;};break;
        default:
            return 1;
    }

};


int main(){
    int maxsize = 256;
    char* backetstack = (char*)calloc(maxsize, sizeof(char));
    int count = 0;
    int strptr = 0;
    //printf("Input:\n");
    while((backetstack[strptr] = getchar()) != EOF && backetstack[strptr] != '\n'){
        //if the character is not a backet, skip iteration and jump to next character
        // if(notbacket(backetstack[strsize])){
        //     continue;
        // };

        //if current strsize is 1 lower then max, increase array length
        if(strptr == maxsize-2){
            //double stack size and relocate memory
            maxsize = 2*maxsize;
            backetstack = (char*)realloc(backetstack, maxsize*sizeof(char));
        }
        if(isclosingbacket(backetstack[strptr])){
            if(strptr>0){
                if(NoMatchOpening(backetstack[strptr-1], backetstack[strptr])){
                    count++;
                };
                //remove the pair of backet and reset their place to 0
                backetstack[strptr--] = 0;
                backetstack[strptr] = 0;
                continue;
            }else{
                printf("Output:\n");
                printf("Impossible\n");
                free(backetstack);
                system("PAUSE");
                //exit(1);
            }
        }
        strptr++;
    }

    //if there is any remaining backets, it cannot be a perfect bracket
    if(strptr>0){
        //printf("Output:\n");
        printf("Impossible\n");
        free(backetstack);
        system("PAUSE");
        //exit(1);
    }else{
        //printf("Output:\n");
        printf("%d\n",count);
        free(backetstack);
        system("PAUSE");
        //exit(1);
    };

}