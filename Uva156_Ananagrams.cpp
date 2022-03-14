#include<iostream>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;
int main(){
    //freopen("txt/input.txt","r",stdin);
    //freopen("txt/output.txt","w",stdout);
    //freopen("txt/output.txt","a",stdout);
    map<string,string> mp;
    vector<string> ss;
    set<string> ananagrams;
    string s;
    while(cin >> s){
        if(s=="#") break;
        ss.push_back(s);
        string buf = s;
        for(int i=0;i<s.size();++i)
            buf[i] = tolower(s[i]);
        sort(buf.begin(),buf.end());
        if(!mp.count(buf)){
            mp[buf] = s;
            ananagrams.insert(s);
        }else{
            ananagrams.erase(mp[buf]);
        }
    }
    for(string as:ananagrams) cout << as << endl;
    return 0;
}