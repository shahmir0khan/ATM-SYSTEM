
#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;

// password for admin is 786
                     ////////////////////////////////////////////////////////////
                     ////////////////////////// USER CLASS //////////////////////
                /////////////////////////////////////////////////////////////
class user {
protected:
  char Name[30];
  int PIN;
  int balance;
  static int i;

public:
  // get Name
  char *Names(void) {
    // Return Name
    return Name;
  }
  void setbal(int bal) { balance = bal; }
  int getbal() { return balance; }
  // setter pass
  void setpass(int pass)
   { PIN = pass; }

  // getter PIN

  int PINs() { return PIN; }
  /////////////////// Function displaying the data ON COMPUTER  //////////////
  void showData(void) {
    cout << "Name:" << Name << ", PIN:" << PIN << ", Balance:" << balance
         << endl;
  }


 
                          /////////////////////////////   DEPOSIT  ///////////////////////////
  void deposit(char *uname) {

    user a;
    fstream file, temp;
    file.open("ATMFILE.txt", ios::in | ios::out | ios::ate);
    temp.open("temp.txt", ios::out | ios::app);
    // from begining
    file.seekg(0);
    file.read((char *)&a, sizeof(a));

    // Till end of the file
    while (!file.eof()) {
      if (!strcmp(a.Names(), uname)) // if found so add else copy as it is
      {
        int b;

        cout << "\nEnter amount "
             << "to deposit:";
        cin >> b;
        a.balance = a.balance + b;
        // printing on receipt
        cout << "\nYou have deposited rs:" << b
             << "\n Your currnt Balance is:" << a.balance;

        temp.write((char *)&a, sizeof(a));
      } else {
        temp.write((char *)&a, sizeof(a));
      }
      file.read((char *)&a, sizeof(a));
    }
    file.close();
    temp.close();
    // deleting previous file
    remove("ATMFILE.txt");
    // renaming new file with previous name
    rename("temp.txt", "ATMFILE.txt");
  }
  

                      ////// ///////////////////   WITHDRAW    //////////////////////////////
  void withdraw(char *uname) {

    user a;
    fstream file, temp;
    file.open("ATMFILE.txt", ios::in | ios::out | ios::ate);
    temp.open("temp.txt", ios::out | ios::app);
    // from begin
    file.seekg(0);
    file.read((char *)&a, sizeof(a));

    // Till end of file is reached
    while (!file.eof()) {
      if (!strcmp(a.Names(), uname)) {
        int b;
        cout << "\nEnter amount "
             << "to withdraw:";
        cin >> b;
        if (a.balance < b) {
          cout << "\nYou dont have sufficient balance"
               << "balance to withdraw";
        } else {
          a.balance = a.balance - b;
          temp.write((char *)&a, sizeof(a));
          // printing on receipt
          cout << "\nYou have withdrawn rs:" << b
               << "\nYour current Balance is:" << a.balance;
        }
      } else {
        temp.write((char *)&a, sizeof(a));
      }
      file.read((char *)&a, sizeof(a));
    }

    // Close the file
    file.close();
    temp.close();
    remove("ATMFILE.txt");
    rename("temp.txt", "ATMFILE.txt");
  }

  // ///taking/reading/getter   data from user
  void getData(void) {

    cout << "\nEnter Name:";
    cin.ignore(); // clear the input buffer

    cin.getline(Name, 20);

    //cout << "\nEnter  PIN for :";
   // cin >> PIN;
    PIN==i++;

    cout << "\nEnter balance at time of making of ATM card:";
    cin >> balance;
  }
  
  

             ////////////////////////  USER DATA FUNC(WHEN USER WANT TO SEE HIS DATA)/////////////////////////
  int showmydata(char *uname, int pass) {
    user a;
    fstream f;

    // Open the file
    f.open("ATMFILE.txt", ios::in);
    if (!f) {
      cout << "Error in opening file..";
      return 0;
    }

    // Read data from file
    f.read((char *)&a, sizeof(a));
    while (!f.eof()) {

      if (!strcmp(a.Names(), uname)) {
        if (a.PINs() == pass) {
          cout << "NAME: " << uname << "\nPASSWORD :" << pass
               << "\nBALANCE: " << a.getbal() << endl;
        }
      }
      f.read((char *)&a, sizeof(a));
    }

    // Close the file
    f.close();
    return 0;
  }

