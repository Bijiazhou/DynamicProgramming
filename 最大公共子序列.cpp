//
// Created by 岳晨阳 on 2019/12/16.
//

#include <cstring>
#include <cstdio>

#define MAX 10000

int LcsLength(char *strX,char *strY){
    int C[MAX][MAX],B[MAX][MAX],i,j;

//    状态转移图的行和列
    int m = strlen(strX)+1;
    int n = strlen(strY)+1;

//    初始化首行和首列都是0
    for (int i = 0; i < m; ++i) {
        C[i][0] = 0;
    }
    for (int k = 0; k < n; ++k) {
        C[0][k] = 0;
    }

//    逐步填写状态转移图
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {

            if(strX[i-1] == strY[j-1]){
                C[i][j] = C[i -1][j-1] + 1;
                B[i][j]=1;
            } else if(C[i-1][j] >= C[i][j-1]){
                C[i][j] = C[i -1][j];
                B[i][j]=2;
            } else{
                C[i][j] = C[i][j-1];
                B[i][j]=3;
            }

        }
    }
    return C[m-1][n-1];
}

int main(){
    char strX[MAX],strY[MAX];

    while (EOF != scanf("%s%s",&strX,&strY)){
        int ans = LcsLength(strX,strY);
        printf("%d\n",ans);
    }
}

