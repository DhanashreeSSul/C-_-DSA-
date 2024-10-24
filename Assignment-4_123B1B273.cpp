/* Name: Dhanashree Sikandar Sul
PRN No: 123B1B273  Div: D3
Assignment No. 4
Title:
Implement a simple text editor application using a doubly linked list to manage the text buffer.
Text editor should support the following functionalities:
a. Insert text
b. Delete text
c. Display text
d. Search text
e. Print text in reverse.
*/

#include <iostream>
using namespace std;

class Statement {
public:
    string text;
    Statement* next;
    Statement* prev;

    Statement() : next(nullptr), prev(nullptr) {}

    // Read function
    void read_text() {
        cout << "ENTER THE TEXT THAT YOU WANT TO ADD: ";
        getline(cin, text);
    }

    // Display function
    void display_text() {
        cout << "YOUR TEXT IS: " << text << endl;
    }
};

class Word_Processor {
public:
    Statement* head, * tail;

    Word_Processor() : head(nullptr), tail(nullptr) {}

    // Add new statement to the end
    void Add_new_Statement() {
        Statement* nn = new Statement();
        nn->read_text();
        if (head == nullptr) {
            head = tail = nn;
        } else {
            tail->next = nn;
            nn->prev = tail;
            tail = nn;
        }
    }

    // Display all statements in the text editor
    void Display_text_editor() {
        Statement* cn = head;
        while (cn) {
            cn->display_text();
            cn = cn->next;
        }
    }

    // Add statement at the beginning
    void Insert_at_beginning() {
        Statement* nn = new Statement();
        nn->read_text();
        if (head == nullptr) {
            head = tail = nn;
        } else {
            nn->next = head;
            head->prev = nn;
            head = nn;
        }
    }

    // Insert at specific position
    void Insert_at_specific_Position(int position) {
        if (position < 0) return;
        Statement* nn = new Statement();
        nn->read_text();
        if (position == 0) {
            Insert_at_beginning();
            return;
        }

        Statement* cn = head;
        for (int i = 0; cn && i < position - 1; i++) {
            cn = cn->next;
        }
        if (cn == nullptr) {
            cout << "Position out of range!" << endl;
            delete nn;
            return;
        }
        nn->next = cn->next;
        nn->prev = cn;
        if (cn->next) {
            cn->next->prev = nn;
        }
        cn->next = nn;
        if (nn->next == nullptr) {
            tail = nn;
        }
    }

    // Delete a statement from the text editor
    void Delete_Statement() {
        string text_to_delete;
        cout << "ENTER TEXT TO DELETE: ";
        getline(cin, text_to_delete);
        Statement* cn = head;
        while (cn) {
            if (cn->text == text_to_delete) {
                if (cn == head) {
                    head = cn->next;
                    if (head) {
                        head->prev = nullptr;
                    }
                } else {
                    cn->prev->next = cn->next;
                }
                if (cn == tail) {
                    tail = cn->prev;
                    if (tail) {
                        tail->next = nullptr;
                    }
                } else {
                    if (cn->next) {
                        cn->next->prev = cn->prev;
                    }
                }
                Statement* temp = cn;
                cn = cn->next;
                delete temp;
                return;
            }
            cn = cn->next;
        }
        cout << "Text not found!" << endl;
    }

    // Display text editor in reverse order
    void Display_text_Editor_reverse() {
        if (head == nullptr) {
            cout << "TEXT EDITOR IS EMPTY!" << endl;
            return;
        } else {
            Statement* cn;
            for (cn = tail; cn != nullptr; cn = cn->prev) {
                cn->display_text();
            }
        }
    }
};

int main() {
    Word_Processor W;
    int choice;

    while (1) {
        cout << endl << "--- OPERATIONS TO PERFORM ON THE TEXT EDITOR ---" << endl;
        cout << "1. ADD STATEMENT AT THE END" << endl;
        cout << "2. ADD STATEMENT AT THE BEGINNING" << endl;
        cout << "3. ADD STATEMENT AT POSITION" << endl;
        cout << "4. DELETE STATEMENT" << endl;
        cout << "5. DISPLAY TEXT IN REVERSE ORDER" << endl;
        cout << "6. EXIT" << endl;
        cout << "CHOOSE YOUR OPTION: ";
        cin >> choice;
        cin.ignore(); // To clear the newline character from the input buffer

        switch (choice) {
        case 1:
            cout << endl << "----- ADD STATEMENT AT THE END -----" << endl;
            W.Add_new_Statement();
            cout << endl << "----- DISPLAYING TEXT EDITOR -----" << endl;
            W.Display_text_editor();
            break;
        case 2:
            cout << endl << "----- ADD STATEMENT AT THE BEGINNING -----" << endl;
            W.Insert_at_beginning();
            cout << endl << "----- DISPLAYING TEXT EDITOR -----" << endl;
            W.Display_text_editor();
            break;
        case 3:
            cout << "----- ADD STATEMENT AT SPECIFIC POSITION -----" << endl;
            int pos;
            cout << "Enter position: ";
            cin >> pos;
            cin.ignore();
            W.Insert_at_specific_Position(pos);
            cout << endl << "----- DISPLAYING TEXT EDITOR -----" << endl;
            W.Display_text_editor();
            break;
        case 4:
            cout << endl << "----- DELETE STATEMENT -----" << endl;
            W.Delete_Statement();
            cout << endl << "----- DISPLAYING TEXT EDITOR -----" << endl;
            W.Display_text_editor();
            break;
        case 5:
            cout << endl << "----- DISPLAY TEXT IN REVERSE ORDER -----" << endl;
            W.Display_text_Editor_reverse();
            break;
        case 6:
            cout << endl << "EXITING FROM THE PROGRAM...THANK YOU!" << endl;
            return 0;
        default:
            cout << endl << "INVALID OPTION! PLEASE TRY AGAIN." << endl;
            break;
        }
    }

    return 0;
}
