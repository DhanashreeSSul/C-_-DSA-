/*Name: Dhanashree Sikandar Sul
Roll No: SYCOD273
PRN No:123B1B273  Div:D3
Assignment No. 9B

Title:Implement a checkout system for a supermarket to efficiently manage customer queues during peak hours. 
The system should support the following operations using a circular queue data structure: 
a. Customer arrival 
b. Customer checkout 
c. Close Checkout Counter
d. View customer. */

#include <iostream>
using namespace std;
#define size 10
class customer{
    string name;
    long mobile_no;
    public:
    //Taking data from user.
    void read()
    {
        cout<<"ENTER THE NAME OF CUSTOMER: ";
        cin>>name;
        cout<<"ENTER THE MOBILE NUMBER: ";
        cin>>mobile_no;
    }
    //Function to dispaly customer details
    void display()
    {
        cout<<endl<<"NAME: "<<name<<endl;
        cout<<endl<<"MOBILE_NUMBER: "<<mobile_no<<endl;
    }
};

class customer_queue{
    customer q[size];           
    int front, rear, currsize=0;
    public:
    //constructor to initialize front and rear
    customer_queue()
    {
        rear=front = -1;
    }
    //Function to add new arrival customer
    void new_arrival_customer()
    {
        if(currsize==size)
        {
            return;
        }
        if(currsize==0)
        {
            rear=front=0;
        }
        else{
            rear=(rear+1)%size;
        }
        q[rear].read();
        currsize++;
        cout<<"CUSTOMER IS ARRIVAL IN QUEUE"<<endl;
    }
    //function to delete checked out customer
    void checkout_customer()
    {
        if(currsize==0)
        {
            return;
        }
        customer element=q[front];
        if(currsize==1)
        {
            front = rear-1;
        }
        else{
            front = (front+1)%size;
        }
        currsize--;
        cout<<"CUSTOMER IS CHECKED OUT"<<endl;
    }

    //function to closed checkout counter 
    void close_checkout_counter()
    {
        if(currsize==0)
        {
            cout<<"QUEUE IS EMPTY AND CHECKOUT COUNTER IS CLOSED"<<endl;
            return;
        }
        cout << "CLOSING CHECKOUT COUNTER. REAMAINING CUSTOMERS IN QUEUE:" << endl;
        while (currsize > 0) {
            checkout_customer();
        }
        cout << "ALL CUSTOMER ARE CHECKED OUT." << endl;
    }

    //function to view Customer in queue
    void view_customers()
    {
        if(currsize==0)
        {
            cout<<"QUEUE IS EMPTY";
        }
        for(int i=0;i<currsize;i++)
        {
            int index= (front+i)%size;
            q[index].display();
        }
    }
};

int main() {
    customer_queue queue;     //Creating object of queue class
    int choice;

    do {
        cout << endl << "---------------------------------------------" << endl;
        cout << "\nMENU:\n1. NEW ARRIVAL CUSTOMER\n2. CHECKOUT CUSTOMER\n3. VIEW CUSTOMERS\n4. CLOSE CHECKOUT COUNTER\n5. EXIT\n";
        cout << endl << "---------------------------------------------" << endl;
        cout << "ENTER YOUR CHOICE: ";
        cin >> choice;

        switch (choice) {
            case 1:
                queue.new_arrival_customer();
                break;
            case 2:
                queue.checkout_customer();
                break;
            case 3:
                queue.view_customers();
                break;
            case 4:
                queue.close_checkout_counter();
                break;
            case 5:
                cout << "EXITING..." << endl;
                break;
            default:
                cout << "INVALID CHOICE .....PLEASE TRY AGAIN!!!" << endl;
        }
    } while (choice != 5);

    return 0;
}
