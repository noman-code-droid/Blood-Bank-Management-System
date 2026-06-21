#include<iostream>
#include<fstream>
#include<stdlib.h>
#include <sstream>
char YourOption; //global variable for moving to main menu
using namespace std;
//----------------donor section functions
void DonorSection();
void AddDonor();
void UpdateDonor();
void ShowAllDonors();
void DeleteDonor();
void ExitTOMainMenu();
//---------------Blood Section functions
void AddUnits();
void BloodSection();
void AvailableUnits();
void DonateUnits();
//========exit to main menu function 
void ExitFrmMainPrgrm();

int main()
{
//menu options
    int USoption;
//wellcome message
    cout<<"\t----------------------------------------\n";
    cout<<"\tWELLCOME TO BLOOD BANK MANAGEMENT SYSTEM";
    cout<<"\n\t----------------------------------------";

    
    cout<<"\n\n\t--------------------\n";
    cout<<"\t\tMENU";
    cout<<"\n\t--------------------";

cout<<"\n\nChoose Number To select The option\n";
cout<<"\n1- Donor Section: ";
cout<<"\n2- Blood Section: ";
cout<<"\n3- Exit From Program: ";

cout<<"\nEnter Your Option: ";
cin>>USoption;


//using switch statements
switch (USoption)
{
case 1:
    DonorSection();
    break;
case 2:
    BloodSection();
    break;
case 3:
    ExitFrmMainPrgrm();
    break;

default:
    cout<<"Invalid Choice! Please Select from the given options.";
    break;
}
 
}

//------donor section functions defining
void DonorSection()
{
    int DonorSectChoice ;

    cout<<"\t----------------------------------------\n";
    cout<<"\tWELLCOME TO Donor Section";
    cout<<"\n\t----------------------------------------";

    cout<<"\n1-Add Donor";
    cout<<"\n2-Update Donor";
    cout<<"\n3-Delete Donor";
    cout<<"\n4-Show All Donors";
    cout<<"\n5-Exit To Main Menu";
    
    cout<<"\n\nEnter Your Choice: ";
    cin>>DonorSectChoice;

    switch (DonorSectChoice)
    {
    case 1:
    AddDonor();
    break;
    
    case 2:
    UpdateDonor();
    break;

    case 3:
     DeleteDonor();
    break;

    case 4:
     ShowAllDonors();
    break;

    case 5:
     ExitTOMainMenu();
    break;

    default:
    cout<<"Invalid Choice!";
        break;
    }

}

////ADDING DONOR

// Define a struct to hold donor information
struct Donor {
    int id;
    string firstName;
    string lastName;
    string bloodGroup;
    string contact;
};

