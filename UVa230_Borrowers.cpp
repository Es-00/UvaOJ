#include<iostream>
#include<cctype>
#include<algorithm>
#include<cmath>
#include<map>
#include<string>
#include<vector>
#include<set>
struct book{
    std::string title;
    std::string author;
    book(){};
    book(std::string t,std::string a){
        title = t;
        author = a;
    }
};
int cmpBooks(book a,book b){
    if(a.author==b.author){
        return (a.title<b.title);
    }else{
        return (a.author<b.author);
    }
}
using namespace std;

int main(){/* 
    freopen("txt/input.txt","r",stdin);
    freopen("txt/output.txt","w",stdout);
    freopen("txt/output.txt","a",stdout); */
    string s,title,author;
    vector<book> books;
    map<string,int> mp;
    while(getline(cin,s)){
        if(s=="END")
            break;
        for(int i=1;i<s.length();++i){
            if(s[i]=='"'){
                title = s.substr(0,i+1);
                author =s.substr(i+5,s.length()); 
                books.push_back(book(title,author));
                mp[title] = 1;
                break;
            }
        }
    }
    sort(books.begin(),books.end(),cmpBooks);
    while(getline(cin,s)){
        if(s[0]=='E')
            break;
        if(s[0]=='S'){
            s = "";
            for(int i=0;i<books.size();++i){
                if(mp[books[i].title]==0){
                    if(s==""){
                        cout << "Put " << books[i].title << " first" <<endl;
                    }else{
                        cout << "Put " << books[i].title << " after " << s << endl;
                    }
                    mp[books[i].title]=1;
                }
                if(mp[books[i].title]==1)
                    s = books[i].title;
            }
            printf("END\n");
        }else{            
            title = s.substr(7,s.length());
            if(s[0]=='B'){
                mp[title] = -1;
            }else if(s[0]=='R'){
                mp[title] = 0;
            }
        }
    }
    return 0;
}