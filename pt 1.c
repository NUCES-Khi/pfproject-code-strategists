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
