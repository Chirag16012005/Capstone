#include<iostream>
#include<string>
#include"by_pranav.cpp"
#include"Person-Object.cpp"
#include"clubinfo.h"
using namespace std;
string club[]={"AI","Dance","Research","Chess","Cubing","Excursion","Microsoft","Radio","DCEI","Sambhav",
    "Developer_Studen","WebKit","Business","BIS","Debate","Music","Programming","IEEE","Heritage","Headrush_Quizzing Club",
    "Muse","Press","DAIICT_Theatre","Film","Khelaiya","EHC","PMMC","CINS"};
int main()
{
    cout<<"If you want to enter into DAIICT club manager PRESS 1 or you may press 0 to EXIT";
    int b;
    cin>>b;
    while(b==1)
    {
    cout<<"Welcome to DA_IICT CLUB MANAGER."<<endl;
   string file_name;
        do 
        {
            cout << "Enter the file name from which data will be loaded into the programme. (Use the extension .txt also)"
                 << endl;
            cin >> file_name;
        } 
        while (!(file_name.size() >= 4 && file_name.substr(file_name.size() - 4) == ".txt"));
    
    
    unordered_map<string,unordered_map<long long,pair<string,pair<long long,string>>>> list;
    list=load_data(file_name);//All the data from file gets loaded into the unordered map
    cout<<"Please follow the following menu \n 2. All club members of a particular club. \n 3. To get the details of all members."
    <<"\n 4. To get details of club";
    int menu;
    switch (menu)
    {
        case 2:
        {
            cout<<"Please enter the club name(You may type the name only and no need for the word CLUB)";
            string club;
            cin>>club;
            mem_club(list,club);
            break;
        }
        case 3:
        {
            cout<<"All the club member details are as follows:";
            get_all_mem(list);
            break;
        }
        case 4:
        {
            cout<<"Please follow the following menu to fetch information about any club"
            <<"1.Radio Club  2.Sambhav  3.Business Club  4.DCEI"
            <<"5.CINS  6.Webkit Club  7.Muse Club  8.Debate Club  9.Music Club"
            <<"10.Developer Student Club  11.Chess Club  12.Press Club  13.IEEE"
            <<"14.Film Club  15.Research Club  16.Programming Club  17.PMMC"
            <<"18.Khelaiya Club  19.Cubing Club  20.Excursion Club  21.BIS club"
            <<"22.Heritage Club  23.Electronic Hobby Centre  24.Headrush-quizzing"
            <<"25.DAIICT Theatre Group";
            int r;
            cin>>r;
            switch(r)
            {
                case 1:
                {
                    radioclub_info();
                    break;
                }
                case 2:
                {
                    sambhav_info();
                    break;
                }
                case 3:
                {
                    businessclub_info();
                    break;
                }
                case 4:
                {
                    DCEI_info();
                    break;
                }
                case 5:
                {
                    CINS_info();
                    break;
                }
                case 6:
                {
                    Webkitclub_info();
                    break;
                }
                case 7:
                {
                museclub_info();
                break;
                }
                case 8:
                {
                    debateclub_info();
                    break;
                }
                case 9:
                {
                    musicclub_info();
                    break;
                }
                case 10:
                {
                    DSClub_info();
                    break;
                }
                case 11:
                {
                    chessclub_info()
                    ;break;
                }
                case 12:
                {
                    Press_info();
                    break;
                }
                case 13:
                {
                    IEEEclub_info();
                    break;
                }
                case 14:
                {
                    filmclub_info();
                    break;
                }
                case 15:
                {
                    researchclub_info();
                    break;
                }
                case 16:
                {
                    programmingclub_info();
                    break;
                }
                case 17:
                {
                    PMMC_info();
                    break;
                }
                case 18:
                {
                    khelaiyaclub_info();
                    break;
                }
                case 19:
                {
                    cubingclub_info();
                    break;
                }
                case 20:
                {
                    excursionclub_info();
                    break;
                }
                case 21:
                {
                    BISclub_info();
                    break;
                }
                case 22:
                {
                    heritageclub_info();
                    break;
                }
                case 23:
                {
                    electronics_hobby_info();
                    break;
                }
                case 24:
                {
                    headrush_info();
                    break;
                }
                case 25:
                {
                    DAIICT_Theatreclub_info();
                    break;
                }
            }

        }
    }
    }
}
