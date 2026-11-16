#include <stdio.h>
#include <string.h>

#define MAX 200
#define FILE_NAME "books.dat"

struct Book {
    int id;
    char name[100], author[100];
    int issued;
};

struct Book books[MAX];
int count = 0;

void saveBooks(void) {
    FILE *fp = fopen(FILE_NAME, "wb");
    if (fp == NULL) {
        printf("Error saving records!\n");
        return;
    }
    fwrite(&count, sizeof(int), 1, fp);
    fwrite(books, sizeof(struct Book), count, fp);
    fclose(fp);
}

void loadBooks(void) {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) return;

    if (fread(&count, sizeof(int), 1, fp) != 1 || count < 0 || count > MAX) {
        count = 0;
        fclose(fp);
        return;
    }
    if (fread(books, sizeof(struct Book), count, fp) != (size_t)count)
        count = 0;
    fclose(fp);
}

int findById(int id) {
    int i;
    for (i = 0; i < count; i++)
        if (books[i].id == id) return i;
    return -1;
}

void addBook(void) {
    struct Book b;
    if (count == MAX) {
        printf("Library is full!\n");
        return;
    }

    printf("Enter Book ID: ");
    scanf("%d", &b.id);

    if (findById(b.id) != -1) {
        printf("Book ID already exists!\n");
        return;
    }

    printf("Enter Book Name: ");
    scanf(" %99[^\n]", b.name);
    printf("Enter Author Name: ");
    scanf(" %99[^\n]", b.author);

    b.issued = 0;
    books[count++] = b;
    saveBooks();
    printf("Book added successfully!\n");
}

void displayBooks(void) {
    int i;
    if (count == 0) {
        printf("No books found.\n");
        return;
    }

    printf("\n%-8s %-25s %-22s %s\n", "Book ID", "Book Name", "Author", "Status");
    printf("-------------------------------------------------------------------\n");
    for (i = 0; i < count; i++)
        printf("%-8d %-25s %-22s %s\n", books[i].id, books[i].name,
               books[i].author, books[i].issued ? "Issued" : "Available");
}

void searchBook(void) {
    int choice, id, i, found = 0;
    char name[100];

    printf("1. Search by ID\n2. Search by Name\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter Book ID: ");
        scanf("%d", &id);
        i = findById(id);
        if (i == -1) printf("Book not found.\n");
        else printf("ID: %d | Name: %s | Author: %s | Status: %s\n",
                    books[i].id, books[i].name, books[i].author,
                    books[i].issued ? "Issued" : "Available");
    } else if (choice == 2) {
        printf("Enter Book Name: ");
        scanf(" %99[^\n]", name);
        for (i = 0; i < count; i++) {
            if (strstr(books[i].name, name) != NULL) {
                printf("ID: %d | Name: %s | Author: %s | Status: %s\n",
                       books[i].id, books[i].name, books[i].author,
                       books[i].issued ? "Issued" : "Available");
                found = 1;
            }
        }
        if (!found) printf("Book not found.\n");
    } else printf("Invalid choice.\n");
}

void sortBooks(void) {
    int choice, i, j, swap;
    struct Book temp;

    printf("1. Sort by Book ID\n2. Sort by Book Name\nEnter choice: ");
    scanf("%d", &choice);
    if (choice != 1 && choice != 2) {
        printf("Invalid choice.\n");
        return;
    }

    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            swap = (choice == 1)
                ? books[j].id > books[j + 1].id
                : strcmp(books[j].name, books[j + 1].name) > 0;
            if (swap) {
                temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
    saveBooks();
    printf("Books sorted successfully.\n");
    displayBooks();
}

void issueBook(void) {
    int id, i;
    printf("Enter Book ID to issue: ");
    scanf("%d", &id);
    i = findById(id);

    if (i == -1) printf("Book not found.\n");
    else if (books[i].issued) printf("Book is already issued.\n");
    else {
        books[i].issued = 1;
        saveBooks();
        printf("Book issued successfully.\n");
    }
}

void returnBook(void) {
    int id, i;
    printf("Enter Book ID to return: ");
    scanf("%d", &id);
    i = findById(id);

    if (i == -1) printf("Book not found.\n");
    else if (!books[i].issued) printf("Book is already available.\n");
    else {
        books[i].issued = 0;
        saveBooks();
        printf("Book returned successfully.\n");
    }
}

void deleteBook(void) {
    int id, i, j;
    printf("Enter Book ID to delete: ");
    scanf("%d", &id);
    i = findById(id);

    if (i == -1) {
        printf("Book not found.\n");
        return;
    }
    for (j = i; j < count - 1; j++)
        books[j] = books[j + 1];

    count--;
    saveBooks();
    printf("Book deleted successfully.\n");
}

void displayIssuedBooks(void) {
    int i, found = 0;
    printf("\nIssued Books:\n");
    for (i = 0; i < count; i++) {
        if (books[i].issued) {
            printf("ID: %d | Name: %s | Author: %s\n",
                   books[i].id, books[i].name, books[i].author);
            found = 1;
        }
    }
    if (!found) printf("No books are currently issued.\n");
}

int main(void) {
    int choice;
    loadBooks();

    do {
        printf("\n===== LIBRARY MANAGEMENT SYSTEM =====\n");
        printf("1. Add Book\n2. Display Books\n3. Search Book\n");
        printf("4. Sort Books\n5. Issue Book\n6. Return Book\n");
        printf("7. Delete Book\n8. Display Issued Books\n9. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            return 0;
        }

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: sortBooks(); break;
            case 5: issueBook(); break;
            case 6: returnBook(); break;
            case 7: deleteBook(); break;
            case 8: displayIssuedBooks(); break;
            case 9: printf("Thank you for using the system!\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 9);

    return 0;
}
