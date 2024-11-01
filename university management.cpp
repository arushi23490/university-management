#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

class University {
private:
    string RollNo, Name, Subject, Address;

public:
    University() : RollNo(""), Name(""), Subject(""), Address("") {}

    void setRollNo(const string& rollNo) {
        RollNo = rollNo;
    }

    void setName(const string& name) {
        Name = name;
    }

    void setSubject(const string& subject) {
        Subject = subject;
    }

    void setAddress(const string& address) {
        Address = address;
    }

    string getRollNo() const {
        return RollNo;
    }

    string getName() const {
        return Name;
    }

    string getSubject() const {
        return Subject;
    }

    string getAddress() const {
        return Address;
    }

    static void add(University& student) {
        string rollNo, name, subject, address;

        cout << "\tEnter RollNo Of Student: ";
        cin >> rollNo;
        student.setRollNo(rollNo);

        cout << "\tEnter Name Of Student: ";
        cin >> name;
        student.setName(name);

        cout << "\tEnter Subject Of Student: ";
        cin >> subject;
        student.setSubject(subject);

        cout << "\tEnter Address Of Student: ";
        cin >> address;
        student.setAddress(address);

        ifstream in("D:/university.txt");
        if (!in) {
            cout << "\tError: File Can't Open!" << endl;
            return;
        }

        string line;
        bool found = false;
        while (getline(in, line)) {
            if (line.find(rollNo) != string::npos) {
                found = true;
                cout << "Roll number already exists. Please use a different roll number." << endl;
                break;
            }
        }
        in.close();

        if (!found) {
            ofstream out("D:/university.txt", ios::app);
            if (!out) {
                cout << "\tError: File Can't Open!" << endl;
            } else {
                out << student.getRollNo() << " : " << student.getName() << " : "
                    << student.getSubject() << " : " << student.getAddress() << endl;
                out.close();
                cout << "\tStudent Added Successfully!" << endl;
            }
        }
    }

    static void search() {
        string rollNo;
        cout << "\tEnter RollNo Of Student: ";
        cin >> rollNo;

        ifstream in("D:/university.txt");
        if (!in) {
            cout << "\tError: File Can't Open!" << endl;
            return;
        }

        string line;
        bool found = false;
        while (getline(in, line)) {
            if (line.find(rollNo) != string::npos) {
                cout << "\t" << line << endl;
                found = true;
                break;
            }
        }
        in.close();

        if (!found) {
            cout << "\tStudent Not Found!" << endl;
        }
    }

    static void update(University& student) {
        string rollNo;
        cout << "\tEnter RollNo Of Student: ";
        cin >> rollNo;

        ifstream infile("D:/university.txt");
        ofstream outfile("D:/universityTemp.txt");
        if (!infile || !outfile) {
            cout << "\tError: File Can't Open!" << endl;
            return;
        }

        string line;
        bool found = false;
        while (getline(infile, line)) {
            if (line.find(rollNo) != string::npos) {
                found = true;
                string address;
                cout << "\tEnter New Address: ";
                cin >> address;
                student.setAddress(address);

                int newPos = line.find_last_of(':');
                line.replace(newPos + 2, string::npos, student.getAddress());
                cout << "\tData Updated!" << endl;
            }
            outfile << line << endl;
        }

        infile.close();
        outfile.close();

        if (found) {
            remove("D:/university.txt");
            rename("D:/universityTemp.txt", "D:/university.txt");
        } else {
            cout << "\tStudent Not Found!" << endl;
            remove("D:/universityTemp.txt");
        }
    }
};

int main() {
    University student;
    bool exit = false;

    while (!exit) {
        system("cls");
        int val;
        cout << "\tWelcome To University Management System" << endl;
        cout << "\t***************************************" << endl;
        cout << "\t1. Add Student." << endl;
        cout << "\t2. Search Student." << endl;
        cout << "\t3. Update Data Of Student." << endl;
        cout << "\t4. Exit." << endl;
        cout << "\tEnter Your Choice: ";
        cin >> val;

        switch (val) {
            case 1:
                system("cls");
                University::add(student);
                Sleep(2000);
                break;
            case 2:
                system("cls");
                University::search();
                Sleep(2000);
                break;
            case 3:
                system("cls");
                University::update(student);
                Sleep(2000);
                break;
            case 4:
                exit = true;
                cout << "\tGood Luck!" << endl;
                Sleep(2000);
                break;
            default:
                cout << "\tInvalid Choice!" << endl;
                Sleep(2000);
                break;
        }
    }
    return 0;
}