void AddDonor()
{
    ofstream AddDonor_List; //making object for storing donor's data table data
    Donor newDonor; // donor struct variable
    
    
    AddDonor_List.open("AddDonorDetails.txt", ios::app);

    if (AddDonor_List.tellp() == 0) // check if file is empty
    {
        // formatting the database with table headers
        AddDonor_List << "Donor ID\t\t\t" << "Donors Full Name\t\t" << "Blood Group\t\t" << "Contact Number\t\t\n";
    }

    do {
        bool found; // flag to indicate if ID is found in the file
        cout << "/////ADD DONOR/////\n";
        
        // Ask for a new ID and check if it already exists in the file
        do {
            found = false; // reset flag before checking for new ID
            cout << "\nDonor ID: ";
            cin >> newDonor.id;
            
            found = false; // assume ID is not found
            ifstream donorFile("AddDonorDetails.txt");
            string line;
            while (getline(donorFile, line)) {
                if (line.find(to_string(newDonor.id)) != string::npos) {
                    found = true;
                    cout << "ID already exists. Please enter a different ID.\n";
                    break;
                }
            }
            donorFile.close();
            
        } while (found);
        
        cout << "Donor First Name: ";
        cin >> newDonor.firstName;
        
        cout << "Donor Last Name: ";
        cin >> newDonor.lastName;
        
        cout << "\nType Your Blood Group As Given\n\nOption\tBlood Group\n\n1\tA+\n2\tO+\n3\tB+\n4\tAB+\n5\tA-\n6\tO-\n7\tB-\n8\tAB-";
        cout << "\nBlood Group: ";
        cin >> newDonor.bloodGroup;
        
        cout << "\nContact Number: ";
        cin >> newDonor.contact;
        
        // Check if the donor already exists in the file
        found = false;
        ifstream donorFile("AddDonorDetails.txt");
        string line;
        while (getline(donorFile, line)) {
            if (line.find(to_string(newDonor.id)) != string::npos) {
                found = true;
                cout << "ID already exists. The donor information will not be added.\n";
                break;
            }
        }
        donorFile.close();
        
        // Write the donor information to the file if it does not already exist
        if (!found) {
            AddDonor_List << newDonor.id << "\t" << newDonor.firstName << " " << newDonor.lastName << "\t" 
                          << newDonor.bloodGroup << "\t" << newDonor.contact << "\n";
        
            cout << "\nRecord Saved Successfully!";
        }
        
        cout << "\n\nWant to add another entry?\nPress ' Y ' To another entry or press ' N ' to  Jump in Main Menu:  ";
        cin >> YourOption;
    } while (YourOption == 'Y' || YourOption == 'y');

    AddDonor_List.close();

    if (YourOption) //asking user to another donor
    {
        main();
    }
}

////UPDATE DONOR
void UpdateDonor()
{
    
   do
   {
     int id;
    cout << "Enter ID of donor to update: ";
    cin >> id;

    ifstream donorFile("AddDonorDetails.txt");
    ofstream tempFile("temp.txt");
    string line;
    bool found = false;
    while (getline(donorFile, line)) {
        stringstream ss(line);
        int donorId;
        string firstName, lastName, bloodGroup, contact;
        ss >> donorId >> firstName >> lastName >> bloodGroup >> contact;
        if (donorId == id) {
            found = true;
            cout << "Donor Found\n";
            cout << "ID: " << donorId << "\n";
            cout << "First Name: " << firstName << "\n";
            cout << "Last Name: " << lastName << "\n";
            cout << "Blood Group: " << bloodGroup << "\n";
            cout << "Contact: " << contact << "\n";

            cout << "\nWhich information would you like to update?\n";
            cout << "1. First Name\n";
            cout << "2. Last Name\n";
            cout << "3. Blood Group\n";
            cout << "4. Contact\n";
            int option;
            cin >> option;

            switch (option) {
                case 1:
                    cout << "Enter new first name: ";
                    cin >> firstName;
                    break;
                case 2:
                    cout << "Enter new last name: ";
                    cin >> lastName;
                    break;
                case 3:
                    cout << "Enter new blood group: ";
                    cin >> bloodGroup;
                    break;
                case 4:
                    cout << "Enter new contact number: ";
                    cin >> contact;
                    break;
                default:
                    cout << "Invalid option.\n";
                    return;
            }
            // Update the donor information
            tempFile << donorId << " " << firstName << " " << lastName << " " << bloodGroup << " " << contact << "\n";
            cout << "Record updated successfully!\n";
        }
        else {
            // Copy unmodified record to temp file
            tempFile << line << "\n";
        }
    }

    if (!found) {
        cout << "Donor not found!\n";
    }

    donorFile.close();
    tempFile.close();

    // Remove original file and rename temp file
    remove("AddDonorDetails.txt");
    rename("temp.txt", "AddDonorDetails.txt");

    cout<<"To exit to main menu Press Y\nPress N to continue.";
    cin>>YourOption;
   } while (YourOption == 'N' || YourOption == 'n');

if (YourOption) //asking user to another donor
    {
        main();
    }
}

