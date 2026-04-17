#include "GymSystem.h"

void GymSystem::startSystem() {
    loginMenu(); // أول حاجة تظهر هي اختيار النوع
}

void GymSystem::loginMenu() {
    int choice;
    do {
        cout << "\n--- Welcome to Gym System ---\nLog in as:\n1. Admin\n2. User (Member)\n0. Exit\nChoice: ";
        if (!(cin >> choice)) { cin.clear(); cin.ignore(100, '\n'); continue; }

        switch (choice) {
            case 1: adminLogin(); break;
            case 2: userLogin(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n"; break;
        }
    } while (choice != 0);
}

// --- دخول الأدمين ---
void GymSystem::adminLogin() {
    string user, pass;
    cout << "\n--- Admin Login ---\n";
    cout << "Enter username: "; cin >> user;
    cout << "Enter password: "; cin >> pass;

    if (user == "admin" && pass == "admin") {
        cout << "\nLogin Successful! Welcome, Admin.\n";
        adminMenu();
    } else {
        cout << "\nInvalid credentials!\n";
    }
}

// --- دخول العضو ---
void GymSystem::userLogin() {
    string user, pass;
    cout << "\n--- User Login ---\n";
    cout << "Enter username: "; cin >> user;
    cout << "Enter password: "; cin >> pass;

    bool found = false;
    for (auto &m : members) {
        if (m.getUsername() == user && m.getPassword() == pass) {
            loggedInMember = &m;
            found = true;
            break;
        }
    }

    if (found) {
        cout << "\nLogin Successful! Welcome, " << loggedInMember->getFirstName() << endl;
        userMenu();
    } else {
        cout << "\nUser not found or wrong password.\n";
    }
}

// --- منيو الأدمين ---
void GymSystem::adminMenu() {
    int choice;
    do {
        cout << "\n--- Admin Dashboard ---\n[1] Add Member\n[2] Manage Trainers\n[3] Search Name\n[4] Search ID\n[5] Payment\n[0] Log out\nChoice: ";
        if (!(cin >> choice)) { cin.clear(); cin.ignore(100, '\n'); continue; }

        switch (choice) {
            case 1: addMember(); break;
            case 2: ManageTrainers(); break;
            case 3: search_by_name(); break;
            case 4: search_by_id(); break;
            case 5: setPayment(); break;
            case 0: cout << "Logging out...\n"; break;
            default: cout << "Invalid!\n"; break;
        }
    } while (choice != 0);
}

// --- منيو اليوزر ---
void GymSystem::userMenu() {
    int choice;
    do {
        cout << "\n--- Member Menu ---\n[1] View Workout Program\n[2] Change Password\n[3] Attendance\n[0] Log out\nChoice: ";
        if (!(cin >> choice)) { cin.clear(); cin.ignore(100, '\n'); continue; }

        switch (choice) {
            case 1: viewWorkoutProgram(); break; 
            case 2: {
                string newPass;
                cout << "Enter new password: "; cin >> newPass;
                loggedInMember->setPassword(newPass);
                cout << "Password updated!\n";
            } break;
            case 3: viewAttendance(); break;
            case 0: cout << "Logging out...\n"; break;
            default: cout << "Invalid choice!\n"; break;
        }
    } while (choice != 0);
    
    loggedInMember = nullptr; // مسح بيانات الجلسة عند الخروج
}
