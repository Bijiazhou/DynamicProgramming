//
// Created by 岳晨阳 on 2019/12/17.
//

#include <stdio.h>
#include <string.h>

#define MaxN 1000
#define MaxC 1000
//0-1背包
double binaryKnapsack(int numItems,int *w, double *v,int capacity){
    int i,j;
    double Val[MaxC];
//    初始化
    memset(Val,0, sizeof(Val));
//    依次判断货物
    for (int i = 0; i < numItems; ++i) {
//        依次判断载重
        for (int j = capacity; j >= 0 ; j--) {
//            背包还有空间 且 退步思考 如果上一个没有放会怎么样换成现在的
            if( j >= w[i] && Val[j]< Val[j - w[i]]+v[i])
                Val[j]= Val[j-w[i]]+v[i];
        }
    }
    return Val[capacity];
}

int main(){
    int i,n,C,w[MaxN];
    double v[MaxN];

    double ans;

    while (scanf("%d%d",&n,&C) != EOF){
        for (int i = 0; i < n; ++i)
            scanf("%d",&w[i]);
        for (int i = 0; i < n; ++i)
            scanf("%lf",&v[i]);

        ans = binaryKnapsack(n,w,v,C);
        printf("%0.1f",ans);
        }
    return 0;
}