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