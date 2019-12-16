
/* [动态规划]描述
        顺治喜欢滑雪，这并不奇怪， 因为滑雪的确很刺激。可是为了获得速度，滑的区域必须向下倾斜，而且当你滑到坡底，你不得不再次走上坡或者等待太监们来载你。顺治想知道载一个区域中最长的滑坡。

区域由一个二维数组给出。数组的每个数字代表点的高度。下面是一个例子：

1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

顺治可以从某个点滑向上下左右相邻四个点之一，当且仅当高度减小。在上面的例子中，一条可滑行的滑坡为24-17-16-1。当然25-24-23-...-3-2-1更长。事实上，这是最长的一条。

格式
        输入格式
输入的第一行表示区域的行数R和列数C(1 <= R,C <= 500)。下面是R行，每行有C个整数，代表高度h，0<=h<=10000。

输出格式
        输出最长区域的长度。

样例1
        样例输入1
5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
样例输出1
25

思路
将高度存入结构体排序，每一次去找他的上下左右，如果比这个数小，则更新那个点的值，最后找每个结点中的值的最大值即可。

状态转移方程：
f[xx+g1[i]][yy+g2[i]]=max(f[xx+g1[i]][yy+g2[i]],f[xx][yy]+1);(g1,g2为方向)"
*/

#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

//每行每列最大值
const int maxn=505;

struct node{
    int x,y,num;
}_map[250005];

//方向？？
int g1[4]={1,-1,0,0};
int g2[4]={0,0,1,-1};

int a[maxn][maxn];
int f[maxn][maxn];
//r c 行列
int r,c,temp;

//两个节点进行比较
bool comp(const node &q,const node &w)
{
    return q.num>w.num;
}

int main()
{
//    初始化
    memset(f,0,sizeof(f));
    scanf("%d%d",&r,&c);
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
        {
            int x;scanf("%d",&x);
            a[i][j]=x;
            _map[++temp].x=i;
            _map[temp].y=j;
            _map[temp].num=x;
        }
    sort(_map+1,_map+temp+1,comp);

    int start=1;
    while(start<=temp)
    {
        int xx=_map[start].x,yy=_map[start].y;
        for(int i=0;i<=3;i++)
        {
            if(a[xx+g1[i]][yy+g2[i]]<a[xx][yy])
                f[xx+g1[i]][yy+g2[i]]=max(f[xx+g1[i]][yy+g2[i]],f[xx][yy]+1);
        }
        start++;
    }

    int ans=0;
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            ans=max(ans,f[i][j]);
    printf("%d",ans+1);
    return 0;
}