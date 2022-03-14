#include<iostream>
#include<cctype>
#include<algorithm>
#include<cmath>
#include<map>
#include<string>
#include<vector>
#include<cstring>
#include<set>
#include<stack>
#include<cstdio>
using namespace std;
const int maxn = 128;
char str[maxn+5];
bool balance(){
    fgets(str,maxn+5,stdin);
    int l = strlen(str)-1;
    stack<int> s;
    for(int i=0;i<l;++i){
        if(str[i]==']'){
            if(!s.empty()&&s.top()=='['){
                s.pop();
            }else{
                return false;
            }
        }else if(str[i]==')'){
            if(!s.empty()&&s.top()=='('){
                s.pop();
            }else{
                return false;
            }
        }else{
            s.push(str[i]);
        }
    }
    if(!s.empty())
        return false;
    return true;
}
int main(){/* 
    freopen("txt/input.txt","r",stdin);
    freopen("txt/output.txt","w",stdout);
    freopen("txt/output.txt","a",stdout); */
    int n;
    fgets(str,maxn,stdin);
    sscanf(str,"%d",&n);
    while(n-->0){
        printf("%s\n",balance()?"Yes":"No");
    }
    return 0;
}