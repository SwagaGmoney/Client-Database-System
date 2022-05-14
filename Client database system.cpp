#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <vector> 
#include "string"
#include <cstdlib>
using namespace std;

class Client {
private:
    char name1[20], address[20];
    int choice, t;
    string word;
    string date, find, name, i;
    int output, boo, report1;
    vector<string>storeClientInfo;
    vector<string>storeSalesRep;
    vector<string>monthlySalesRep;
    vector<string>servicesSalesProd;
    vector<string>storeMonthlySales;
    vector<string>storeSales;

public:
    void update_client();

    void menu();
    void read_client();
    void product_rep();
    void monthly_bonus();
    void monthly_sales();
    void services_prod();
    void sales();


};

//case 1 clients info 
void Client::read_client() {
    int modify = 1, i;
    system("clear");
    cout << "Texas Cliental LLC.\t Client's Information\n\n" << endl;
    ifstream file; //read from the file
    file.open("ClientInfo.txt", ios::app | ios::in);
    string input;
    while (getline(file, input)) {
        storeClientInfo.push_back(input);

    }
    for (i = 0; i < storeClientInfo.size(); i++) {
        cout << i + 1 << " - " << storeClientInfo.at(i) << endl;
    }
    file.close();


    //// write in file 

    ofstream dot; // write 
    cout << "\nPress -1 to Add Client.\nPress -2 to Update Client.\n" << endl;
    cin >> output;
    if (output == -1) {
        cout << "enter name" << endl;
        cin >> name1;
        cout << "enter address" << endl;
        cin.ignore();
        cin.getline(address, 20);
        cout << "enter date(00/00/00)" << endl;
        cin >> date;
        //write in file 
        dot.open("ClientInfo.txt", ios::app);
        dot << name1 << "," << address << ", " << date << "." << endl;
        dot.close();


    }
}

void Client::update_client() {
    if (output == -2) {

        cout << "Enter the Client's Name you want to update" << endl;
        cin >> name1;

    }
}
// end  of case 1 clients info 


// case 2 Sales Rep 
void Client::product_rep() {
    //read from the file 
    int modify = 1, i;
    system("cls");
    cout << "Texas Cliental LLC.\t Sales Representatives \n\n" << endl;
    ifstream file; //read from the file
    file.open("SalesRep.txt");
    string boop;
    while (getline(file, boop)) {
        storeSalesRep.push_back(boop);

    }
    for (i = 0; i < storeSalesRep.size(); i++) {
        cout << i + 1 << " - " << storeSalesRep.at(i) << endl;
    }
    file.close();

    /// write in the file 


    ofstream boo; // write 
    cout << "\nPress -1: To Add Sales Rep.\nPress -2: To Update Sales Rep.\nPress -3: Look/Modify at Monthly Sales Bonus\n" << endl;
    cin >> output;
    if (output == -1) {
        cout << "enter name" << endl;
        cin >> name;
        cout << "enter address" << endl;
        cin.ignore();
        cin.getline(address, 20);
        cout << "enter date(00/00/00)" << endl;
        cin >> date;
        //write in file 
        boo.open("SalesRep.txt", ios::app);
        boo << name << "," << address << ", " << date << "." << endl;
        boo.close();

    }
    else if (output == -2) {
        cout << "hello" << endl;
    }
    else {
        cout << "error" << endl;
    }
}

void Client::monthly_bonus() {
    if (output == -3) {
        int mod, i;
        ifstream file1;
        file1.open("Salebonus.txt");
        string m;
        while (getline(file1, m)) {
            monthlySalesRep.push_back(m);
        }
        for (i = 0; i < monthlySalesRep.size(); i++) {
            cout << i + 1 << " --> " << monthlySalesRep.at(i) << endl;
        }
        file1.close();
        // write in file..
        int bonus, fbonus;
        ofstream rep;
        cout << "Press 1: To change Sales bonus" << endl;
        cin >> bonus;
        if (bonus == 1) {
            cout << "Enter name" << endl;
            cin >> name;
            cout << "Enter Sales month period (jan00 - dec00)" << endl;
            cin.ignore();
            cin.getline(address, 20);
            cout << "Enter Sales Amount" << endl;
            cin >> fbonus;
            rep.open("Salebonus.txt", ios::app);
            rep << name << " - " << address << " - " << "$" << fbonus << endl;
            rep.close();
        }
    }
}


// end of case 2 sales rep

