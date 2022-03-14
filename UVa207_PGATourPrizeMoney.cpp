#include<iostream>
#include<cctype>
#include<algorithm>
#include<cmath>
#include<map>
#include<string>
#include<vector>
#include<set>

class player{
    public:
        std::string name;
        int score[4],dq,tie,place,total[2];
        double prize;
        bool amateur,t,pr;
        player(){          
            place = 1;
            name = "";
            amateur = true;
            dq = 4;
            tie = 0;
            pr = 0;
        };
        player(std::string s);
        void print();
};

player::player(std::string s){
    place = 1;
    name = "";
    amateur = true;
    dq = 4;
    tie = 0;
    pr = 0;
    for(int i=0;i<20;++i){
        if(s[i]=='*')
            amateur = true;
        name += s[i];
    }
    for(int i=0;i<dq;++i){
        score[i] = 0;
        for(int j=0;j<3;++j){
            if(s[21+3*i+j]=='D'){
                dq = i;
                break;
            }
            if(!isblank(s[21+3*i+j]))
                score[i] = 10*score[i] + s[21+3*i+j] - '0';
        }
    }
    total[0] = score[0]+score[1];
    total[1] = total[0]+score[2]+score[3];
};
int cmp1(const player &a,const player &b){
    if(a.dq<2) return 0;
    if(b.dq<2) return 1;
    return a.total[0]>b.total[0];
}
int cmp2(const player &a,const player &b){
    if(a.dq<4) return 0;
    if(b.dq<4) return 1;
    return a.total[1]>b.total[1];
}

void printSpace(int n){
    for(int i=0;i<n;++i)
        printf(" ");
}

void player::print(){
    int space,t;
    std::cout << name << " ";
    space = 10;
    if(dq==4){
        printf("%d",place);
        if(tie) {
            printf("T");
            --space;
        }
        t = place;
        do{
            --space;
        }while((t=t/10)>0);
    }
    printSpace(space);
    for(int i=0;i<dq;++i){
        space = 5;
        printf("%d",score[i]);
        t = score[i];
        do{
            --space;
        }while((t=t/10)>0);
        printSpace(space);
    }
    printSpace(5*(4-dq));
    space = 10;
    if(dq==4){
        printf("%d",total[1]);
        if(!pr){
            printf("\n");
        }else{
            t = total[1];
            do{
                --space;
            }while((t=t/10)>0);
            printSpace(space);
            printf("$");
            space = 6;
            t = floor(prize);
            do{
                --space;
            }while((t=t/10)>0);
            printSpace(space);
            printf("%.2f\n",prize);
        }
    }else{
        printf("DQ\n");
    }
}

using namespace std;

int main(){
    freopen("txt/input.txt","r",stdin);
    freopen("txt/output.txt","w",stdout);
    freopen("txt/output.txt","a",stdout);
    int n1,n2;
    double prize,prizeAllocate[70];
    player players[150];
    string s;
    while(scanf("%d\n\n",&n1)==1){
        scanf("%lf\n",&prize);
        for(int i=0;i<70;++i){
            scanf("%lf\n",&prizeAllocate[i]);
            prizeAllocate[i] *= prize/100;
        }
        scanf("%d\n",&n2);
        for(int i=0;i<n2;++i){
            getline(cin,s);
            s+=" ";
            players[i] = player(s);
        }
        sort(players,players+n2,cmp1);
        int k = 0;
        while(k<n2&&k<70&&players[k].dq>1)
            ++k;
        if(k==70){
            while(k<n2&&players[k].dq>1&&players[k].total[0]==players[69].total[0])
                ++k;
        }
        sort(players,players+k,cmp2);
        int z1=0;
        if(!players[0].amateur){
            players[0].prize = prizeAllocate[z1++];
            players[0].pr = 1;
        }
        for(int i=1;i<k;++i){
            if(players[i].dq<4){
                k = i;
                break;
            }
            if(players[i].total[1] == players[i-1].total[1]){
                players[i].place = players[i-1].place;
            }else{
                players[i].place = k+1;
            }
        }
        sort(players+k,players+n2,cmp2);
        printf("Player Name          Place     RD1  RD2  RD3  RD4  TOTAL     Money Won\n");
        printf("-----------------------------------------------------------------------\n");
        for(int i=0;i<n2;++i)
            players[i].print();
    }
    return 0;
}   