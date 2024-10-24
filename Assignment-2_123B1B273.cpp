/*Name: Dhanashree Sikandar Sul
PRN No:123B1B273  Div:D3
Assignment No. 2A
Title:
Consider Employee database of PCCOE (at least 20 records).
 Database contains different fields of every employee like EMP-ID, EMP-Name and EMP-Salary.
 a. Arrange list of employees according to EMP-ID in ascending order using Quick Sort 
 b. Arrange list of Employee alphabetically using Merge Sort.*/

#include <iostream>
#include <cstring>
using namespace std;

class Employee {
public:
    char name[50];
    int id;
    int salary;

    void getdata() {
        cout << "ENTER THE NAME OF EMPLOYEE: ";
        cin.ignore();  // To handle newline characters
        cin.getline(name, 50);
        cout << "ENTER THE EMPLOYEE ID: ";
        cin >> id;
        cout << "ENTER THE EMPLOYEE SALARY: ";
        cin >> salary;
        cout << endl;
    }

    void showdata() {
        cout << "THE NAME OF EMPLOYEE: " << name << endl;
        cout << "ID OF THE EMPLOYEE: " << id << endl;
        cout << "SALARY OF THE EMPLOYEE: " << salary << endl;
        cout << endl;
    }

    // Friend functions for quicksort and merge sort
    friend void Quick_sort(Employee a[], int i, int j);
    friend int partition(Employee a[], int i, int j);
    friend void merge_sort(Employee a[], int low, int high);
    friend void merge(Employee a[], int low, int mid, int high);
};

// Quick Sort for sorting by Employee ID
void Quick_sort(Employee a[], int i, int j) {
    if (i < j) {
        int pos_pivot = partition(a, i, j);
        Quick_sort(a, i, pos_pivot - 1);
        Quick_sort(a, pos_pivot + 1, j);
    }
}

int partition(Employee a[], int i, int j) {
    int left = i, right = j;
    int pivot = a[i].id;

    while (left < right) {
        while (a[left].id <= pivot && left < j) {
            left++;
        }
        while (a[right].id > pivot) {
            right--;
        }
        if (left < right) {
            // Swap the entire employee objects
            Employee temp = a[left];
            a[left] = a[right];
            a[right] = temp;
        }
    }

    // Swap pivot with a[right]
    Employee temp = a[i];
    a[i] = a[right];
    a[right] = temp;

    return right;
}

// Merge Sort for sorting alphabetically by Employee Name
void merge_sort(Employee a[], int low, int high) {
    if (low >= high) {
        return;
    }

    int mid = (low + high) / 2;
    merge_sort(a, low, mid);
    merge_sort(a, mid + 1, high);
    merge(a, low, mid, high);
}

void merge(Employee a[], int low, int mid, int high) {
    Employee temp[100];  // Temporary array for merging
    int left = low;
    int right = mid + 1;
    int i = 0;

    while (left <= mid && right <= high) {
        if (strcmp(a[left].name, a[right].name) <= 0) {
            temp[i] = a[left];
            left++;
        } else {
            temp[i] = a[right];
            right++;
        }
        i++;
    }

    // Copy remaining elements from left half
    while (left <= mid) {
        temp[i] = a[left];
        left++;
        i++;
    }

    // Copy remaining elements from right half
    while (right <= high) {
        temp[i] = a[right];
        right++;
        i++;
    }

    // Copy the sorted elements back to the original array
    for (int j = 0; j < i; j++) {
        a[low + j] = temp[j];
    }
}

// Main function with menu-driven approach
int main() {
    Employee a[100];
    int n, choice;

    cout << "ENTER THE NUMBER OF EMPLOYEES (MAX 100): ";
    cin >> n;
    cout << endl;

    cout << "TAKING DATA FROM USER: " << endl;
    for (int i = 0; i < n; i++) {
        a[i].getdata();
    }

    while (true) {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Sort by Employee ID (Quick Sort)" << endl;
        cout << "2. Sort by Employee Name (Merge Sort)" << endl;
        cout << "3. Display All Employee Records" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                Quick_sort(a, 0, n - 1);
                cout << "\nEMPLOYEE RECORDS SORTED BY EMPLOYEE ID:" << endl;
                for (int i = 0; i < n; i++) {
                    a[i].showdata();
                }
                break;

            case 2:
                merge_sort(a, 0, n - 1);
                cout << "\nEMPLOYEE RECORDS SORTED BY NAME:" << endl;
                for (int i = 0; i < n; i++) {
                    a[i].showdata();
                }
                break;

            case 3:
                cout << "\nDISPLAYING ALL EMPLOYEE RECORDS:" << endl;
                for (int i = 0; i < n; i++) {
                    a[i].showdata();
                }
                break;

            case 4:
                cout << "Exiting the program..." << endl;
                return 0;

            default:
                cout << "Invalid choice! Try again." << endl;
                break;
        }
    }

    return 0;
}
