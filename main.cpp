#include <iostream>
#include <string>
#include "functions.cpp"
#include <fstream>
#include "clubinfo.h"
#include "addentry.h"
#include "intoduction.h"
using namespace std;

int main()
{
    std::cout << endl;
    std::cout << "======================================= Welcome to DA_IICT CLUB MANAGER =======================================" << endl;
    intro();
    string file_name;

item:
    std::cout << endl;
    std::cout << "Enter the file name from which data will be loaded into the programme. (Use the extension .txt also): ";
    cin >> file_name;
    ifstream fin;
    fin.open(file_name, ios::in);

    if (!fin && !fin.eof())
    {
        std::cout << endl;
        std::cout << "File does not exist or file is empty" << endl;
        std::cout << "Press 0 to exit or Press 1 to continue and give file name again: ";
        int k;
        cin >> k;

        if (k == 0)
        {
            return 0;
        }
        else
        {
            goto item;
        }
    }

    unordered_map<string, unordered_map<long long, pair<string, pair<long long, string>>>> list;
    unordered_multimap<string,long long> na_id;

    auto temp = load_data(file_name); // All the data from file gets loaded into the unordered map

    list = temp.first;

    na_id = temp.second;

    int b = 1;
    cout << "File Uploaded successfully..!!" << endl;
    unordered_map<string, unordered_multimap<int, Event>> data;
    data = ev_load();
    while (b == 1)
    {
        std::cout << endl;
        std::cout << "Please follow the following menu" << endl;
        std::cout << "--------------------------------" << endl;
        std::cout << " 1. All club members of a particular club. \n 2. To get the details of all members."
                  << "\n 3. To get details of club \n 4. To search any club member. \n 5. To become a member in any club \n 6. To leave any club ." << endl;
        std::cout << " 7. to exit" << endl;
        std::cout << "Enter Choice: ";
        int menu;
        cin >> menu;
        cin.ignore();
        switch (menu)
        {

        case 1:
        {
            std::cout << endl;
            std::cout << "Please enter the club name(You may type the name only and no need for the word CLUB, only for developer student club type DSClub): ";
            string club;
            cin >> club;
            mem_club(list, club);

            break;
        }

        case 2:
        {
            std::cout << "All the club member details are as follows: " << endl;
            get_all_mem(list);
            break;
        }

        case 3:
        {
            std::cout << endl;
            std::cout << "Please follow the following menu to fetch information about any club: " << endl;
            std::cout << "---------------------------------------------------------------------" << endl;
            std::cout << left << setw(30) << "1.Radio Club" << setw(30) << "2.Sambhav" << setw(30) << "3.Business Club" << setw(30) << "4.DCEI" << endl
                      << left << setw(30) << "5.CINS" << setw(30) << "6.Webkit Club" << setw(30) << "7.Muse Club" << setw(30) << "8.Debate Club" << endl
                      << left << setw(30) << "9.Music Club" << setw(30) << "10.Developer Student Club" << setw(30) << "11.Chess Club" << setw(30) << "12.Press Club" << endl
                      << left << setw(30) << "13.IEEE" << setw(30) << "14.Film Club" << setw(30) << "15.Research Club" << setw(30) << "16.Programming Club" << endl
                      << left << setw(30) << "18.Khelaiya Club" << setw(30) << "19.Cubing Club" << setw(30) << "20.Excursion Club" << setw(30) << "21.BIS club" << endl
                      << left << setw(30) << "17.PMMC" << setw(30) << "22.Heritage Club" << setw(30) << "23.Electronic Hobby Centre" << setw(30) << "24.Headrush-quizzing" << endl
                      << left << "25.DAIICT Theatre Group" << endl;

            int c1;
            do
            {
                int r;
                std::cout << "Enter Your choice: ";
                cin >> r;
                info(r);
                std::cout << "If you again want information, press 1 or Press 0 if you do not want any info: ";
                cin >> c1;
            } while (c1 == 1);
            break;
        }

        case 4:
        {
            search(list,na_id);
            break;
        }
        case 5:
        {
            addentry(list);
            break;
        }
        case 6:
        {
            del_entry(list);
            break;
        }
        case 7:
        {
            cout << endl;
            event(data);
            break;
        }
        case 8:
        {
            cout << endl;
            edit_ev(data, list);
            break;
        }
        case 9:
        {
            reload_data(list,file_name);
            return 0;
        }
        default:
        {
            cout << endl;
            std::cout << "Invalid choice. Please enter a valid option." << std::endl;
            break;
        }
        }
    }
}
