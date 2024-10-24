/*Name: Dhanashree Sikandar Sul
PRN No:123B1B273  Div:D3
Assignment No. 11
Title:
Consider an employee database of N employees. 
Make use of a hash table implementation to quickly look up the employer's id number.
*/

#include <iostream>
#include <cstring>
using namespace std;

class Employee
{
    int emp_id;
    string name;
    long long mob_num;

public:
    void read()
    {
        cout << "ENTER EMPLOYEE NAME: ";
        cin >> name;
        cout << "ENTER EMPLOYEE ID: ";
        cin >> emp_id;
        cout << "ENTER THE MOBILE NUMBER: ";
        cin >> mob_num;
    }

    void display()
    {
        cout << "NAME: " << name << endl;
        cout << "EMPLOYEE ID: " << emp_id << endl;
        cout << "MOBILE NUMBER: " << mob_num << endl;
    }

    int getEMPid()
    {
        return emp_id;
    }
};

#define size 10

class HashTable
{
    Employee HT[size];
    int flag[size];

public:
    HashTable()
    {
        for (int i = 0; i < size; i++)
        {
            flag[i] = 0;
        }
    }

    void insert()
    {
        Employee newR;
        newR.read();
        int ID = newR.getEMPid();
        int hashV = ID % size;

        if (flag[hashV] == 0)
        {
            HT[hashV] = newR;
            flag[hashV] = 1;
            cout << "EMPLOYEE DETAILS ADDED TO HASHTABLE." << endl;
        }
        else
        {
            for (int i = 1; i < size; i++)
            {
                int p = (hashV + i) % size;
                if (flag[p] == 0)
                {
                    HT[p] = newR;
                    flag[p] = 1;
                    cout << "EMPLOYEE DETAILS ADDED TO HASHTABLE." << endl;
                    break;
                }
            }
        }
    }

    void search()
    {
        int searchID;
        cout << "ENTER EMPLOYEE ID YOU WANT TO SEARCH: ";
        cin >> searchID;

        int hashV = searchID % size;

        if (flag[hashV] == 1 && HT[hashV].getEMPid() == searchID)
        {
            cout << "EMPLOYEE FOUND AT POSITION " << hashV << " IN HASHTABLE" << endl;
            HT[hashV].display();
        }
        else
        {
            for (int i = 1; i < size; i++)
            {
                int p = (hashV + i) % size;
                if (flag[p] == 1 && HT[p].getEMPid() == searchID)
                {
                    cout << "EMPLOYEE FOUND AT POSITION " << p << " IN HASHTABLE" << endl;
                    HT[p].display();
                    return;
                }
            }
            cout << "EMPLOYEE NOT FOUND." << endl;
        }
    }

    void displayHT()
    {
        for (int i = 0; i < size; i++)
        {
            if (flag[i] == 1)
            {
                cout << "POSITION " << i << ": ";
                HT[i].display();
            }
        }
    }
};

int main()
{
  HashTable H;
  
    int choice;
    do{
        cout<<"---------------------------------------------------------------------------"<<endl;
        cout<<"CHOOSE WHAT YOU WANT TO DO:"<<endl<<"1. INSERT EMPLOYEE DETAILS."<<endl
        <<"2. DISPLAY EMPLOYEE DETAILS."<<endl<<"3. SEARCH EMPLOYEE BY ID."<<endl<<"4. EXIT."<<endl;
        cin>>choice;
        cout<<"---------------------------------------------------------------------------"<<endl;
        switch(choice){
            case 1:
            cout<<" "<<endl;
             H.insert();
             break;

            case 2:
            H.displayHT();
            break;

            case 3:
            H.search();
            break;

            case 4:
            exit(0);
            cout<<"THANK YOU .......EXITING THE PROGRAMM"<<endl;
            break;

            default:
              cout<<"WRONG choice"<<endl;
              break;
        }
   
    }while(true);
    return 0;
}
