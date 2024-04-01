#include<iostream>
#include<string>
#include"by_pranav.h"
#include<fstream>
#include"clubinfo.h"
using namespace std;

int main()
{
   
cout<<"Welcome to DA_IICT CLUB MANAGER."<<endl;
string file_name;
  
        cout << "Enter the file name from which data will be loaded into the programme. (Use the extension .txt also)"<<endl;

            label:

            cin >> file_name;
            ifstream fin;
            fin.open(file_name,ios::in);

            if(!fin && !fin.eof())
            {
                cout<<"File does not exist or file is empty"<<endl;
                
                cout<<"Press 0 to exit or Press 1 to continue and give file name again"<<endl;
                int k;
                cin>>k;

                if(k==0)
                {
                    return 0;
                }
                else
                {
                    goto label;
                }
            }

    unordered_map<string,unordered_map<long long,pair<string,pair<long long,string>>>> list;

    list=load_data(file_name);  //All the data from file gets loaded into the unordered map
    int b=1;

    while(b==1)
    {
    cout<<"Please follow the following menu \n 2. All club members of a particular club. \n 3. To get the details of all members."
    <<"\n 4. To get details of club \n 5. To search any club member."<<endl;
    int menu;
    cin>>menu;
    switch (menu)
    {

        case 2:
        {
            cout<<"Please enter the club name(You may type the name only and no need for the word CLUB)"<<endl;
            string club;
            cin>>club;
            mem_club(list,club);

            break;
        }

        case 3:
        {
            cout<<"All the club member details are as follows:"<<endl;
            get_all_mem(list);

            break;
        }

        case 4:
        {
            cout<<"Please follow the following menu to fetch information about any club"<<endl
            <<"1.Radio Club  2.Sambhav  3.Business Club  4.DCEI"<<endl
            <<"5.CINS  6.Webkit Club  7.Muse Club  8.Debate Club  9.Music Club"<<endl
            <<"10.Developer Student Club  11.Chess Club  12.Press Club  13.IEEE"<<endl
            <<"14.Film Club  15.Research Club  16.Programming Club  17.PMMC"<<endl
            <<"18.Khelaiya Club  19.Cubing Club  20.Excursion Club  21.BIS club"<<endl
            <<"22.Heritage Club  23.Electronic Hobby Centre  24.Headrush-quizzing"<<endl
            <<"25.DAIICT Theatre Group"<<endl;

            int c1;
            do
            {
            int r;
            cin>>r;
            info(r);
            cout<<"If you again want information, press 1 or Press 0 if you do not want any info"<<endl;
            cin>>c1;
            }
            while(c1==1);

            break;
            }

            case 5:
            {
                search(list);

                break;
            }
    }

    cout<<"If you want to enter into DAIICT club manager , press 1 or you may press 0 to exit"<<endl;
    cin>>b;
}

return 0;
}