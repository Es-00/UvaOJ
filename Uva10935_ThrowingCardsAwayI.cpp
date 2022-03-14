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
int main(){/* 
    freopen("txt/input.txt","r",stdin);
    freopen("txt/output.txt","w",stdout);
    freopen("txt/output.txt","a",stdout); */
    int n;
    queue<int> q;
    while(scanf("%d",&n)){
        if(n==0)
            break;
        for(int i=1;i<=n;++i){
            q.push(i);
        }
        printf("Discarded cards:");
        while(q.size()>1){
            printf(" %d",q.front());
            q.pop();
            q.push(q.front());
            q.pop();
            if(q.size()>1){
                printf(",");
            }
        }
        printf("\n");
        printf("Remaining card: %d\n",q.front());
        q.pop();
    }
    return 0;
}
