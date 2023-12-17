[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/j0WbCUcA)
[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=13059281&assignment_repo_type=AssignmentRepo)


#### Railway Management System Project Report
### 1. Introduction
The Railway Management System is a console-based application designed to manage information related to trains, carriages, and passengers. The system enables users to view available trains, book tickets, display passenger details, and save/load data persistently from/to files.

### 2. Features
## 2.1 Display All Trains
Users can view details of all available trains, including the train number, name, destination, and information about each carriage.

## 2.2 Book a Ticket
Passengers can book tickets for a specific train and carriage. The system ensures the availability of seats and records passenger information.

## 2.3 Display All Passengers
The system allows users to view details of all passengers, including their names, ages, seat numbers, and associated train numbers.
 
## 2.4 Save Data to Files
Data related to trains and passengers can be saved to files, allowing for persistent storage and retrieval of information between program executions.

## 2.5 Exit
The system provides an option to exit the application.

### 3. Code Structure

## 3.1 Structures
Carriage: Represents a train carriage with a unique number, available seats, and an array to store booked seat numbers.
Train: Represents a train with a unique number, name, destination, and an array of carriages.
Passenger: Represents a passenger with a name, age, seat number, and associated train number.
## 3.2 Functions
displayMenu: Displays the main menu of the Railway Management System.
displayTrainDetails: Displays detailed information about a specific train, including carriage details.
displayAllTrains: Displays details of all available trains.
bookTicket: Implements the ticket booking logic, allowing passengers to select a train, carriage, and enter their details.
displayPassengerDetails: Displays detailed information about a specific passenger.
displayAllPassengers: Displays details of all passengers.
saveDataToFile: Saves train and passenger data to files for persistent storage.
loadDataFromFile: Loads train and passenger data from files, facilitating the continuation of previous sessions.
## 3.3 File Handling
The system uses fopen, fprintf, and fscanf for file handling to read and write data to files.
### 4. Improvements and Future Work
Implement additional error handling to enhance the robustness of the application.
Improve the user interface by adding more descriptive messages and options.
Allow for dynamic allocation of memory to handle an arbitrary number of trains, carriages, and passengers.
Enhance code documentation for better understanding and maintainability.
### 5. Conclusion
The Railway Management System provides a functional and user-friendly interface for managing train and passenger information. It serves as a foundation for further development and improvements to meet evolving requirements.
