/*Name: Dhanashree Sikandar Sul
PRN No:123B1B273  Div:D3
Assignment No. 1B(Shell sort) */

#include <iostream>
#include <cstring>
using namespace std;
class student
{
    public:
    char name[50];
    int rno;
    int sgpa;
    void getdata()
    {
        cout<<"ENTER NAME OF STUDENT:";
        cin>>name;
        cout<<"ENTER ROLL NO. OF STUDENT:";
        cin>>no;
        cout<<"ENTER GPA OF STUDENT:";
        cin>>sgpa;
    }
    void display()
    {
        cout<<"NAME OF STUDENT:"<<name<<endl;
        cout<<"ROLL NO. OF STUDENT:"<<rno<<endl;
        cout<<"SGPA OF STUDENT:"<<sgpa<<endl;        
    }
friend void shellsort(student a[], int n);
};
void shellsort(student a[20], int n)
{
    int interval = n/2;
    while(interval>=1)
    {
        for(int i = interval;i<n; i++)
        {
            student temp=a[i];
            int j;
            for(j=i - interval; j>=0;j=j-interval)
            {
               if (strcmp(a[j].name, temp.name) > 0) 
                {
                    a[j+interval] = a[j];
                }
                else
                {   break; }  
            }
            a[j+interval]=temp;
        }
         interval/=2;
    }
}
int main()
{
    student aobj[10];
    int n;
    cout<<"Enter Array Size";
    cin>>n;
    cout<<"ENTER INPUT DETAILS:"<<endl;
    for(int i=0;i<n;i++)
    {
        aobj[i].getdata();
    }
    shellsort(aobj, n);
     cout<<endl<<"OUTPUT DETAILS:"<<"\n";
    for(int i=0;i<n;i++)
    { aobj[i].display();
        cout<<" ";
    }
    return 0;
}

