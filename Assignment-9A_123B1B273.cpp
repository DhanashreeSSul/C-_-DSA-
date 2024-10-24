/*Name: Dhanashree Sikandar Sul
Roll No: SYCOD273
PRN No:123B1B273  Div:D3
Assignment No. 9A

Title: Implement a restaurant waitlist system using the queue data structure.
 Restaurant waitlist provide following facility: 
 a. Add Party to Waitlist 
 b. Seat Party 
 c. Display Waitlist
 */

#include <iostream>
using namespace std;
#define size 10
class Party{
     public:
    Party *next;
    Party(){
        next = NULL;
    }
    string party_name;
    long mobile_no;
    int ticket_no;
   
    //Taking data from user.
    void read()
    {
        cout<<"ENTER THE NAME OF PARTY: ";
        cin>>party_name;
        cout<<"ENTER THE MOBILE NUMBER: ";
        cin>>mobile_no;
        cout<<"ENTER TICKET NUMBER:";
        cin>>ticket_no;
    }
    //Function to dispaly Party Details
    void display()
    {
        cout<<"PARTY_NAME: "<<party_name<<endl;
        cout<<"MOBILE_NUMBER: "<<mobile_no<<endl;
        cout<<"TICKET NUMBER:"<<ticket_no<<endl;
    }
};

class Party_Queue{
    public:

    Party *front, *rear;
    int currsize;
    Party_Queue()
    {
        front = rear = NULL;
        currsize = 0;
    }
    // funtion to add party in Waitlist
     void ADD_PARTY_TO_WAITLIST()
    {
        Party* temp = new Party();
        temp->read();
        temp->next = nullptr;

        if (currsize == 0) {
            front = rear = temp;
        } else {
            rear->next = temp;  
            rear = temp;       
        }

        currsize++;
        cout << "PARTY IS ADDED TO WAITLIST."<<endl;
    }

    // Function to seat a party and remove it from the waitlist
    void Seat_Party()
    {
        if (currsize == 0) {
            cout << "WAITLIST IS EMPTY" << endl;
            return;
        }

        Party* temp = front; 
        front = front->next; 
        delete temp;         

        currsize--;
        if (currsize == 0) {
            rear = nullptr; 
        }

        cout << "PARTY IS SEATED." << endl;
    }

    // Function to view the parties in the waitlist
    void View_Waitlist()
    {
        if (currsize == 0) {
            cout << "WAITLIST IS EMPTY" << endl;
            return;
        }

        Party* temp = front;
        cout << "DISPLAYING WHOLE WAITLIST:" << endl;
        while (temp != nullptr) {
            temp->display();
            temp = temp->next; 
        }
    }
};


int main()
{
    Party_Queue q;
    int choice;

    do {
        cout << "---------------------------------------------" << endl;
        cout << "\nMENU:\n1. ADD PARTY TO WAITLIST\n2. SEAT PARRTY\n3. VIEW CUSTOMERS\n4. EXIT\n\n";
        cout << "ENTER YOUR CHOICE: ";
        cin >> choice;
        cout << "---------------------------------------------" << endl;

        switch (choice) {
            case 1:
                q.ADD_PARTY_TO_WAITLIST();
                break;
            case 2:
                q.Seat_Party();
                break;
            case 3:
                q.View_Waitlist();
                break;
            case 4:
                exit(0);
                cout << "EXITING..." << endl;
                break;
            
            default:
                cout << "INVALID CHOICE .....PLEASE TRY AGAIN!!!" << endl;
        }
    } while (true);

    return 0;
}