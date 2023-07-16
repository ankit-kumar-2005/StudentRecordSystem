#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    int rollNum;
    string name;
    string branch;
    int semester;
    float Score;
    float attendance;
    bool feePaid;
    Student* next;
};

class StudentRecord {
private:
    Student* head;

public:
    StudentRecord() {
        head = NULL;
    }

    void addStudent(int rollNum, const string& name, const string& branch, int semester, float Score, float attendance, bool feePaid) {
        Student* newStudent = new Student;
        newStudent->rollNum = rollNum;
        newStudent->name = name;
        newStudent->branch = branch;
        newStudent->semester = semester;
        newStudent->Score = Score;
        newStudent->attendance = attendance;
        newStudent->feePaid = feePaid;
        newStudent->next = NULL;

        if (head == NULL) {
            head = newStudent;
        } else {
            Student* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newStudent;
        }
        cout << "Student added successfully." << endl;
    }

    void displayStudents() {
        if (head == NULL) {
            cout << "No students found." << endl;
        } else {
            Student* temp = head;
            while (temp != NULL) {
                cout << "Roll Number: " << temp->rollNum << endl;
                cout << "Name: " << temp->name << endl;
                cout << "branch: " << temp->branch << endl;
                cout << "Semester: " << temp->semester << endl;
                cout << "Score: " << temp->Score << endl;
                cout << "Attendance: " << temp->attendance << endl;
                cout << "Fee Paid: " << (temp->feePaid ? "Yes" : "No") << endl;
                cout << "-----------------------" << endl;
                temp = temp->next;
            }
        }
    }

    void printExamEligibleStudents() {
        if (head == NULL) {
            cout << "No students found." << endl;
            return;
        }

        Student* temp = head;
        bool found = false;
        while (temp != NULL) {
            if (temp->Score >= 40 && temp->attendance >= 75 && temp->feePaid) {
                cout << "Roll Number: " << temp->rollNum << endl;
                cout << "Name: " << temp->name << endl;
                cout << "-----------------------" << endl;
                found = true;
            }
            temp = temp->next;
        }

        if (!found)
            cout << "No eligible students found." << endl;
    }

    void printLowAttendanceStudents() {
        if (head == NULL) {
            cout << "No students found." << endl;
            return;
        }

        Student* temp = head;
        bool found = false;
        while (temp != NULL) {
            if (temp->attendance < 75) {
                cout << "Roll Number: " << temp->rollNum << endl;
                cout << "Name: " << temp->name << endl;
                cout << "Attendance: " << temp->attendance << endl;
                cout << "-----------------------" << endl;
                found = true;
            }
            temp = temp->next;
        }

        if (!found)
            cout << "No students with low attendance found." << endl;
    }

    void printFeePendingStudents() {
        if (head == NULL) {
            cout << "No students found." << endl;
            return;
        }

        Student* temp = head;
        bool found = false;
        while (temp != NULL) {
            if (!temp->feePaid) {
                cout << "Roll Number: " << temp->rollNum << endl;
                cout << "Name: " << temp->name << endl;
                cout << "-----------------------" << endl;
                found = true;
            }
            temp = temp->next;
        }

        if (!found)
            cout << "No students with pending fees found." << endl;
    }

    void clearStudents() {
        Student* temp;
        while (head != NULL) {
            temp = head;
            head = head->next;
            delete temp;
        }
        cout << "Student records cleared." << endl;
    }

    ~StudentRecord() {
        clearStudents();
    }

    void deleteStudent(int rollNum) {
        if (head == NULL) {
            cout << "No students found." << endl;
            return;
        }

        if (head->rollNum == rollNum) {
            Student* temp = head;
            head = head->next;
            delete temp;
            cout << "Student with roll number " << rollNum << " deleted successfully." << endl;
            return;
        }

        Student* prev = NULL;
        Student* current = head;

        while (current != NULL && current->rollNum != rollNum) {
            prev = current;
            current = current->next;
        }

        if (current == NULL) {
            cout << "Student with roll number " << rollNum << " not found." << endl;
            return;
        }

        prev->next = current->next;
        delete current;
        cout << "Student with roll number " << rollNum << " deleted successfully." << endl;
    }

