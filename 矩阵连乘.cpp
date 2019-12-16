//
// Created by 岳晨阳 on 2019/12/16.
//
#include <stdio.h>
#include <string.h>

#define MaxNum 1000

//矩阵个数
long MatrixChain(int );

int dim[MaxNum];

//记录最优值的数组 m
long memoTabel[MaxNum][MaxNum];
//记录最优分配位置k的数组 s
int bestK[MaxNum][MaxNum];

long MatrixChainMemo(int i,int j);

int main(){
    int i,matrixNum;
    while (EOF != scanf("%d",&matrixNum)){
        for (int i = 0; i <= matrixNum; ++i) {
            scanf("%d",&dim[i]);
//            printf("%ld",MatrixChain(matrixNum));
        }
        memset(memoTabel,-1, sizeof(memoTabel));
        printf("%ld",MatrixChainMemo(1,matrixNum));

    }
    return 0;
}


long MatrixChain(int matrixNum){
    int i,j,len,k;

//    对角线自己乘自己
    for (int i = 0; i < matrixNum; ++i) {
        memoTabel[i][i] = 0;
    }

//    长度为len的矩阵的最优值
    for (int len = 2; len < matrixNum ; ++len) {
//矩阵链开始矩阵下标
        for (int i = 1; i < matrixNum - len + 1; ++i) {
//            矩阵链结束矩阵下标
            j = i + len -1;
            memoTabel[i][j] = 1000000;

            for (int k = 0; k < j; ++k) {

                long ans = memoTabel[i][k] + memoTabel[k+1][j] + dim[i-1]*dim[k]*dim[j];

                if (ans < memoTabel[i][j]) {
                    bestK[i][j] = k;
                    memoTabel[i][j] = ans;
                }
            }
        }
    }
    return memoTabel[1][matrixNum];
}

//递归方法
long MatrixChainMemo(int i,int j){
//    不是-1代表有填上数字
    if(memoTabel[i][j] != -1)
        return memoTabel[i][j];

//    对角线是自己乘自己
    if(i == j) {
        memoTabel[i][j] = 0;
        return 0;
    }

//    初始化ans 和 max
    long ans,max = 10000000;

//    递归调用自己  每一次都是 i->k + k+1 ->j + ***
    for (int k = i; k < j; ++k) {
        ans = MatrixChainMemo(i,k) +  MatrixChainMemo(k+1,j) + dim[i-1]*dim[k]*dim[j];

        if (ans < max){
            bestK[i][j] = k;
            max = ans;
        }
    }
    memoTabel[i][j] = max;
    return max;
}