////DELETE DONOR
void DeleteDonor(){
    do
    {
        cout<<"/////Delete DONOR DATA /////\n";
    
    ifstream donorFile("AddDonorDetails.txt");
    ofstream tempFile("temp.txt");

    int deleteId;
    cout << "Enter ID of donor to delete: ";
    cin >> deleteId;

    Donor deletedDonor;
    bool found = false;
    string line;
    while (getline(donorFile, line)) {
        stringstream ss(line);
        ss >> deletedDonor.id >> deletedDonor.firstName >> deletedDonor.lastName
           >> deletedDonor.bloodGroup >> deletedDonor.contact;
        if (deletedDonor.id == deleteId) {
            found = true;
            cout << "Donor Found\n";
            cout << "Donor ID: " << deletedDonor.id << endl;
            cout << "Name: " << deletedDonor.firstName << " " << deletedDonor.lastName << endl;
            cout << "Blood Group: " << deletedDonor.bloodGroup << endl;
            cout << "Contact: " << deletedDonor.contact << endl;
            char confirmDelete;
            cout << "Are you sure you want to delete this donor? (y/n) ";
            cin >> confirmDelete;
            if (confirmDelete == 'y' || confirmDelete == 'Y') {
                cout << "Donor deleted\n";
            } else {
                cout << "Deletion aborted\n";
                tempFile << line << endl;
            }
        } else {
            tempFile << line << endl;
        }
    }
    donorFile.close();
    tempFile.close();

    remove("AddDonorDetails.txt");
    rename("temp.txt", "AddDonorDetails.txt");

    if (!found) {
        cout << "Donor with ID " << deleteId << " not found\n";
    }

    cout<<"To exit to main menu Press Y\nPress N to continue.";
    cin>>YourOption;
    } while (YourOption == 'N' || YourOption == 'n');
if (YourOption) //asking user to another donor
    {
        main();
    }
    
}

   
////SHOW ALL DONORS
void ShowAllDonors()
{
    do
    {
        ifstream donorFile("AddDonorDetails.txt");
    if (!donorFile) {
        cout << "Error opening file.\n";
        return;
    }
    
    cout << "All Donors:\n";
    cout << "Donor ID\t\t\t" << "Donors Full Name\t\t" << "Blood Group\t\t" << "Contact Number\t\t\n";
    
    string line;
    while (getline(donorFile, line)) {
        cout << line << endl;
    }
    
    donorFile.close();
    cout<<"To exit to main menu Press Y\nPress N to continue.";
    cin>>YourOption;
    } while (YourOption == 'N' || YourOption == 'n');
if (YourOption) //asking user to another donor
    {
        main();
    }

}

////EXIT TO MAIN MENU FUNCTION 
////WHENEVER IT IS CALLED THE CONTROL MOVE TO main() FUNCTION
void ExitTOMainMenu(){
     main();                                        
}

///for donor section
//---------------Blood Section functions
void BloodSection()
{
    cout<<"\t----------------------------------------\n";
    cout<<"\tWELLCOME TO Blood Section";
    cout<<"\n\t----------------------------------------";

    int BloodSectionChoice ;
    cout<<"\n1- Add Units";
    cout<<"\n2- Available Units";
    cout<<"\n3- Donate Unit";
    cout<<"\n4- Exit To Main Menu";
   
    cout<<"\nEnter Your Choice: ";
    cin>>BloodSectionChoice ;
    
    switch (BloodSectionChoice)
    {
    
    case 1:
    AddUnits();
    break;

    case 2:
    AvailableUnits();
    break;

    case 3:
    DonateUnits();
    break;

    case 4:
    ExitTOMainMenu();
    break;
    
    default:
    cout<<"Enter A valid Choice";
        break;
    }
}
////ADD UNITS
void AddUnits()
{
    
    ofstream AddUnit_Head; //making object for storing unit's data table head
    ofstream AddUnit_List; //making object for storing unit's data table data
    char YourOption;

    AddUnit_Head.open("AddUnitDetails.txt");
    // formatting the database with table headers
    AddUnit_Head << "Blood Group\t\t" << "Units\t\n";
    AddUnit_Head.close();

    AddUnit_List.open("AddUnitDetails.txt", ios::app);

    do {
        string bloodGroup;
        int units;

        cout << "/////ADD UNITS/////\n";

        cout << "Enter Blood Group: ";
        cin >> bloodGroup;

        cout << "Enter Number of Units: ";
        cin >> units;

        // Write the unit information to the file
        AddUnit_List << bloodGroup << "\t\t" << units << "\n";

        cout << "\nRecord Saved Successfully!";

        cout << "\n\nWant to add another entry?\nPress ' Y ' To add another entry or press ' N ' to jump to Main Menu: ";
        cin >> YourOption;

    } while (YourOption == 'Y' || YourOption == 'y');

    AddUnit_List.close();

    if (YourOption)
     {
        main();
    }

}

