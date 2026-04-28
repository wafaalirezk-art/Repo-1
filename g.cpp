#include <iostream>
#include <vector>
using namespace std;

class Student {
public:
    int id;
    string name;
    vector<string> courses;

    Student(int i, string n) {
        id = i;
        name = n;
    }
};

class System {
private:
    vector<Student> students;

public:
    void addStudent() {
        int id;
        string name;

        cout << "Enter ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);

        students.push_back(Student(id, name));
        cout << "Student added!\n";
    }

    void deleteStudent() {
        int id;
        cout << "Enter ID: ";
        cin >> id;

        for (int i = 0; i < students.size(); i++) {
            if (students[i].id == id) {
                students.erase(students.begin() + i);
                cout << "Deleted!\n";
                return;
            }
        }
        cout << "Not found!\n";
    }

    void addCourse() {
        int id;
        string course;

        cout << "Enter Student ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Course: ";
        getline(cin, course);

        for (auto &s : students) {
            if (s.id == id) {
                s.courses.push_back(course);
                cout << "Course added!\n";
                return;
            }
        }
        cout << "Student not found!\n";
    }

    void deleteCourse() {
        int id;
        string course;

        cout << "Enter Student ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Course: ";
        getline(cin, course);

        for (auto &s : students) {
            if (s.id == id) {
                for (int i = 0; i < s.courses.size(); i++) {
                    if (s.courses[i] == course) {
                        s.courses.erase(s.courses.begin() + i);
                        cout << "Course removed!\n";
                        return;
                    }
                }
            }
        }
        cout << "Not found!\n";
    }

    void displayStudents() {
        cout << "\nStudents:\n";
        for (auto &s : students) {
            cout << s.id << " - " << s.name << endl;
            cout << "Courses: ";
            for (auto &c : s.courses) {
                cout << c << ", ";
            }
            cout << endl;
        }
    }
};

int main() {
    System sys;
    int choice;

    do {
        cout << "\n--- Student System ---\n";
        cout << "1. Add Student\n2. Delete Student\n3. Add Course\n";
        cout << "4. Delete Course\n5. Display\n0. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1: sys.addStudent(); break;
            case 2: sys.deleteStudent(); break;
            case 3: sys.addCourse(); break;
            case 4: sys.deleteCourse(); break;
            case 5: sys.displayStudents(); break;
        }
    } while (choice != 0);

    return 0;
}