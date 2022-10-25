#include <bits/stdc++.h>
using namespace std;
class student {
   private:
    string name1, no, name2, name3, address, mobile;

   public:
    void menu();
    void admin_login();
    void faculty_login();
    void student_login();
    void add_student();
    void remove_student();
    void student_record();
    void information();
};
void student ::menu() {
    int choice1;
    char x;
// system("cls");
menustart:

    cout << "\t\t\t\t****************************" << endl;
    cout << "\t\t\t\t****************************" << endl;
    cout << "\t\t\t\t|| Student Management System ||" << endl;
    cout << "\t\t\t\t****************************" << endl;
    cout << "\t\t\t\t****************************" << endl;

    cout << "\t\t\t\t 1. ADMIN LOGIN" << endl;
    cout << "\t\t\t\t 2. FACULTY LOGIN" << endl;
    cout << "\t\t\t\t 3. STUDENT LOGIN" << endl;
    cout << "\t\t\t\t 4. EXIT" << endl;
    cout << "\t\t\t\t---------------------------" << endl;
    cout << "\t\t\t\t CHOOSE OPTION[1,2,3,4]" << endl;
    cout << "\t\t\t\t---------------------------" << endl;
    cout << "\t\t\t\t ENTER YOUR OPTION: " << endl;
    cin >> choice1;

    switch (choice1) {
        case 1:
            admin_login();
            break;
        case 2:
            faculty_login();
            break;
        case 3:
            student_login();
            break;
        case 4:
            exit(0);

        default:
            cout << "\n\t\t\t\t Please try again later" << endl;
            break;
    }
}
void student::admin_login() {
    int choice2;
    char x1;
menustart:
    // system("cls");
    fstream file;
    cout << "\n------------------------------------------------------------------------------------------";
    cout << "\n-------------------------------------ADMIN LOGIN------------------------------------------" << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
    cout << "\n\t\t\t\t 1.ADD NEW STUDENT" << endl;
    cout << "\t\t\t\t 2.REMOVE STUDENT" << endl;
    cout << "\t\t\t\t 3.STUDENT DISPLAY" << endl;
    cout << "\t\t\t\t 4.EXIT" << endl;
    cout << "\t\t\t\t---------------------------" << endl;
    cout << "\t\t\t\t CHOOSE OPTION[1,2,3]" << endl;
    cout << "\t\t\t\t---------------------------" << endl;
    cout << "\t\t\t\t ENTER YOUR OPTION: " << endl;
    cin >> choice2;

    switch (choice2) {
        case 1:

            do {
                add_student();
                cout << "\n\t\t\tadd another student record(Y<N add_student(Y,N): ";
                cin >> x1;
            } while (x1 == 'y' || x1 == 'Y');

            break;
        case 2:
            remove_student();
            break;
        case 3:
            student_record();
            break;
        case 4:
            exit(0);

        default:
            cout << "\n\t\t\t\t Please try again later" << endl;
            break;
    }
}
void student::add_student() {
menustart:
    fstream file;
    cout << "\n------------------------------------------------------------------------------------------";
    cout << "\n-------------------------------------ADD NEW STUDENT------------------------------------------" << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t ENTER NAME: " << endl;
    cin >> name1;
    cout << "\t\t ROLL NO: " << endl;
    cin >> no;
    cout << "\t\t FATHERS NAME: " << endl;
    cin >> name2;
    cout << "\t\t MOTHERS NAME: " << endl;
    cin >> name3;
    cout << "\t\t EMAIL ADDRESS: " << endl;
    cin >> address;
    cout << "\t\t MOBILE NO: " << endl;
    cin >> mobile;
    file.open("studentRecord.txt", ios::app | ios::out);
    file << " " << name1 << " " << no << " " << name2 << " " << name3 << " " << address << " " << mobile << "\n";
    file.close();
}
void student::remove_student() {
manustart:
    fstream file;
    cout << "\n------------------------------------------------------------------------------------------";
    cout << "\n-------------------------------------REMOVE STUDENT------------------------------------------" << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
}
void student::student_record() {
manustart:
    fstream file;
    int total = 1;
    cout << "\n------------------------------------------------------------------------------------------";
    cout << "\n-------------------------------------STUDENT RECORD------------------------------------------" << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file) {
        cout << "\n\t\t\t NO DATA IS PRESENT....";
        file.close();
    } else {
        file >> name1 >> no >> name2 >> name3 >> address >> mobile;
        while (!file.eof()) {
            cout << "\t\t\t STUDENT NO: " << total++ << endl;
            cout << "\t\t\t STUDENT NAME: " << name1 << endl;
            cout << "\t\t\t STUDENT FATHERS NAME: " << name2 << endl;
            cout << "\t\t\t STUDENT MOTHERS NAME: " << name3 << endl;
            cout << "\t\t\t STUDENT EMAIL ADDRESS: " << address << endl;
            cout << "\t\t\t STUDENT MOBILE NO: " << mobile << endl;
            file >> name1 >> no >> name2 >> name3 >> address >> mobile;
        }
        if (total == 0) {
            cout << "\n\t\t\t NO DATA IS PRESENT....";
        }
    }
    file.close();
}
void student::faculty_login() {
menustart:
    // system("cls");
    fstream file;
    cout << "\n------------------------------------------------------------------------------------------";
    cout << "\n-------------------------------------FACULTY LOGIN------------------------------------------" << endl;
    cout << "\n-------------------------------------------------------------------------------------------";
}

void student::student_login() {
    int choice2;
    char x2;
menustart:
    // system("cls");
    fstream file;
    cout << "\n------------------------------------------------------------------------------------------";
    cout << "\n-------------------------------------STUDENT LOGIN------------------------------------------" << endl;
    cout << "-------------------------------------------------------------------------------------------";
    cout << "\n\t\t\t\t 1.INFORMATION" << endl;
    cout << "\t\t\t\t 2.EXIT" << endl;
    cin >> choice2;
    switch (choice2) {
        case 1:
            information();
            break;
        case 2:
            exit(0);
        default:
            cout << "\t\t\t\t Please try again later" << endl;
            break;
    }
}
void student::information() {
manustart:
    fstream file;
    int search = 1;
    file.open("studentRecord.txt", ios::in);
    if (!file) {
        cout << "\n------------------------------------------------------------------------------------------";
        cout << "\n-------------------------------------INFORMATION------------------------------------------" << endl;
        cout << "-------------------------------------------------------------------------------------------" << endl;
        cout << "\n\t\t\t DATA IS'NT AVAILABLE NOW..........";
    } else {
        string roll_no;
        cout << "\n------------------------------------------------------------------------------------------";
        cout << "\n-------------------------------------INFORMATION------------------------------------------" << endl;
        cout << "-------------------------------------------------------------------------------------------" << endl;
        cout << "\n\t\t\t PLEASE ENTER YOUR ROLL NO: ";
        cin >> roll_no;
        file >> name1 >> no >> name2 >> name3 >> address >> mobile;
        while (!file.eof()) {
            if (roll_no == no) {
                cout << "\t\t\t STUDENT NAME: " << name1 << endl;
                cout << "\t\t\t STUDENT FATHERS NAME: " << name2 << endl;
                cout << "\t\t\t STUDENT MOTHERS NAME: " << name3 << endl;
                cout << "\t\t\t STUDENT EMAIL ADDRESS: " << address << endl;
                cout << "\t\t\t STUDENT MOBILE NO: " << mobile << endl;
                file >> name1 >> no >> name2 >> name3 >> address >> mobile;
                search++;
            }
        }
    }
}

main()

{
    student project;
    project.menu();
    return 0;
}