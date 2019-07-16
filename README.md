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
struct Person {
	char firstName[50];
	char lastName[50];
	char streetAddress[60];
	char cityName[30];
	char stateName[40];
	char zipCode[40];
	char phoneNumber[40];
	char emailAdddress[60];
};
 
//Prototypes 
void addContact(Person *person); 
void searchContact(); 
void deleteContact(); 
void viewAllContacts(); 




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
    FILE* tmpfile(void);
    // Struct Variable
    Person person;
	
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
        addContact(&person); 
        break; 
    case 2: 
        searchContact(); 
        break; 
    case 3: 
        deleteContact(); 
        break; 
    case 4: 
        viewAllContacts(); 
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
void addContact(Person *person) {
	system("cls");
	printf("Please enter the First Name of the contact: ");
	scanf("%s", &person->firstName);
	printf("\nPlease enter the Last Name of the contact: ");
	scanf("%s", &person->lastName);
	printf("\nPlease enter the Street Name of the contact: ");
	scanf(" %[^\n]", &person->streetAddress);
	printf("\nPlease enter the City Name of the contact: ");
	scanf("%s", &person->cityName);
	printf("
	
	printf("%s", &person->streetAddress);
	system("pause");

}

void searchContact() {
	
}

void deleteContact() {
	
}

void viewAllContacts() {
	
}

 
