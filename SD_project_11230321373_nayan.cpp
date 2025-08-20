#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    int roll;
    string name;
    float marks;
};

void addStudent() {
    Student s;
    ofstream out("students.txt", ios::app);
    cout << "Enter Roll, Name, Marks: ";
    cin >> s.roll >> s.name >> s.marks;
    out << s.roll << " " << s.name << " " << s.marks << endl;
    out.close();
}

void viewStudents() {
    Student s;
    ifstream in("students.txt");
    while (in >> s.roll >> s.name >> s.marks) {
        cout << s.roll << " " << s.name << " " << s.marks << endl;
    }
    in.close();
}

void deleteStudent() {
    int r;
    cout << "Enter Roll to Delete: ";
    cin >> r;

    ifstream in("students.txt");
    ofstream temp("temp.txt");
    Student s;
    bool found = false;

    while (in >> s.roll >> s.name >> s.marks) {
        if (s.roll != r) temp << s.roll << " " << s.name << " " << s.marks << endl;
        else found = true;
    }

    in.close();
    temp.close();
    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found) cout << "Deleted successfully.\n";
    else cout << "Record not found.\n";
}

int main() {
    int choice;
    do {
        cout << "\n1. Add Student\n2. View Students\n3. Delete Student\n4. Exit\nEnter choice: ";
        cin >> choice;
        if (choice == 1) addStudent();
        else if (choice == 2) viewStudents();
        else if (choice == 3) deleteStudent();
    } while (choice != 4);
    return 0;
}
