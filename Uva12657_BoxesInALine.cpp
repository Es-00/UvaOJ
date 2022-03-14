#include<iostream>
#include<cctype>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<map>
#include<string>
#include<vector>
#include<set>

#define maxn 100000+10
struct bigInt{
    unsigned int a,b;
    bigInt(){
        a=0;b=0;
    }
    void plus(int x){
        b += x;
        a += b/100000;
        b = b%100000;
    }
}sum;
using namespace std;

int boxes[maxn][2];

void link(int a,int b){
    boxes[a][1] = b;
    boxes[b][0] = a;
}

int main(){/* 
    freopen("txt/input.txt","r",stdin);
    freopen("txt/output.txt","w",stdout);
    freopen("txt/output.txt","a",stdout); */
    int n,m,a,b,num = 0,op,p1,p2,t;
    bool rev;
    while(scanf("%d%d\n",&n,&m)!=EOF){
        rev = false;
        ++num;
        boxes[0][0] = 0;
        boxes[n+1][0] = n;
        boxes[n+1][1] = n+1;
        for(int i=0;i<=n;++i){
            link(i,i+1);
        }
        while(m-->0){
            scanf("%d",&op);
            if(op==4){
                rev = !rev;
            }else{
                scanf("%d%d",&a,&b);
                if(op==3){
                    if(boxes[a][1]==b){
                        link(boxes[a][0],b);
                        link(a,boxes[b][1]);
                        link(b,a);
                    }else if(boxes[a][0]==b){
                        link(boxes[b][0],a);
                        link(b,boxes[a][1]);
                        link(a,b);
                    }else{
                        p1 =boxes[a][0];
                        p2 = boxes[a][1];
                        link(boxes[b][0],a);
                        link(a,boxes[b][1]);
                        link(p1,b);
                        link(b,p2);
                    }   
                }else{
                    link(boxes[a][0],boxes[a][1]);
                    if(rev){
                        op= op==2?1:2;
                    }
                    if(op==2){
                        link(a,boxes[b][1]);
                        link(b,a);
                    }else{
                        link(boxes[b][0],a);
                        link(a,b);
                    }
                }
            }/* 
            for(int i = boxes[0][1];i<=n;i=boxes[i][1]){
                printf("%d ",i);
            }
            printf("\n"); */
        }
        sum = bigInt();
        if(rev){
            for(int i = boxes[n+1][0];i>0;i=boxes[i][0]){
                sum.plus(i);
                i = boxes[i][0];
            }
        }else{
            for(int i = boxes[0][1];i<=n;i=boxes[i][1]){
                sum.plus(i);
                i = boxes[i][1];
            }
        }
        if(sum.a>0){
            printf("Case %d: %d",num,sum.a);
            for(int i=10000;i>0;i=i/10){
                t = sum.b/i;
                sum.b -= t*i;
                printf("%d",t);
            }
            printf("\n");
        }else{
            printf("Case %d: %d\n",num,sum.b);
        }
    }
    return 0;
}