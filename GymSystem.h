#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Member.h" // تأكد إن كلاس Member فيه username و password

using namespace std;

class GymSystem {
private:
    vector<Member> members; // لتخزين الأعضاء والبحث عنهم وقت الدخول
    Member* loggedInMember = nullptr; // لتتبع العضو اللي سجل دخوله حالياً

    // دوال الدخول
    void loginMenu();
    void adminLogin();
    void userLogin();

    // القوائم
    void adminMenu();
    void userMenu();

    // دوال الأدمين (زي ما هي)
    void addMember(); // هنعدل دي عشان تولد اليوزر والباسورد تلقائي

public:
    void startSystem();
};
