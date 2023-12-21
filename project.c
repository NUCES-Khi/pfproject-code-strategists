#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TRAINS 20
#define MAX_CARRIAGES 3
#define MAX_SEATS_PER_CARRIAGE 20
#define MAX_PASSENGERS 500
#define MAX_NAME_LENGTH 50
#define MAX_DEST_LENGTH 50
// Structures
struct Carriage {
    int availableSeats;
    int bookedSeats[MAX_SEATS_PER_CARRIAGE];
};
struct Train {
    int trainNumber;
    char name[MAX_NAME_LENGTH];
    char destination[MAX_DEST_LENGTH];
    struct Carriage carriages[MAX_CARRIAGES];
};
struct Passenger {
    char name[MAX_NAME_LENGTH];
    int age;
    int seatNumber;
    int trainNumber;
};
// Function prototypes
void displayMenu();
void displayTrainDetails(struct Train train);
void displayAllTrains(struct Train trains[], int numTrains);
void bookTicket(struct Train trains[], int numTrains, struct Passenger passengers[], int* numPassengers);
void displayPassengerDetails(struct Passenger passenger);
void displayAllPassengers(struct Passenger passengers[], int numPassengers);
void saveDataToFile(struct Train trains[], int numTrains, struct Passenger passengers[], int numPassengers);
void loadDataFromFile(struct Train trains[], int* numTrains, struct Passenger passengers[], int* numPassengers);

// File names
const char* trainsFile = "trains.txt";
const char* passengersFile = "passengers.txt";
int main() {
    struct Train trains[MAX_TRAINS];
    struct Passenger passengers[MAX_PASSENGERS];
    int numTrains = 0;
    int numPassengers = 0;


    // Load data from files
    loadDataFromFile(trains, &numTrains, passengers, &numPassengers);

    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                displayAllTrains(trains, numTrains);
                break;
            case 2:
                bookTicket(trains, numTrains, passengers, &numPassengers);
                break;
            case 3:
                displayAllPassengers(passengers, numPassengers);
                break;
            case 4:
                saveDataToFile(trains, numTrains, passengers, numPassengers);
                break;
            case 5:
                // Exit
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}
void displayMenu() {
    printf("\nRAILWAY MANAGEMENT SYSTEM\n");
    printf("1. Display All Trains\n");
    printf("2. Book a Ticket\n");
    printf("3. Display All Passengers\n");
    printf("4. Save Data to Files\n");
    printf("5. Exit\n");
}
void displayTrainDetails(struct Train train) {
    printf("Train Number: %d\n", train.trainNumber);
    printf("Train Name: %s\n", train.name);
    printf("Destination: %s\n", train.destination);
    printf("Carriages:\n");
    for (int i = 0; i < MAX_CARRIAGES; i++) {
        printf("Carriage %d: Available Seats: %d\n", i+1, train.carriages[i].availableSeats);
    }
}
void displayAllTrains(struct Train trains[], int numTrains) {
    printf("\nAll Trains:\n");
    for (int i = 0; i < numTrains; i++) {
        displayTrainDetails(trains[i]);
        printf("\n");
    }
}
void bookTicket(struct Train trains[], int numTrains, struct Passenger passengers[], int* numPassengers) {
    // Implement the ticket booking logic
    int selectedTrain;
    displayAllTrains(trains, numTrains);
    printf("Enter the train number you want to book: ");
    scanf("%d", &selectedTrain);

    if (selectedTrain < 1 || selectedTrain > numTrains) {
        printf("Invalid train number. Please try again.\n");
        return;
    }

    struct Train* selectedTrainPtr = &trains[selectedTrain - 1];

    int selectedCarriage;
    printf("Select a carriage (1-%d): ", MAX_CARRIAGES);
    scanf("%d", &selectedCarriage);

    if (selectedCarriage < 1 || selectedCarriage > MAX_CARRIAGES) {
        printf("Invalid carriage number. Please try again.\n");
        return;
    }
    struct Carriage* selectedCarriagePtr = &selectedTrainPtr->carriages[selectedCarriage - 1];
    if (selectedCarriagePtr->availableSeats == 0) {
        printf("All seats in this carriage are booked. Choose another carriage.\n");
        return;
    }

    printf("Enter passenger name: ");
    scanf("%s", passengers[*numPassengers].name);

    printf("Enter passenger age: ");
    scanf("%d", &passengers[*numPassengers].age);

    selectedCarriagePtr->bookedSeats[selectedCarriagePtr->availableSeats - 1] = *numPassengers + 1;
    passengers[*numPassengers].seatNumber = selectedCarriagePtr->bookedSeats[selectedCarriagePtr->availableSeats - 1];
    passengers[*numPassengers].trainNumber = selectedTrainPtr->trainNumber;

    selectedCarriagePtr->availableSeats--;

    (*numPassengers)++;

    printf("Ticket booked successfully!\n");
}
void displayPassengerDetails(struct Passenger passenger) {
    printf("Passenger Name: %s\n", passenger.name);
    printf("Age: %d\n", passenger.age);
    printf("Seat Number: %d\n", passenger.seatNumber);
    printf("Train Number: %d\n", passenger.trainNumber);
}
void displayAllPassengers(struct Passenger passengers[], int numPassengers) {
    printf("\nAll Passengers:\n");
    for (int i = 0; i < numPassengers; i++) {
        displayPassengerDetails(passengers[i]);
        printf("\n");
    }
}
void saveDataToFile(struct Train trains[], int numTrains, struct Passenger passengers[], int numPassengers) {
    // Implement saving data to files
    FILE* trainsFilePtr = fopen("trains.txt", "w");
    FILE* passengersFilePtr = fopen("passengers.txt", "w");

    if (trainsFilePtr == NULL || passengersFilePtr == NULL) {
        printf("Error opening files for writing.\n");
        return;
    }

    // Save train data
    for (int i = 0; i < numTrains; i++) {
     fprintf(trainsFilePtr, "%d,%s,%s", trains[i].trainNumber, trains[i].name, trains[i].destination);
      for (int j = 0; j < MAX_CARRIAGES; j++) {
        fprintf(trainsFilePtr, ",%d", trains[i].carriages[j].availableSeats);
      }
     fprintf(trainsFilePtr, "\n");
}

    fclose(trainsFilePtr);

    // Save passenger data
    for (int i = 0; i < numPassengers; i++) {
        fprintf(passengersFilePtr, "%s,%d,%d,%d\n", passengers[i].name, passengers[i].age, passengers[i].seatNumber, passengers[i].trainNumber);
    }

    fclose(passengersFilePtr);

    printf("Data saved successfully.\n");
}

