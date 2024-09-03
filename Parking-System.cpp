#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;

void vehicle_entry();
void vehicle_exit();
void parking_fee();
void parking_statistics();

time_t s, e;
int price;
int sum = 0;

struct node {
    long long int reg_num;
    char driver_name[20];
    char model[10];
    char make[20];
    char colour[20];
    node* nptr;
};

node* fptr = NULL;

int main() {
    int x;
    for (;;) {
        cout << "*****************MAIN MENU**********************\n";
        cout << "PRESS 1 FOR VEHICLE ENTRY\nPRESS 2 FOR VEHICLE EXIT\nPRESS 3 TO CHECK PARKING FEE COLLECTED\nPRESS 4 TO CHECK PARKING STATISTICS\nPRESS 5 TO EXIT\n";
        cout << "PLEASE ENTER ONE OF THE OPTIONS: ";
        cin >> x;

        if (x == 1)
            vehicle_entry();
        else if (x == 2)
            vehicle_exit();
        else if (x == 3)
            parking_fee();
        else if (x == 4)
            parking_statistics();
        else
            exit(0);
    }
}

void vehicle_entry() {
    fstream file;
    file.open("parking_data.txt", ios::app);  

    if (!file) {
        cout << "File not created!";
    } else {
        node* ptr = new node;
        cout << "VEHICLE REGISTRATION NUMBER: ";
        cin >> ptr->reg_num;
        cout << "DRIVER NAME: ";
        cin >> ptr->driver_name;
        cout << "VEHICLE MODEL: ";
        cin >> ptr->model;
        cout << "VEHICLE MAKE: ";
        cin >> ptr->make;
        cout << "VEHICLE COLOUR: ";
        cin >> ptr->colour;
        cout << endl;

        time(&s);
        ptr->nptr = NULL;

        if (fptr == NULL) {
            fptr = ptr;
        } else {
            node* currentptr = fptr;
            while (currentptr->nptr != NULL) {
                currentptr = currentptr->nptr;
            }
            currentptr->nptr = ptr;
        }

        file << "Registration number: " << ptr->reg_num << "\nDriver name: " << ptr->driver_name << "\nVehicle model: " << ptr->model
             << "\nVehicle make: " << ptr->make << "\nVehicle colour: " << ptr->colour << "\n\n";
        file.close();

        cout << "Vehicle Entry Successful!\n\n";
    }
}

void parking_statistics() {
    if (fptr == NULL) {
        cout << "\nNo vehicles are currently parked.\n";
    } else {
        node* currentptr = fptr;
        cout << "\nTHE CARS PRESENT IN THE PARKING LOT ARE:\n";
        while (currentptr != NULL) {
            cout << "VEHICLE REGISTRATION NUMBER: " << currentptr->reg_num << "\n\n";
            currentptr = currentptr->nptr;
        }
    }
}

void vehicle_exit() {
    long long int y;
    int flag = 0;

    cout << "PLEASE ENTER THE REGISTRATION NUMBER OF THE CAR THAT HAS LEFT THE PARKING LOT: ";
    cin >> y;

    node* currentptr = fptr;
    node* previous = NULL;

    while (currentptr != NULL) {
        if (currentptr->reg_num == y) {
            flag = 1;
            break;
        }
        previous = currentptr;
        currentptr = currentptr->nptr;
    }

    if (flag == 1) {
        time(&e);
        int d = difftime(e, s);
        price = (d < 60) ? 50 : 70;
        sum += price;

        cout << "THE CAR WITH REGISTRATION NUMBER: " << currentptr->reg_num << " HAS JUST LEFT THE PARKING LOT.\n";
        cout << "Collect " << price << " Rupees.\n";

        if (previous == NULL) {
            fptr = currentptr->nptr;
        } else {
            previous->nptr = currentptr->nptr;
        }

        delete currentptr;
    } else {
        cout << "THIS CAR IS NOT PRESENT IN THE PARKING LOT.\n";
    }
}

void parking_fee() {
    cout << "TOTAL PARKING FEE COLLECTED IS: " << sum << " Rupees\n";
}

