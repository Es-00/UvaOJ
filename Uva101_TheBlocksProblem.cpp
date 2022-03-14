#include<cstdio>
#include<vector>
#include<string>
#include<iostream>
using namespace std;

vector<int> blocks[25];
int location[25];

void reset(int a){
    int la = location[a], n = blocks[la].size(), l=0;
    while(blocks[la][l++]!=a);
    for(int i = l; i<n; ++i){
        int x = blocks[la][i];
        blocks[x].push_back(x);
        location[x]=x;
    }
    blocks[la].resize(l);
}

void move(int a,int b){
    int la = location[a], lb = location[b], n = blocks[la].size(), l=0;
    while(blocks[la][l++]!=a);
    for(int i = l - 1; i < n; i++){
        int x = blocks[la][i];
        blocks[lb].push_back(x);
        location[x] = lb;
    }
    blocks[la].resize(l - 1);
}

void printBlocks(int n){
    for(int i=0; i<n; ++i){
        printf("%d:",i);
        int si = blocks[i].size();
        for(int j=0; j<si;++j)
            printf(" %d",blocks[i][j]);
        printf("\n");
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; ++i) {
        blocks[i].push_back(i);
        location[i]=i;
    }
    while(1){
        string s1,s2;
        int a,b;
        cin >> s1;
        if(s1=="quit") break;
        cin >> a >> s2 >> b;
        if(a==b||location[a]==location[b]) continue;
        if(s1=="move") reset(a);
        if(s2=="onto") reset(b);
        move(a,b);
        //printBlocks(n);
    }
    printBlocks(n);
    return 0;
}