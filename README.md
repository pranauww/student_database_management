# Student Database Management System

## Table of Contents
1. [Introduction](#introduction)
2. [Features](#features)
3. [System Requirements](#system-requirements)
4. [Installation](#installation)
5. [How to Use](#how-to-use)
6. [Code Overview](#code-overview)

## Introduction
The **Student Database Management System** is a console-based program developed in C for managing student records. It provides a user-friendly interface to perform various operations such as adding, searching, deleting, modifying, and displaying student records. The program stores student information in a file system and allows easy access and modification of records.

## Features
- **Login System**: Provides password protection to access the system.
- **Add Student Record**: Add new student information such as name, roll number, course, marks, etc.
- **Search Student Record**: Search for a student using their roll number.
- **Display Student Records**: Display all student records stored in the system.
- **Modify Student Record**: Modify existing student records.
- **Delete Student Record**: Delete a student record based on the roll number.
- **Backup Database**: Creates a backup of the database.
- **Exit System**: Exits the program gracefully.

## System Requirements
- **Operating System**: Windows (uses Turbo C++ for graphics)
- **Compiler**: Turbo C++ (or any C compiler that supports Turbo C++ graphics)
- **Graphics Support**: Turbo C++ BGI library

## Installation
1. **Install Turbo C++**: Download and install Turbo C++ on your machine.
2. **Download the Project**: Clone or download the project files.
3. **Copy the Files**: Copy the project files to your Turbo C++ directory, ensuring the graphics libraries are set up correctly.
4. **Compile and Run**: Open the Turbo C++ IDE, open the project, and compile and run the program.

## How to Use
1. **Login**: On starting the program, you will be prompted to enter a password. The default password is `admin`. You can modify this in the `password_input` function.
2. **Main Menu**: After logging in, you will be presented with the main menu, where you can select various options:
   - Add new student records
   - Search for student records
   - Modify or delete student records
   - Display all stored records
   - Backup the database
3. **Operations**: Enter your choice by selecting the appropriate option from the menu.
4. **Exit**: To exit the program, select the exit option from the main menu.

## Code Overview
### Key Functions:
- `login_window()` and `password_input()`: Handles the login system.
- `add_student_record()`: Adds a new student record to the system.
- `search_student_record()`: Searches for a specific student using their roll number.
- `modify_student_record()`: Allows modification of student details.
- `delete_student_record()`: Deletes a student record.
- `display_data()`: Displays all student records.
- `backup_database()`: Backs up the database to a separate file.
- `exit_system()`: Exits the application.

### Data Structure:
The system uses a structure `STUDENT` to hold student details, including:
- **ROLL_NO**: Roll number of the student.
- **F_NAME**: First name of the student.
- **L_NAME**: Last name.
- **SEX**: Gender.
- **COURSE_NAME**: Course enrolled.
- **ADMISSION DATE**: Date of admission.
- **MOBILE_NO**: Contact number.
- **FEES**: Fees paid.
- **MARKS**: Marks obtained.
- **ADDRESS**: Stores street, city, country, and PIN code.

### File Handling:
- The student records are stored in a file `DATABASE.DAT`.
- A backup is created using `BACKUP.DAT`.
- Temporary files are used for modifying and deleting records.
