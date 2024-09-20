/*Name: Dhanashree Sikandar Sul
PRN No:123B1B273  Div:D3
Assignment No. 2B(Merge Sorting By The Name of Employee) */

#include <iostream>
#include <cstring>
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
    
    friend void merge_sort(Employee a[], int low, int high);
    friend void merge(Employee a[], int low, int mid, int high);
};

void merge_sort(Employee a[], int low, int high)
{
    if(low>=high){
    return ;}
    
    int mid =(low+high)/2;
    merge_sort(a, low, mid);
    merge_sort(a, mid+1, high);
    
    merge(a, low, mid, high);
    
}

void merge(Employee a[], int low, int mid, int high)
{
    Employee temp[10];
    int left = low;
    int right = mid+1;
    int i=0;
    while(left<=mid && right<=high)
    {
        if(strcmp(a[left].name, a[right].name)<=0)
        {
            temp[i]=a[left];
            left++;
            i++;
        }
        else
        {
            temp[i]=a[right];
            right++;
            i++;
        }
    }
    
    while(left<=mid)
    {
        temp[i]=a[left];
        left++;
        i++;
    }
    
    while(right<=high)
    {
        temp[i]=a[right];
        right++;
        i++;
    }
    
    for(int i=low;i<=high;i++)
    {
        a[i]=temp[i-low];
    }
}
int main()
{
   Employee a[100];
   int n;
   //int low=0, high=n;
   cout<<"ENTER THE NUMBER OF EMPLOYEE'S:";
   cin>>n;
   cout<<endl;
   cout<<"TAKE DATA FRPOM USER: "<<endl;
   for(int i=0;i<n;i++)
   {
       a[i].getdata();
   }
   merge_sort(a, 0,n-1);
   cout<<"SHOW SORTED DATA TO USER: "<<endl;
   for(int i=0;i<n;i++)
   {
       a[i].showdata();
   }
    return 0;
}
