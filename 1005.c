#include <stdio.h>
#include <string.h>

int main(){
    char english[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char result[110][10], n[100];
    int sum = 0, count = 0;
    scanf("%s", n);
    
    for(int i = 0; n[i] != '\0'; i++){
        sum += n[i] - '0';
    }
    // printf("%d", sum);

    // 注意==0的情况
    if(!sum){
        printf("zero");
    }
    while(sum){
        strcpy(result[count], english[sum % 10]);
        count++;
        sum /= 10;
    }
    for(int i = count-1; i >= 0; i--){
        printf("%s%c", result[i], i == 0 ? '\0' : ' ');
    }
    
    return 0;
}