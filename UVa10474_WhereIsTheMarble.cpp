#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int getint(){
    int x;
    scanf("%d",&x);
    return x;
}

int main(){
    //freopen("txt/output.txt","w",stdout);
    //freopen("txt/output.txt","a",stdout);
    int n,q,num=0;
    while(1){
        scanf("%d%d", &n, &q);
        if(n==0&&q==0) break;
        vector<int> m;
        for(int i=0; i<n; ++i) m.push_back(getint());
        sort(m.begin(), m.end());
        printf("CASE# %d:\n", ++num);
        for(int i=0; i<q; ++i){
            int x = getint();
            vector<int>::iterator p = lower_bound(m.begin(),m.end(),x);
            if(*p==x){
                int r = p-m.begin()+1;
                printf("%d found at %d\n",x,r);
            }else{
                printf("%d not found\n",x);
            }
        }
    }
    return 0;
}