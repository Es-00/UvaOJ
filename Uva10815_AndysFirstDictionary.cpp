#include<cstdio>
#include<iostream>
#include<set>
#include<string>
#include<cstring>

using namespace std;

int main(){
    //freopen("txt/input.txt","r",stdin);
    //freopen("txt/output.txt","w",stdout);
    //freopen("txt/output.txt","a",stdout);
    set<string> dictionary;
    char s[200];
    while(scanf("%s",s)==1) {
        int n = strlen(s);
        string buf = "";
        for(int i=0;i<n;++i){
            if(isalpha(s[i]))
                buf += tolower(s[i]);
            else{
                if(!buf.empty()){
                    dictionary.insert(buf);
                    buf = "";
                }
            }
        }
        if(!buf.empty())
            dictionary.insert(buf);
    }
    for(string ds:dictionary) cout << ds << endl;
    return 0;
}