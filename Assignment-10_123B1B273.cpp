/*Name: Dhanashree Sikandar Sul
Roll No: SYCOD273
PRN No:123B1B273  Div:D3
Assignment No. 10
Title:
Implement a job scheduling system for a manufacturing plant using a double-ended queue. 
The system needs to efficiently manage the processing of jobs on various machines throughout the plant. 
Each job has a Job_priority. 
The system should support the following operations: 
a. Add Job 
b. Remove Job 
c. Display Job 
d. Search Job */


#include <iostream>
using namespace std;

class Job {
    int jobid;              
    string jobpriority;     
    string name;            
public:
    // Function to add job details (ID, name, and priority)
    void addJobDetails() {
        cout << "Enter Job id: ";
        cin >> jobid;
        cout << "Enter Job name: ";
        cin.ignore();       
        getline(cin, name);   
        cout << "Enter Job priority: ";
        cin >> jobpriority;
    }

    // Function to display job details (ID, name, and priority)
    void displayJob() {
        cout << "Job Id: " << jobid << " | Name: " << name << " | Job Priority: " << jobpriority << endl;
    }

    // Getter function to retrieve Job ID
    int getJobId() {
        return jobid;
    }

    friend class JobScheduling;
};

class JobScheduling {
    Job jobQueue[10]; 
    int front, rear;   
public:
    // Constructor initializes front and rear
    JobScheduling() {
        front = rear = -1;
    }

    // Function to check if the queue is empty
    bool isQueueEmpty() {
        return (front == -1);
    }

    // Function to check if the queue is full
    bool isQueueFull() {
        return (front == (rear + 1) % 10);
    }

    // Function to insert a job at the rear end of the queue
    void addJobAtRear() {
        if (isQueueFull()) {
            cout << "No more Job can be added!" << endl;
            return;
        }
        rear = (rear + 1) % 10;
        jobQueue[rear].addJobDetails();
        if (front == -1) {
            front = 0;
        }
    }

    // Function to insert a job at the front end of the queue
    void addJobAtFront() {
        if (isQueueFull()) {
            cout << "No more Job can be added!" << endl;
            return;
        }
        if (front == -1) {
            front = rear = 0;
        } else if (front == 0) {
            front = 9;
        } else {
            front = front - 1;
        }
        jobQueue[front].addJobDetails();
    }

    // Function to remove a job from the rear end of the queue
    void removeJobFromRear() {
        if (isQueueEmpty()) {
            cout << "No Job is present." << endl;
            return;
        }
        jobQueue[rear].displayJob();
        cout << "is Deleted!" << endl;
        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = 9;
        } else {
            rear = rear - 1;
        }
    }

    // Function to remove a job from the front end of the queue
    void removeJobFromFront() {
        if (isQueueEmpty()) {
            cout << "No Job is present." << endl;
            return;
        }
        jobQueue[front].displayJob();
        cout << "is Deleted!" << endl;
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % 10;
        }
    }

    // Function to display all jobs in the queue
    void displayAllJobs() {
        if (isQueueEmpty()) {
            cout << "No jobs to display." << endl;
            return;
        }
        int i = front;
        while (i != rear) {
            jobQueue[i].displayJob();
            i = (i + 1) % 10;
        }
        jobQueue[i].displayJob();
    }

    // Function to search for a job by its ID
    void searchJobById(int jobid) {
        if (isQueueEmpty()) {
            cout << "No Job is present in the queue." << endl;
            return;
        }
        int i = front;
        bool found = false;
        while (i != rear) {
            if (jobQueue[i].getJobId() == jobid) {
                jobQueue[i].displayJob();
                found = true;
                break;
            }
            i = (i + 1) % 10;
        }
        if (jobQueue[i].getJobId() == jobid) {
            jobQueue[i].displayJob();
            found = true;
        }
        if (!found) {
            cout << "Job with id " << jobid << " not found." << endl;
        }
    }
};

int main() {
    JobScheduling jobScheduler;
    int choice;
    
    do {
        cout << "\n--- Job Scheduling System Menu ---\n";
        cout << "1. Add Job at Front\n";
        cout << "2. Add Job at Rear\n";
        cout << "3. Remove Job from Front\n";
        cout << "4. Remove Job from Rear\n";
        cout << "5. Display all Jobs\n";
        cout << "6. Search for a Job by ID\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                jobScheduler.addJobAtFront();
                break;
            case 2:
                jobScheduler.addJobAtRear();
                break;
            case 3:
                jobScheduler.removeJobFromFront();
                break;
            case 4:
                jobScheduler.removeJobFromRear();
                break;
            case 5:
                jobScheduler.displayAllJobs();
                break;
            case 6: {
                int jobid;
                cout << "Enter Job ID to search: ";
                cin >> jobid;
                jobScheduler.searchJobById(jobid);
                break;
            }
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
