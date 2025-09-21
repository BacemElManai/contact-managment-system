# contact-managment-system
📞 Contact Management System
A sophisticated C++-based Contact Management System designed for efficient handling of personal and professional contacts with robust data validation, secure storage, and intelligent search capabilities.

🚀 Features
🔐 Advanced Data Validation
Name Validation: Alphabetic characters only enforcement

Phone Validation: Exact 10-digit numeric validation

Email Validation: Format validation requiring exactly one '@' and one '.'

💾 Smart Data Management
Text File Storage: Secure plaintext storage in contacts.txt

Temporary File Processing: Safe deletion using tempFile.txt as intermediate storage

Structured Storage: Organized contact storage with name, phone, and email on consecutive lines

File Integrity: Comprehensive file handling with proper opening/closing procedures

🔍 Intelligent Search & Management
Contact Deletion: Complete removal with confirmation and file updating

Contact Search: Efficient name-based searching with full detail display

Complete Display: Formatted output of all contacts with clear organization

Menu Navigation: User-friendly interface with continuous operation

🛠 Technical Architecture
Core Functions
deleteContact(): Safe contact removal with temporary file processing

validateEmail(): Email format validation with '@' and '.' checking

validatePhone(): 10-digit numeric validation

validateName(): Alphabetic character validation

addContact(): Guided contact addition with real-time validation

displayContacts(): Organized contact display in groups of three

searchContact(): Name-based contact searching

Data Structure

// Contacts are stored in consecutive lines:
// Line 1: Name
// Line 2: Phone
// Line 3: Email
📋 Usage

g++ contact_manager.cpp -o contact_manager
./contact_manager
Menu Options
Add contact: Complete data entry with guided validation

Delete contact: Remove contacts by name with confirmation

Search contact: Find and display specific contacts

Display all contacts: Show all stored contacts

Exit: Graceful program termination

🎯 Business Value
Contact Organization: Streamlined personal and professional contact management

Data Integrity: Comprehensive validation ensures database quality

Quick Access: Efficient search and retrieval capabilities

Data Maintenance: Safe deletion and updating procedures

🔧 Technical Excellence
Robust Error Handling: Comprehensive file operation management

Input Validation: Real-time validation with user feedback

Memory Safety: Proper file handling and resource management

Code Organization: Modular design with separated functionality

User Experience: Intuitive menu system with clear prompts

📁 File System
contacts.txt: Primary contact database (auto-generated)

tempFile.txt: Temporary processing file (auto-managed)

📊 Sample Output

Contact management system:
1. Add contact
2. Delete contact
3. Search contact
4. Display all contacts
5. Exit
Enter your choice: 1

Enter name: John Doe
Enter phone number: 1234567890
Enter email: john.doe@email.com
🚦 Validation Examples
✅ "John Doe" - Valid Name (alphabetic characters only)

❌ "John123" - Invalid Name (contains numbers)

✅ "1234567890" - Valid Phone (exactly 10 digits)

❌ "123-456-7890" - Invalid Phone (contains non-digit characters)

✅ "email@domain.com" - Valid Email (contains @ and .)

❌ "invalid-email" - Invalid Email (missing @ and .)

💡 Ideal For
Personal contact management and organization

Business contact tracking and management

Educational demonstrations of file I/O operations

C++ programming examples showcasing validation techniques

Small business customer relationship management

Developer portfolios demonstrating complete applications

This system represents production-ready C++ code with professional error handling, comprehensive data validation, and modular architecture suitable for personal use, small business applications, and educational purposes. The structured file handling and validation system ensures data integrity while maintaining user-friendly operation.
