/*  
* File Name: 
* Name: 
* Course:         COP 2220C at Valencia College 
* Facilitator:    David Stendel 
* Description:
* Team Members:   Scott Willard, Isaiah Payne 
* Date:
*/

// Preprocessor Directives   
#include <stdio.h>   
#include <stdlib.h>   

//Structs  
typedef struct Person Person; 
struct Person {
    char firstName[50]; 
    char lastName[50]; 
    char streetAddress[60]; 
    char cityName[40]; 
    char stateName[40]; 
    char zipCode[40]; 
    char phoneNumber[40]; 
    char emailAddress[60]; 
}; 

  

//Prototypes   
void addContact(Person *person); 
void searchContact(Person person); 
void deleteContact(Person *person); 
void viewAllContacts(Person person); 
  
/* 
* Name:           main() 
* Parameters:     None. 
* Processes:
* Return Value:   An integer representing an error code; if the program ends without 
*                 error, zero will be returned to the calling program or operating * 
*                 system. 
*/ 
  

main() { 
    // Variables  
    int exit = 0; 
    // Temporary File  

    // Struct Variable  
    Person contact; 

  

    // Menu Loop  
    while (exit == 0) { 
        system("cls"); 
        printf("-----PHONE BOOK-----\n"); 
        printf("1. Add Contact\n"); 
        printf("2. Search Contact\n"); 
        printf("3. Delete Contact\n"); 
        printf("4. View All Contacts\n"); 
        printf("5. Exit\n"); 
        printf("Select an option: "); 

  
        int option = 0; 
        scanf("%d", &option); 
        switch (option) 
        { 
        case 1: 
            addContact(&contact); 
            break; 
        case 2: 
            searchContact(contact); 
            break;
        case 3: 
            deleteContact(&contact); 
            break; 
        case 4: 
            viewAllContacts(contact); 
            break; 
        case 5: 
            exit = 1; 
            break; 
        default: 
            main(); 
        } 
    } 
    system("pause"); 
    return 0; 

} 

  

/* 
* Name:           addContact() 
* Parameters:     None. 
* Processes:      Creates a contact including all related fields for retrieval and removal if needed. 
* Return Value:   An integer representing an error code; if the program ends without 
*                 error, zero will be returned to the calling program or operating * 
*                 system. 
*/ 

void addContact(Person *person) { 
    // Local Variables  
    FILE *pb;
    pb = fopen("contacts.txt", "a+"); 

    system("cls"); 

    printf("-----Add Contact-----"); 

    printf("\nPlease enter the First Name of the contact: "); 
    scanf("%s", &person->firstName); 

    printf("\nPlease enter the Last Name of the contact: "); 
    scanf("%s", &person->lastName); 

    printf("\nPlease enter the Street Name of the contact: "); 
    scanf(" %[^\n]", &person->streetAddress); 

    printf("\nPlease enter the City Name of the contact: "); 
    scanf("%s", &person->cityName); 
  
    printf("Please enter the State Name of the contact: "); 
    scanf("%s", &person->stateName); 

    printf("Please enter the  ZIP Code of the contact: "); 
    scanf("%s", &person->zipCode); 


    printf("Please enter the phone number of the contact: "); 
    scanf("%s", &person->phoneNumber); 

    printf("Please enter the email address of the contact: "); 
    scanf("%s", &person->emailAddress); 

    fprintf(pb, "%s %s %s %s %s %s %s %s \n", person->firstName, person->lastName, person->streetAddress, person->cityName, person->stateName, person->zipCode, person->phoneNumber, person->emailAddress); 
    fclose(pb); 
    printf("\nPress any key to continue...."); 
    getch(); 
    main(); 

} 

  

/* 
* Name:            searchContact() 
* Parameters:        None. 
* Processes:        Search and find contacts within the address book by name and other values. 
* Return Value:    None. 
*/ 