////AVAILABLE UNITS
  void AvailableUnits()
{

do
{
    ifstream inFile("AddUnitDetails.txt");
    if (!inFile) {
        cout << "Unable to open file blood_bank.txt\n";
        return;
    }
     cout<<"/////AVAILABLE UNITS/////\n";
    string bloodType;
    cout << "Enter the blood type to check available units: ";
    cin >> bloodType;
    
    string line;
    bool found = false;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string bloodGroup;
        int units;
        ss >> bloodGroup >> units;
        if (bloodGroup == bloodType) {
            found = true;
            cout << "Blood Group: " << bloodGroup << " Units: " << units << endl;
        }
    }
    
    if (!found) {
        cout << "No units available for blood type " << bloodType << endl;
    }
    
    inFile.close();
    
    cout << "\n\nWant to Check another blood group unit?\nPress ' Y ' To Continue or press ' N ' to jump to Main Menu: ";
    cin >> YourOption;

} while (YourOption == 'Y' || YourOption == 'y');


if (YourOption)
     {
        main();
    }

}

////DONATE UNITS
void DonateUnits() 
{
   
    do
    {
         ifstream unitFile("AddUnitDetails.txt", ios::in);
    ofstream tempFile("temp.txt", ios::out);
    
    string bloodGroup;
    int unitsToDonate;
    bool found = false;
    
    cout << "Enter the blood group to donate: ";
    cin >> bloodGroup;
    
    // Check if the blood group exists in the file
    string line;
    while (getline(unitFile, line)) {
        stringstream ss(line);
        string group;
        int units;
        
        ss >> group >> units;
        
        if (group == bloodGroup) {
            cout << "Available units: " << units << endl;
            
            cout << "Enter the number of units to donate: ";
            cin >> unitsToDonate;
            
            if (unitsToDonate > units) {
                cout << "Not enough units available!" << endl;
                break;
            }
            
            units -= unitsToDonate;
            found = true;
        }
        
        tempFile << group << " " << units << endl;
    }
    
    unitFile.close();
    tempFile.close();
    
    // If blood group is found and units are deducted from the file
    if (found) {
        // Delete the old file and rename the temp file to the original file name
        remove("AddUnitDetails.txt");
        rename("temp.txt", "AddUnitDetails.txt");
        
        cout << "Units successfully donated!" << endl;
    } else {
        cout << "Blood group not found!" << endl;
        remove("temp.txt");
    }
    
    // Ask if the user wants to donate more units or go back to main menu
    cout << "\n\nDonate another blood group unit?\nPress ' Y ' To Continue or press ' N ' to jump to Main Menu: ";
    cin >> YourOption;

} while (YourOption == 'Y' || YourOption == 'y');


if (YourOption)
     {
        main();
    }
    

}

////EXIT FROM THE WHOLE PROGRAM FUNCTION
void ExitFrmMainPrgrm(){

    char chr ;
    cout<<"Do You Want To Exit from the program? ";
    cout<<"\nPress ' Y ' to continue or press any key to exit from the program: ";
    cin>>chr;

    if (chr == 'y' || chr == 'Y')
    {
        main();
    }
    else{
        cout<<"Bye!";
    }

}
