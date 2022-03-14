#include<iostream>
#include<cctype>
#include<algorithm>
#include<cmath>
#include<map>
#include<cstring>
#include<string>
#include<vector>
#include<set>
#include<queue>
#include<climits>
using namespace std;
int n,m;
int dist[100000+10],color[100000+10],ancestor[100000+10],vist[100000+10];
vector<vector<int>> path[100000+10];
void bfs(){
    //vector<int> dist(n+1,INT_MAX),color(n+1,INT_MAX),ancestor(n+1,0);
    //vector<int> ftime(n+1,0);
    queue<int> q;
    int x,d1,d2;
    q.push(n);
    dist[n] = 0;
    vist[n] = 1;
    ancestor[n] = -1;
    while(!q.empty()){
        x = q.front();
        q.pop();
        if(x==1) break;
        for(vector<int> p:path[x]){
            if(vist[p[0]]==0){
                vist[p[0]] = 1;
                q.push(p[0]);
                color[p[0]] = p[1];
                dist[p[0]] = dist[x]+1;
                ancestor[p[0]] = x;
            }else if(dist[x]+1==dist[p[0]] && p[1] <= color[p[0]]){
                if(p[1]==color[p[0]]){
                    d1=x,d2=ancestor[p[0]];   
                    while(d1!=d2&&d1!=n&&d2!=n&&color[d1]==color[d2]){
                        d1 = ancestor[d1];
                        d2 = ancestor[d2];
                    }   
                    if(d1==d2 || color[d1]>=color[d2]) continue;
                }
                color[p[0]] = p[1];
                ancestor[p[0]] = x;
            }
        }
    }
    int l = dist[x];
    printf("%d\n",l);
    for(int i=0;i<l;++i,x=ancestor[x]){
        printf("%d",color[x]);
        if(i==l-1)
            printf("\n");
        else
            printf(" ");
    }
    return;
}
int main(){
    /* freopen("txt/input.txt","r",stdin);
    freopen("txt/output.txt","w",stdout);
    freopen("txt/output.txt","a",stdout); */
    
    int r1,r2,c;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=1;i<=n;++i){
            path[i].clear();
        }
        memset(dist,0,(n+1)*sizeof(int));
        memset(color,0,(n+1)*sizeof(int));
        memset(vist,0,(n+1)*sizeof(int));
        for(int i=0;i<m;++i){
            scanf("%d%d%d",&r1,&r2,&c);
            path[r1].push_back({r2,c});
            path[r2].push_back({r1,c});
        }
        bfs();
    }
    return 0;
}