/*فانكشن دي هتتحط في GymSystem.cpp
-------------------------------------------------
/ملاحظات هامة لتعديل الكلاسات الأخرى
كلاس Member: لازم تضيف فيه متغيرات
string username و string password مع الـ Getters والـ Setters بتاعتهم عشان تقدر تستخدمهم في الـ GymSystem.

الـ Vector: تأكد إن الـ vector<Member> members متعرف في الـ private بتاع الـ GymSystem عشان يفضل محتفظ بالبيانات طول ما البرنامج شغال.

الـ ID: في دالة توليد الباسورد، استخدمنا to_string(id) ودي محتاجة #include <string>.

بهذا الشكل، الأدمين هو اللي بيكريت الحسابات، واليوزر يقدر يدخل ببياناته ويغير الباسورد الخاص بيه
*/
void GymSystem::addMember() {
    string fName, lName;
    int id;
    cout << "Enter First Name: "; cin >> fName;
    cout << "Enter Last Name: "; cin >> lName;
    cout << "Enter ID: "; cin >> id;

    // توليد البيانات تلقائياً
    string generatedUser = fName + "_" + lName;
    string generatedPass = fName + "_" + lName + to_string(id);

    // إنشاء الـ Object وإضافته للـ vector
    Member newMember(fName, lName, id);
    newMember.setUsername(generatedUser);
    newMember.setPassword(generatedPass);

    members.push_back(newMember);

    cout << "\nMember Added Successfully!\n";
    cout << "Username: " << generatedUser << "\n";
    cout << "Default Password: " << generatedPass << "\n";
}
