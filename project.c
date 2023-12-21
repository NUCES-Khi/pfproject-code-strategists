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