void loadDataFromFile(struct Train trains[], int* numTrains, struct Passenger passengers[], int* numPassengers) {
    // Implement loading data from files
    FILE* trainsFilePtr = fopen("trains.txt", "r");
    FILE* passengersFilePtr = fopen("passengers.txt", "r");

    if (trainsFilePtr == NULL || passengersFilePtr == NULL) {
        printf("Error opening files for reading.\n");
        return;
    }

 // Load train data
 // Adjust the number of format specifiers to match the actual number of items
    while (fscanf(trainsFilePtr, "%d,%49[^,],%49[^,]",&trains[*numTrains].trainNumber, trains[*numTrains].name, trains[*numTrains].destination) == 3) {
        int carriageIndex = 0;
        int seats;
        // Read available seats for each carriage dynamically until the end of the line
        while (fscanf(trainsFilePtr, ",%d", &seats) == 1) {
            if (carriageIndex < MAX_CARRIAGES) {
                trains[*numTrains].carriages[carriageIndex].availableSeats = seats;
                carriageIndex++;
            } else {
                printf("Error: Too many carriages for a train.\n");
                break;
            }
        }
        if (*numTrains >= MAX_TRAINS) {
            printf("Error: Too many trains read from the file.\n");
            break;
        }

        (*numTrains)++;
    }
    fclose(trainsFilePtr);
    // Load passenger data
    while (fscanf(passengersFilePtr, "%49[^,],%d,%d,%d\n", passengers[*numPassengers].name, &passengers[*numPassengers].age,
                  &passengers[*numPassengers].seatNumber, &passengers[*numPassengers].trainNumber) == 4) {
        (*numPassengers)++;
    }
    fclose(passengersFilePtr);
    printf("Data loaded successfully.\n");
}
