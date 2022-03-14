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
int layer[8];
char terminal[500],op[10],str[50];
int main(){
/*     freopen("txt/input.txt","r",stdin);
    freopen("txt/output.txt","w",stdout);
    freopen("txt/output.txt","a",stdout);
  */   int n,m,order=1,head,tail,l;
    while(fgets(str,10,stdin)){
        sscanf(str,"%d",&n);       
        if(n==0) break;
        printf("S-Tree #%d:\n",order++);
        fgets(str,30,stdin);
        for(int i=0;i<n;++i){
            layer[i]=str[3*i+1]-'0';
        }
        fgets(terminal,500,stdin);
        l = strlen(terminal)-1;
        fgets(str,10,stdin);
        sscanf(str,"%d",&m);
        for(int i=0;i<m;++i){
            fgets(op,10,stdin);
            head=0,tail=l;
            for(int j=0;j<n;++j){
                if(op[layer[j]-1]=='0'){
                    tail = (head+tail)/2;
                }else{
                    head = (head+tail)/2;
                }
            }
            printf("%c",terminal[head]);
        }
        printf("\n\n");
    }
    return 0;
}