#include <stdio.h>
#include <string.h>

#define MAX_VOLUNTEERS 100
#define MAX_EVENTS 10
#define MAX_LENGTH 50

typedef struct {
    char name[MAX_LENGTH];
    char skill[MAX_LENGTH];
    char interest[MAX_LENGTH];
    char location[MAX_LENGTH];
    int hours;
} Volunteer;

typedef struct {
    char title[MAX_LENGTH];
    char interestTag[MAX_LENGTH];
    char location[MAX_LENGTH];
    int requiredHours;
} Event;

Volunteer volunteers[MAX_VOLUNTEERS];
Event events[MAX_EVENTS];

int volunteerCount = 0;
int eventCount = 0;

// Register a new volunteer
void registerVolunteer() {
    if (volunteerCount >= MAX_VOLUNTEERS) {
        printf("Volunteer limit reached.\n");
        return;
    }

    printf("\n--- Register a Volunteer ---\n");
    printf("Name: ");
    scanf(" %[^\n]", volunteers[volunteerCount].name);

    printf("Skill: ");
    scanf(" %[^\n]", volunteers[volunteerCount].skill);

    printf("Interest Area (e.g., Medical, Logistics, Education): ");
    scanf(" %[^\n]", volunteers[volunteerCount].interest);

    printf("Location: ");
    scanf(" %[^\n]", volunteers[volunteerCount].location);

    volunteers[volunteerCount].hours = 0;
    volunteerCount++;

    printf("Registration successful!\n");
}

// Add a new event
void addEvent() {
    if (eventCount >= MAX_EVENTS) {
        printf("Event limit reached.\n");
        return;
    }

    printf("\n--- Add New Event ---\n");
    printf("Event Title: ");
    scanf(" %[^\n]", events[eventCount].title);

    printf("Interest Tag (Medical, Logistics, Education): ");
    scanf(" %[^\n]", events[eventCount].interestTag);

    printf("Location: ");
    scanf(" %[^\n]", events[eventCount].location);

    printf("Required Hours: ");
    scanf("%d", &events[eventCount].requiredHours);

    eventCount++;

    printf("Event added successfully!\n");
}

// Notify matching volunteers
void notifyVolunteers() {
    printf("\n--- Notifying Volunteers About Matching Events ---\n");

    for (int i = 0; i < volunteerCount; i++) {
        printf("\nChecking matches for %s...\n", volunteers[i].name);
        int matchFound = 0;

        for (int j = 0; j < eventCount; j++) {
            if (strcmp(volunteers[i].interest, events[j].interestTag) == 0 &&
                strcmp(volunteers[i].location, events[j].location) == 0) {
                printf("🔔 %s is a good match for event: %s\n", volunteers[i].name, events[j].title);
                matchFound = 1;
            }
        }

        if (!matchFound) {
            printf("No matching events found for %s.\n", volunteers[i].name);
        }
    }
}

// Log volunteer hours
void logVolunteerHours() {
    char name[MAX_LENGTH];
    int hours;

    printf("\n--- Log Volunteer Hours ---\n");
    printf("Enter volunteer name: ");
    scanf(" %[^\n]", name);

    int found = 0;

    for (int i = 0; i < volunteerCount; i++) {
        if (strcmp(name, volunteers[i].name) == 0) {
            printf("Enter hours to log: ");
            scanf("%d", &hours);
            volunteers[i].hours += hours;
            printf("Hours updated! Total: %d hours\n", volunteers[i].hours);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Volunteer not found.\n");
    }
}

// View all volunteer records
void viewVolunteers() {
    printf("\n--- Volunteer List ---\n");
    for (int i = 0; i < volunteerCount; i++) {
        printf("Name: %s | Skill: %s | Interest: %s | Location: %s | Hours: %d\n",
            volunteers[i].name, volunteers[i].skill, volunteers[i].interest, 
            volunteers[i].location, volunteers[i].hours);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Volunteer Management Menu ---\n");
        printf("1. Register Volunteer\n");
        printf("2. Add Event\n");
        printf("3. Notify Volunteers of Opportunities\n");
        printf("4. Log Volunteer Hours\n");
        printf("5. View Volunteers\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: registerVolunteer(); break;
            case 2: addEvent(); break;
            case 3: notifyVolunteers(); break;
            case 4: logVolunteerHours(); break;
            case 5: viewVolunteers(); break;
            case 6: return 0;
            default: printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}


    displayGroups(volunteers, num);

    return 0;
}
