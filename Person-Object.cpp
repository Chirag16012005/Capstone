#include<iostream>
#include<string>
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
