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
        cout<<"NAME OF STUDENT:"<<name<<endl;
        cout<<"ROLL NO:"<<rno<<endl;
        cout<<"C.G.P.A.:"<<cgpa<<endl;

     }
     friend void insertionSort(int n, Student s[]);
     
 };
 void insertionSort(int n, Student s[10])
 {
    for(int i=1;i<n;i++)
    {
        Student x =s[i];
        int j=i-1;
        while(s[j].rno>x.rno && j>=0)
        {
            s[j+1] = s[j];
            j--;
        }
        s[j+1]=x;
    }
 }

 int main()
 {
    Student sobj[10];
    int n;
    cout<<"ENTER THE NUMBER OF ARRAYS:";
    cin>>n;
    cout<<"INPUT INFORMATION:"<<endl;
    for(int i = 0; i<n; i++)
    {
        sobj[i].read();
    }
    insertionSort(n, sobj);
    cout<<endl<<endl;
    cout<<"OUTPUT INFORMATION:"<<endl;
   for(int i = 0; i<n; i++)
   {
    sobj[i].display();
   }
    return 0;
 }
