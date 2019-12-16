//
// Created by 岳晨阳 on 2019/12/16.
//

#include <math.h>
#include <stdio.h>
#include <memory.h>

#define MaxStage 100

int minRoad[MaxStage][MaxStage];
int MultiStageGraph(int ,int*);

int MultiStageGraph(int stateNum, int * numPerStage) {
    int i,q,p,weight,temp;
    memset(minRoad,0x3f, sizeof(minRoad));

//    初始化源顶点层
    for (int p = 0; p < numPerStage[0]; ++p) {
        minRoad[0][p] = 0;
    }

//    按照段来计算 终止于最后的那个顶点哪里
    for (int  i = 0; i < stateNum - 1; ++i) {
//      遍历第i段顶点
        for (int q = 0; q < numPerStage[i]; ++q) {
//          遍历第i+1段定点 与前者配合形成边
            for (int p = 0; p < numPerStage[i+1]; ++p) {
                //读取边q p的权重
                scanf("%d",&weight);

                if(weight != -1) {
                    temp = minRoad[i][q] + weight;
//                    都是 i - > p 的路径
                    if(temp < minRoad[i+1][p])
                        minRoad[i+1][p]= temp;
                }
            }
        }

    }
    return minRoad[stateNum-1][0];
}

int main(){
    int ni[MaxStage],k,i;

    while (scanf("%d",&k),k!= -1){
        for (int i = 0; i < k; ++i) {
            scanf("%d",&ni[i]);
        }
        printf("%d\n",MultiStageGraph(k,ni));
    }
}