                        //////////////////////////////// UPDATE PIN////////////////////////////////
  void UPDATEPIN(char *uname) {
    user a;
    int pass;
    fstream file, temp;
    file.open("ATMFILE.txt", ios::in | ios::out | ios::ate);
    temp.open("temp.txt", ios::out | ios::app);
    // from begin
    file.seekg(0);
    file.read((char *)&a, sizeof(a));

    // Till end of file is reached
    while (!file.eof()) {
      if (!strcmp(a.Names(), uname)) {

        
        cout << "enter new password\n";
        cin >> pass;
        a.setpass(pass);
        temp.write((char *)&a, sizeof(a));

      } else {
        temp.write((char *)&a, sizeof(a));
      }
      file.read((char *)&a, sizeof(a));
    }

    // Close the file
    file.close();
    temp.close();
    remove("ATMFILE.txt");
    rename("temp.txt", "ATMFILE.txt");
  }
};
int user::i =0001;

                            ////////////////////////////////////////////////////////////
                            ////////////////////////// ADMIN CLASS //////////////////////
                            /////////////////////////////////////////////////////////////

class admin : public user {
public:
	
	
                                  ///////////////////   ADD USER   ////////// /////
  int add_new_user() {
    user a;

    ofstream file;

    // Open file in write mode
    file.open("ATMFILE.txt", ios::out | ios::app);
    if (!file) {
      cout << "Error in creating "
           << "file.." << endl;
      return 0;
    }

    // Read from user class func getdata
    a.getData();
    cout<<"YOUR ACCOUNT HAS CREATED"<<endl<<"YOUR PIN IS :"<<a.PINs();
    

    // Write the whole object into file
    file.write((char *)&a, sizeof(a));

    // Close the file
    file.close();

    return 0;
  }
  
  
                      ///////////////////   VIEW ALL USER   ////////// /////
  int all_data() {

    user a;

    ifstream file1;

    // Open file in read mode
    file1.open("ATMFILE.txt", ios::in);
    if (!file1) {
      cout << "Error in opening file..";
      return 0;
    }

    // Read data of whole from file until end of file
    file1.read((char *)&a, sizeof(a));
    while (!file1.eof()) {

      // Display data on monitor
      a.showData();
      file1.read((char *)&a, sizeof(a));
    }

    // Close the file
    file1.close();
    return 0;
  }
  
  
                      ////////////////////////   DELETING USER     /////////////////////////
  int deleteuser() {
    char uname[30];
    cout << "\nEnter the "
         << "Name to be "
         << "deleted : ";
    cin.ignore(); // clear the input buffer

    cin.getline(uname, 20);

    admin a;

    fstream original, temp;
    // opening perevious file
    original.open("ATMFILE.txt", ios::in);
    if (!original) {
      cout << "\nfile not found";
      return 0;
    } else { // open new file name temp to copy data of org file
      temp.open("temp.txt", ios::out | ios::app);
      original.read((char *)&a, sizeof(a));

      // Till end of previous file
      while (!original.eof()) {
        // when Name find display deleted and not copy in temp
        if (!strcmp(a.Names(), uname)) {
          cout << "data found "
               << "and deleted\n"
               << a.Name << "\n";
        } else {
          temp.write((char *)&a, sizeof(a));
        }
        original.read((char *)&a, sizeof(a));
      }
      original.close();
      temp.close();
      remove("ATMFILE.txt");
      // changing the temp file name to previous name
      rename("temp.txt", "ATMFILE.txt");
      a.all_data();
    }
    return 0;
  }
  
  
                  /////////////////////////////// SEARCH USER ////////////////////////////////

