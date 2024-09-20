/*Name: Dhanashree Sikandar Sul
PRN No:123B1B273  Div:D3
Assignment No. 2A(Quick Sort for arranging Employee ID in Ascending order) */

#include <iostream>
using namespace std;
class Employee
{
    public:
    char name[50];
    int id;
    int salary;
    void getdata()
    {
        cout<<"ENTER THE NAME OF EMPLOYEE:";
        cin>>name;
        cout<<"ENTER THE EMPLOYEE ID:";
        cin>>id;
        cout<<"ENTER THE EMPLOYEE SALARY:";
        cin>>salary;
        cout<<endl<<endl;
    }
    
    void showdata()
    {
        cout<<"THE NAME OF EMPLOYEE:"<<name<<endl;
        cout<<"ID OF THE EMPLOYEE:"<<id<<endl;
        cout<<"SALARY OF THE EMPLOYEE:"<<salary<<endl;
        cout<<endl<<endl;
    }
    
    friend void Quick_sort(Employee a[], int i, int j);
    friend int partition(Employee a[], int i, int j);
};

void Quick_sort(Employee a[], int i, int j)
{
    if(i<j){
    int pos_pivot = partition(a, i, j);
    
    Quick_sort(a, i, pos_pivot-1);
    Quick_sort(a, pos_pivot+1, j);
    }
}

 int partition(Employee a[], int i, int j)
 {
     int left = i, right = j;
     int pivot = a[i].id;
     
     while(left<right)
     {
         while(a[left].id<= pivot)
         {
             left++;
         }
         while(a[right].id> pivot)
         {
             right--;
         }
         if(left<right)
         {
             int temp = a[left].id;
             a[left].id = a[right].id;
             a[right].id = temp;
         }
     }
     int temp = a[i].id;
     a[i].id = a[right].id;
     a[right].id = temp;
     
     return j;
 }
 
 
int main()
{
   Employee a[100];
   int n;
   
   cout<<"ENTER THE NUMBER OF EMPLOYEE'S:";
   cin>>n;
   cout<<endl;
   cout<<"TAKE DATA FRPOM USER: "<<endl;
   for(int i=0;i<n;i++)
   {
       a[i].getdata();
   }
   Quick_sort(a, 0,n-1);
   cout<<"SHOW SORTED DATA TO USER: "<<endl;
   for(int i=0;i<n;i++)
   {
       a[i].showdata();
   }
    return 0;
}

