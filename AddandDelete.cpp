#include <iostream>
#include <map>
#include <string>

using namespace std;

// Club member structure
struct ClubMember {
    string id;
    string name;
    int age;
    string position;
};

// Function to display a particular club member
void 
displayMember(const ClubMember& member) {
    cout << "ID: " << member.id << ", Name: " << member.name << ", Age: " << member.age << ", Position: " << member.position << endl;
}

// Function to display all club members
void displayAllMembers(const map<string, ClubMember>& club) {
    cout << "All Club Members:" << endl;
    for (const auto& pair : club) {
        displayMember(pair.second);
    }
}

// Function to search for a club member by ID
void searchMember(const map<string, ClubMember>& club, const string& id) {
    auto it = club.find(id);
    if (it != club.end()) {
        cout << "Club member found:" << endl;
        displayMember(it->second);
    } else {
        cout << "Club member with ID " << id << " not found." << endl;
    }
}

// Function to add a new club member
void addMember(map<string, ClubMember>& club, const ClubMember& newMember) {
    // Check if the ID already exists
    if (club.find(newMember.id) == club.end()) {
        club[newMember.id] = newMember;
        cout << "New member added successfully." << endl;
    } else {
        cout << "Member with ID " << newMember.id << " already exists." << endl;
    }
}

// Function to delete a club member by ID
void deleteMember(map<string, ClubMember>& club, const string& id) {
    auto it = club.find(id);
    if (it != club.end()) {
        club.erase(it);
        cout << "Member with ID " << id << " deleted successfully." << endl;
    } else {
        cout << "Member with ID " << id << " not found." << endl;
    }
}

int main() {
    map<string, ClubMember> club;

    // stored data
    ClubMember member1 = {"001", "pranav", 25, "Leader"};
    ClubMember member2 = {"002", "mayank", 23, "coordinator"};
    ClubMember member3 = {"003", "raj", 29, "core member"};
    ClubMember member4 = {"004", "krish", 21, "volunteer"};


    // Adding members to the club
    club[member1.id] = member1;
    club[member2.id] = member2;
    club[member3.id] = member3;
    club[member4.id] = member4;

    int choice;
    string id;
    ClubMember newMember;

    do {
        cout << "\nDAIICT Club Management System\n";
        cout << "1. Display all members\n";
        cout << "2. Display a particular member\n";
        cout << "3. Search for a member\n";
        cout << "4. Add a new member\n";
        cout << "5. Delete a member\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayAllMembers(club);
                break;
            case 2:
                cout << "Enter member ID: ";
                cin >> id;
                displayMember(club[id]);
                break;
            case 3:
                cout << "Enter member ID to search: ";
                cin >> id;
                searchMember(club, id);
                break;
            case 4:
                cout << "Enter new member details:\n";
                cout << "ID: ";
                cin >> newMember.id;
                cout << "Name: ";
                cin >> newMember.name;
                cout << "Age: ";
                cin >> newMember.age;
                cout << "Position: ";
                cin >> newMember.position;
                addMember(club, newMember);
                break;
            case 5:
                cout << "Enter member ID to delete: ";
                cin >> id;
                deleteMember(club, id);
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }

    } while (choice != 6);

    return 0;
}

