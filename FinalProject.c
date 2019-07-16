/* 
 * File Name:       
 * Name:            
 * Course:         COP 2220C at Valencia College 
 * Facilitator:    David Stendel 
 * Description:     
 * Team Members:   Scott Willard, Gopal Ghosh, Isaiah Payne 
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
	char cityName[30];
	char stateName[40];
	char zipCode[10];
	char phoneNumber[12];
	char emailAddress[60];
};
 
//Prototypes 
void addContact(Person *person); 
void searchContact(); 
void deleteContact(); 
void viewAllContacts(); 




/* 
 * Name:           main() 
 * Parameters:     None. 
 * Processes:      Hosts a functional contact book where the user my Create, Retrieve, Update, or Delete contacts.
 * Return Value:   None.                  
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
        searchContact(); 
        break; 
    case 3: 
        deleteContact(); 
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
 * Name:           main() 
 * Parameters:     None. 
 * Processes:       
 * Return Value:   An integer representing an error code; if the program ends without       
 *                 error, zero will be returned to the calling program or operating *      
 *                 system. 
 */ 

/* 
 * Name:           addContact() 
 * Parameters:     *person Passing the struct variable through the function.
 * Processes:      Creates and stores the Name, Address, Phone Number, and Email Address of the contact.
 * Return Value:   None.   
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
	
    fprintf(pb, "%s %s %s %s %s %s %s %s", person->firstName, person->lastName, person->streetAddress, person->cityName, person->stateName, person->zipCode, person->phoneNumber, person->emailAddress);
    
    fclose(pb);
	
	system("pause");

}

void searchContact() {
	
}

void deleteContact() {
	
}

/* 
 * Name:           viewAllContacts() 
 * Parameters:     *person Passes the struct variable through the function.
 * Processes:       List all contacts that are contained within the contact book.
 * Return Value:   None.   
 */ 
void viewAllContacts(Person person) {
    //Local Variables 
    FILE *pb;     
    pb = fopen("contacts.txt", "r"); 
    system("cls"); 
    printf("-----All Contacts-----"); 
    while (fscanf(pb, "%s %s %s %s %s %s %s %s", person.firstName, person.lastName, person.streetAddress, person.cityName, person.stateName, person.zipCode, person.phoneNumber, person.emailAddress) != EOF) { 
        printf("\n Name    :  %s %s", person.firstName, person.lastName); 
        printf("\n Street  :  %s", person.streetAddress); 
        printf("\n City    :  %s", person.cityName);
        printf("\n State   :  %s", person.stateName);
        printf("\n ZipCode :  %s", person.zipCode);
        printf("\n Phone # :  %s", person.phoneNumber);
        printf("\n Email @ :  %s", person.emailAddress);
    } 

    fclose(pb); 

    system("pause");
}

 
