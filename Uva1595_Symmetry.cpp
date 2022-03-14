#include<iostream>
#include<cctype>
#include<algorithm>
#include<cmath>
#include<map>
#include<string>
#include<vector>
#include<set>

struct dot{
    int x,y;
    dot(){};
    dot(int a,int b){x=a,y=b;};
};
dot dots[1000+10];

int cmp(dot a,dot b){
    return (a.x<b.x);
}

using namespace std;

map<int,map<int,int>> mp;

int main(){/* 
    freopen("txt/input.txt","r",stdin);
    freopen("txt/output.txt","w",stdout);
    freopen("txt/output.txt","a",stdout); */
    int n,sum;
    bool flag;
    scanf("%d",&n);
    while(n-->0){
        flag = true;
        mp.clear();
        scanf("%d",&sum);
        for(int i=0;i<sum;++i){
            scanf("%d%d",&dots[i].x,&dots[i].y);
            mp[dots[i].x][dots[i].y] = 1;
        }
        sort(dots,dots+sum,cmp);
        int line = (dots[sum/2].x+dots[(sum-1)/2].x);
        for(int i=0;i<sum;++i){
            if(!(mp[line-dots[i].x].count(dots[i].y))){
                flag = false;
                break;
            }
        }
        printf("%s\n",flag?"YES":"NO");
    }
    return 0;
}