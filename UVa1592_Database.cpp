#include<iostream>
#include<cctype>
#include<algorithm>
#include<cmath>
#include<map>
#include<string>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
int main(){
    //freopen("txt/input.txt","r",stdin);
    //freopen("txt/output.txt","w",stdout);
    //freopen("txt/output.txt","a",stdout);
    int r,c;
    while(scanf("%d %d\n",&r,&c)==2){
        vector<vector<string>> table(r,vector<string>(c,""));
        string str;
        for(int i=0;i<r;++i){
            getline(cin,str);
            int len = str.length(),k=0;
            for(int j=0;j<len;++j){
                if(str[j]!=','){
                    table[i][k]+=str[j];
                }else{
                    ++k;
                }
            }
        }
        /*
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
                cout << table[i][j] << " ";
            }
            printf("\n");
        }
        */
        bool flag = true;
        vector<map<string,int>> mp(c);
        for(int i=0;i<r;++i){
            map<int,int> repeat;
            for(int j=0;j<c;++j){
                if(!mp[j].count(table[i][j])){
                    mp[j][table[i][j]] = i;
                }else{
                    if(!repeat.count(mp[j][table[i][j]])){
                        repeat[mp[j][table[i][j]]] = j;
                    }else{
                        flag = false;
                        printf("NO\n");
                        printf("%d %d\n",mp[j][table[i][j]]+1,i+1);
                        printf("%d %d\n",repeat[mp[j][table[i][j]]]+1,j+1);
                        break;
                    }
                }
                if(!flag) break;
            }
        }
        if(flag){
            printf("YES\n");
        }
    }
    return 0;
}