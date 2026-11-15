/* SIMPLE LIBRARY MANAGEMENT SYSTEM */

#include <stdio.h>

/* max number of books */
#define MAX 100

struct Book {
    int  id;
    char title[50];
    char author[30];
    int  issued;
};

struct Book books[MAX];
int count = 0;

/* ---------- file handling ---------- */
void load()
{
    FILE *fp = fopen("library.dat", "rb");
    if (fp == NULL) return;
    fread(&count, sizeof(int), 1, fp);
    fread(books, sizeof(struct Book), count, fp);
    fclose(fp);
}

void save()
{
    FILE *fp = fopen("library.dat", "wb");
    fwrite(&count, sizeof(int), 1, fp);
    fwrite(books, sizeof(struct Book), count, fp);
    fclose(fp);
}

/* ---------- find book (returns index or -1) ---------- */
int find(int id)
{
    int i;
    for (i = 0; i < count; i++)
        if (books[i].id == id)
            return i;
    return -1;
}

/* ---------- operations ---------- */
void addBook()
{
    struct Book *b;

    if (count == MAX) {
        printf("Library is full!\n");
        return;
    }
    b = &books[count];

    printf("Book ID: ");
    scanf("%d", &b->id);
    if (find(b->id) != -1) {
        printf("ID already exists!\n");
        return;
    }
    printf("Title: ");
    scanf(" %[^\n]", b->title);
    printf("Author: ");
    scanf(" %[^\n]", b->author);
    b->issued = 0;
    count++;
    printf("Book added.\n");
}

void showBooks()
{
    int i;
    if (count == 0) {
        printf("No books.\n");
        return;
    }
    printf("\nID    Title                Author          Status\n");
    for (i = 0; i < count; i++)
        printf("%-5d %-20s %-15s %s\n", books[i].id, books[i].title,
               books[i].author, books[i].issued ? "Issued" : "Available");
}


void changeStatus(int status)
{
    int id, i;
    printf("Book ID: ");
    scanf("%d", &id);
    i = find(id);

    if (i == -1)
        printf("Book not found.\n");
    else if (books[i].issued == status)
        printf(status ? "Already issued.\n" : "Book is already in library.\n");
    else {
        books[i].issued = status;
        printf(status ? "Book issued.\n" : "Book returned.\n");
    }
}

void deleteBook()
{
    int id, i;
    printf("Book ID: ");
    scanf("%d", &id);
    i = find(id);

    if (i == -1) {
        printf("Book not found.\n");
        return;
    }
    for (; i < count - 1; i++)
        books[i] = books[i + 1];
    count--;
    printf("Book deleted.\n");
}

/* ---------- main ---------- */
int main()
{
    int choice;
    load();

    do {
        printf("\n--- LIBRARY MENU ---\n");
        printf("1. Add Book\n2. Show Books\n3. Issue Book\n");
        printf("4. Return Book\n5. Delete Book\n0. Save & Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook();         break;
            case 2: showBooks();       break;
            case 3: changeStatus(1);   break;
            case 4: changeStatus(0);   break;
            case 5: deleteBook();      break;
            case 0: save(); printf("Saved. Bye!\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}