void searchContact(Person person) { 

    //Local Variables 
    FILE *pb; 
    char name[20]; 
    int count = 0;

    pb = fopen("contacts.txt", "r"); 
    system("cls"); 
    printf("-----Search Contacts"); 
    printf("\nEnter the first or last Name of your contact: "); 
    scanf("%s", name); 
  
  	printf("\n-----Contacts with ''%s''", name);
    while (fscanf(pb, "%s %s %s %s %s %s %s %s", person.firstName, person.lastName, person.streetAddress, person.cityName, person.stateName, person.zipCode, person.phoneNumber, person.emailAddress) != EOF) { 
        if ((strcmp(name, person.firstName) == 0) || (strcmp(name, person.lastName) == 0)) { 
            printf("\n\n Name    :  %s %s", person.firstName, person.lastName); 
        	printf("\n Street  :  %s", person.streetAddress); 
        	printf("\n City    :  %s", person.cityName); 
        	printf("\n State   :  %s", person.stateName); 
        	printf("\n ZipCode :  %s", person.zipCode); 
        	printf("\n Phone # :  %s", person.phoneNumber); 
        	printf("\n Email @ :  %s", person.emailAddress);
        } 
    }
    printf("\n----------\n");
    
    
    fclose(pb); 
    printf("\nPress any key to continue..."); 

    getch(); 
    main(); 

} 

void deleteContact(Person *person) { 

    //Local Variables  
    FILE *pb, *pb1; 

    char name[20]; 
    char name1[20]; 

    pb = fopen("contacts.txt", "r+"); 
    pb1 = fopen("temp.txt", "w"); 
  
    system("cls"); 

    printf("-----Delete Contact-----"); 

    printf("\nEnter the first or last name of the contact: "); 
    scanf("%s", name);

  

    while (fscanf(pb, "%s %s %s %s %s %s %s %s", person->firstName, person->lastName, person->streetAddress, person->cityName, person->stateName, person->zipCode, person->phoneNumber, person->emailAddress) != EOF) { 
        if ((strcmp(name, person->firstName) == 0) || (strcmp(name, person->lastName) == 0)) { 
            continue; 
        } 
        fprintf(pb1, "%s %s %s %s %s %s %s %s \n", person->firstName, person->lastName, person->streetAddress, person->cityName, person->stateName, person->zipCode, person->phoneNumber, person->emailAddress); 
    } 

    fclose(pb); 
    fclose(pb1); 

    pb = fopen("contacts.txt", "w"); 
    pb1 = fopen("temp.txt", "r"); 

  

    while (fscanf(pb1, "%s %s %s %s %s %s %s %s", person->firstName, person->lastName, person->streetAddress, person->cityName, person->stateName, person->zipCode, person->phoneNumber, person->emailAddress) != EOF) { 
        fprintf(pb, "%s %s %s %s %s %s %s %s \n", person->firstName, person->lastName, person->streetAddress, person->cityName, person->stateName, person->zipCode, person->phoneNumber, person->emailAddress); 
    } 
    fclose(pb); 
    fclose(pb1); 
    remove("temp.txt"); 
    printf("\nPress any key to continue..."); 
    getch(); 
    main(); 

} 

void viewAllContacts(Person person) { 

    //Local Variables  
    FILE *pb; 
    pb = fopen("contacts.txt", "r"); 
    system("cls"); 

  

    printf("-----All Contacts-----"); 
    while (fscanf(pb, "%s %s %s %s %s %s %s %s", person.firstName, person.lastName, person.streetAddress, person.cityName, person.stateName, person.zipCode, person.phoneNumber, person.emailAddress) != EOF) { 
        printf("\n\n Name    :  %s %s", person.firstName, person.lastName); 
        printf("\n Street  :  %s", person.streetAddress); 
        printf("\n City    :  %s", person.cityName); 
        printf("\n State   :  %s", person.stateName); 
        printf("\n ZipCode :  %s", person.zipCode); 
        printf("\n Phone # :  %s", person.phoneNumber); 
        printf("\n Email @ :  %s", person.emailAddress); 
    } 

  

    fclose(pb); 
    printf("\nPress any key to continue...."); 
    getch(); 
    main(); 

} 

 

 
