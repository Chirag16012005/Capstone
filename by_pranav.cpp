#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Assumption : file is prechecked. file exist or not

string club[] = {"AI", "Dance", "Research", "Chess", "Cubing", "Excursion", "Microsoft", "Radio", "DCEI", "Sambhav",
                 "Developer_Student", "WebKit", "Business", "BIS", "Debate", "Music", "Programming", "IEEE", "Heritage", "Headrush_Quizzing Club",
                 "Muse", "Press", "DAIICT_Theatre", "Film", "Khelaiya", "EHC", "PMMC", "CINS"};

unordered_map<string, unordered_map<long long, pair<string, pair<long long, string>>>> load_data(string file_name)
{
    ifstream fin;
    fin.open(file_name, ios::in);

    long long id, number;
    string name, club_name, position, temp2;

    unordered_map<string, unordered_map<long long, pair<string, pair<long long, string>>>> directory;

    while (fin >> club_name >> id >> name >> temp2 >> number >> position)
    {
        name = name + " " + temp2;
        directory[club_name][id] = make_pair(name, make_pair(number, position));
    }

    fin.close();

    return directory;
}

void mem_club(unordered_map<string, unordered_map<long long, pair<string, pair<long long, string>>>> directory, string club_name)
{
    int n = 1;
    cout << left << setw(20) << "Name" << setw(15) << "Student ID" << setw(15) << "Contact Number" << setw(20) << "Position" << endl;
    cout << "-----------------------------------------------------------" << endl;
    for (auto dir : directory[club_name])
    {
        cout << setw(20) << dir.second.first << setw(15) << dir.first << setw(15) << dir.second.second.first << setw(20) << dir.second.second.second << endl;
        n++;
    }
    cout << "------------//--------------//-------------//--------------" << endl;
    cout << endl
         << endl;
}

void get_all_mem(unordered_map<string, unordered_map<long long, pair<string, pair<long long, string>>>> directory)
{
    int n;
    for (int i = 0; i < 28; i++)
    {
        if (!directory[club[i]].empty())
        {
            cout << "=> " << club[i] << " Club :" << endl;
            cout << endl;
            cout << left << setw(20) << "Name" << setw(15) << "Student ID" << setw(15) << "Contact Number" << setw(20) << "Position" << endl;
            cout << "-----------------------------------------------------------" << endl;
            n = 1;
            for (auto dir : directory[club[i]])
            {
                cout << setw(20) << dir.second.first << setw(15) << dir.first << setw(15) << dir.second.second.first << setw(20) << dir.second.second.second << endl;
                n++;
            }
            cout << "------------//--------------//-------------//--------------" << endl;
            cout << endl
                 << endl;
        }
    }
}

void find_by_id(unordered_map<string, unordered_map<long long, pair<string, pair<long long, string>>>> directory, long long id)
{
    int a = 0, n = 1;
    for (int i = 0; i < 28; i++)
    {
        auto person = directory[club[i]].find(id);
        if (person != directory[club[i]].end())
        {
            a++;
            if (a == 1)
            {
                cout << left << setw(15) << "Student ID" << setw(20) << "Student Name" << "Contact Number" << endl;
                cout << setw(15) << person->first << setw(20) << person->second.first << person->second.second.first << endl;
                cout<<endl;
                cout<<setw(15)<<"Joined Club"<<setw(15)<<"Position"<<endl;
                cout<<n<<"."<<setw(15)<<club[i]<<setw(15)<<person->second.second.second<<endl;
                n++;
            }
            else
            {
                cout<<n<<"."<<setw(15)<<club[i]<<setw(15)<<person->second.second.second<<endl;
                n++;
            }
        }
    }
    if (a == 0)
    {
        cout << "Person not found..!!" << endl;
    }
    cout << endl;
}

void find_by_contact(unordered_map<string, unordered_map<long long, pair<string, pair<long long, string>>>> directory, long long number){

    long long id;
    for(int i=0;i<28;++i){

        for(auto element : directory[club[i]]){

            if(number==element.second.second.first){
                id=element.first;
                find_by_id(directory,id);
                return;
            }
            
        }
    }
}


