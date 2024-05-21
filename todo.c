#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    FILE *file;
    char note[256];

    printf("Enter the number from 1 to 3\n");
    printf("1. Enter a new note. \n");
    printf("2. Edit the note. \n");
    printf("3. Delete the note. \n");
    printf("4. Read note\n");

    scanf("%d", &choice);

    if(choice < 1 || choice > 4) {
        printf("Invalid number. You can only select a number between 1 and 4.\n");
    } else {
        printf("You have selected: %d\n", choice);
        if(choice == 1) {
            printf("Enter your note: ");
            getchar();
            fgets(note, sizeof(note), stdin); 
            
            file = fopen("note.txt", "w");
            if(file == NULL) {
                printf("Error opening file!\n");
                return 1;
            }
            
            fprintf(file, "%s", note);
            
            fclose(file);
            
            printf("Note saved successfully to note.txt\n");
        } else if (choice == 2) {
            file = fopen("note.txt", "r+");
            if (file == NULL) {
                printf("Error opening file! Make sure the file exists.\n");
                return 1;
            }

            printf("Current content of the note:\n");
            while (fgets(note, sizeof(note), file) != NULL) {
                printf("%s", note);
            }

            printf("\nEnter new content for the note: ");
            getchar(); 
            fgets(note, sizeof(note), stdin);

            fseek(file, 0, SEEK_SET);

            fprintf(file, "%s", note);

            fclose(file);

            printf("Note edited successfully.\n");
            
        }  else if(choice == 3) {
                if(remove("note.txt")==0){
                    printf("Your note has been deleted.");
                }else{
                    printf("There was some error in deleting the note.");
                }
        } else if (choice == 4) {
            file = fopen("note.txt", "r");
            if (file == NULL) {
                printf("Error opening file! Make sure the file exists.\n");
                return 1;
            }

            printf("Reading note from note.txt:\n");
            while (fgets(note, sizeof(note), file) != NULL) {
                printf("%s", note);
            }

            fclose(file);
        }
    }
    

    return 0;
}
