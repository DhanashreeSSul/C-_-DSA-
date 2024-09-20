/*Name: Dhanashree Sikandar Sul
PRN No:123B1B273  Div:D3
Assignment No. 1C(Radix sort) */

#include <iostream>
using namespace std;
 class Student {
     public:
     char name[20];
     float cgpa;
     int rno;
     
     void read()
     {
         cout<<"ENTER THE NAME OF STUDENT:";
         cin>>name;
         cout<<"ENTER THE ROLL NO:";
         cin>>rno;
         cout<<"ENTER THE C.G.P.A:";
         cin>>cgpa;
     }
     void display()
     {
        cout<<"NAME OF STUDENT:"<<name;
        cout<<endl;
        cout<<"ROLL NO:"<<rno;cout<<endl;
        cout<<"C.G.P.A.:"<<cgpa;cout<<endl;

     }
     friend void countSort(int n, Student s[], int exp);
     friend void radixsort(int n, Student s[]);
     friend int getMax(int n, Student s[]);
     
 };
 
 
 
 void countSort(Student s[], int n, int exp)
 {
    Student output[n];
    int i, count[10]={0};
    for (i=0;i<n;i++)
    {
        int digit = (s[i].rno/exp)%10;
        count[digit]++;
    }
    
    for(i=1;i<10;i++)
    {
        count[i] += count[i-1];
    }
    
    for (i=n-1;i>=0;i--)
    {
        int digit = (s[i].rno/exp)%10;
        count[digit]--;
        output[count[digit]]=s[i];
    }
    
    for(i=0;i<n;i++)
    {
        s[i] = output[i];
    }
 }


int getMax(Student s[], int n)
{
    int max;
    max = s[0].rno;
    for(int i=1;i<n;++i)
    {
        if(max<s[i].rno)
        {
            max = s[i].rno;
           
        }
    }
    
    return max;
}


void radixsort(Student s[], int n)
{
    int max = getMax(s, n);
    int exp;
    for(int exp=1;exp<max;exp*=10)
    {
        countSort(s, n, exp);
    }
}


 int main()
 {
    Student s[10];
    int n;
    cout<<"ENTER THE NUMBER OF ARRAYS:";
    cin>>n;
    cout<<"INPUT INFORMATION:"<<endl;
    for(int i = 0; i<n; i++)
    {
        s[i].read();
    }
    radixsort(s, n);
    cout<<"OUTPUT INFORMATION:"<<endl;
   for(int i = 0; i<n; i++)
   {
    s[i].display();
   }
   
   
    return 0;
 }
