// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect // =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <numeric> // for accumulate
using namespace std;

// Struct to represent each student
struct Student {
    string name;
    int id;
    vector<double> scores;
};

// Function prototypes
void addStudent(vector<Student> &students);
void displayAllStudents(const vector<Student> &students);
void calculateAverage(const vector<Student> &students);
void showMenu();

int main() {
    vector<Student> students;
    int choice;

    do {
        showMenu();
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        cin.ignore(); // clear newline for getline

        switch(choice) {
            case 1: addStudent(students); break;
            case 2: displayAllStudents(students); break;
            case 3: calculateAverage(students); break;
            case 4: cout << "Goodbye!" << endl; break;
            default: cout << "Invalid choice! Please enter 1-4." << endl;
        }
        cout << endl;
    } while(choice != 4);

    return 0;
}

void showMenu() {
    cout << "================================" << endl;
    cout << "   STUDENT RECORD SYSTEM MENU   " << endl;
    cout << "================================" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Display all students" << endl;
    cout << "3. Calculate average score" << endl;
    cout << "4. Quit" << endl;
}
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
void addStudent(vector<Student> &students) {
    Student s;
    int numScores;

    cout << "Student name: ";
    getline(cin, s.name);

    cout << "Student ID: ";
    cin >> s.id;

    cout << "How many scores? ";
    cin >> numScores;

    for(int i = 0; i < numScores; i++) {
        double score;
        cout << "Enter score " << i + 1 << ": ";
        cin >> score;
        s.scores.push_back(score);
    }

    students.push_back(s);
    cout << "Student \"" << s.name << "\" added successfully." << endl;
}
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
void displayAllStudents(const vector<Student> &students) {
    if (students.empty()) {
        cout << "No students have been added yet." << endl;
        return;
    }

    cout << left << setw(20) << "Name" 
         << setw(12) << "ID" 
         << setw(30) << "Scores" 
         << "Average" << endl;
    cout << "----------------------------------------------------------------------" << endl;

    for(const auto &s : students) {
        double avg = 0.0;
        if (!s.scores.empty()) {
            avg = accumulate(s.scores.begin(), s.scores.end(), 0.0) / s.scores.size();
        }

        cout << left << setw(20) << s.name 
             << setw(12) << s.id;

        // print scores
        for(double score : s.scores) {
            cout << score << " ";
        }
        
        // pad spaces before average
        cout << setw(5) << " ";
        cout << fixed << setprecision(2) << avg << endl;
    }
}
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
void calculateAverage(const vector<Student> &students) {
    if (students.empty()) {
        cout << "No students in the system." << endl;
        return;
    }

    int searchId;
    cout << "Enter student ID: ";
    cin >> searchId;

    for(const auto &s : students) {
        if (s.id == searchId) {
            double avg = 0.0;
            if (!s.scores.empty()) {
                avg = accumulate(s.scores.begin(), s.scores.end(), 0.0) / s.scores.size();
            }
            cout << s.name << "'s average score: " << fixed << setprecision(2) << avg << endl;
            return;
        }
    }
    cout << "Error: Student ID " << searchId << " not found." << endl;
}
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

