/*Name: Dhanashree Sikandar Sul
PRN No:123B1B273  Div:D3
Assignment No. 7
Title:
Implement a browser history management system using a stack data structure to track the user's browsing history. 
The system should support the following functionalities: 
a. Add visited page 
b. Navigate back 
c. View current page 
d. Check if history is empty or not Assume no upper bound on number of pages visited. */

#include <iostream>
using namespace std;

class Webpage {
public:
    string Site_Name;  
    Webpage *next;     

    Webpage() {
        next = NULL;
    }

    // Function to read the site name from the user
    void read() {
        cout << "ENTER THE SITE NAME: ";
        cin >> Site_Name;
    }

    // Function to display the site name
    void display() {
        cout << "SITE IS: " << Site_Name << endl;
    }
};

class browserhistory {
public:
    Webpage *top;  
    browserhistory() {
        top = NULL;
    }

    // Function to check if the browser history is empty
    void isEmpty() {
        if (top == NULL) {
            cout << "WEB HISTORY IS EMPTY" << endl;
        } else {
            cout << "WEB HISTORY IS NOT EMPTY" << endl;
        }
    }

    // Function to add a new webpage to the top of the history stack
    void ADD_NEW_PAGE() {  // push()
        Webpage *nn = new Webpage;  
        nn->read();  
        if (top == NULL) {
            top = nn;  
        } else {
            nn->next = top;  
            top = nn; 
        }
    }

    // Function to navigate back 
    void NAVIGATE_BACK() { //pop() 
        Webpage *temp = top;  
        if (top == nullptr) {
            cout << "WEB HISTORY IS EMPTY" << endl; 
        } else {
            top = top->next; 
            cout << temp->Site_Name << " SITE IS DELETED" << endl;  
            delete temp;  
        }
    }

    // Function to display the last visited webpage
    void PEAK_LAST_SITE() {
        if (top == nullptr) {
            cout << "WEBPAGE HISTORY IS EMPTY" << endl;  
        } else {
            cout << "LAST WEBPAGE IS: ";
            cout << top->Site_Name; 
            cout << endl;
        }
    }
};

int main() {
    browserhistory H;  
    int choice;
    
    do {
        cout << "---------------------------------------------------------------------------" << endl;
        cout << "CHOOSE WHAT YOU WANT TO DO:" << endl
             << "1. PUSH." << endl
             << "2. POP." << endl
             << "3. PEAK." << endl
             << "4. ISEMPTY." << endl
             << "5. EXIT" << endl;
        cin >> choice;
        cout << "---------------------------------------------------------------------------" << endl;

        switch (choice) {
            case 1:
                cout << " " << endl;
                H.ADD_NEW_PAGE(); 
                break;

            case 2:
                H.NAVIGATE_BACK(); 
                break;

            case 3:
                H.PEAK_LAST_SITE();  
                break;

            case 4:
                H.isEmpty(); 
                break;

            case 5:
                exit(0);  
                cout << "THANK YOU .......EXITING THE PROGRAM" << endl;
                break;

            default:
                cout << "WRONG choice" << endl;  
                break;
        }

    } while (true); 
    return 0;
}
