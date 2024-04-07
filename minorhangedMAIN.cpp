#include <iostream>
#include <string>
#include "functions.cpp"
#include <fstream>
#include "clubinfo.h"
#include "addentry.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define BOLD    "\033[1m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BLACK       "\033[30m"
#define BOLD_BLACK  "\033[1m\033[30m"
#define BOLD_RED    "\033[1m\033[31m"
#define BOLD_GREEN  "\033[1m\033[32m"
#define BOLD_YELLOW "\033[1m\033[33m"
#define BOLD_BLUE   "\033[1m\033[34m"
#define BOLD_MAGENTA "\033[1m\033[35m"
#define BOLD_CYAN   "\033[1m\033[36m"
#define BOLD_WHITE  "\033[1m\033[37m"
#define BRIGHT_BLACK        "\033[90m"
#define BRIGHT_RED          "\033[91m"
#define BRIGHT_GREEN        "\033[92m"
#define BRIGHT_YELLOW       "\033[93m"
#define BRIGHT_BLUE         "\033[94m"
#define BRIGHT_MAGENTA      "\033[95m"
#define BRIGHT_CYAN         "\033[96m"
#define BRIGHT_WHITE        "\033[97m"


using namespace std;

int main()
{
    std::cout << endl;
    std::cout <<BOLD_YELLOW<< "======================================= Welcome to DA_IICT CLUB MANAGER =======================================" <<RESET<< endl;
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
        std::cout <<RED<< "File does not exist or file is empty" <<RESET<< endl;
        std::cout <<BRIGHT_RED<< "Press 0 to exit or Press 1 to continue and give file name again: ";
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
    cout <<GREEN<< "File Uploaded successfully..!!" <<RESET<< endl;
    while (b == 1)
    {
         std::cout << endl;
         std::cout <<BOLD_MAGENTA<< "Please follow the following menu" <<RESET<< endl;
         std::cout <<BOLD_MAGENTA<< "--------------------------------" <<RESET<< endl;
         std::cout << BLUE << BOLD << "1. All club members of a particular club." << RESET << endl;
         std::cout << BLUE << BOLD << "2. To get the details of all members." << RESET << endl;
         std::cout << BLUE << BOLD << "3. To get details of club." << RESET << endl;
         std::cout << BLUE << BOLD << "4. To search any club member." << RESET << endl;
         std::cout << BLUE << BOLD << "5. To become a member in any club." << RESET << endl;
         std::cout << BLUE << BOLD << "6. To leave any club." << RESET << endl;
         std::cout << BLUE << BOLD << "7. To get detials for Events" << RESET << endl;
         std::cout << BLUE << BOLD << "8. to edit event detials" << RESET << endl;
         std::cout << BLUE << BOLD << "9. to Participate any Event" << RESET << endl;
         std::cout << BLUE << BOLD << "10.To get ditials of festivals" << RESET << endl;
         std::cout << BLUE << BOLD << "11.to exit" << RESET << endl;
         std::cout << "Enter Choice: ";
        int menu;
        cin >> menu;
        switch (menu)
        {

        case 1:
        {
            std::cout << endl;
            std::cout <<BRIGHT_RED<< "Please enter the club name(You may type the name only and no need for the word CLUB, only for developer student club type DSClub): "<<RESET<<endl;
            string club;
            cin >> club;
            mem_club(list, club);

            break;
        }

        case 2:
        {
            std::cout <<YELLOW<< "All the club member details are as follows: " <<<RESET< endl;
            get_all_mem(list);
            break;
        }

        case 3:
        {
            std::cout << endl;
            std::cout <<BOLD_BLUE<< "Please follow the following menu to fetch information about any club: " <<RESET<< endl;
            std::cout <<BOLD_BLUE<< "---------------------------------------------------------------------" <<RESET<< endl;
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
                std::cout <<BRIGHT_GREEN<< "Enter Your choice: ";
                cin >> r;
                info(r);
                std::cout <<BRIGHT_BLUE<< "If you again want information, press 1 or Press 0 if you do not want any info: ";
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
        case 8:
        {
            cout << endl;
            edit_ev(data, list);
            break;
        }
        case 9:
        {
            cout << endl;
            ev_par(par_detials, data, s);
            break;
        }
        case 10:
        {
            cout << endl;
            mj_event();
            break;
        }
        case 11:
        {
            reload_data(list, file_name);
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
