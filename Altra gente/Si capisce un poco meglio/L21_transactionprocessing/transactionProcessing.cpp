//transactionProcessing.cpp
//This program reads a random-access file sequentially, updates data previously
//written to the file, creates data to be placed in the file and deletes data 
//previously stored in the file
#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdlib>
#include"ClientData.h"
using namespace std;

enum class Choice{PRINT=1, UPDATE, NEW, DELETE, END}; //mettendo il primo ad 1 gli altri elementi vengono inizializzati in maniera sequenziale
Choice enterChoice();
void createTextFile(fstream&);
void updateRecord(fstream&);
void newRecord(fstream&);
void deleteRecord(fstream&);
void outputLine(ostream&, const ClientData&);
int getAccount(const char* const);


int main() {
    //open file for reading and writing
    fstream InOutCredit{"credit.dat", ios::in | ios::out | ios::binary};
    if(!InOutCredit){
        cerr<<"File could not be opened";
        exit(EXIT_FAILURE);
    }

    Choice choice; //store user choice

    //enable user to specify action
    while((choice=enterChoice())!=Choice::END) {
        switch (choice) {
            case Choice::PRINT :
                createTextFile(InOutCredit);
                break;
            case Choice::UPDATE:
                updateRecord(InOutCredit);
                break;
            case Choice::NEW:
                newRecord(InOutCredit);
                break;
            case Choice::DELETE:
                deleteRecord(InOutCredit);
                break;
            default:
                cerr<<"Incorrect choice"<<endl;
                break;
        }
        InOutCredit.clear(); //reset EoF indicator
    }

}

Choice enterChoice(){
    //display available options
    cout<<"\nEnter your choice\n"
        <<"1 - store a formatted text file of accounts\n"
        <<"    called \"print.txt\" for printing\n"
        <<"2 - update an account\n"
        <<"3 - add a new account\n"
        <<"4 - delete an account\n"
        <<"5 - end program\n?";
    int menuChoice; //input menu selection from user
    cin>>menuChoice;
    return static_cast<Choice>(menuChoice);
}

void createTextFile(fstream& readFromFile){
    ofstream outPrintFile("print.txt", ios::out); //create text file
    
    //exit program if ofstream cannot create the file
    if(!outPrintFile){
        cerr<<"File could not be opened."<<endl;
        exit(EXIT_FAILURE);
    }

    //output column heads
    outPrintFile<<left<<setw(10)<<"Account"<<setw(16)
        <<"Last Name"<<setw(11)<<"First Name"<<right
        <<setw(10)<<fixed<<showpoint<<"Balance"<<endl;
    
    //set file-position pointer to beginning of readFromFile
    readFromFile.seekg(0);
    
    //read first record from record file
    ClientData client;
    readFromFile.read(reinterpret_cast<char*> (&client), sizeof(ClientData));

    //copy all records from record file into text file
    while(!readFromFile.eof()){
        //write single record to text file
        if (client.getAccountNumber() != 0){
            outputLine(outPrintFile, client);
        }

        //read next record from file
        readFromFile.read(reinterpret_cast<char*>(&client),sizeof(ClientData));
    }
}

void updateRecord(fstream& updateFile) {
    //obtain number of accounts to update
    int accountNumber{getAccount("Enter account to update")};
    //move file-position pointer to the correct record in file
    updateFile.seekg((accountNumber-1)*sizeof(ClientData));

    //create record object and read first record from file
    ClientData client;
    updateFile.read(reinterpret_cast<char*>(&client), sizeof(ClientData));

    //update record
    if (client.getAccountNumber()!=0){
        outputLine(cout, client); //display the record
        
        //request user to specify transaction
        cout<<"\nEnter charge (+) or payment (-): ";
        double transaction;
        cin>>transaction;

        //update record balance
        double oldBalance=client.getBalance();
        client.setBalance(oldBalance+transaction);
        outputLine(cout, client); //display the record

        //move file-position pointer to correct record in file
        updateFile.seekp((accountNumber-1)*sizeof(ClientData));

        //move updated record over old record in file
        updateFile.write(reinterpret_cast<const char*>(&client), sizeof(ClientData));
    }
    else { //display error if account doesn't exist
        cerr<<"Account #"<<accountNumber<<"has no information"<<endl;
    }
}

void newRecord(fstream& insertInFile){
    //obtain number of account to create
    int accountNumber{getAccount("Enter new account number")};

    //move file position pointer to correct position in file
    insertInFile.seekg((accountNumber-1)*sizeof(ClientData));

    //read record from file
    ClientData client;
    insertInFile.read(reinterpret_cast<char*>(&client), sizeof(ClientData));

    //create record, if record does not exist previously
    if (client.getAccountNumber()==0){
        string lastName;
        string firstName;
        double balance;
    

        //user enters last name, first name and balance
        cout<<"Enter last name, first name and balance\n?";
        cin>>setw(15)>>lastName;
        cin>>setw(10)>>firstName;
        cin>>balance;

        //use values to populate account values
        client.setLastName(lastName);
        client.setFirstName(firstName);
        client.setBalance(balance);
        client.setAccountNumber(accountNumber);

        //move file-position pointer to correct record in file
        insertInFile.seekp((accountNumber-1)*sizeof(ClientData));

        //insert record in file
        insertInFile.write(reinterpret_cast<char*>(&client), sizeof(ClientData));
    }
    else {  //display error if account already exists
        cerr<<"Account #"<<accountNumber<<" already contains information."<<endl;
    }
}

void deleteRecord(fstream& deleteFromFile){
    //obtain number of account to delete
    int accountNumber{getAccount("Enter account to delete")};

    //move file-position pointer to correct record in file
    deleteFromFile.seekg((accountNumber-1)*sizeof(ClientData));

    //read record from file
    ClientData client;
    deleteFromFile.read(reinterpret_cast<char*>(&client), sizeof(ClientData));

    //delete record, if record exists in file
    if (client.getAccountNumber() != 0){
        ClientData blankClient; //create blank record

        //move file-position pointer to correct record in file
        deleteFromFile.seekp((accountNumber-1)*sizeof(ClientData));

        //replace existing record with blank record
        deleteFromFile.write(reinterpret_cast<char*>(&blankClient), sizeof(ClientData));

        cout<<"Account #"<<accountNumber<<"deleted.\n";
    }
    else{   //display error if record does not exist
        cerr<<"Account #"<<accountNumber<<"does not exist."<<endl;
    }
}

void outputLine(ostream& output, const ClientData& record){
    output<<left<<setw(10)<<record.getAccountNumber()<<setw(16)
        <<record.getLastName()<<setw(11)<<record.getFirstName()
        <<setw(10)<<setprecision(2)<<right<<fixed<<showpoint<<record.getBalance()<<endl;        
}

//obtain account-number value
int getAccount(const char* const prompt){
    int accountNumber;

    // obtain account-number value
    do {
        cout<<prompt<<" (1-100): ";
        cin>>accountNumber;
    } while(accountNumber <1 || accountNumber > 100);

    return accountNumber;
}