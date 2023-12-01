#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a structure for storing schedule
struct Schedule {
    int morning;
    int afternoon;
    int day;
    int night;
};

// Define a structure for storing status of the train
struct Status {
    char isDelayed;
    char isCancelled;
    char hasArrived;
};

// Define a structure for storing train information
struct Train {
    int trainNumber;
    char trainName[50];
    struct Schedule trainSchedule;
    struct Status trainStatus;
};

// Define a structure for storing passenger information
struct Passenger {
    char name[50];
    int bookingDate;
    char bookingType[20];
};

// Function to check train status
void checkTrainStatus(struct Train *train) {
    if (train->trainStatus.isDelayed) {
        printf("Train %d (%s) is delayed.\n", train->trainNumber, train->trainName);
    } else {
        printf("Train %d (%s) is on time.\n", train->trainNumber, train->trainName);
    }
}

// Function to check booking type
void checkBookingType(struct Passenger *passenger) {
    printf("Booking type for passenger %s is %s.\n", passenger->name, passenger->bookingType);
}

// Function to initialize a train with random status
void initializeTrainWithRandomStatus(struct Train *train, int number, const char *name, int morning, int afternoon, int day, int night) {
    train->trainNumber = number;
    strcpy(train->trainName, name);
    train->trainSchedule.morning = morning;
    train->trainSchedule.afternoon = afternoon;
    train->trainSchedule.day = day;
    train->trainSchedule.night = night;

    // Generate random status for the train
    train->trainStatus.isDelayed = rand() % 2;      // 0 or 1
    train->trainStatus.isCancelled = rand() % 2;    // 0 or 1
    train->trainStatus.hasArrived = rand() % 2;      // 0 or 1
}

// Function to initialize a passenger
void initializePassenger(struct Passenger *passenger, int passengerNumber) {
    // Allow the user to input passenger information
    printf("\nEnter information for Passenger %d:\n", passengerNumber);

    // Input passenger name
    printf("Enter passenger name: ");
    scanf("%s", passenger->name);

    // Input booking date and type
    printf("Enter booking date: ");
    scanf("%d", &passenger->bookingDate);

    printf("Enter booking type: ");
    scanf("%s", passenger->bookingType);
}

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Example: Asking for information for n passengers and n trains
    int n;  // Number of passengers and trains
    printf("Enter the number of passengers and trains: ");
    scanf("%d", &n);

    // Array to store train information
    struct Train trains[n];

    // Input train information
    for (int i = 0; i < n; i++) {
        printf("\nEnter information for Train %d:\n", i + 1);
        initializeTrainWithRandomStatus(&trains[i], i + 1, "Express", 1200, 0, 0, 0);
    }

    // Array to store passenger information
    struct Passenger passengers[n];

    // Input passenger information
    for (int i = 0; i < n; i++) {
        initializePassenger(&passengers[i], i + 1);
    }

    // Display train information
    for (int i = 0; i < n; i++) {
        printf("\nTrain %d Information:\n", i + 1);
        checkTrainStatus(&trains[i]);
    }

    // Display passenger information
    for (int i = 0; i < n; i++) {
        printf("\nPassenger %d Information:\n", i + 1);
        checkBookingType(&passengers[i]);
    }

    return 0;
}
