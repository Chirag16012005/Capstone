void find_student_id(map<long long int, pair<string, pair<string, string>>> &directory, long long x)
{
    cout << endl;
    auto a = directory.find(202301472);
    cout << "------Student Detials------" << endl;
    cout << endl;
    cout << "Std id is: " << a->first << endl;
    cout << "Name is: " << a->second.first << endl;
    cout << "Club name is: " << a->second.second.first << endl;
    cout << "Position: " << a->second.second.second << endl;
    cout << endl;
}

void find_student_by_club_name(map<long long int, pair<string, pair<string, string>>> &directory, const string &clubName)
{
    cout << endl;
    cout << "------" << clubName << " all members detials------" << endl;
    cout << endl;
    bool found = false;
    cout << "   Student id\t" << "Student Name\t" << "Position\t" << endl;
    cout << endl;
    int i = 0;
    for (auto &element : directory)
    {
        if (element.second.second.first == clubName)
        {
            found = true;
            i++;
            cout << i << ". " << element.first << "\t" << element.second.first << "\t" << element.second.second.second;
            cout << endl;
        }
    }
    if (!found)
    {
        cout << "No students found in club '" << clubName << "'" << endl;
        cout << endl;
    }
}

void find_student_by_name(map<long long int, pair<string, pair<string, string>>> &directory, string name)
{
    cout << endl;
    cout << "------Student Detials------" << endl;
    cout << endl;
    bool found = false;
    int i = 0;
    for (auto &element : directory)
    {
        if (element.second.first == name)
        {
            found = true;
            i++;
            cout << "Std id is: " << element.first << endl;
            cout << "Name is: " << element.second.first << endl;
            cout << "Club name is: " << element.second.second.first << endl;
            cout << "Position: " << element.second.second.second << endl;
            cout << endl;
        }
    }
    if (!found)
    {
        cout << "No student found..!!" << endl;
        cout << endl;
    }
}