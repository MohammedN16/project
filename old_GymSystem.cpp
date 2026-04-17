//GymSystem.cpp
#include "GymSystem.h"
#include <iostream>
#include <string>
#include <vector>
#include "Person.h"
#include "Member.h"
#include "Trainer.h"
#include "MembershipPlan.h"
#include "Exercise.h"
#include "WorkoutProgram.h"
#include "Payment.h"
#include "AttendanceRecord.h"
  //For Record New Attendance
  void GymSystem :: addRecord(int id, string d, string in, string out)
  {
    AttendanceRecord newRec(id, d, in, out);
    attendanceList.push_back(newRec);
    cout << "Done! Attendance added.\n";
  }
  // to shcw all attendance
  void GymSystem :: showAllAttendance()
  {
    cout << "\n--- Attendance Records List ---\n";
    for (int i = 0; i < attendanceList.size(); i++)
    {
      attendanceList[i].print();
    }
  }
//GymSystem.h
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Person.h"
#include "Member.h"
#include "Trainer.h"
#include "MembershipPlan.h"
#include "Exercise.h"
#include "WorkoutProgram.h"
#include "Payment.h"
#include "AttendanceRecord.h"
using namespace std;
class GymSystem
{
private:
  // vector<Member> members;
  // vector<Trainer> trainers;
  vector<AttendanceRecord> attendanceList;
public:
  /*GymSystem();
  ~GymSystem();
  void startMenu();
  void loadData();
  void saveData();*/
  void addRecord(int id, string d, string in, string out);
  void showAllAttendance();
};
