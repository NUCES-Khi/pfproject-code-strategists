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

struct maintenance {
    char engineIssues;
    char breaksIssues;
    char infrastructureIssues;
    char trackIssue;
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
    char bookingDate[50];
    char bookingType[20];
    char destination[20];
    char departure[20];
    char arrival[20];
};

// Function to check train status
void checkTrainStatus(struct Train *train) {
    if (train->trainStatus.isDelayed) {
        printf("is delayed.\n");
    } else {
        printf("is on time.\n");
    } 
}

// Function to check booking type
void checkBookingType(struct Passenger *passenger) {
    printf("Booking type for passenger %s is %s.\n", passenger->name, passenger->bookingType);
}

// Function to initialize a train with random status
void initializeStatus(struct Train *train) {
    // Generate random status for the train
    train->trainStatus.isDelayed = rand() % 2;      // 0 or 1
    train->trainStatus.isCancelled = rand() % 2;    // 0 or 1
    train->trainStatus.hasArrived = rand() % 2;      // 0 or 1
}
//Function to initialize train 
void initializeTrain(struct Train *trains, int trainsNumber) {
    // Allow the user to input train information 
    printf("\nEnter information for Train %d\n", trainsNumber);
    // train information number
    printf("Enter train number: ");
    scanf("%d", &trains->trainNumber);

    // Input train name
    printf("Enter train name: ");
    scanf("%s", &trains->trainName);
}

// Function to initialize a passenger
void initializePassenger(struct Passenger *passenger, int passengerNumber) {
    // Allow the user to input passenger information
    printf("\nEnter information for Passenger %d \n", passengerNumber);

    // Input passenger name
    printf("Enter passenger name: ");
    scanf("%s", &passenger->name);

    // Input booking date and type
    printf("Enter booking date: ");
    scanf("%s", &passenger->bookingDate);

    printf("Enter booking type: ");
    scanf("%s", &passenger->bookingType);
    
    printf("Enter arrival: ");
    scanf("%s", &passenger->arrival);
    
     printf("Enter departure: ");
    scanf("%s", &passenger->departure);
}
void print(int n) {
    int k;
    for(k = 1; k <= n; k++){
        printf("_");
    }
}

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Example: Asking for information for n passengers 
    int n;  // Number of passengers and trains
    printf("Enter the number of passengers: ");
    scanf("%d", &n);
    printf("\n\n");
    
    // Example: Asking for information for x trains
    int x; //Number of trains
    printf("Enter the number of trains: ");
    scanf("%d", &x);
    printf("\n\n");

    // Array to store train information
    struct Train trains[x];

    // Input train information
    for (int i = 0; i < x; i++) {
        initializeTrain(&trains[i], i + 1);
        printf("\n\n");
    }

    // Array to store passenger information
    struct Passenger passengers[n];

    // Input passenger information
    for (int i = 0; i < n; i++) {
        initializePassenger(&passengers[i], i + 1);
        printf("\n\n");
    }
    
    
    // Display train information
    printf("\n\nTHE INFORMATION OF TRAIN IS AS FOLLOWS\n\n");
    
    print(50);
    printf("\n\tTrain number\tTrain name\t\tTrain Status\n");
    print(50);
    printf("\n");
    
    for (int i = 0; i < x; i++) {
        printf("\t%d", trains[i].trainNumber);
        printf("\t\t|\t\t");
        printf("%s", trains[i].trainName);
        printf("\t\t|\t\t");
        checkTrainStatus(&trains[i]);
        printf("\n");
    }
    print(50);
    
// Display paseenger information
    printf("\n\nTHE INFORMATION OF THE PASSENGERS IS AS FOLLOWS\n\n");
    
    print(60);
    printf("\n\nS.NO\tName\tDate\t\ttype\tdeparture\t\tarrival\n");
    print(60);
    printf("\n");
    
    for (int i = 0; i < n; i++) {
        printf("%d", i+1);
        printf("\t|%s", passengers[i].name);
        printf("\t|\t");
        printf("%s", passengers[i].bookingDate);
        printf("\t|\t");
        printf("%s", passengers[i].bookingType);
         printf("\t|\t");
        printf("%s", passengers[i].departure);
         printf("\t|\t");
        printf("%s", passengers[i].arrival);
        printf("\n");
    }
    print(60);
    
    return 0;
}