  void search1_user(char *uname, int pass) {
    user a;
    fstream f;

    // Open the file
    f.open("ATMFILE.txt", ios::in);
    if (!f) {
      cout << "Error in opening file..";
    }

    // Read data from file
    f.read((char *)&a, sizeof(a));
    while (!f.eof()) {

      if (!strcmp(a.Names(), uname)) {
        if (a.PINs() == pass) {
          cout << "NAME: " << uname << "\nPASSWORD :" << pass
               << "\nBALANCE: " << a.getbal() << endl;
        }
      }
      f.read((char *)&a, sizeof(a));
    }

    // Close the file
    f.close();
  }

  int search_user(char *uname, int pass) {
    user a;
    fstream f;

    // Open the file
    f.open("ATMFILE.txt", ios::in);
    if (!f) {
      cout << "Error in opening file..";
      return 0;
    }

    // Read data from file
    f.read((char *)&a, sizeof(a));
    while (!f.eof()) {

      if (!strcmp(a.Names(), uname)) {
        if (a.PINs() == pass) {
          return 1;
        }
      }
      f.read((char *)&a, sizeof(a));
    }

    // Close the file
    f.close();
    return 0;
  }
};

                ////////////////////////////////////////////////////////////
               ////////////////////////// MAIN MENU //////////////////////
              /////////////////////////////////////////////////////////////

int main() {
  char uname[30];
  int pass, ch, ch1, ch2, found = 0;
begining:
  cout << "\n///////////////////////Welcome to ATM SYSTEM//////////////////////";
  cout << "\nLogin as :\n1. Admin\n2."
       << " User\n3. "
          "Exit\nChoose one : ";
  cin >> ch;
  admin a;
  switch (ch) {
  case 1:
  admin:

    cout << "\nEnter details to"
         << " login as Admin\n";
    cout << "\nEnter password:";
    cin >> pass;
    if (pass == 786) {

      cout << "\nWelcome to"
           << " Admin Menu";
      cout << "\n1. Add User\n2."
           << " Delete User\n3. "
              "View All User\n4. "
           << "search specific user\n5."
           << "Exit\n";
      cout << "\nSelect one : ";
      cin >> ch1;
      switch (ch1) {
      case 1:
        a.add_new_user();
        goto begining;
      case 2:

        a.deleteuser();
        goto begining;

      case 3:
        a.all_data();

        goto begining;

      case 4:

        cout << "Enter Name:";
        cin.ignore();
        cin.getline(uname, 30);
        cout << "\nEnter PIN:";

        cin >> pass;
        a.search1_user(uname, pass);
        goto admin;
        
      }
    } else {
      cout << "wrong password";
      goto admin;
    }
    break;
  case 2:

    cout << "\n Enter details to"
         << " login as User\n";

    cout << "Enter Name:";
    cin.ignore();
    cin.getline(uname, 30);
    cout << "\nEnter PIN:";

    cin >> pass;
    found = a.search_user(uname, pass);

    if (found) {
    user:

      cout << "\nWelcome " << uname;
      cout << "\nWelcome to"
           << " User Menu";
      cout << "\n1. SHOW MY DATA\n2."
           << " DEPOSIT MONEY\n3. "
              "WITHDRAW MONEY\n4. "

           << "UPDATE PIN\n5."
           << "Exit\n";
      cout << "\nSelect one : ";
      cin >> ch2;

      switch (ch2) {
      case 1:
        a.search1_user(uname, pass);
        goto user;
        break;
      case 2:
        a.deposit(uname);
        goto user;
      case 3:
        a.withdraw(uname);
        
        goto user;
      case 4:
        cin.ignore();
        cout << "Enter Name:";
        cin.getline(uname, 30);
        a.UPDATEPIN(uname);
        goto user;
      case 5:
        cout << "Thank you";
        break;
      }
    } else {
      cout << "\nCan not find the Account"
           << " with Name "
              ":(\n\nHit 'ENTER' to continue "
           << uname;
      cin.get();
    }
    goto begining;

  case 3:
    cout << "\nThankyou for  using  SAS ATM";
    cin.get();
    break;
  }
}
