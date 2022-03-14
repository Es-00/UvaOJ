#include<iostream>
#include<cctype>
#include<algorithm>
#include<cmath>
#include<map>
#include<string>
#include<vector>
#include<set>
using namespace std;
int main(){
    //freopen("txt/input.txt","r",stdin);
    //freopen("txt/output.txt","w",stdout);
    //freopen("txt/output.txt","a",stdout);
    int n,sum;
    scanf("%d",&n);
    while(n-->0){
        scanf("%d",&sum);
        vector<int> tuples(sum);
        map<vector<int>,int> mp;
        int temp;
        bool isZero = true;

        for(int i=0;i<sum;++i){
            scanf("%d",&tuples[i]);
            if(tuples[i]!=0) isZero = false;
        }

        while(1){
            if(isZero){
                printf("ZERO\n");
                break;
            }
            if(mp.count(tuples)){
                printf("LOOP\n");
                break;
            }
            mp[tuples] = 1;
            isZero = true;
            temp = tuples[0];
            for(int i=0;i<sum-1;++i){
                tuples[i] = abs(tuples[i]-tuples[i+1]);
                if(tuples[i]!=0) isZero = false;
            }
            tuples[sum-1] = abs(tuples[sum-1]-temp);
            if(tuples[sum-1]!=0) isZero = false;
        }
    }
    return 0;
}