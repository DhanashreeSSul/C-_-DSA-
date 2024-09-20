#include <iostream>
using namespace std;


class Statement {
public:
   string text;
   Statement *next;
   Statement *prev;


   Statement() : next(nullptr), prev(nullptr) {}


   void read_text() {
       cout << "ENTER THE TEXT THAT YOU WANT TO ADD:" << endl;
       cin>>text;
   }


   void display_text() {
       cout << "YOUR TEXT IS: " << text << endl;
   }
};


class Word_Processor {
public:
   Statement *head, *tail;


   Word_Processor() : head(nullptr), tail(nullptr) {}


   void Add_new_Statement() {
       Statement *nn = new Statement();
       nn->read_text();


       if (head == nullptr) {
           head = tail = nn;
       } else {
           tail->next = nn;
           nn->prev = tail;
           tail = nn;
       }
   }


   void Display_text_editor() {
       Statement *cn = head;
       while (cn) {
           cn->display_text();
           cn = cn->next;
       }
   }


   void Insert_at_beginning() {
       Statement *nn = new Statement();
       nn->read_text();


       if (head == nullptr) {
           head = tail = nn;
       } else {
           nn->next = head;
           head->prev = nn;
           head = nn;
       }
   }


   void Insert_at_specific_Position(int position) {
       if (position < 0) return;


       Statement *nn = new Statement();
       nn->read_text();


       if (position == 0) {
           Insert_at_beginning();
           return;
       }


       Statement *cn = head;
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


   void Delete_Statement() {
       string text_to_delete;
       cout << "ENTER TEXT TO DELETE:" << endl;
       cin>>text_to_delete;


       Statement *cn = head;
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
               Statement *temp = cn;
               cn = cn->next;
               delete temp;
               return;
           }
           cn = cn->next;
       }
       cout << "Text not found!" << endl;
   }


   void Display_text_Editor_reverse()
   {
       if(head==nullptr)
       {
           cout<<"LIST IS EMPTY";
           return;
       }
       else{
           Statement *cn;
           for(cn=tail;cn!=nullptr;cn = cn->prev)
           {
               cout<<"\n";
               cn->display_text();
           }
       }
   }
};


int main() {
   Word_Processor W;
 int choice;
  while(1){
        cout<<endl<<"--- OPERATIONS TO PERFORM ON THE TEXT EDITOR ---"<<endl;
        cout<<"1.ADD STATEMENT AT THE END"<<endl;
        cout<<"2.ADD STATEMENT AT THE BEGINNING"<<endl;
        cout<<"3.ADD STATEMENT AT POSITION"<<endl;
        cout<<"4.DELETE STATEMENT"<<endl;
        cout<<"5.DISPLAY IN REVERSE STATEMENT"<<endl;
        cout<<"6.EXIT"<<endl;
        cout<<"CHOOSE YOUR OPTION: ";
        cin>>choice;
        switch(choice){
        case 1:
            cout<<endl<<"----- ADD ELEMENT -----"<<endl;
            W.Add_new_Statement();
            cout<<endl<<"----- DISPLAYING TEXT EDITOR -----"<<endl;
            W.Display_text_editor();
            break;
        case 2:
            cout<<endl<<"-----INSERT AT BEGINNING: -----"<<endl;
            W.Insert_at_beginning();
            cout<<endl<<"----- DISPLAYING TEXT EDITOR -----"<<endl;
            W.Display_text_editor();
            break;
        case 3:
            cout << "-----INSERT AT SPECIFIC POSITION:------" << endl;
            int pos;
            cout << "Enter position: ";
            cin >> pos;
            cin.ignore();
            W.Insert_at_specific_Position(pos);
            cout<<endl<<"----- DISPLAYING TEXT EDITOR -----"<<endl;
            W.Display_text_editor();
            break;
        case 4: 
            cout<<endl<<"----- DELETE STATEMENT -----"<<endl;
            W.Delete_Statement();
            cout<<endl<<"----- DISPLAYING TEXT EDITOR -----"<<endl;
            W.Display_text_editor();
            break;
        case 5:
            cout<<endl<<"----- DISPLAY TEXT EDITOR IN REVERSE -----"<<endl;
            W.Display_text_Editor_reverse();
            break;
        case 6:
            cout<<endl<<"EXITING FROM THE PROGRAM...THANK YOU !"<<endl;
            exit(0);
        default:
            cout<<endl<<"WRONG OPTION ENTERED!";
            break;
        }
    }


   return 0;
}
