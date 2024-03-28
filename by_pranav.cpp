#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>
using namespace std;

// Assumption : file is prechecked. file exist or not

string club[]={"AI","Dance","Research","Chess","Cubing","Excursion","Microsoft","Radio","DCEI","Sambhav",
    "Developer_Studen","WebKit","Business","BIS","Debate","Music","Programming","IEEE","Heritage","Headrush_Quizzing Club",
    "Muse","Press","DAIICT_Theatre","Film","Khelaiya","EHC","PMMC","CINS"};

unordered_map<string,unordered_map<long long,pair<string,pair<long long,string>>>> load_data(string file_name){ 
    
    ifstream fin;
    fin.open(file_name,ios::in);

    long long id,number;
    string name,club_name,position,temp2;

    unordered_map<string,unordered_map<long long,pair<string,pair<long long,string>>>> directory;

    while(fin>>club_name>>id>>name>>temp2>>number>>position){

        name=name+" "+temp2;

        directory[club_name][id]=make_pair(name,make_pair(number,position));
    }

    fin.close();

    return directory;
}

void mem_club(unordered_map<string,unordered_map<long long,pair<string,pair<long long,string>>>> directory,string club_name){

    int n=1;
    for(auto dir : directory[club_name]){
        cout<<"Person "<<n<<" :"<<endl;
        cout<<"Name : "<<dir.second.first<<endl;
        cout<<"Student ID : "<<dir.first<<endl;
        cout<<"Contact Number : "<<dir.second.second.first<<endl;
        cout<<"Position in club : "<<dir.second.second.second<<endl;
        cout<<endl;
        n++;
    }
    cout<<endl;
}

void get_all_mem(unordered_map<string,unordered_map<long long,pair<string,pair<long long,string>>>> directory){
    
    int n;
    for(int i=0;i<28;i++){
        if(!directory[club[i]].empty()){
            cout<<club[i]<<" Club :"<<endl;
            n=1;
            for(auto dir: directory[club[i]]){
                cout<<n<<". "<<dir.first<<"   "<<dir.second.first<<"   "<<dir.second.second.first<<"   "<<dir.second.second.second<<endl;
                n++;
            }
            cout<<endl;
        }
    }
}

int main(){

    unordered_map<string,unordered_map<long long,pair<string,pair<long long,string>>>> directory;

    directory = load_data("test.txt");

    mem_club(directory,"CINS");

    get_all_mem(directory);

    return 0;
}
