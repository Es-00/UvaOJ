#include<iostream>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<stack>
using namespace std;

map<set<int>,int> mp;
int cnt = 0;

int ID(set<int> st){
    if(mp.count(st)) return mp[st];
    return mp[st] = cnt++;
}

void pop2(stack<set<int>> &stk,set<int> &a,set<int> &b){
    a = stk.top();
    stk.pop();
    b = stk.top();
    stk.pop();
}

int main(){
    freopen("txt/input.txt","r",stdin);
    freopen("txt/output.txt","w",stdout);
    freopen("txt/output.txt","a",stdout);
    int t;
    cin >> t;
    for(int i=0;i<t;++i){
        int n;
        cin >> n;
        stack<set<int>> stk;
        for(int i=0;i<n;++i){
            string s;
            cin >> s;
            set<int> a,b,c;
            if(s=="PUSH"){
                stk.push(set<int>{});
            }
            else if(s=="DUP"){
                stk.push(stk.top());
            }
            else if(s=="UNION"){
                pop2(stk,a,b);
                for(int u:a)
                    b.insert(u);
                stk.push(b);
            }
            else if(s=="INTERSECT"){
                pop2(stk,a,b);
                for(int u:a){
                    if(b.count(u))
                        c.insert(u);
                }
                stk.push(c);
            }
            else if(s=="ADD"){
                pop2(stk,a,b);
                b.insert(ID(a));
                stk.push(b);
            }
            /*
            set<int> topS = stk.top();
            for(int ts:topS) cout << ts << " ";
            cout << endl;
            */
            cout << stk.top().size() << endl;
        }
        cout << "***" << endl; 
    }
    return 0;
}