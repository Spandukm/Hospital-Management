#pragma warning (disable:4996) // disables error-4996 in visual studio
#include "include/display_single_visitor.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* This function reads the file "visitor_info.csv" and finds a patient by
his name and phone number which is the input to this function. If the patient is found 
it displays the visitor information of the visitor who visited the specific patient.
If the patient is not found it will display appropriate message. The function returns zero
displaying appropriate message to the console window and returns to main.

*/
int display_single_visitor(char *name, char *ph)
{
    // File pointer to open the given file
    FILE *fp=fopen("visitor_info.csv","r");

    // Character array string with size 1024 to read a line from a file.
	char string[1024];

    // Character pointer token and field.
	char *token,*field;

    // integer variable row_count and field_count to keep count of coloum initialted at 0.
    int row_count = 0;
    int field_count = 0;

    // Checking if file is found.
     if (!fp) {
        printf("Can't open file\n");
        return 0;
     }

     //Searching the file and displaying the appropriate message on the console window
    while (fgets(string, 1024, fp)){
            field_count = 0;
            row_count++;
            if (row_count == 1){
                continue;
            }
            field = strtok(string, ",");
            token = strtok(NULL, ",");

            //If patient is found display the corresponding patient's visitor information
            if(strcmp(token,name)==0){
                while (field){
                    if (field_count == 0) {
                    printf("ID:");
                    }
                    if (field_count == 1) {
                    printf("Patient name:");
                    printf("%s\n",name);
                    field_count++;
                    }
                    if (field_count == 2) {
                    printf("Patient phone number:");
                    }
                    if (field_count == 3) {
                    printf("Visitor name:");
                    }
                    if (field_count == 4) {
                    printf("Visitor address:");
                    }
                    if (field_count == 5) {
                    printf("Visitor phone number:");
                    }
                    if(field_count<6){
                        printf("%s\n",field);
                        field = strtok(NULL, ",");
                        field_count++;
                    }
                }break;
            }

            //if no recoed is found.
            else
            {
                printf("\nNo record found!");
            }
        }
    // closing the file.
    fclose(fp);
    return 0;
}
