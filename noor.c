#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a contact
struct Contact {
    char name[100];
    char phone[20];
    struct Contact* next;
};

struct Contact* head = NULL;

// Create a new contact
struct Contact* createContact(char name[], char phone[]) {
    struct Contact* newContact = (struct Contact*)malloc(sizeof(struct Contact));
    strcpy(newContact->name, name);
    strcpy(newContact->phone, phone);
    newContact->next = NULL;
    return newContact;
}

// Add contact to the end of the list
void addContact() {
    char name[100], phone[20];
    printf("Enter name: ");
    scanf(" %[^\n]", name);
    printf("Enter phone number: ");
    scanf(" %[^\n]", phone);

    struct Contact* newContact = createContact(name, phone);

    if (head == NULL) {
        head = newContact;
    } else {
        struct Contact* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newContact;
    }

    printf("Contact added successfully!\n");
}

// Display all contacts
void displayContacts() {
    struct Contact* temp = head;
    if (temp == NULL) {
        printf("No contacts to display.\n");
        return;
    }

    printf("\n--- Contact List ---\n");
    while (temp != NULL) {
        printf("Name: %s | Phone: %s\n", temp->name, temp->phone);
        temp = temp->next;
    }
}

// Search for a contact by name
void searchContact() {
    char searchName[100];
    printf("Enter name to search: ");
    scanf(" %[^\n]", searchName);

    struct Contact* temp = head;
    int found = 0;

    while (temp != NULL) {
        if (strcmp(temp->name, searchName) == 0) {
            printf("Contact found!\n");
            printf("Name: %s | Phone: %s\n", temp->name, temp->phone);
            found = 1;
            break;
        }
        temp = temp->next;
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

// Delete a contact by name
void deleteContact() {
    char deleteName[100];
    printf("Enter name to delete: ");
    scanf(" %[^\n]", deleteName);

    struct Contact *temp = head, *prev = NULL;

    while (temp != NULL && strcmp(temp->name, deleteName) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Contact not found.\n");
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Contact deleted successfully!\n");
}

// Free memory
void freeContacts() {
    struct Contact* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main menu
int main() {
    int choice;

    while (1) {
        printf("\n--- Phonebook Menu ---\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addContact();
            break;
        case 2:
            displayContacts();
            break;
        case 3:
            searchContact();
            break;
        case 4:
            deleteContact();
            break;
        case 5:
            freeContacts();
            printf("Exiting Phonebook. Goodbye!\n");
            return 0;
        default:
            printf("Invalid choice. Try again.\n");
        }
    }
}
