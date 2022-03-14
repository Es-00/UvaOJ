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
const int step[8][2]{{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
int dist[8][8],start[2],target[2],x,y,xt,yt;
queue<int> qx,qy;
char str[10];
int main(){/* 
    freopen("txt/input.txt","r",stdin);
    freopen("txt/output.txt","w",stdout);
    freopen("txt/output.txt","a",stdout); */
    while(fgets(str,10,stdin)){
        if(isblank(str[0])) break;
        while(!qx.empty()) qx.pop();
        while(!qy.empty()) qy.pop();
        start[0] = str[0]-'a';
        start[1] = str[1]-'1';
        target[0] = str[3]-'a';
        target[1] = str[4]-'1';
        qx.push(start[0]),qy.push(start[1]);
        memset(dist,0,sizeof(dist));
        dist[start[0]][start[1]] = 1;
        while(1){
            x = qx.front(),y = qy.front();
            if(x==target[0]&&y==target[1]) break;
            qx.pop(),qy.pop();
            for(int i=0;i<8;++i){
                xt = x+step[i][0],yt = y+step[i][1];
                if(xt>=0&&yt>=0&&xt<8&&yt<8&&dist[xt][yt]==0){
                    dist[xt][yt]=dist[x][y]+1;
                    qx.push(xt),qy.push(yt);
                }
            }
        }
        printf("To get from %c%c to %c%c takes %d knight moves.\n",str[0],str[1],str[3],str[4],dist[target[0]][target[1]]-1);
    }
    return 0;
}