    void searchStudent(int rollNum) {
        if (head == NULL) {
            cout << "No students found." << endl;
            return;
        }

        Student* temp = head;
        while (temp != NULL) {
            if (temp->rollNum == rollNum) {
                cout << "Roll Number: " << temp->rollNum << endl;
                cout << "Name: " << temp->name << endl;
                cout << "Branch: " << temp->branch << endl;
                cout << "semester: " << temp -> semester << endl;
                cout << "Score: " << temp->Score << endl;
                cout << "Attendace: " << temp->attendance << endl;
                cout <<"Fees Paid: " << temp->feePaid << endl; 
                return;
            }
            temp = temp->next;
        }

        cout << "Student with roll number " << rollNum << " not found." << endl;
    }

    void updateScore_updateSemester(int rollNum, float Score, int Newsemester) {
        if (head == NULL) {
            cout << "No students found." << endl;
            return;
        }

        Student* temp = head;
        while (temp != NULL) {
            if (temp->rollNum == rollNum) {
                temp->Score = Score;
                temp->semester = Newsemester;
                cout << "Score and Semester updated successfully." << endl;
                return;
            }
            temp = temp->next;
        }

        cout << "Student with roll number " << rollNum << " not found." << endl;
    }

};

int main() {
    StudentRecord record;
    int choice;


    do {
        cout << "-----------------------" << endl;
        cout << "Student Record Management System" << endl;
        cout << "-----------------------" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display Students" << endl;
        cout << "3. Delete Student" << endl;
        cout << "4. Search Student" << endl;
        cout << "5. Update Score" << endl;
        // cout << "6. Calculate Average Score" << endl;
        cout << "6. Print Exam Eligible Student" << endl;
        cout << "7. Print Low Attendace Students" << endl;
        cout << "8. Print Fee Pending Students" << endl;
        cout << "0. Exit" << endl;
        cout << "-----------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1: {
                int rollNum;
                string name; 
                string branch;
                int semester;
                float Score;
                float attendance;
                bool feePaid;
                

                cout << "Enter Roll Number: ";
                cin >> rollNum;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Branch/Department: " ;
                cin >> branch ;
                cout << "Enter Your Current Semester: " ;
                cin >> semester;
                cout << "Enter Score: ";
                cin >> Score;
                cout << "Attendance: ";
                cin>> attendance ;
                cout << "Fee Paid (0/1): ";
                cin >> feePaid ; 


                record.addStudent(rollNum,name,branch,semester,Score,attendance,feePaid);
                cout << endl;
                break;
            }
            case 2: {
                //All Students will be Displayed
                record.displayStudents();
                cout << endl;
                break;
            }
            case 3: {
                int rollNum;
                cout << "Enter Roll Number of Student to Delete: ";
                cin >> rollNum;

                record.deleteStudent(rollNum);
                cout << endl;
                break;
            }
            case 4: {
                int rollNum;
                cout << "Enter Roll Number of Student to Search: ";
                cin >> rollNum;

                //Students with particular roll number be displayed
                record.searchStudent(rollNum);
                cout << endl;
                break;
            }
            case 5: {
                int rollNum;
                float Score;
                int newSemester;
                cout << "Enter Roll Number of Student to Update Score: ";
                cin >> rollNum;
                cout << "Enter New Score: ";
                cin >> Score;
                cout << "Enter Next Semester ";
                cin >> newSemester;

                record.updateScore_updateSemester(rollNum, Score, newSemester);
                cout << endl;
                break;
            }
            // case 6: {
            //     // record.calculateAverageScore();
            //     cout << endl;
            //     break;
            // }
            case 6: {
                record.printExamEligibleStudents();
                cout<<endl;
                break;

            }
            case 7: {
                record.printLowAttendanceStudents();
                cout << endl;
                break;
            }
            
            case 8: {
                record.printFeePendingStudents();
                cout << endl;
                break;
            }

            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                cout << endl;
        }
    } while (choice != 0);

    return 0;
}
