#include<iostream>
#include<map>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;


string files[105];

void print(string s,int m){
    cout << s;
    for(int i=s.length();i<m;++i)
        printf(" ");
}

int main(){
    //freopen("txt/input.txt","r",stdin);
    //freopen("txt/output.txt","w",stdout);
    //freopen("txt/output.txt","a",stdout);
    int n,M;
    while(scanf("%d",&n)!=EOF){
        M=0;
        for(int i=0;i<n;++i){
            cin >> files[i];
            M = max(M,int(files[i].length()));
        }
        sort(files,files+n);
        int row,col;
        col = floor(62.0/(M+2));
        row = ceil(double(n)/col);
        for(int i=0;i<60;++i)
            printf("-");
        printf("\n");
        for(int i =0;i<row;++i){
            for(int j=0;j<col;++j){
                if(i+j*row<n){
                    print(files[i+j*row],(i+(j+1)*row)<n?M+2:M);
                }
            }
            printf("\n");
        }
    }
    return 0;
}