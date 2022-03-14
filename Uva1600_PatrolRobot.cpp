#include<iostream>
#include<cctype>
#include<algorithm>
#include<cmath>
#include<map>
#include<string>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<climits>
#include<cstring>
using namespace std;
int sum,n,m,k,mindist,dist,maze[20][20],vist[20][20],d[20][20];
const int step[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int getint(){
    int x;
    scanf("%d",&x);
    return x;
}
void dfs(int x,int y,int k1){
    if(maze[x][y]==0){
        k1=k;
        if(d[x][y]==-1||dist<d[x][y]){
            d[x][y]=dist;
        }else{
            return;
        }
    }else{
        if(--k1<0) return;
    } 
    vist[x][y]=1;
    if(x==m-1&&y==n-1){
        if(mindist==-1||dist<mindist){
            mindist = dist;
        }
    }else{
        int xt,yt;
        for(int i=0;i<4;++i){
            xt=x+step[i][0],yt=y+step[i][1];
            if(xt>=0&&xt<m&&yt>=0&&yt<n&&vist[xt][yt]==0){
                ++dist;
                dfs(xt,yt,k1);
                --dist;
            }
        }
    }
    vist[x][y]=0;
}
int main(){/* 
    freopen("txt/input.txt","r",stdin);
    freopen("txt/output.txt","w",stdout);
    freopen("txt/output.txt","a",stdout); */
    scanf("%d",&sum);
    while(sum-->0){
        scanf("%d%d%d",&m,&n,&k);
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                maze[i][j]=getint();
            }
        } 
        memset(vist,0,sizeof(vist));
        memset(d,-1,sizeof(d));
        dist=0,mindist=-1;
        dfs(0,0,k);
        printf("%d\n",mindist);
    }
    return 0;
}