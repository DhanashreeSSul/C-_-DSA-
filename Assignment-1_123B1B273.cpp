/*Name: Dhanashree Sikandar Sul
Roll No: SYCOD273
PRN No:123B1B273  Div:D3
Assignment No. 1

Title:Consider a student database of SY COMP class (at least 15 records). 
Database contains different fields of every student like Roll No, Name and SGPA. 
a. Design a roll call list, arrange list of students according to roll numbers in ascending order using Insertion Sort 
b. Arrange list of students alphabetically using shell sort 
c. Arrange list of students to find out first ten toppers from a class using Radix sort.*/

#include <iostream>
#include <cstring>
using namespace std;

class Student {
public:
    char name[50];
    float cgpa;
    int rno;

    void read() {
        cout << "ENTER THE NAME OF STUDENT: ";
        cin >> name;
        cout << "ENTER THE ROLL NO: ";
        cin >> rno;
        cout << "ENTER THE C.G.P.A: ";
        cin >> cgpa;
    }

    void display() {
        cout << "NAME OF STUDENT: " << name << endl;
        cout << "ROLL NO: " << rno << endl;
        cout << "C.G.P.A.: " << cgpa << endl;
    }

    friend void insertionSort(int n, Student s[]);
    friend void shellSort(Student s[], int n);
    friend void countSort(Student s[], int n, int exp);
    friend void radixSort(Student s[], int n);
    friend int getMax(Student s[], int n);
    friend void reverseArray(Student s[], int n);
};

// Insertion Sort for sorting by Roll Numbers
void insertionSort(int n, Student s[]) {
    for (int i = 1; i < n; i++) {
        Student x = s[i];
        int j = i - 1;
        while (j >= 0 && s[j].rno > x.rno) {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = x;
    }
}

// Shell Sort for sorting alphabetically by name
void shellSort(Student s[], int n) {
    int interval = n / 2;
    while (interval >= 1) {
        for (int i = interval; i < n; i++) {
            Student temp = s[i];
            int j;
            for (j = i - interval; j >= 0 && strcmp(s[j].name, temp.name) > 0; j -= interval) {
                s[j + interval] = s[j];
            }
            s[j + interval] = temp;
        }
        interval /= 2;
    }
}

// Radix Sort for sorting by CGPA (to find top students)
void countSort(Student s[], int n, int exp) {
    Student output[n];
    int i, count[10] = {0};

    for (i = 0; i < n; i++) {
        int digit = (int(s[i].cgpa * 1000) / exp) % 10;
        count[digit]++;
    }

    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; i--) {
        int digit = (int(s[i].cgpa * 1000) / exp) % 10;
        output[--count[digit]] = s[i];
    }

    for (i = 0; i < n; i++) {
        s[i] = output[i];
    }
}

int getMax(Student s[], int n) {
    float max = s[0].cgpa;
    for (int i = 1; i < n; i++) {
        if (s[i].cgpa > max) {
            max = s[i].cgpa;
        }
    }
    return int(max * 1000);
}

void radixSort(Student s[], int n) {
    int max = getMax(s, n);
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(s, n, exp);
    }
}

void reverseArray(Student s[], int n) {
    for (int i = 0; i < n / 2; i++) {
        Student temp = s[i];
        s[i] = s[n - 1 - i];
        s[n - 1 - i] = temp;
    }
}

int main() {
    Student students[15];
    int n, choice;

    cout << "ENTER THE NUMBER OF STUDENTS (MAX 15): ";
    cin >> n;

    cout << "ENTER STUDENT DETAILS:\n";
    for (int i = 0; i < n; i++) {
        students[i].read();
    }

    while (true) {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Sort by Roll Number (Insertion Sort)" << endl;
        cout << "2. Sort by Name (Shell Sort)" << endl;
        cout << "3. Find Top 10 Students by CGPA (Radix Sort)" << endl;
        cout << "4. Display All Students" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                insertionSort(n, students);
                cout << "\nStudents sorted by Roll Number:\n";
                for (int i = 0; i < n; i++) {
                    students[i].display();
                }
                break;

            case 2:
                shellSort(students, n);
                cout << "\nStudents sorted by Name:\n";
                for (int i = 0; i < n; i++) {
                    students[i].display();
                }
                break;

            case 3:
                radixSort(students, n);
                reverseArray(students, n); // To get top CGPA students in descending order
                cout << "\nTop 10 Students by CGPA:\n";
                for (int i = 0; i < min(n, 10); i++) {
                    students[i].display();
                }
                break;

            case 4:
                cout << "\nStudent Details:\n";
                for (int i = 0; i < n; i++) {
                    students[i].display();
                }
                break;

            case 5:
                cout << "Exiting the program..." << endl;
                return 0;

            default:
                cout << "Invalid choice! Try again." << endl;
                break;
        }
    }

    return 0;
}