void find_by_name(unordered_map<string, unordered_map<long long, pair<string, pair<long long, string>>>> directory, string name)
{
    long long id;
    int count = 0;
    for (int i = 0; i < 28; i++)
    {
        for (auto element : directory[club[i]])
        {
            if (name == element.second.first)
            {
                if(count==0){
                    id=element.first;
                    count++;
                }
                else if(count==1){
                    if(id!=element.first){
                        count++;
                        break;
                    }
                }
            }
        }
        if(count==2){
            break;
        }
    }

    if (count == 0)
    {
        cout << "Person not found..!!" << endl;
        cout << endl;
        return;
    }
    else if (count == 1)
    {
        find_by_id(directory,id);
    }
    else if(count==2)
    {
        cout << "Here we got more than one result..!!" << endl;
        cout<<"We want some additional information"<<endl;

        lable:

        cout << "Press 1 for show all results" << endl;
        cout << "Press 2 for find through id" << endl;
        cout<<"Press 3 for find through contact number"<<endl;
        cout<<"Press 4 for find through club name"<<endl;
        int a;
        cin >> a;
        if (a == 1)
        {
            int k;
            vector<long long> vec;
            for(int i=0;i<28;++i){
                for(auto element : directory[club[i]]){
                    if(name == element.second.first){
                        k=0;
                        for(int j=0;j<vec.size();++j){
                            if(element.first==vec[j]){
                                k=1;
                                break;
                            }
                        }
                        if(k==0){
                            vec.push_back(element.first);
                        }
                    }
                }
            }

            for(int i=0;i<vec.size();++i){
                find_by_id(directory,vec[i]);
            }
        }
        else if (a == 2)
        {
            long long b;
            cout << "Enter Student id "<<endl;
            cin >> b;
            find_by_id(directory, b);
        }
        else if( a==3){
            long long number;
            cout<<"Enter number "<<endl;
            cin>>number;
            find_by_contact(directory,number);
        }
        else if(a==4){
            long long id;
            int c=0;
            string cl;
            cout<<"Enter club name"<<endl;
            cin>>cl;

            for(auto element:directory[cl]){
                if(name==element.second.first){
                    if(c==0){
                        c++;
                        id=element.first;
                    }
                    else if(c==1){
                        if(id!=element.first){
                            c++;
                            break;
                        }
                    }
                }
            }

            if(c==0){
                cout<<"You provided wrong club name"<<endl;
                cout<<"Please enter some other detail"<<endl;
                goto lable;
            }
            else if(c==1){
                find_by_id(directory,id);
            }
            else if(c==2){
                cout<<"We got more than one person with same name present in "<<cl<<endl;
                cout<<"We want some additional information"<<endl;
                
                cout<<"Press 1 to show all result"<<endl;
                cout<<"Press 2 to give id"<<endl;
                cout<<"Press 3 to give contact number"<<endl;

                int g;
                cin>>g;

                if(g==1){
                    for(auto element:directory[cl]){
                        if(name==element.second.first){
                            id=element.first;
                            find_by_id(directory,id);
                        }
                    }
                }
                else if(g==2){
                    long long id;
                    cin>>id;

                    find_by_id(directory,id);
                }
                else if(g==3){
                    long long number;
                    cin>>number;

                    find_by_contact(directory,number);
                }
            }
        }
    }
}

void search(unordered_map<string, unordered_map<long long, pair<string, pair<long long, string>>>> directory){
    cout<<"Press 1 to search by id"<<endl;
    cout<<"Press 2 to search by name"<<endl;
    cout<<"Press 3 to search by contact number"<<endl;

    int a;
    cin>>a;
    cin.ignore();

    if(a==1){
        cout<<"Enter student id"<<endl;
        long long id;
        cin>>id;
        find_by_id(directory,id);
    }
    else if(a==2){
        cout<<"Enter name"<<endl;
        string name;
        getline(cin,name);
        cout<<name<<endl;
        find_by_name(directory,name);
    }
    else if(a==3){
        cout<<"Enter contact number"<<endl;
        long long number;
        cin>>number;
        find_by_contact(directory,number);
    }
}

void reload_data(unordered_map<string, unordered_map<long long, pair<string, pair<long long, string>>>> &directory,string file_name){
    ofstream fout;
    fout.open(file_name,ios::out);
    string name,position;
    long long id,number;

    for(int i=0;i<28;++i){

        if(!directory[club[i]].empty()){

            for(auto person : directory[club[i]]){

                id=person.first;
                name=person.second.first;
                number=person.second.second.first;
                position=person.second.second.second;

                fout<<club[i]<<" "<<id<<" "<<name<<" "<<number<<" "<<position<<endl;
            }
        }
    }
    fout.close();
}

void del_entry(unordered_map<string, unordered_map<long long, pair<string, pair<long long, string>>>> &directory){
    string temp,club;
    cout<<"What made you to leave this club"<<endl;
    cin.ignore();
    getline(cin, temp);
    long long id;
    label:
    cout<<"Please enter your id and club name"<<endl;
    cin>>id;
    cin>>club;
    if(directory[club].find(id) != directory[club].end()){
        directory[club].erase(id);
    }
    else{
        cout<<"You have entered wrong club name or id"<<endl;
        goto label;
    }
}



int main()
{

    unordered_map<string, unordered_map<long long, pair<string, pair<long long, string>>>> directory;

    directory = load_data("test.txt");

    search(directory);

    //mem_club(directory, "CINS");

    //get_all_mem(directory);

    //find_by_id(directory, 202303042);

    // find_by_name(directory, "Manan Chhabhaya");
    //find_by_name(directory, "Vraj Patel");
    return 0;
}
