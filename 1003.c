#include <stdio.h>
#include <stdlib.h>

int N, M, C1, C2;
int res[500] = {0};
int weight[500][500] = {0};
int dist[500] = {0};
int num[500] = {0};
int maxr[500] = {0};

/* 
    用dijsstra算法
    weight[]:用一维表示的二维数组,weight[i][j]表是顶点i和j之间路径的权值（若无则为无穷)
    dist[]:v到i的最短路径的长度
    num[]:v到i的最短路径条数
    res[]:i城市的救援队数量
    maxr[]:v到i的最大的救援队数量
*/
void dijkstra(){
    // found[i]=1 起始点到i找到了最短路径  =0 未找到
    int found[500] = {0};

    //初始化
    dist[C1] = 0;
    maxr[C1] = res[C1];
    num[C1] = 1;
    
    
    for(int i = 0; i < N; i++){
        int min = __INT_MAX__;
        int Vmin = -1;

        //对不在集合内的顶点（即found==0) 进行遍历 得到距离最小的顶点
        for(int j = 0; j < N; j++){
            if(found[j] == 0 && dist[j] < min){
                Vmin = j;
                min = dist[j];
            }
        }

        //更新c1到未加入集合的顶点j的最小距离，以及最小路径数量，最大救援数量
        found[Vmin] = 1;
        for(int j = 0; j < N; j++){
            if(found[j] == 0 && weight[Vmin][j] != __INT_MAX__){
                if(dist[j] > dist[Vmin] + weight[Vmin][j]){
                    dist[j] = dist[Vmin] + weight[Vmin][j];
                    num[j] = num[Vmin];
                    maxr[j] = res[j] + maxr[Vmin];
                } else if(dist[j] == dist[Vmin] + weight[Vmin][j]){
                    num[j] = num[Vmin] + num[j];
                    if(maxr[j] < maxr[Vmin] + res[j]){
                        maxr[j] = maxr[Vmin] + res[j];
                    }
                }
            }
        }
    }

    
}
int main(){
    scanf("%d %d %d %d", &N, &M, &C1, &C2);

    //初始化w[][], dist[]
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i != j){
                weight[i][j] = __INT_MAX__;
            }
        }
        dist[i] = __INT_MAX__;
    }

    //读取第i个城市的救援队数量
    for(int i = 0; i < N; i++){
        scanf("%d", &res[i]); 
    }

    //读取a b 两个城市之间的边权值
    for(int i = 0; i < M; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);//读取a b之间的道路权值
        weight[b][a] = weight[a][b] = c; //无向图
    }

    dijkstra();
    printf("%d %d", num[C2], maxr[C2]);

    return 0;
}