/*Name: Dhanashree Sikandar Sul
PRN No:123B1B273  Div:D3
Assignment No. 6
Title:
Consider two polynomial expressions of any degree.
Design solution to perform addition of these two polynomials with suitable data structure and display results. */

#include <iostream>
using namespace std;

class Polynomial;

class Node {
public:
    int coeff;
    int pow;
    Node *next;

    Node() {
        next = NULL;  
    }

    Node(int c, int p) {
        coeff = c;
        pow = p;
        next = NULL;
    }
     // Function to display the term of the polynomial
    void display() {
        cout << coeff << "x^" << pow;
    }

    // Friend function to add two polynomials
    friend Polynomial addPolynomial(Polynomial &p1, Polynomial &p2);
};

class Polynomial {
public:
    Node *head;

    Polynomial() {
        head = NULL;
    }

 // Function to insert a new term (node) into the polynomial
    void insertNode(int coeff, int pow) {
        Node* newNode = new Node(coeff, pow);
        if (!head) {
            head = newNode; 
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next; 
            }
            temp->next = newNode;  
        }
    }

     // Function to display the polynomial
    void displayPolynomial() {
        Node* temp = head;
        while (temp) {
            temp->display();  
            if (temp->next != NULL)
                cout << " + "; 
            temp = temp->next;
        }
        cout << endl;
    }

 // Function to read polynomial terms from user input
    void readPolynomial() {
        int n;
        cout << "ENTER NUMBER OF TERMS IN THE POLYNOMIAL: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            int coeff, pow;
            cout << "TERM " << i + 1 << ": " << endl;
            cout << "ENTER COEFFICIENT: ";
            cin >> coeff;
            cout << "ENTER POWER: ";
            cin >> pow;
            insertNode(coeff, pow); 
        }
    }

    // Friend function to add two polynomials
    friend Polynomial addPolynomial(Polynomial &p1, Polynomial &p2);
};

 // Function to add two polynomials and return the result
Polynomial addPolynomial(Polynomial &p1, Polynomial &p2) {
   
    Polynomial p3;
    Node* cn1 = p1.head;
    Node* cn2 = p2.head;

    while (cn1 && cn2) {
        if (cn1->pow > cn2->pow) {
            p3.insertNode(cn1->coeff, cn1->pow);  
            cn1 = cn1->next;
        } else if (cn1->pow < cn2->pow) {
            p3.insertNode(cn2->coeff, cn2->pow);  
            cn2 = cn2->next;
        } else {
            p3.insertNode(cn1->coeff + cn2->coeff, cn1->pow);  
            cn1 = cn1->next;
            cn2 = cn2->next;
        }
    }

    // Add remaining terms from first polynomial
    while (cn1) {
        p3.insertNode(cn1->coeff, cn1->pow);
        cn1 = cn1->next;
    }

    // Add remaining terms from second polynomial
    while (cn2) {
        p3.insertNode(cn2->coeff, cn2->pow);
        cn2 = cn2->next;
    }

    return p3;
}

int main() {
    Polynomial p1, p2;
    cout << "------------ POLYNOMIAL ADDITION ------------" << endl;
    cout << endl;
    cout << "----- INPUT POLYNOMIALS -----" << endl;
    cout << "POLYNOMIAL-1: " << endl;
    p1.readPolynomial();
    cout << endl;
    cout << "POLYNOMIAL-2: " << endl;
    p2.readPolynomial();
    cout << endl;
    cout << "----- DISPLAYING POLYNOMIALS -----" << endl;
    cout << "POLYNOMIAL-1: " << endl;
    p1.displayPolynomial();
    cout << "POLYNOMIAL-2: " << endl;
    p2.displayPolynomial();
    
    // Adding two polynomials and displaying the result
    Polynomial p3;
    p3 = addPolynomial(p1, p2);
    cout << "POLYNOMIAL-3: " << endl;
    cout << "P3 = P1 + P2" << endl;
    p3.displayPolynomial();
    cout << endl << "---------------------------------------------" << endl;

    return 0;
}
