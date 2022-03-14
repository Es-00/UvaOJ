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
char pre[100],mid[100],post[100];
int len,n1,n2;
void reorder(int head,int tail,char c){
    if(head>tail) return;
    ++n1;
    if(head!=tail){
        int k = strchr(mid+head,c)-mid;
        reorder(head,k-1,pre[n1]);
        reorder(k+1,tail,pre[n1]);
    }
    post[n2++] = c;
}



int main(){
    freopen("txt/input.txt","r",stdin);
    freopen("txt/output.txt","w",stdout);
    freopen("txt/output.txt","a",stdout);
    while(scanf("%s%s",pre,mid)==2){
        len = strlen(pre);
        n1 = n2 = 0;
        reorder(0,len-1,pre[n1]);
        post[len] = '\0';
        printf("%s\n",post);
    }
    return 0;
}