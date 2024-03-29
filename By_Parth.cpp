#include <iostream>
#include <unordered_map>
using namespace std;

void find_by_id(unordered_map<string, pair<long long, pair<string, pair<long long, string>>>> &directory, long long x)
{
    cout << endl;
    int i = 0;
    cout << "  Club name\t" << "Student id\t" << "Student name\t" << "Contact Number\t" << "Position" << endl;
    for (auto element : directory)
    {
        if (x == element.second.first)
        {
            i++;
            cout << i << ". " << element.first << "\t" << element.second.first << "\t" << element.second.second.first << "\t" << element.second.second.second.first << "\t" << element.second.second.second.second << endl;
        }
    }
    cout << endl;
}

void find_by_name(unordered_map<string, pair<long long, pair<string, pair<long long, string>>>> &directory, string name)
{
    cout << endl;
    int count = 0;
    unordered_map<string, pair<long long, pair<string, pair<long long, string>>>> m;
    for (auto element : directory)
    {
        if (element.second.second.first == name)
        {
            m[element.first] = make_pair(element.second.first, make_pair(element.second.second.first, make_pair(element.second.second.second.first, element.second.second.second.second)));
            count++;
        }
    }
    if (count > 1)
    {
    label:
        cout << endl;
        cout << "Press 1 for show all same name members" << endl;
        cout << "Press 2 for find member through id" << endl;
        cout << "Press 3 for find member through Number" << endl;
        cout << "Press 4 for find member through club name" << endl;
        int x;
        cin >> x;
        switch (x)
        {
        case 1:
            cout << "  Club name\t" << "Student id\t" << "Student name\t" << "Contact Number\t" << "Position" << endl;
            cout << endl;
            int i = 0;
            for (auto element : m)
            {
                i++;
                cout << i << ". " << element.first << "\t" << element.second.first << "\t" << element.second.second.first << "\t" << element.second.second.second.first << "\t" << element.second.second.second.second << endl;
            }
            break;
        case 2:
            long long y;
            cin >> y;
            int i = 0;
            cout << "  Club name\t" << "Student id\t" << "Student name\t" << "Contact Number\t" << "Position" << endl;
            cout << endl;
            for (auto element : m)
            {
                if (y == element.second.first)
                {
                    i++;
                    cout << i << ". " << element.first << "\t" << element.second.first << "\t" << element.second.second.first << "\t" << element.second.second.second.first << "\t" << element.second.second.second.second << endl;
                }
            }
            if (i == 0)
            {
                cout << "Student Id which you entered is invalid..!!" << endl;
                goto label;
            }
            break;
        case 3:
            long long y;
            cin >> y;
            int i = 0;
            cout << "  Club name\t" << "Student id\t" << "Student name\t" << "Contact Number\t" << "Position" << endl;
            cout << endl;
            for (auto element : m)
            {
                if (y == element.second.second.second.first)
                {
                    i++;
                    cout << i << ". " << element.first << "\t" << element.second.first << "\t" << element.second.second.first << "\t" << element.second.second.second.first << "\t" << element.second.second.second.second << endl;
                }
            }
            if (i == 0)
            {
                cout << "Contact number which you entered is invalid..!!" << endl;
                goto label;
            }
            break;
        case 4:
            string s;
            cout << "Enter Club name(like: Radio,Cins ext..): ";
            cin >> s;
            int count1 = 0;
            for (auto element : m)
            {
                if (s == element.first)
                    count1++;
            }
            if (count > 1)
            {
            label:
                cout << endl;
                cout << "Press 1 for show all same name members" << endl;
                cout << "Press 2 for find member through id" << endl;
                cout << "Press 3 for find member through Number" << endl;
                int x1;
                cin >> x1;
                switch (x1)
                {
                case 1:
                    cout << "  Club name\t" << "Student id\t" << "Student name\t" << "Contact Number\t" << "Position" << endl;
                    cout << endl;
                    int i = 0;
                    for (auto element : m)
                    {
                        if (s == element.first)
                        {
                            i++;
                            cout << i << ". " << element.first << "\t" << element.second.first << "\t" << element.second.second.first << "\t" << element.second.second.second.first << "\t" << element.second.second.second.second << endl;
                        }
                    }
                    break;
                case 2:
                    long long y;
                    cout << "Enter Student Id: ";
                    cin >> y;
                    int i = 0;
                    cout << "  Club name\t" << "Student id\t" << "Student name\t" << "Contact Number\t" << "Position" << endl;
                    cout << endl;
                    for (auto element : m)
                    {
                        if (y == element.second.first && s == element.first)
                        {
                            i++;
                            cout << i << ". " << element.first << "\t" << element.second.first << "\t" << element.second.second.first << "\t" << element.second.second.second.first << "\t" << element.second.second.second.second << endl;
                        }
                    }
                    if (i == 0)
                    {
                        cout << "Student Id which you entered is invalid..!!" << endl;
                        goto label;
                    }
                    break;
                case 3:
                    long long y;
                    cout << "Enter Contact Number: ";
                    cin >> y;
                    int i = 0;
                    cout << "  Club name\t" << "Student id\t" << "Student name\t" << "Contact Number\t" << "Position" << endl;
                    cout << endl;
                    for (auto element : m)
                    {
                        if (y == element.second.second.second.first && s == element.first)
                        {
                            i++;
                            cout << i << ". " << element.first << "\t" << element.second.first << "\t" << element.second.second.first << "\t" << element.second.second.second.first << "\t" << element.second.second.second.second << endl;
                        }
                    }
                    if (i == 0)
                    {
                        cout << "Contact number which you entered is invalid..!!" << endl;
                        goto label;
                    }
                    break;
                }
                break;
            }
            else
            {
                int i = 0;
                cout << "  Club name\t" << "Student id\t" << "Student name\t" << "Contact Number\t" << "Position" << endl;
                cout << endl;
                for (auto element : m)
                {
                    if (s == element.first)
                    {
                        i++;
                        cout << i << ". " << element.first << "\t" << element.second.first << "\t" << element.second.second.first << "\t" << element.second.second.second.first << "\t" << element.second.second.second.second << endl;
                    }
                }
            }
        }
    }
    else
    {
        int i = 0;
        cout << "  Club name\t" << "Student id\t" << "Student name\t" << "Contact Number\t" << "Position" << endl;
        cout << endl;
        for (auto element : directory)
        {
            if (element.second.second.first == name)
            {
                i++;
                cout << i << ". " << element.first << "\t" << element.second.first << "\t" << element.second.second.first << "\t" << element.second.second.second.first << "\t" << element.second.second.second.second << endl;
            }
        }
    }
}
