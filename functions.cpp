#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Assumption : file is prechecked. file exist or not

string club[] = {"AI", "Dance", "Research", "Chess", "Cubing", "Excursion", "Microsoft", "Radio", "DCEI", "Sambhav",
                 "Developer_Student", "WebKit", "Business", "BIS", "Debate", "Music", "Programming", "IEEE", "Heritage", "Headrush_Quizzing",
                 "Muse", "Press", "DAIICT_Theatre", "Film", "Khelaiya", "EHC", "PMMC", "CINS"};

pair<unordered_map<string, unordered_map<long long, pair<string, pair<long long, string>>>>,unordered_multimap<string,long long>> load_data(string file_name)
{
    ifstream fin;
    fin.open(file_name, ios::in);

    int c,a;
    long long id, number;
    string name, club_name, position, temp2;

    unordered_map<string, unordered_map<long long, pair<string, pair<long long, string>>>> directory;
    unordered_multimap<string,long long> na_id;

    while (fin >> club_name >> id >> name >> temp2 >> number >> position)
    {
        name = name + " " + temp2;
        directory[club_name][id] = make_pair(name, make_pair(number, position));

        a=0;
        c= na_id.count(name);
        if(c>0){
            auto range = na_id.equal_range(name);

            for(auto person = range.first ; person != range.second ; ++person){
                if(person->second==id){
                    a=1;
                }
            }
        }

        if(c==0 ||  a==0){
            na_id.insert({name,id});
        }
    }

    fin.close();

    return make_pair(directory,na_id);
}

void mem_club(unordered_map<string, unordered_map<long long, pair<string, pair<long long, string>>>> &directory, string club_name)
{
    std::cout << endl;
    int n = 0;
    for (auto dir : directory[club_name])
    {
        if (n == 0)
        {
            std::cout <<CYAN<< "================ "<< club_name << CYAN<< " Club member detials ================" <<RESET<< endl;
            std::cout <<YELLOW<< left << setw(20) << "Name" << setw(15) << "Student ID" << setw(15) << "Contact Number" << setw(20) << "Position" <<RESET<< endl;
            std::cout <<BRIGHT_GREEN<< "-----------------------------------------------------------" <<RESET<< endl;
            std::cout << setw(20) << dir.second.first << setw(15) << dir.first << setw(15) << dir.second.second.first << setw(20) << dir.second.second.second << endl;
            n++;
        }
        else
        {
            std::cout << setw(20) << dir.second.first << setw(15) << dir.first << setw(15) << dir.second.second.first << setw(20) << dir.second.second.second << endl;
            n++;
        }
    }
    if (n == 0)
    {
        std::cout <<LIGHT_YELLOW<< "There are no member in " << club_name << " ..!!" <<RESET<< endl;
    }
    std::cout << "------------//--------------//-------------//--------------" << endl;
    std::cout << endl
              << endl;
}

void get_all_mem(unordered_map<string, unordered_map<long long, pair<string, pair<long long, string>>>> &directory)
{
    cout << endl;
    int n;
    for (int i = 0; i < 28; i++)
    {
        if (!directory[club[i]].empty())
        {
            std::cout <<YELLLOW<< "=> " << club[i] << " Club :" <<RESET<< endl;
            std::cout <<BLUE<< left << setw(20) << "Name" << setw(15) << "Student ID" << setw(15) << "Contact Number" << setw(20) << "Position" <<RESET<< endl;
            std::cout <<MAGENTA<< "-----------------------------------------------------------" <<RESET<< endl;
            n = 1;
            for (auto dir : directory[club[i]])
            {
                std::cout << setw(20) << dir.second.first << setw(15) << dir.first << setw(15) << dir.second.second.first << setw(20) << dir.second.second.second << endl;
                n++;
            }
            std::cout << "------------//--------------//-------------//--------------" << endl;
            std::cout << endl
                      << endl;
        }
    }
}

