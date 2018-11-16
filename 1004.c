#include <stdio.h>

int v[100][100], child[100] = {0}, result[100], maxd = -1;

/*
    思路：用dfs遍历树并记录当前层的叶子结点
*/

void dfs(int index, int depth){
    if(child[index] == 0){
        result[depth]++;
        maxd = maxd > depth ? maxd : depth;
        return;
    }
    for(int i = 0; i < child[index]; i++){
        dfs(v[index][i], depth + 1);
    }
}

int main(){
    int N, M, id, K;

    scanf("%d %d", &N, &M);

    for(int i = 0; i < M; i++){
        scanf("%d %d", &id, &K);
        for(int j = 0; j < K; j++){
            int c;
            scanf("%d", &c);
            v[id][child[id]] = c;
            child[id]++;
        }
    }

    dfs(1, 0);
    
    for(int i = 0; i <= maxd; i++){
        printf("%d%c", result[i], i != maxd ? ' ' : '\0');
    }
    return 0;
}