#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structures section
struct Race {
    int numberOfLaps;
    int currentLap;
    char firstPlaceDriverName[50];  // Corrected: Array for storing strings
    char firstPlaceRaceCarColor[20];  // Corrected: Array for storing strings
};

struct RaceCar {
    char driverName[50];  // Corrected: Array for storing strings
    char raceCarColor[20];  // Corrected: Array for storing strings
    int totalLapTime;
};

// Print functions section
void printIntro() {
    printf("Welcome to our main event digital race fans!\n");
    printf("I hope everybody has their snacks because we are about to begin!\n");
}

void printCountDown() {
    printf("Racers Ready! In...\n");

    printf("5\n");
    printf("4\n");
    printf("3\n");
    printf("2\n");
    printf("1\n");

    printf("Race!\n");
}

void printFirstPlaceAfterLap(struct Race race) {
    printf("After lap number %d\n", race.currentLap);
    printf("First Place Is: %s in the %s race car!\n", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
}

void printCongratulations(struct Race race) {
    printf("Let's all congratulate %s in the %s race car for an amazing performance.\n", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
    printf("It truly was a great race and everybody have a goodnight!\n");
}

// Logic functions section
int calculateTimeToCompleteLap() {
    // Seed the random number generator
    srand(time(NULL));

    // Declare and initialize three variables with random numbers between 1 and 3
    int speed = rand() % 3 + 1;
    int acceleration = rand() % 3 + 1;
    int nerves = rand() % 3 + 1;

    // Return the summation of speed, acceleration, and nerves
    return speed + acceleration + nerves;
}

void updateRaceCar(struct RaceCar *raceCar) {
    // Simulate the time it took to complete a lap (generate a random time between 50 and 100 seconds)
    int lapTime = rand() % 51 + 50;

    // Update the total lap time for the race car
    raceCar->totalLapTime += lapTime;
}

void updateFirstPlace(struct Race *race, struct RaceCar *raceCar1, struct RaceCar *raceCar2) {
    if (raceCar1->totalLapTime <= raceCar2->totalLapTime) {
        // Set firstPlaceDriverName and firstPlaceRaceCarColor based on raceCar1
        snprintf(race->firstPlaceDriverName, sizeof(race->firstPlaceDriverName), "%s", raceCar1->driverName);
        snprintf(race->firstPlaceRaceCarColor, sizeof(race->firstPlaceRaceCarColor), "%s", raceCar1->raceCarColor);
    } else {
        // Set firstPlaceDriverName and firstPlaceRaceCarColor based on raceCar2
        snprintf(race->firstPlaceDriverName, sizeof(race->firstPlaceDriverName), "%s", raceCar2->driverName);
        snprintf(race->firstPlaceRaceCarColor, sizeof(race->firstPlaceRaceCarColor), "%s", raceCar2->raceCarColor);
    }
}

void startRace(struct RaceCar *raceCar1, struct RaceCar *raceCar2) {
    // Initialize a Race structure with the specified values
    struct Race race = {
        .numberOfLaps = 5,
        .currentLap = 1,
        .firstPlaceDriverName = "",
        .firstPlaceRaceCarColor = ""
    };

    // Seed the random number generator
    srand(time(NULL));

    // Start the race loop
    for (int lap = 1; lap <= race.numberOfLaps; lap++) {
        // Simulate lap times (generate random times between 50 and 100 seconds)
        raceCar1->totalLapTime += rand() % 51 + 50;
        raceCar2->totalLapTime += rand() % 51 + 50;

        // Update first place information based on lap times
        if (raceCar1->totalLapTime <= raceCar2->totalLapTime) {
            snprintf(race.firstPlaceDriverName, sizeof(race.firstPlaceDriverName), "%s", raceCar1->driverName);
            snprintf(race.firstPlaceRaceCarColor, sizeof(race.firstPlaceRaceCarColor), "%s", raceCar1->raceCarColor);
        } else {
            snprintf(race.firstPlaceDriverName, sizeof(race.firstPlaceDriverName), "%s", raceCar2->driverName);
            snprintf(race.firstPlaceRaceCarColor, sizeof(race.firstPlaceRaceCarColor), "%s", raceCar2->raceCarColor);
        }

        // Print first place information after each lap
        printf("After lap number %d, First Place Is: %s in the %s race car!\n", lap, race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
    }
    printf("Congratulations to %s in the %s race car for winning the race!\n", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
}

int main() {
    // Declare and initialize 2 RaceCar types
    struct RaceCar car1 = {"Lewis", "Silver", 0};
    struct RaceCar car2 = {"Sebastian", "Red", 0};

    // Print the race intro
    printIntro();

    // Begin the countdown
    printCountDown();

    // Call the startRace function with pointers to the RaceCar types
    startRace(&car1, &car2);

    // Enjoy the race!
    printf("Enjoy the race!\n");

    // Rest of your program...

    return 0;
}
