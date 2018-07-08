#include <stdio.h>

int main(){
    int k1,k2,maxt = 0;
    double a1[1001] = {0}, a2[1001] = {0}, b[1001] = {0};
    scanf("%d", &k1);
    for(int i = 0; i < k1; i++){
        int tmp;
        scanf("%d", &tmp);
        scanf("%lf", &a1[tmp]);
        if(tmp > maxt){
            maxt = tmp;
        }
    }
    scanf("%d", &k2);
    for(int i = 0; i < k2; i++){
        int tmp;
        scanf("%d", &tmp);
        scanf("%lf", &a2[tmp]);
        if(tmp > maxt){
            maxt = tmp;
        }
    }
    int count = 0;
    for(int i = 0; i <= maxt; i++){
        b[i] = a1[i] + a2[i];
        if(b[i] != 0){
            count++;
        }
    }
    printf("%d", count);
    for(int i = maxt; i >= 0; i--){
        if(b[i]){
            printf(" %d %.1lf", i, b[i]);
        }
    }

    return 0;
}