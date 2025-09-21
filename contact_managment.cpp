#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
// Function to delete the contact of a given name.
// It reads contact details name, phone, and email, and writes all contacts except the one to delete into tempFile.txt.
// If the contact is found, it prints "Contact deleted successfully"; else, it prints "Contact not found." The files are closed after processing.
void deleteContact() {
    string contactToDelete, contactName, contactPhone, contactEmail;
    bool isDeleted = false;
    ifstream contactFile;
    ofstream tempFile;
    cout << "Enter the name of the contact to delete: ";
    cin >> contactToDelete;
    tempFile.open("tempFile.txt");
    contactFile.open("contacts.txt");
    while (getline(contactFile, contactName) && getline(contactFile, contactPhone) && getline(contactFile, contactEmail)) { // Read consecutive lines from the file and store them in variables.
        if (contactName == contactToDelete) {
            isDeleted = true;
            cout << "Contact deleted successfully" << endl;
            continue; // Skip and move to the next iteration of the loop.
        }
        tempFile << contactName << endl;
        tempFile << contactPhone << endl;
        tempFile << contactEmail << endl;
    }
    tempFile.close();
    contactFile.close();
    if (!isDeleted) {
        cout << "Contact not found" << endl;
        return;
    }
    // Copy contact details (name, phone, and email) from tempFile.txt to contacts.txt.
    ofstream updatedContactFile;
    ifstream tempReadFile;
    updatedContactFile.open("contacts.txt");
    tempReadFile.open("tempFile.txt");
    while (getline(tempReadFile, contactName) && getline(tempReadFile, contactPhone) && getline(tempReadFile, contactEmail)) {
        updatedContactFile << contactName << endl;
        updatedContactFile << contactPhone << endl;
        updatedContactFile << contactEmail << endl;
    }
    tempReadFile.close();
    updatedContactFile.close();
}
// Function to verify the email format.
// It checks if a string `emailInput` is a valid email. The string must contain exactly one '@' and one '.'.
bool validateEmail(string emailInput) {
    int atCount = 0, dotCount = 0;
    for (int i = 0; i < emailInput.length(); i++) {
        if (emailInput[i] == '@') {
            atCount++;
        } else if (emailInput[i] == '.') {
            dotCount++;
        }
    }
    return (atCount == 1 && dotCount == 1);
}
// Function to verify the phone number.
// It checks if `phoneInput` is a valid 10-digit phone number. It returns false if the length is not 10 or if any character is not a digit.
bool validatePhone(string phoneInput) {
    if (phoneInput.length() != 10) return false;
    for (int i = 0; i < phoneInput.length(); i++) {
        if (phoneInput[i] < '0' || phoneInput[i] > '9') return false;
    }
    return true;
}
// Function to verify the name.
// This function checks if `nameInput` contains only alphabetic characters. It returns true if all characters are alphabetic.
bool validateName(string nameInput) {
    int validCharCount = 0;
    for (int i = 0; i < nameInput.length(); i++) {
        if ((nameInput[i] >= 'A' && nameInput[i] <= 'Z') || (nameInput[i] >= 'a' && nameInput[i] <= 'z')) {
            validCharCount++;
        }
    }
    return (validCharCount == nameInput.length()); // Return true if all characters are alphabetic.
}
// Function to add a contact.
void addContact() {
    string newName, newEmail, newPhone; // `newName`, `newEmail`, and `newPhone` refer to the name, email, and phone number respectively.
    ofstream contactFile;
    contactFile.open("contacts.txt", ios::app);
    // Name input with validation.
    do {
        cout << "Enter name: ";
        cin >> newName;
        if (!validateName(newName)) {
            cout << "Invalid input" << endl;
            cout << "Name should only contain alphabetic characters" << endl;
        }
    } while (!validateName(newName));
    // Phone number input with validation.
    do {
        cout << "Enter phone number: ";
        cin >> newPhone;
        if (!validatePhone(newPhone)) { // Validate that the phone number is a 10-digit number.
            cout << "Invalid input" << endl;
            cout << "Phone number should only contain 10 digit numbers" << endl;
        }
    } while (!validatePhone(newPhone));
    // Email input with validation.
    do {
        cout << "Enter email: ";
        cin >> newEmail;
        if (!validateEmail(newEmail)) { // Validate the email contains exactly one '@' and one '.'.
            cout << "Invalid input" << endl;
            cout << "The email should contain '@' and '.'" << endl;
        }
    } while (!validateEmail(newEmail));
    // Write the valid contact to the file.
    contactFile << newName << endl;
    contactFile << newPhone << endl;
    contactFile << newEmail << endl;
    contactFile.close();
}
// Function to display all contacts.
void displayContacts() {
    fstream contactFile;
    contactFile.open("contacts.txt", ios::in); // Open the file in read mode.
    if (contactFile) {
        string contactDetails;
        int contactField = 0;
        while (getline(contactFile, contactDetails)) {
            if (contactField == 0) {
                cout << "Name: " << contactDetails << endl;
                contactField++;
            } else if (contactField == 1) {
                cout << "Phone number: " << contactDetails << endl;
                contactField++;
            } else if (contactField == 2) {
                cout << "Email: " << contactDetails << endl;
                contactField = 0;
            }
        }
    }
    contactFile.close();
}
// Function to search for a contact.
void searchContact() {
    fstream contactFile;
    contactFile.open("contacts.txt", ios::in); // Open the file in read mode.
    string searchName, contactName, contactPhone, contactEmail;
    cout << "Enter the name of the contact to search: ";
    cin >> searchName;
    bool isFound = false; // Flag to check if the contact is found.
    // Search for the contact in the file.
    while (getline(contactFile, contactName)) {
        getline(contactFile, contactPhone);
        getline(contactFile, contactEmail);
        if (contactName == searchName) {
            isFound = true;
            cout << "Name: " << contactName << endl;
            cout << "Phone: " << contactPhone << endl;
            cout << "Email: " << contactEmail << endl;
            break;
        }
    }
    if (!isFound) {
        cout << "Contact not found." << endl;
    }
    contactFile.close(); // Close the file.
}
// The main function.
int main() {
    int userChoice;
    do {
        cout << "Contact management system:" << endl;
        cout << "1. Add contact" << endl;
        cout << "2. Delete contact" << endl;
        cout << "3. Search contact" << endl;
        cout << "4. Display all contacts" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> userChoice;
        switch (userChoice) {
            case 1:
                addContact(); // Add a new contact.
                break;
            case 2:
                deleteContact(); // Delete a contact.
                break;
            case 3:
                searchContact(); // Search for a contact.
                break;
            case 4:
                displayContacts(); // Display all contacts.
                break;
            case 5:
                break; // Exit the program.
            default:
                cout << "Invalid input" << endl; // Handle invalid inputs.
                break;
        }
    } while (userChoice != 5);
    cout << "Exiting..." << endl; // Display exiting message and end the program.
    return 0;
}