/*Name: Dhanashree Sikandar Sul
PRN No:123B1B273  Div:D3
Assignment No. 3
Title:
Consider the playlist in a music player. 
Implement a playlist feature in music player application using singly linked list.
Each song in the playlist is represented as a node in the linked list. 
Each node contains information about the song (such as title or artist or duration, etc.). 
The playlist should allow users to:
a. Add songs b. Remove songs
c. Display the entire playlist
d. Play specific songs. */

#include <iostream>
#include <cstring>
using namespace std;

class song {
public:
    song() {
        next = NULL;
    }
    song *next;
    char title[100];
    char artist[50];
    float duration;

    void read() {
        cout << "ENTER THE TITLE OF SONG: ";
        cin.ignore();
        cin.getline(title, 100);
        cout << "ENTER THE ARTIST NAME: ";
        cin.getline(artist, 50);
        cout << "DURATION OF THE SONG: ";
        cin >> duration;
        cout << endl;
    }

    void display() {
        cout << "TITLE: " << title << endl;
        cout << "ARTIST: " << artist << endl;
        cout << "DURATION: " << duration << endl;
        cout << endl;
    }
};

class Playlist {
    song *head;
public:
    Playlist() {
        head = NULL;
    }

    void insertatend() {
        song *cn;
        song *nn = new song;
        nn->read();
        if (head == NULL) {
            head = nn;
        } else {
            for (cn = head; cn->next != NULL; cn = cn->next);
            cn->next = nn;
        }
    }

    void insertatfirst() {
        song *nn = new song;
        nn->read();
        nn->next = head;
        head = nn;
    }

    void insertbet() {
        int pos;
        cout << "ENTER POSITION TO INSERT SONG: ";
        cin >> pos;
        if (pos <= 1) {
            insertatfirst();
        } else {
            song *cn = head;
            song *nn = new song;
            nn->read();
            for (int i = 1; i < pos - 1 && cn != NULL; i++) {
                cn = cn->next;
            }
            if (cn != NULL) {
                nn->next = cn->next;
                cn->next = nn;
            } else {
                cout << "Invalid position!" << endl;
            }
        }
    }

    void deletesong() {
        if (head == NULL) {
            cout << "PLAYLIST IS EMPTY!" << endl;
            return;
        }
        string deltitle;
        cout << "ENTER THE TITLE OF THE SONG TO DELETE: ";
        cin.ignore();
        getline(cin, deltitle);

        song *prev = NULL;
        song *cn = head;

        if (strcmp(head->title, deltitle.c_str()) == 0) {
            head = head->next;
            delete cn;
            return;
        }

        while (cn != NULL && strcmp(cn->title, deltitle.c_str()) != 0) {
            prev = cn;
            cn = cn->next;
        }

        if (cn == NULL) {
            cout << "SONG NOT FOUND!" << endl;
        } else {
            prev->next = cn->next;
            delete cn;
        }
    }

    void Search() {
        string searchTitle;
        cout << "ENTER THE TITLE OF THE SONG TO SEARCH: ";
        cin.ignore();
        getline(cin, searchTitle);

        song *cn = head;
        while (cn != NULL) {
            if (strcmp(cn->title, searchTitle.c_str()) == 0) {
                cout << "SONG FOUND!" << endl;
                cn->display();
                return;
            }
            cn = cn->next;
        }
        cout << "SONG NOT FOUND!" << endl;
    }

    void displaysong() {
        if (head == NULL) {
            cout << "PLAYLIST IS EMPTY!" << endl;
            return;
        }
        song *cn;
        for (cn = head; cn != NULL; cn = cn->next) {
            cn->display();
        }
    }
};

int main() {
    Playlist playlist;
    int choice;
    while (1) {
        cout << endl << "--- OPERATIONS TO PERFORM ON THE PLAYLIST ---" << endl;
        cout << "1. ADD SONG AT THE END" << endl;
        cout << "2. ADD SONG AT THE BEGINNING" << endl;
        cout << "3. ADD SONG AT POSITION" << endl;
        cout << "4. DELETE SONG" << endl;
        cout << "5. SEARCH SONG" << endl;
        cout << "6. DISPLAY PLAYLIST" << endl;
        cout << "7. EXIT" << endl;
        cout << "CHOOSE YOUR OPTION: ";
        cin >> choice;

        switch (choice) {
        case 1:
            playlist.insertatend();
            break;
        case 2:
            playlist.insertatfirst();
            break;
        case 3:
            playlist.insertbet();
            break;
        case 4:
            playlist.deletesong();
            break;
        case 5:
            playlist.Search();
            break;
        case 6:
            playlist.displaysong();
            break;
        case 7:
            cout << "EXITING PROGRAM... THANK YOU!" << endl;
            exit(0);
        default:
            cout << "INVALID OPTION! TRY AGAIN!" << endl;
            break;
        }
    }
    return 0;
}
