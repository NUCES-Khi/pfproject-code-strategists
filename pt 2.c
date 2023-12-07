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

void print(int n) {
    int k;
    for(k = 1; k <= n; k++){
        printf("_");
    }
}

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
   