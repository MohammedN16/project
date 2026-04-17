#include <iostream>
#include <vector>
//in gymsystem class
// ... (باقي الكود بتاعك) ...

void displayTopActiveMembers(const vector<AttendanceRecord>& allRecords) {
    // متغيرات بسيطة جداً لحفظ أسماء وعدد جلسات التوب 3
    // البداية أصفار والأسماء فاضية
    string name1 = "", name2 = "", name3 = "";
    int max1 = 0, max2 = 0, max3 = 0;

    // اللوب اللي هيمر على كل السجلات
    for (int i = 0; i < (int)allRecords.size(); i++) {
        int currentSessions = allRecords[i].getTotalSessions();
        string currentName = allRecords[i].getMemberName();

        // لو العضو الحالي جلساته أكتر من الأول
        if (currentSessions > max1) {
            // التشفيت للأسفل
            max3 = max2; name3 = name2; 
            max2 = max1; name2 = name1; 
            // تسجيل العضو الجديد في المركز الأول
            max1 = currentSessions; name1 = currentName; 
        }
        // لو جلساته أكتر من التاني (بس مش أكتر من الأول)
        else if (currentSessions > max2) {
            // التشفيت للأسفل
            max3 = max2; name3 = name2; 
            // تسجيل العضو في المركز التاني
            max2 = currentSessions; name2 = currentName; 
        }
        // لو جلساته أكتر من التالت
        else if (currentSessions > max3) {
            // تسجيل العضو في المركز التالت
            max3 = currentSessions; name3 = currentName; 
        }
    }

    // ── طباعة النتيجة ───────────────────────────────────────────────
    cout << "\n========================================\n";
    cout << "      🏆 أكثر الأعضاء نشاطاً (Top 3) 🏆\n";
    cout << "========================================\n";

    // لو الاسم مش فاضي، معناه إننا لقينا عضو وحطيناه في المركز ده
    if (name1 != "") cout << " 🥇 المركز الأول: " << name1 << " (" << max1 << " جلسات)\n";
    if (name2 != "") cout << " 🥈 المركز الثاني: " << name2 << " (" << max2 << " جلسات)\n";
    if (name3 != "") cout << " 🥉 المركز الثالث: " << name3 << " (" << max3 << " جلسات)\n";

    if (allRecords.empty() || name1 == "") {
        cout << " ✘ لا يوجد أعضاء نشطين حتى الآن.\n";
    }
    cout << "========================================\n";
}