void find_by_id(unordered_map<string, unordered_map<long long, pair<string, pair<long long, string>>>> &directory, long long id)
{
    std::cout << endl;
    int a = 0, n = 1;
    for (int i = 0; i < 28; i++)
    {
        auto person = directory[club[i]].find(id);
        if (person != directory[club[i]].end())
        {
            a++;
            if (a == 1)
            {
                std::cout <<BOLD_BLUE<< "===============================Student Detials================================" <<RESET<< endl;
                std::cout <<GREEN<< left << setw(15) << "Student ID" << setw(20) << "Student Name" << setw(20) << "Contact Number" << setw(15) << "Joined Club" << setw(15) << "Position" <<RESET<< endl;
                std::cout << "------------------------------------------------------------------------------" << endl;
                std::cout << setw(15) << person->first << setw(20) << person->second.first << setw(20) << person->second.second.first << setw(15) << club[i] << setw(15) << person->second.second.second << endl;
                n++;
            }
            else
            {
                std::cout << right << setw(62) << club[i] << right << setw(14) << person->second.second.second << endl;
                n++;
            }
        }
    }
    if (a == 0)
    {
        std::cout <<RED<< "Person not found..!!" <<RESET<< endl;
        return;
    }
    std::cout << "------//----------//----------//-----------//-----------//-----------//-------";
    std::cout << endl
              << endl;
}

void find_by_contact(unordered_map<string, unordered_map<long long, pair<string, pair<long long, string>>>> &directory, long long number)
{
    int count = 0;
    long long id;
    for (int i = 0; i < 28; ++i)
    {

        for (auto element : directory[club[i]])
        {

            if (number == element.second.second.first)
            {
                id = element.first;
                count++;
                find_by_id(directory, id);
                return;
            }
        }
    }
    if (count == 0)
    {
        std::cout <<RED<< "Person Not Found..!!" <<RESET<< endl;
        std::cout << endl;
    }
}

void find_by_name(unordered_map<string, unordered_map<long long, pair<string, pair<long long, string>>>> &directory, string name,unordered_multimap<string,long long> &na_id)
{
    long long id;
    int count;

    count= na_id.count(name);

    if (count == 0)
    {
        std::cout <<RED<< "Person not found..!!" <<RESET<< endl;
        std::cout << endl;
        return;
    }
    else if (count == 1)
    {
        auto temp = na_id.find(name);
        id = temp->second;
        find_by_id(directory,id);
    }
    else if (count == 2)
    {
        std::cout <<BRIGHT_YELLOW<< "Here we got more than one result..!!" <<RESET<< endl;
        std::cout <<BRIGHT_YELLOW<< "We want some additional information" <<RESET<< endl;
        std::cout << endl;

    lable:

        std::cout <<BRIGHT_CYAN<< "1. to show all results" <<RESET<< endl;
        std::cout <<BRIGHT_CYAN<< "2. to find through id" <<RESET<< endl;
        std::cout <<BRIGHT_CYAN<< "3. to find through contact number" <<RESET<< endl;
        std::cout <<BRIGHT_CYAN<< "4. to find through club name" <<RESET<< endl;
        std::cout << "Enter Choice: ";
        int a;
        cin >> a;
        if (a == 1)
        {
            auto temp = na_id.equal_range(name);

            for(auto person = temp.first; person != temp.second;++person){
                id=person->second;
                find_by_id(directory,id);
            }

        }
        else if (a == 2)
        {
            long long b;
            std::cout << "Enter Student id: ";
            cin >> b;
            find_by_id(directory, b);
        }
        else if (a == 3)
        {
            long long number;
            std::cout << "Enter number: ";
            cin >> number;
            find_by_contact(directory, number);
        }
        else if (a == 4)
        {
            long long id;
            int c = 0;
            string cl;
            std::cout << "Enter club name: ";
            cin >> cl;

            for (auto element : directory[cl])
            {
                if (name == element.second.first)
                {
                    if (c == 0)
                    {
                        c++;
                        id = element.first;
                    }
                    else if (c == 1)
                    {
                        if (id != element.first)
                        {
                            c++;
                            break;
                        }
                    }
                }
            }

            if (c == 0)
            {
                std::cout << endl;
                std::cout <<YELLOW<< "You provided wrong club name" <<RESET<< endl;
                std::cout <<YELLOW<< "Please enter some other detail" <<RESET<< endl;
                std::cout << endl;
                goto lable;
            }
            else if (c == 1)
            {
                find_by_id(directory, id);
            }
            else if (c == 2)
            {
                std::cout << endl;
                std::cout << "We got more than one person with same name present in " << cl << " club " << endl;
                std::cout << "We want some additional information" << endl;
                std::cout << endl;
                std::cout <<BRIGHT_GREEN<< "1. to show all result"<<RESET<< endl;
                std::cout <<BRIGHT_GREEN<< "2. to give id" <<RESET<< endl;
                std::cout <<BRIGHT_GREEN<< "3. to give contact number" <<RESET<< endl;
                std::cout << "Enter choice: ";
                int g;
                cin >> g;

                if (g == 1)
                {
                    for (auto element : directory[cl])
                    {
                        if (name == element.second.first)
                        {
                            id = element.first;
                            find_by_id(directory, id);
                        }
                    }
                }
                else if (g == 2)
                {
                    long long id;
                    cin >> id;

                    find_by_id(directory, id);
                }
                else if (g == 3)
                {
                    long long number;
                    cin >> number;

                    find_by_contact(directory, number);
                }
            }
        }
    }
}

