#include<bits/stdc++.h>
using namespace std;

typedef unordered_map<long long, pair<string,pair<long long,string>>> innermap;
typedef unordered_map<string,innermap> outermap;

outermap directory;

void addentry(string type,long long ind,string name,long long phone,string address){
    directory[type][ind]=make_pair(name ,make_pair(phone,address));
}

void deleteentry(string type,long long ind){
    for(auto i : directory[type]){
        if((i.first) == ind){
            directory[type].erase(ind);
            break;
        }
    }
}

void display(){
    for(auto i : directory){
        for(auto j : i.second){
        cout<<i.first<<" "<<(j).first<<" "<<((j).second).first<<" "<<(((j).second).second).first<<" "<<(((j).second).second).second<<endl;
        }
    }
}