// case 3 product and services
void Client::services_prod() {
    int modify = 1, i;
    system("cls");
    cout << "Texas Cliental LLC.\t Product and Services\n\n" << endl;
    ifstream file2; //read from the file
    file2.open("ServicesProd.txt", ios::app | ios::in);
    string dot;
    while (getline(file2, dot)) {
        servicesSalesProd.push_back(dot);

    }
    for (i = 0; i < servicesSalesProd.size(); i++) {
        cout << i + 1 << " - " << servicesSalesProd.at(i) << endl;
    }
    file2.close();

    ofstream m;
    cout << "\nPress -1: To Add Product/Services.\nPress -2: To Update Product/Services.\nPress -3: Look/Modify the Montly Sales Report\n" << endl;
    cin >> output;

    if (output == -1) {
        double dollar;
        cout << "Enter name of product" << endl;
        cin.ignore();
        cin.getline(address, 20);
        cout << "Enter Amount" << endl;
        cin >> fixed >> setprecision(2) >> dollar;

        // write in the file 3
        ofstream prod;
        prod.open("ServicesProd.txt", ios::app);
        prod << address << " - " << "$" << dollar << "." << endl;
        prod.close();

    }
    else if (output == -2) {
        cout << "hello!!!" << endl;
    }
}

void Client::monthly_sales() {
    if (output == -3) {
        // Read from the file 
        int mod, i;
        ifstream file1;
        file1.open("MontlySales.txt");
        string m;
        while (getline(file1, m)) {
            storeMonthlySales.push_back(m);
        }
        for (i = 0; i < storeMonthlySales.size(); i++) {
            cout << i + 1 << " --> " << storeMonthlySales.at(i) << endl;
        }
        file1.close();

        // write in the file 
        int jaan;
        double dollar;
        ofstream jan;
        cout << "Press 1: To look/Modify the Montly Sales Report" << endl;
        cin >> jaan;
        if (jaan == 1) {
            cout << "Enter the Name of Product" << endl;
            cin.ignore();
            cin.getline(name1, 20);
            cout << "Enter the Amount Sold" << endl;
            cin >> dollar;
            jan.open("MontlySales.txt", ios::app);
            jan << name1 << " - " << dollar << " sold" << "." << endl;
            jan.close();
        }
    }

}

// end of case 3 product and services

// case 4 Sales
void Client::sales() {
    int modify = 1, i;
    system("cls");
    cout << "Texas Cliental LLC.\t Sales Report\n\n" << endl;
    ifstream file; //read from the file
    file.open("MontlySales.txt", ios::app | ios::in);
    string input;
    while (getline(file, input)) {
        storeSales.push_back(input);

    }
    for (i = 0; i < storeSales.size(); i++) {
        cout << i + 1 << " - " << storeSales.at(i) << endl;
    }
    file.close();
    cout << "\nPress -1: To Add Sales.\nPress -2: To Update Sales." << endl;
    cin >> output;
    if (output == -1) {
        double dollar;
        ofstream jan;

        cout << "Enter the Name of Product" << endl;
        cin.ignore();
        cin.getline(name1, 20);
        cout << "Enter the Amount Sold" << endl;
        cin >> dollar;
        jan.open("MontlySales.txt", ios::app);
        jan << name1 << " - " << dollar << " sold" << "." << endl;
        jan.close();
    }
    else if (output == -2) {
        cout << "hello!" << endl;
    }
    else {
        cout << "error!" << endl;
    }

}
// end of case 4 sales


void Client::menu() {

    cout << "\n\n\n----- Welcome------\n\n" << endl;
    cout << "[1] - Client's Information" << endl;
    cout << "[2] - Sales Representatives" << endl;
    cout << "[3] - Product/Services" << endl;
    cout << "[4] - Sales" << endl;
    cout << "\n-------------------\n\n" << endl;
    cout << "Enter your Choice:" << endl;
    cin >> choice;

    switch (choice) {
    case 1: {
        cin.ignore();
        read_client();
        update_client();
        break;
    }
    case 2: {
        cin.ignore();
        product_rep();
        monthly_bonus();

        break;
    }
    case 3: {
        cin.ignore();
        services_prod();
        monthly_sales();
        break;
    }
    case 4: {
        cin.ignore();
        sales();
        break;
    }

    default: {
        break;
    }


    }// end switch
    if (choice != 1 & choice != 2 & choice != 3 & choice != 4) {
        cout << "Input error!! Program Terminated!" << endl;
    }

}





int main() {
    Client project;
    project.menu();
    return 0;
}
