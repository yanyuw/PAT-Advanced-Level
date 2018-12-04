#include <stdio.h>
// #include <string.h>

typedef struct{
    char id[20];
    int in;
    int out;
}Person;

int main()
{
    int M;
    scanf("%d",&M);
    Person p[M], *pmin, *pmax;
    for(int i = 0; i < M; i++){
        int tmp[3];
        scanf("%s", p[i].id);
        scanf("%d:%d:%d", &tmp[0], &tmp[1], &tmp[2]);
        p[i].in = tmp[0]*3600 + tmp[1]*60 + tmp[2];
        scanf("%d:%d:%d", &tmp[0], &tmp[1], &tmp[2]);
        p[i].out = tmp[0]*3600 + tmp[1]*60 + tmp[2];
        if(i == 0){
            pmin = &p[i];
            pmax = &p[i];
        } else {
            if(p[i].in <= pmin->in){
                pmin = &p[i];
            }
            if(p[i].out >= pmax->out){
                pmax = &p[i];
            }
        }
    }
    //原来不用思考开门和锁门是同一个啊……
    // if(!strcmp(pmin->id, pmax->id)){
    //     printf("%s", pmin->id);
    // }else{
        printf("%s %s", pmin->id, pmax->id);
    // }
    return 0;
}
