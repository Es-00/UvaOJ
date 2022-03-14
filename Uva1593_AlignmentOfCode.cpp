#include<iostream>
#include<cctype>
#include<algorithm>
#include<cmath>
#include<map>
#include<string>
#include<vector>
#include<set>
using namespace std;

int maxlen[180+10] = {0};
int sumOfWords[1000+10];
string words[1000+10][180+10] = {""};

int main(){
    freopen("txt/input.txt","r",stdin);
    freopen("txt/output.txt","w",stdout);
    freopen("txt/output.txt","a",stdout);
    string s;
    int n = 0;
    while(getline(cin,s)){
        int cnt = 0,len=0;
        bool isWord = false;
        for(char c:s){
            if(!isblank(c)){
                words[n][cnt] += c;
                ++len;
                isWord = true;
            }else if(isWord){
                maxlen[cnt] = max(len,maxlen[cnt]);
                len = 0;
                isWord =false;
                ++cnt;
            }
        }
        if(isWord){
                maxlen[cnt] = max(len,maxlen[cnt]);
                len = 0;
                isWord =false;
                ++cnt;
        }
        sumOfWords[n++] = cnt;
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<sumOfWords[i];++j){
            cout << words[i][j];
            if(j==sumOfWords[i]-1){
                printf("\n");
            }else{
                for(int k=words[i][j].length();k<maxlen[j]+1;++k)
                    printf(" ");
            }
        }
    }
    return 0;
}