#include<iostream>
#include<cctype>
#include<algorithm>
#include<cmath>
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
    int n,sum,pos,pmax,temp,ret;
    scanf("%d",&n);
    while(n-->0){
        queue<int> q;
        vector<int> priority(10,0);
        ret=0,pmax=0;
        scanf("%d%d",&sum,&pos);
        for(int i=0;i<sum;++i){
            scanf("%d",&temp);
            priority[temp]++;
            pmax = max(pmax,temp);
            if(i==pos){
                temp += 10;
            }
            q.push(temp);
        }
        while(1){
            temp = q.front();
            q.pop();
            if(temp%10==pmax){
                ret++;
                if(temp>10){
                    printf("%d\n",ret);
                    break;
                }
                priority[pmax]--;
                while(priority[pmax]==0){
                    --pmax;
                }
            }else{
                q.push(temp);
            }
        }
    }
    return 0;
}