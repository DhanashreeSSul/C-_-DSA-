/*Name: Dhanashree Sikandar Sul
PRN No:123B1B273  Div:D3
Assignment No. 5(Circular Linked List) */

#include <iostream>
using namespace std;
class Route{
   public:
   string source;
   string destination;
   float distance;
   
   Route *next;
   Route(){
       next =nullptr;}


   void read()
   {
         cout<<"ENTER SOURCE:";
       cin>>source;
       cout<<"ENTER DESTINATION:";
       cin>>destination;
       cout<<"ENTER DISTANCE:";
       cin>>distance;
   }


   void display()
   {
       cout<<"SOURCE: "<<source<<endl<<"Destination "<<destination<<endl<<"Distance "<<distance<<endl;
   }
};


class Route_Navigation
{


   Route* tail;
   public:
       Route_Navigation()
       {
           tail = nullptr;
       }


      void insert_at_end()
       {
           Route *cn = new Route;
           cn->read();
           cn->next = nullptr;
           if(tail==nullptr)
           {
               tail=cn;
               cn->next = cn;
           }
           else{
           cn->next = tail->next;
           tail->next = cn;
           tail=cn;
           }


       }
      void insert_at_head()
       {
           Route *cn = new Route;
           cn->read();
         
           if(tail==nullptr)
           {
               tail=cn;
               cn->next = cn;
           }
           else{
           cn->next = tail->next;
           tail->next = cn;
          
           }

       }
      
      void remove_route(){
       Route *t = tail->next;
       Route *p = tail;
       string destinationtodelete;
       cin>>destinationtodelete;
       do{
           if(t->destination==destinationtodelete)
           {
               if(t!=tail)
               {
                   p->next = t->next;
                   delete t;
                   return;
               }
               else{
                   p->next = t->next;
                   p=tail;
                   delete t;
                   return;
               }
           }
           else{
               p=t;
               t=t->next;
           }
       }while(t!=tail->next);
       if(tail=tail->next)
       {
           tail=NULL;
       }
       }  

      void search_route() {
        if (tail == nullptr) {
            cout << "No routes to search." << endl;
            return;
        }

        string destination_to_search;
        cout << "ENTER THE DESTINATION TO SEARCH: ";
        cin >> destination_to_search;

        Route* t = tail->next;
        do {
            if (t->destination == destination_to_search) {
                cout << "ROUTE FOUND:" << endl;
                t->display();
                return;
            }
            t = t->next;
        } while (t != tail->next);

        cout << "DESTINATION NOT FOUND." << endl;
       }
       
      void print()
       {
           Route *t = tail->next;
           for(t=tail->next;t!=tail;t=t->next)
           {
               t->display();
           }
           t->display();
       }
};


int main()
{
   Route_Navigation R;
    int choice;
    do {
        cout << "---------------------------------------------------------------------------" << endl;
        cout << "CHOOSE WHAT YOU WANT TO DO:" << endl 
             << "1. INSERT AT HEAD." << endl 
             << "2. INSERT AT END." << endl
             << "3. REMOVE ROUTE DESTINATION." << endl 
             << "4. SEARCH ROUTE DESTINATION." << endl 
             << "5. EXIT" << endl;
        cin >> choice;
        cout << "---------------------------------------------------------------------------" << endl;
        switch (choice) {
            case 1:
                cout << "ENTER THE ROUTE NAVIGATION: " << endl;
                R.insert_at_head();
                cout << endl << "AFTER ADDING ROUTE NAVIGATION" << endl;
                R.print();
                break;

            case 2:
                cout << "ENTER THE ROUTE NAVIGATION: " << endl;
                R.insert_at_end();
                cout << endl << "AFTER ADDING ROUTE NAVIGATION" << endl;
                R.print();
                break;

            case 3:
                cout << "ENTER THE DESTINATION YOU HAVE TO DELETE: " << endl;
                R.remove_route();
                cout << endl << "AFTER DELETING ROUTE NAVIGATION" << endl;
                R.print();
                break;

            case 4:
                  cout<<"SEARCHING OF DESTINATION:"<<endl;
                  R.search_route();
                  break;

            case 5:
                cout << endl << "EXITING FROM THE PROGRAM...THANK YOU !" << endl;
                exit(0);

            default:
                cout << "WRONG choice" << endl;
                break;
        }

    } while (true);
    return 0;
}