#include <stdio.h>
#include <string.h>

#define MAX_VOLUNTEERS 100
#define MAX_EVENTS 10
#define MAX_LENGTH 50

//Struct representing volunteer//
typedef struct 
{
    char name[MAX_LENGTH];
    char skill[MAX_LENGTH];
    char interest[MAX_LENGTH];
    char location[MAX_LENGTH];
    int hours;
} Volunteer;

//Struct representing event//
typedef struct 
{
    char title[MAX_LENGTH];
    char interestedskill[MAX_LENGTH];
    char location[MAX_LENGTH];
    int requiredHours;
} Event;

//Arrays and counters//
Volunteer volunteers[MAX_VOLUNTEERS];
Event events[MAX_EVENTS];

int volunteerCount = 0;
int eventCount = 0;

//Save volunteer to volunteers.txt file, logged to have access later//
void volunteerSave(Volunteer vData)
{
    FILE *vmsA = fopen("volunteers.txt", "a");
    if (vmsA == NULL)
    {
        printf("\nCould not open file, extiing now.\n");
        return;
    }
    fprintf(vmsA, "New Volunteer: \n");
    fprintf(vmsA, "Name: %s\n", vData.name);
    fprintf(vmsA, "Skill: %s\n", vData.skill);
    fprintf(vmsA, "Interest: %s\n", vData.interest);
    fprintf(vmsA, "Location: %s\n\n", vData.location);

    fclose(vmsA);
}

//Save volunteer data to file to be easily read by computer//
void vSave(Volunteer vData)
{
    FILE *vmsA = fopen("vSave.txt", "a");
    if (vmsA == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    fprintf(vmsA, "%s;%s;%s;%s;%d", vData.name, vData.skill, vData.interest, vData.location, vData.hours);

    fclose(vmsA);
}

//Load past volunteer data//
void vLoad()
{
    FILE *vmsA = fopen("vSave.txt", "r");
    if (vmsA == NULL)
    {
        printf("\nNo saved volunteer data found.\n");
        return;
    }

    while (fscanf(vmsA, "%[^;];%[^;];%[^;];%[^;];%d", 
    volunteers[volunteerCount].name, volunteers[volunteerCount].skill, volunteers[volunteerCount].interest,
    volunteers[volunteerCount].location, &volunteers[volunteerCount].hours) == 5)
    {
        volunteerCount++;
        if (volunteerCount >= MAX_VOLUNTEERS)
        break;
    }

    fclose(vmsA);
    printf("\nVolunteer data loaded successfully.\n");

}

//Save event to events.txt file//
void eventSave(Event eData)
{
    FILE *vmsA = fopen("events.txt", "a");
    if (vmsA == NULL)
    {
        printf("\nCould not open file. Exiting now.\n");
        return;
    }
    fprintf(vmsA, "New Event: \n");
    fprintf(vmsA, "Title: %s\n", eData.title);
    fprintf(vmsA, "Skill required: %s\n", eData.interestedskill);
    fprintf(vmsA, "Location: %s\n", eData.location);
    fprintf(vmsA, "Required hours: %d\n\n", eData.requiredHours);

    fclose(vmsA);

}

//Save event data to be read by computer//
void eSave(Event eData)
{
    FILE *vmsA = fopen("eSave.txt", "a");
    if (vmsA == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    fprintf(vmsA, "%s;%s;%s;%d", eData.title, eData.interestedskill, eData.location, eData.requiredHours);
    fclose(vmsA);
}

//Load in past event information//
void eLoad()
{
    FILE *vmsA = fopen("eSave.txt", "r");
    if (vmsA == NULL)
    {
        printf("No saved event data found.\n");
        return;
    }

    while (fscanf(vmsA, "%[^;];%[^;];%[^;];%d", 
    events[eventCount].title, events[eventCount].interestedskill, events[eventCount].location, &events[eventCount].requiredHours) == 4)
    {
        eventCount++;
        if (eventCount >= MAX_EVENTS)
        break;
    }

    fclose(vmsA);
    printf("Event data loaded successfully.\n");

}

// Register a new volunteer
void registerVolunteer() 
{
    if (volunteerCount >= MAX_VOLUNTEERS) 
    {
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

    //Save to file//
    volunteerSave(volunteers[volunteerCount -1 ]);
    vSave(volunteers[volunteerCount -1]);

    printf("\nRegistration successful!\n");
}

// Add a new event
void addEvent() 
{
    if (eventCount >= MAX_EVENTS) 
    {
        printf("Event limit reached.\n");
        return;
    }

    printf("\n--- Add New Event ---\n");
    printf("Event Title: ");
    scanf(" %[^\n]", events[eventCount].title);

    printf("Interest skills (Medical, Logistics, Education): ");
    scanf(" %[^\n]", events[eventCount].interestedskill);

    printf("Location: ");
    scanf(" %[^\n]", events[eventCount].location);

    printf("Required Hours: ");
    scanf("%d", &events[eventCount].requiredHours);

    eventCount++;

    //Save to file//
    eventSave(events[eventCount -1]);
    eSave(events[eventCount- 1]);

    printf("\nEvent added successfully!\n");
}

// Notify matching volunteers
void notifyVolunteers() 
{
    printf("\n--- Notifying Volunteers About Matching Events ---\n");

    for (int i = 0; i < volunteerCount; i++) 
    {
        printf("\nChecking matches for %s...\n", volunteers[i].name);
        int matchFound = 0;

        for (int j = 0; j < eventCount; j++) 
        {
            if (strcmp(volunteers[i].interest, events[j].interestedskill) == 0 &&
                strcmp(volunteers[i].location, events[j].location) == 0) 
            {
                printf("🔔 %s is a good match for event: %s\n", volunteers[i].name, events[j].title);
                matchFound = 1;
            }
        }

        if (!matchFound) 
        {
            printf("No matching events found for %s.\n", volunteers[i].name);
        }
    }
}

//Display events//
void viewEvents() 
{
    char name[MAX_LENGTH];
    int Events;

    if (eventCount == 0)
    {
        printf("\nNo events found.\n");
        return;
    }

    printf("\n--- View Events ---\n");
    for (int i = 0; i < eventCount; i++)
    {
        printf("Event #%d: \n", i +1);
        printf("%s\n", events[i].title);
        printf("Required Skill: %s\n", events[i].interestedskill);
        printf("Location: %s\n", events[i].location);
        printf("Required hours: %d\n\n", events[i].requiredHours);
    }

}

// Display volunteer records
void viewVolunteers() 
{
    printf("\n--- Volunteer List ---\n");
    if (volunteerCount == 0)
    {
        printf("\nNo volunteers listed.\n");
        return;
    }
    
    for (int i = 0; i < volunteerCount; i++) 
    {
        printf("Name: %s | Skill: %s | Interest: %s | Location: %s\n",
            volunteers[i].name, volunteers[i].skill, volunteers[i].interest, 
            volunteers[i].location);
    }
}

int main() 
{
    vLoad();
    eLoad();
    int choice;

    while (1) 
    {
        //Actions menu and selection//
        printf("\n--- Volunteer Management Menu ---\n");
        printf("1. Register Volunteer\n");
        printf("2. Add Event\n");
        printf("3. Notify Volunteers of Opportunities\n");
        printf("4. View your Events\n");
        printf("5. View Volunteers\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1: registerVolunteer(); break;
            case 2: addEvent(); break;
            case 3: notifyVolunteers(); break;
            case 4: viewEvents(); break;
            case 5: viewVolunteers(); break;
            case 6: return 0;
            default: printf("\nInvalid choice. Try again.\n");
        }
    }

    return 0;
}


