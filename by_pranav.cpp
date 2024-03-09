#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Person{

public:

    string club_name;
    long long id;
    string name;
    long long contact;
    string pos;

    Person(){
        club_name="empty";
        id=0;
        name="empty";
        contact=0;
        pos="empty";
    }    

    ~Person(){

    }

    void dis_search(){
        cout<<"Name : "<<name<<"\n"<<"Id : "<<id<<"\n"<<"Contact Number : "<<contact<<"\n"<<"Joined club's : "<<"\n"<<club_name<<" : "<<pos<<endl;
    }

    void copy(Person C){
        club_name=C.club_name;
        id=C.id;
        name=C.name;
        contact=C.contact;
        pos=C.pos;
    }

};

void search_id(long long a){

    ifstream fi;
    int k=0;
    fi.open("test.txt",ios::in);
    
    if(!fi){
        cout<<"File not found"<<endl;
    }
    else{
        int d=0;
        Person temp;
        fi>>temp.club_name>>temp.id>>temp.name>>temp.contact>>temp.pos;
        while(!fi.eof()){
            if(temp.id==a && d==0){
                temp.dis_search();
                d=1;
                k=1;
            }
            else if(temp.id==a && d==1){
                cout<<temp.club_name<<" : "<<temp.pos<<endl;
            }
            fi>>temp.club_name>>temp.id>>temp.name>>temp.contact>>temp.pos;
        }
        
        if(k==0){
            cout<<"Person not found"<<endl;
        }
    }
    fi.close();
}

void search_contact(long long a){

    int k=0;
    ifstream fin;
    fin.open("test.txt",ios::in);
    
    if(!fin){
        cout<<"File not found"<<endl;
    }
    else{
        int d=0;
        Person temp;
        fin>>temp.club_name>>temp.id>>temp.name>>temp.contact>>temp.pos;
        while(!fin.eof()){
            if(temp.contact==a && d==0){
                temp.dis_search();
                d=1;
                k=1;
            }
            else if(temp.contact==a && d==1){
                cout<<temp.club_name<<" : "<<temp.pos<<endl;
            }
            fin>>temp.club_name>>temp.id>>temp.name>>temp.contact>>temp.pos;
        }

        if(k==0){
            cout<<"Person not found"<<endl;
        }
    }
    fin.close();
}

void search_name(string a){

    ifstream fin;
    fin.open("test.txt",ios::in);

    if(!fin){
        cout<<"File not found"<<endl;
    }
    else{
        int d=0,c;
        long long tem;
        Person temp;

        fin>>temp.club_name>>temp.id>>temp.name>>temp.contact>>temp.pos;
        while(!fin.eof()){
            if(d==0 && a==temp.name){
                tem=temp.id;
                d=1;
            }
            else if(d==1 && (a==temp.name && tem!=temp.id)){
                cout<<"More than one person available whose name is "<<a<<endl;
                cout<<"Enter more detais"<<endl;
                cout<<"Press 1 , 2 , 3 or 4"<<"\n1.Enter student id\n2.Enter Contact number"<<endl;
                cout<<"3.Enter club name\n4.Get detail of all person whose name is "<<a<<endl;
                cin>>c;
                d=2;
                break;
            }
            fin>>temp.club_name>>temp.id>>temp.name>>temp.contact>>temp.pos;
        }
        fin.close();

        if(d==0){
            cout<<"Person not found"<<endl;
        }
        else if(d==1){
            search_id(tem);
        }
        else if(d==2){

            switch(c){

                case 1:
                long long ide;
                cin>>ide;
                search_id(ide);
                break;

                case 2:
                long long co;
                cin>>co;
                search_contact(ide);
                break;

                case 3:
                {
                string cl;
                cin>>cl;
                ifstream fin;
                fin.open("test.txt",ios::in);

                if(!fin){
                    cout<<"File not found"<<endl;
                }
                else{
                    Person temp;
                    long long tem;
                    int d=0,f;

                    fin>>temp.club_name>>temp.id>>temp.name>>temp.contact>>temp.pos;
                    while(!fin.eof()){
                        if(d==0 && temp.name==a && temp.club_name==cl){
                            d=1;
                            tem=temp.id;
                        }
                        else if(d==1 && temp.name==a && temp.club_name==cl && temp.id!=tem){
                            d=2;
                            cout<<"More than one person available whose name is "<<a<<endl;
                            cout<<"Enter more detais"<<endl;
                            cout<<"Person 1,2 or 3"<<endl;
                            cout<<"1.Enter id\n2.Enter contact\n3.Get detai of all person whose name is "<<a<<" and who is in club "<<cl<<endl;
                            cin>>f;
                        }
                        fin>>temp.club_name>>temp.id>>temp.name>>temp.contact>>temp.pos;
                    }
                    fin.close();

                    if(d==0){
                        cout<<"Person not found"<<endl;
                    }
                    else if(d==1){
                        search_id(tem);
                    }
                    else if(d==2){

                        switch(f){
                            case 1:
                            long long ide;
                            cin>>ide;
                            search_id(ide);
                            break;

                            case 2:
                            long long co;
                            cin>>co;
                            search_contact(co);
                            break;

                            case 3:
                            ifstream fin;
                            fin.open("test.txt",ios::in);
                            long long idf;

                            if(!fin){
                                cout<<"File not found"<<endl;
                            }
                            else{
                               fin>>temp.club_name>>temp.id>>temp.name>>temp.contact>>temp.pos; 
                               while(!fin.eof()){
                                    if(a==temp.name && cl==temp.club_name){
                                        idf=temp.id;
                                        search_id(idf);
                                    }
                                    fin>>temp.club_name>>temp.id>>temp.name>>temp.contact>>temp.pos;
                               }
                            }
                            fin.close();
                            break;
                        }
                    }
                }
                break;
                }

                case 4:
                {
                vector<long long> vec;
                ifstream fin;
                long long h;
                int g=0,av=0;
                fin.open("test.txt",ios::in);

                if(!fin){
                    cout<<"File not found"<<endl;
                }
                else{
                    fin>>temp.club_name>>temp.id>>temp.name>>temp.contact>>temp.pos;
                    while(!fin.eof()){
                        if(g==0 && a==temp.name){
                            h=temp.id;
                            vec.push_back(h);
                            search_id(h);
                            g=1;
                        }
                        else if(g==1 && a==temp.name){
                            av=0;
                            for(int i=0;i<vec.size();++i){
                                if(temp.id==vec[i]){
                                    av=1;
                                    break;
                                }
                            }

                            if(av==0){
                                h=temp.id;
                                vec.push_back(h);
                                search_id(h);
                            }
                        }
                        fin>>temp.club_name>>temp.id>>temp.name>>temp.contact>>temp.pos;
                    }
                    fin.close();
                }
                break;
                }
            }
        }
    }
}

void search(){
    cout<<"Press 1,2,3 or 4"<<endl;
    cout<<"1.Enter student id\n2.Enter contact number\n3.Enter name\n4.Enter club name\n"<<endl;
    int n;
    cin>>n;
    
    switch(n){
        case 1:
        {
        long long ide;
        cin>>ide;
        search_id(ide);
        break;
        }

        case 2:
        {
        long long co;
        cin>>co;
        search_contact(co);
        break;
        }

        case 3:
        {
        string na;
        cin>>na;
        search_name(na);
        break;
        }

        case 4:
        {
        string cl;
        cin>>cl;
        //display_club_member(cl); [work remainig]
        break;
        }
    }
}

class Chess{

private:

    Person member;

public:


};

int main(){

    search();
    
}
