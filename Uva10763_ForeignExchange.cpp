#include<iostream>
#include<cctype>
#include<algorithm>
#include<cmath>
#include<map>
#include<string>
#include<vector>
#include<set>
using namespace std;
int main(){/* 
    freopen("txt/input.txt","r",stdin);
    freopen("txt/output.txt","w",stdout);
    freopen("txt/output.txt","a",stdout); */
    int n,x,y;
    while(scanf("%d",&n)==1){
        if(n==0) break;
        map<int,map<int,int>> mp;
        int flag = 0;
        for(int i=0;i<n;++i){
            scanf("%d%d",&x,&y);
            if(mp.count(y)&&mp[y].count(x)&&mp[y][x]>0){
                --flag;
                --mp[y][x];
            }else{
                ++flag;
                if(mp.count(x)&&mp[x].count(y)){
                    ++mp[x][y];
                }else{
                    mp[x][y]=1;
                }
            }
        }
        if(flag==0){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }

    return 0;
}