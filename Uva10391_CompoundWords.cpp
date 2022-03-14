#include<iostream>
#include<cctype>
#include<algorithm>
#include<cmath>
#include<map>
#include<string>
#include<vector>
#include<set>

using namespace std;

string words[120000];
map <string,int> mp;

int main(){/* 
    freopen("txt/input.txt","r",stdin);
    freopen("txt/output.txt","w",stdout);
    freopen("txt/output.txt","a",stdout); */
    int n=0;
    while(cin>>words[n]){
        mp[words[n]] = 1;
        ++n;
    }
    int len;
    string a,b;
    for(int i=0;i<n;++i){
        len = words[i].length();
        for(int j=1;j<len;++j){
            a=words[i].substr(0,j);
            b=words[i].substr(j,len);
            if(mp.count(a)&&mp.count(b)){
                cout << words[i] <<endl;
                break;
            }
        }
    }
    return 0;
}