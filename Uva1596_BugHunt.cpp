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

map<string,unsigned int> mp1;
map<string,map<unsigned int,int>> mp2;

unsigned int toNum(const string &s){
    unsigned int n=0;
    for(int i = 0;i<s.length();++i){
        n  = n*10 + (s[i] - '0');
    }
    return n;
}

void leftab(const string &l,string &la,string &lb){
    for(int i=0;i<l.length();++i){
        if(l[i]=='['){
            la = l.substr(0,i);
            lb = l.substr(i+1,l.length()-i-2);
            break;
        }
    }
}

unsigned int sToNum(const string &s,bool &isbug){
    string a;
    unsigned int b;
    bool flag = true;
    for(int i=0;i<s.length();++i){
        if(s[i]=='['){
            a = s.substr(0,i);
            b = sToNum(s.substr(i+1,s.length()-i-2),isbug);
            flag = false;
            break;
        }
    }
    if(flag){
        return toNum(s);
    }
    if(isbug){
        return 0;
    }
    if(mp2[a].count(b)){
        return mp2[a][b];
    }else{
        isbug = true;
        return 0;
    }
}

int main(){/* 
    freopen("txt/input.txt","r",stdin);
    freopen("txt/output.txt","w",stdout);
    freopen("txt/output.txt","a",stdout); */
    unsigned int n=0,left,right;
    string s,l,r,la,lb;
    bool flag,isbug=false;
    while(1){
        getline(cin,s);
        ++n;
        if(s=="."){
            if(n==1){
                break;
            }else{
                if(!isbug){
                    printf("0\n");
                }
                n=0;
                isbug = false;
                mp1.clear();
                mp2.clear();
            }
        }else{
            if(isbug) continue;
            flag = false;
            for(int i=0;i<s.length();++i){
                if(s[i]=='='){
                    l = s.substr(0,i);
                    r = s.substr(i+1,s.length());
                    flag = true;
                    break;
                }
            }
            if(flag){
                leftab(l,la,lb);
                left = sToNum(lb,isbug);
                right = sToNum(r,isbug);
                if(left>=mp1[la]){
                    isbug = true;
                }
                if(isbug){
                    printf("%d\n",n);
                    continue;
                }
                mp2[la][left] = right;
            }else{
                leftab(s,la,lb);
                mp1[la]=toNum(lb); 
            }
        }
    }

    return 0;
}