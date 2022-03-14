#include<iostream>
#include<sstream>
#include<cctype>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<set>
#include<queue>

using namespace std;
int main(){
    freopen("txt/input.txt","r",stdin);
    freopen("txt/output.txt","w",stdout);
    freopen("txt/output.txt","a",stdout);
    int teamSum,scenario = 0;
    while(scanf("%d",&teamSum)){
        if(teamSum==0) break;
        queue<int> mainq;
        map<int,int> team;
        for(int i = 0;i<teamSum;++i){
            int x,teamNum;
            scanf("%d",&teamNum);
            for(int j=0;j<teamNum;++j){
                scanf("%d",&x);
                team[x] = i;
            }
        }
        cout << "Scenario #" << ++scenario << endl; 
        string op;
        vector<queue<int>> subq(1000);
        while(cin>>op){
            if(op[0]=='S') break;
            if(op[0]=='E'){
                int x,teamnumber;
                scanf("%d",&x);
                teamnumber = team[x];
                if(subq[teamnumber].empty()){
                    mainq.push(teamnumber);
                }
                subq[teamnumber].push(x);
            }
            else if(op[0]=='D'){
                int t,x;
                t = mainq.front();
                x = subq[t].front();
                subq[t].pop();
                if(subq[t].empty()) mainq.pop();
                printf("%d\n",x);
            }
        }
        printf("\n");
    }
    return 0;
}