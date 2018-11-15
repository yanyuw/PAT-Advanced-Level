#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    int c = a + b;
    if(c < 0){
        printf("-");
        c = -c;
    }
    char s[20];
    sprintf(s, "%d", c);
    int len = strlen(s);
    int t = len%3;
    for(int i = 0; i < t; i++){
        printf("%c", s[i]);
        if(i == t-1 && len > 3){
            printf(",");
        }
    }
    
    for(int i = t; i < len; i++){
        printf("%c", s[i]);
        if((i-t+1) % 3 == 0 && i != len-1 ){
            printf(",");
        }
    }
    
    
    return 0;
}