void search(unordered_map<string, unordered_map<long long, pair<string, pair<long long, string>>>> &directory ,unordered_multimap<string,long long> &na_id)
{
    std::cout << endl;
    std::cout <<MAGENTA<< "1. to search by id" <<RESET<< endl;
    std::cout <<MAGENTA<< "2. to search by name" <<RESET<< endl;
    std::cout <<MAGENTA<< "3. to search by contact number" <<RESET<< endl;
    std::cout << "Enter choice: ";
    int a;
    cin >> a;
    cin.ignore();

    if (a == 1)
    {
        std::cout << endl;
        std::cout << "Enter student id: ";
        long long id;
        cin >> id;
        std::cout << endl;
        find_by_id(directory, id);
    }
    else if (a == 2)
    {
        std::cout << endl;
        std::cout << "Enter name: ";
        string name;
        getline(cin, name);
        std::cout << endl;
        find_by_name(directory, name,na_id);
    }
    else if (a == 3)
    {
        std::cout << endl;
        std::cout << "Enter contact number: ";
        long long number;
        cin >> number;
        std::cout << endl;
        find_by_contact(directory, number);
    }
}

void del_entry(unordered_map<string, unordered_map<long long, pair<string, pair<long long, string>>>> &directory)
{
    std::cout << endl;
    string temp, club;
    std::cout <<BRIGHT_MAGENTA<< "What made you to leave this club: "<<RESET<<endl;
    std::getline(cin, temp);
    std::cin.ignore();
    long long id;
label:
    std::cout << endl;
    std::cout << "Please enter your id: ";
    cin >> id;
    cout << "Please enter Your name: ";
    cin >> club;
    if (directory[club].find(id) != directory[club].end())
    {
        directory[club].erase(id);
    }
    else
    {
        std::cout <<RED<< "You have entered wrong club name or id..!!" <<RESET<< endl;
        cout<<"Press 1 to re-enter or 0 to exit : ";
        int k;
        cin>>k;
        cin.ignore();
        if(k==1){
            goto label;
        }
        else{
            return;
        }
    }
}

void reload_data(unordered_map<string, unordered_map<long long, pair<string, pair<long long, string>>>> &directory, string file_name)
{
    ofstream fout;
    fout.open(file_name, ios::out);
    string name, position;
    long long id, number;

    for (int i = 0; i < 28; ++i)
    {

        if (!directory[club[i]].empty())
        {

            for (auto person : directory[club[i]])
            {

                id = person.first;
                name = person.second.first;
                number = person.second.second.first;
                position = person.second.second.second;

                fout << club[i] << " " << id << " " << name << " " << number << " " << position << endl;
            }
        }
    }
    fout.close();
}

// int main()
// {

//     unordered_map<string, unordered_map<long long, pair<string, pair<long long, string>>>> directory;

//     directory = load_data("test.txt");

//     search(directory);

//     //mem_club(directory, "CINS");

//     //get_all_mem(directory);

//     //find_by_id(directory, 202303042);

//     // find_by_name(directory, "Manan Chhabhaya");
//     //find_by_name(directory, "Vraj Patel");
//     return 0;
// }
