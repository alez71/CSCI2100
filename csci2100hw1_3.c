#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

int max(int a, int b, int c){
    if(abs(a) >= abs(b) && abs(a) >= abs(c)){return a;};
    if(abs(b) >= abs(c) && abs(b) >= abs(a)){return b;};
    if(abs(c) >= abs(b) && abs(c) >= abs(a)){return c;};
}

int min(int a, int b){
    if(a<b){return a;}else{return b;};
}

int check(char* str1, char* str2, int len1, int len2){
    //check s1 s2 with s1 suffix and s2 prefix
    // ==
    //   ==
    // ==
    //  ==
    int match1 = 0;
    int check1 = 1;
    for (int i=1; i<=min(len1, len2); i++){
        // printf("i=%d\n",i);
        for(int j=0;j<i;j++){
            // printf("j=%d\n",j);
            if(str1[len1-i+j] != str2[j]){
                // printf("break i=%dj=%d\n",i,j);
                check1 = 0;
                break;
            }
            check1 = 1;
        };
        if(check1){match1 = i;};
        // printf("match=%d\n",match1);
    }
    //check s1 s2 with s1 prefix and s2 suffix
    //    ==
    //  ==
    //    ==
    //   ==
    int match2 = 0;
    int check2 = 1;
    for (int i=1; i<=min(len1, len2); i++){
        for(int j=0;j<i;j++){
            if(str1[j] != str2[len2-i+j]){
                check2 = 0;
                break;
            }
        };
        if(check2){match2 = i;};
    }

    // if overlap of s1suffix s2prefix is larger
    // return result of s1suffs2pref
    // else return negative of s1prefs2suff
    if(match1>match2){
        // printf("match1=%d\n",match1);
        return match1;
    }else{
        // printf("match2=%d\n",match2);
        return -match2;
    }
}

void combine(char* s1, char* s2, int len1, int len2, int match, char* middle){
    if(match >= 0){
        strcpy(middle, s1);
        for(int i = 0; i<len2-match; i++){
            middle[len1+i] = s2[i+match];
        }
    }else if(match < 0){
        match = -match;
        strcpy(middle, s2);
        for(int i = 0;i<len1-match;i++){
            middle[len2+i] = s1[i+match];
        }
    }
}


void clearstring(char* str, char f){
    str[0] = f;
    int i = 1;
    while(str[i] != 0){
        str[i++] = 0;
    }
}

void checkrepeat(char* s1,char* s2,char* s3){
    if(strstr(s1, s2) != NULL){
        clearstring(s2, s1[0]);
    }else if(strstr(s2, s1) != NULL){
        clearstring(s1, s2[0]);
    }
    if(strstr(s2, s3) != NULL){
        clearstring(s3, s2[0]);
    }else if(strstr(s3, s2) != NULL){
        clearstring(s2, s3[0]);
    }
    if(strstr(s1, s3) != NULL){
        clearstring(s3, s1[0]);
    }else if(strstr(s3, s1) != NULL){
        clearstring(s1, s3[0]);
    }
}

int main(){
    char s1[100000] = {0};
    char s2[100000] = {0};
    char s3[100000] = {0};
    char middle[200000] = {0};
    char final[300000] = {0};
    fgets(s1, 1000001-1, stdin);
    fgets(s2, 1000001-1, stdin);
    fgets(s3, 1000001-1, stdin);


    int lens1 = 0;
    while(s1[lens1] != 10){lens1++;};
    s1[lens1] = 0;
    int lens2 = 0;
    while(s2[lens2] != 10){lens2++;};
    s2[lens2] = 0;
    int lens3 = 0;
    while(s3[lens3] != 10){lens3++;};
    s3[lens3] = 0;

    checkrepeat(s1,s2,s3);
    checkrepeat(s1,s2,s3);

    lens1 = 0;
    while(s1[lens1] != 0){lens1++;};
    s1[lens1] = 0;
    lens2 = 0;
    while(s2[lens2] != 0){lens2++;};
    s2[lens2] = 0;
    lens3 = 0;
    while(s3[lens3] != 0){lens3++;};
    s3[lens3] = 0;

    int s1s2 = check(s1, s2, lens1, lens2);
    int s2s3 = check(s2, s3, lens2, lens3);
    int s1s3 = check(s1, s3, lens1, lens3);
    int temp = max(s1s2, s2s3, s1s3);
    if(temp == s1s2){
        combine(s1, s2, lens1, lens2, s1s2, middle);
        temp = check(middle, s3, lens1+lens2-s1s2, lens3);
        combine(middle,s3,lens1+lens2-s1s2,lens3,temp,final);
    }else if(temp == s2s3){
        combine(s2,s3,lens2,lens3,s2s3,middle);
        temp = check(middle, s1, lens2+lens3-s2s3,lens1);
        combine(middle,s1,lens2+lens3-s1s2,lens1,temp,final);
    }else{
        combine(s1,s3,lens1,lens3,s1s3,middle);
        temp = check(middle,s2,lens1+lens3-s1s3,lens2);
        combine(middle,s2,lens1+lens3-s1s3,lens2,temp,final);
    }
    int a = 0;
    // while(s1[a] != 0){
    //     printf("%c ",s1[a]);
    //     a++;
    // }
    // printf("\n");
    // a = 0;
    // while(s2[a] != 0){
    //     printf("%c ",s2[a]);
    //     a++;
    // }
    // printf("\n");
    // a = 0;
    // while(s3[a] != 0){
    //     printf("%c ",s3[a]);
    //     a++;
    // }
    // printf("\n");
    // a = 0;
    // while(middle[a] != 0){
    //     printf("%c ",middle[a]);
    //     a++;
    // }
    // printf("\n");
    end:
    a = 0;
    while(final[a] != 0){
        // printf("%c ",final[a]);
        a++;
    }
    printf("%d",a);
    
    

    // system("PAUSE");
}