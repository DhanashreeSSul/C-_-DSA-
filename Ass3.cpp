/*Name: Dhanashree Sikandar Sul
PRN No:123B1B273  Div:D3
Assignment No. 3(Singly Linked List) */

#include <iostream>
using namespace std;
class song
{
    public:
    song (){
        next = NULL;
    }
    song *next;
    char title[100];
    char artist[50];
    float duration;
    
    
    void read()
    {
        cout<<"ENTER THE TITLE OF SONG:";
        cin>>title;
        cout<<"ENTER THE ARTIST NAME:";
        cin>>artist;
        cout<<"DURATION OF THE SONG:";
        cin>>duration;
        cout<<endl;
    }
    
    void display()
    {
        cout<<"TITLE: "<<title<<endl;
        cout<<"ARTIST: "<<artist<<endl;
        cout<<"DURATION: "<<duration<<endl;
        cout<<endl;
    }
   
};

class Playlist
{
    song *head;
    public:
    Playlist(){
        head = NULL;
    }
void addsong()
    {
        song *cn;
        song *nn = new  song;
        
        nn->read();
        if(head==NULL)
        {
            head = nn;
        }
        else
        {
            for(cn=head;cn->next != NULL;cn=cn->next);
            cn->next = nn;
        }
    }
void Search()
    {
        song *cn = head;
        string name;
        cout<<"ENTER NAME TO SEARCH:"<<endl;
        cin>>name;
         cout<<"ENTER NAME TO MODIFY:"<<endl;
        string newname;
        cin>>newname;
        for(cn = head;cn!=NULL;cn = cn->next)
        {
            if(cn->title == name)
            {
               cout<<"song is found!";
               name = newname;
                return;
            }
        }
        cout<<"SONG NOT FOUND!";
    }
void displaysong()
    {
        song *cn;
        for(cn=head;cn!=NULL;cn=cn->next)
        {
            cn->display();
        }
    }
void deletesong()
    {
            song *prev = NULL;
            song *cn=head;
            
            string deltitle;
            cin>>deltitle;
            if(head->title==deltitle)
            {
                head = head->next;
                delete cn;
            }
            else{
            for(cn = head;cn!=NULL;cn = cn->next)
            {
                if(cn->title==deltitle)
                {
                    prev->next=cn->next;
                    delete cn;
                    return;
                }
                else{
                    prev = cn;
                }
            }
            }
    }
void insertatfirst()
    {
        song *nn = new song;
        nn->read();
        nn->next = head;
        head = nn;
    }
void insertatend()
    {
        song *cn;
        song *nn=new song;
        nn->read();
        if(head == NULL)
        {
            head = nn;
        }
        else{
        for(cn=head;cn->next!=NULL;cn=cn->next);
        cn->next=nn;
        }
    }
void insertbet()
    {
        song *cn = head;
        song *nn=new song;
        nn->read();
       
        for(cn = head;cn!=NULL;cn = cn->next)
        {
            if(cn->next == nn)
            {
                nn->next = cn->next;
                cn->next=nn;
            }
        }
    }
};
int main() {
    Playlist playlist;
    int choice;
  while(1){
        cout<<endl<<"--- OPERATIONS TO PERFORM ON THE PLAYLIST ---"<<endl;
        cout<<"1.ADD SONG AT THE END"<<endl;
        cout<<"2.ADD SONG AT THE BEGINNING"<<endl;
        cout<<"3.ADD SONG AT POSITION"<<endl;
        cout<<"4.DELETE SONGS"<<endl;
        cout<<"5.SEARCH SONGS"<<endl;
        cout<<"6.EXIT"<<endl;
        cout<<"CHOOSE YOUR OPTION: ";
        cin>>choice;
        switch(choice){
        case 1:
            cout<<endl<<"----- ADD SONG -----"<<endl;
            playlist.insertatend();
            cout<<endl<<"----- DISPLAYING PLAYLIST -----"<<endl;
            playlist.displaysong();
            break;
        case 2:
            cout<<endl<<"----- ADD SONG -----"<<endl;
            playlist.insertatfirst();
            cout<<endl<<"----- DISPLAYING PLAYLIST -----"<<endl;
             playlist.displaysong();
            break;
        case 3:
            cout<<endl<<"----- ADD SONG -----"<<endl;
            playlist.insertbet();
            cout<<endl<<"----- DISPLAYING PLAYLIST -----"<<endl;
              playlist.displaysong();
            break;
        case 4: 
            cout<<endl<<"----- DELETE SONG -----"<<endl;
            playlist.deletesong();
            cout<<endl<<"----- DISPLAYING PLAYLIST -----"<<endl;
            playlist.displaysong();
            break;
        case 5:
            cout<<endl<<"----- SEARCH SONG -----"<<endl;
            playlist.Search();
            cout<<"AFTER SEARCHING AND MODIFYING:"<<endl;
            playlist.displaysong();
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

