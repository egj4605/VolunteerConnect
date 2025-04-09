#include <stdio.h>
#include <string.h>

#define MAX_VOLUNTEERS 100
#define MAX_NAME_LENGTH 50
#define MAX_SKILL_LENGTH 50

typedef struct 
{
    char name[MAX_NAME_LENGTH];
    char skill[MAX_SKILL_LENGTH];
    int taskChoice;
} Volunteer;

void displayTasks() 
{
    printf("\nAvailable Tasks:\n");
    printf("1. Event Setup\n");
    printf("2. Food Distribution\n");
    printf("3. First Aid Support\n");
}

void displayGroups(Volunteer volunteers[], int count) 
{
    printf("\n--- Volunteer Groups ---\n");

    for (int i = 1; i <= 3; i++) 
    {
        printf("\nTask %d Group:\n", i);
        for (int j = 0; j < count; j++) 
        {
            if (volunteers[j].taskChoice == i) 
            {
                printf("Name: %s | Skill: %s\n", volunteers[j].name, volunteers[j].skill);
            }
        }
    }
}

int main() {
    int num;
    Volunteer volunteers[MAX_VOLUNTEERS];

    printf("Enter number of volunteers: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        printf("\n--- Enter details for Volunteer %d ---\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", volunteers[i].name); 

        printf("Skill (e.g., Communication, Medical, Logistics): ");
        scanf(" %[^\n]", volunteers[i].skill);

        displayTasks();
        printf("Select Task (1-3): ");
        scanf("%d", &volunteers[i].taskChoice);

        if (volunteers[i].taskChoice < 1 || volunteers[i].taskChoice > 3) {
            printf("Invalid task selected. Assigning default task (1).\n");
            volunteers[i].taskChoice = 1;
        }
    }

    displayGroups(volunteers, num);

    return 0;
}
