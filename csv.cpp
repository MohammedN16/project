void saveToCSV() {

    Grade_letter();

    ofstream file("students.csv");
    if (!file.is_open()) {
        cout << "Error opening file for saving.";
        return;
    }

    // Header
    file << "Name,ID";
    for (int i = 0; i < MAX_SUBJECTS; i++) file << "," << subjectNames[i];
    file << ",GPA,GradeLetter" << "\n"; 

    // Data
    for (int i = 0; i < studentCount; i++) {
        file << names[i] << "," << IDs[i];
        for (int j = 0; j < MAX_SUBJECTS; j++)
            file << "," << grades[i][j];
        
        file << "," << gpas[i] << "," << gradeLetter[i] << "\n"; // <--- FIXED: Added newline
    }
    file.close();
    cout << "Data saved to students.csv successfully.";
}

void loadFromCSV() {
ifstream file("students.csv");
    if (!file.is_open()) {
        cout << "Error opening CSV file.";
        return;
    }

    string line;
    getline(file, line); // Skip header

    while (getline(file, line)) {

        // Stop if system is full
        if (studentCount >= MAX_STUDENTS) {
            cout << "\nSystem full! Some records were not loaded.\n";
            break;
        }

        stringstream ss(line);
        string cell;
        vector<string> row;

        while (getline(ss, cell, ',')) {
            row.push_back(cell);
        }

        if (row.size() < 3 + MAX_SUBJECTS) continue;

        int index = studentCount;

        names[index] = row[0];
        IDs[index] = stoi(row[1]);

        for (int i = 0; i < MAX_SUBJECTS; i++) {
            grades[index][i] = stof(row[2 + i]);
        }

        gpas[index] = stof(row[2 + MAX_SUBJECTS]);
        gradeLetter[index] = row[3 + MAX_SUBJECTS];

        studentCount++;
    }

    file.close();
    cout << "CSV appended successfully.\n";
