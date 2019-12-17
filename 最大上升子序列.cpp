//
// Created by 岳晨阳 on 2019/12/17.
//
#include <stdio.h>
#include <string.h>

#define MAXN 10000

int LISLength(int num,int * seqSrc){
//  res label
//  Len[m] 以m为上界的上升子序列
    int Len[MAXN],res=1;
//    思路：限界上升子序列 逐步逼近
    for (int m = 0; m < num; ++m) {
//        初始化
        Len[m] = 1;
        for (int i = 0; i < m; ++i) {
            //上升子序列 且 长度更大
            if (seqSrc[i] < seqSrc[m] && Len[i] + 1 > Len[m])
                Len[m] = Len[i] + 1;
//            更新最大值
            res = (res > Len[m] ? res : Len[m]);
        }
    }
    return res;
}

int main(){
    int n,seq[MAXN];

    while (scanf("%d",&n)!= EOF){
        for (int i = 0; i < n; ++i) {
            scanf("%d",&seq[i]);
        }
        printf("%d\n",LISLength(n,seq));
    }
    return 0;
}
