#include "GymSystem.h"

void GymSystem::startSystem() {
    loginMenu(); // أول حاجة تظهر هي اختيار النوع
}

void GymSystem::loginMenu() {
    int choice;
    do {
        cout << "\n--- Welcome to Gym System ---\n";
        cout << "Log in as:\n";
        cout << "1. Admin\n";
        cout << "2. User (Member)\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) adminLogin();
        else if (choice == 2) userLogin();
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
        cout << "\n--- Admin Dashboard ---\n";
        cout << "[1] Add New Member\n";
        cout << "[2] Manage Trainers\n";
        cout << "[0] Log out\n";
        cout << "Choice: "; cin >> choice;

        if (choice == 1) addMember();
        // باقي الاختيارات...
    } while (choice != 0);
}

// --- منيو اليوزر ---
void GymSystem::userMenu() {
    int choice;
    do {
        cout << "\n--- Member Menu ---\n";
        cout << "[1] View Workout Program\n";
        cout << "[2] Change Password\n";
        cout << "[3] Attendance Record\n";
        cout << "[0] Log out\n";
        cout << "Choice: "; cin >> choice;

        if (choice == 1) { /* نادى دالة عرض البرنامج */ }
        else if (choice == 2) {
            string newPass;
            cout << "Enter new password: "; cin >> newPass;
            loggedInMember->setPassword(newPass);
            cout << "Password updated!\n";
        }
    } while (choice != 0);
    loggedInMember = nullptr; // مسح بيانات الجلسة عند الخروج
}
