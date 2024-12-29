#include <stdio.h>
#include <string.h>
#include <time.h>

// Making a Struct to define the variables of each book:
struct Book {
    char title[50];
    char author[50];
    char department[30];
    int id;
    int is_borrowed;    // 0 = not borrowed, 1 = borrowed
};

// setting the max number of books in the Inventory to 100 books (Global Variable):
#define MAX_BOOKS 100
struct Book inventory[MAX_BOOKS];
int book_count = 0;

// Making the Inventory:
void initialize_inventory() {
    strcpy(inventory[0].title, "Calculus 1");
    strcpy(inventory[0].author, "Youssef Ahmed");
    strcpy(inventory[0].department, "Math");
    inventory[0].id = 1;
    inventory[0].is_borrowed = 0;

    strcpy(inventory[1].title, "Computing");
    strcpy(inventory[1].author, "Ahmed Mohamed");
    strcpy(inventory[1].department, "Computer Science");
    inventory[1].id = 2;
    inventory[1].is_borrowed = 0;

    strcpy(inventory[2].title, "Calculus 2");
    strcpy(inventory[2].author, "Ahmed Zaki");
    strcpy(inventory[2].department, "Math");
    inventory[2].id = 3;
    inventory[2].is_borrowed = 0;

    strcpy(inventory[3].title, "Networks");
    strcpy(inventory[3].author, "Mark Hany");
    strcpy(inventory[3].department, "Computer Science");
    inventory[3].id = 4;
    inventory[3].is_borrowed = 0;

    strcpy(inventory[4].title, "Creativity");
    strcpy(inventory[4].author, "Mona Ahmed");
    strcpy(inventory[4].department, "Creative Thinking");
    inventory[4].id = 5;
    inventory[4].is_borrowed = 0;

    strcpy(inventory[5].title, "Information System");
    strcpy(inventory[5].author, "Mahmoud Hassan");
    strcpy(inventory[5].department, "Computer Science");
    inventory[5].id = 6;
    inventory[5].is_borrowed = 0;

    strcpy(inventory[6].title, "Database");
    strcpy(inventory[6].author, "Rana Ahmed");
    strcpy(inventory[6].department, "Computer Science");
    inventory[6].id = 7;
    inventory[6].is_borrowed = 0;

    strcpy(inventory[7].title, "Statics");
    strcpy(inventory[7].author, "Mohamed Hassn");
    strcpy(inventory[7].department, "Math");
    inventory[7].id = 8;
    inventory[7].is_borrowed = 0;

    strcpy(inventory[8].title, "Serway Physics");
    strcpy(inventory[8].author, "Micheal Ben");
    strcpy(inventory[8].department, "Physics");
    inventory[8].id = 9;
    inventory[8].is_borrowed = 0;

    strcpy(inventory[9].title, "Organic Chemistry");
    strcpy(inventory[9].author, "Ben Pitt");
    strcpy(inventory[9].department, "Chemistry");
    inventory[9].id = 10;
    inventory[9].is_borrowed = 0;

    strcpy(inventory[10].title, "Human Anatomy");
    strcpy(inventory[10].author, "Allen Sorkin");
    strcpy(inventory[10].department, "Biology");
    inventory[10].id = 11;
    inventory[10].is_borrowed = 0;

    strcpy(inventory[11].title, "Fundamentals Of Law");
    strcpy(inventory[11].author, "Harvey Specter");
    strcpy(inventory[11].department, "Law");
    inventory[11].id = 12;
    inventory[11].is_borrowed = 0;

    strcpy(inventory[12].title, "Dynamics");
    strcpy(inventory[12].author, "Mike Ross");
    strcpy(inventory[12].department, "Math");
    inventory[12].id = 13;
    inventory[12].is_borrowed = 0;

    strcpy(inventory[13].title, "Software Security");
    strcpy(inventory[13].author, "Mohamed Seif");
    strcpy(inventory[13].department, "Computer Science");
    inventory[13].id = 14;
    inventory[13].is_borrowed = 0;

    strcpy(inventory[14].title, "Plants Anatomy");
    strcpy(inventory[14].author, "Rich Spencer");
    strcpy(inventory[14].department, "Biology");
    inventory[14].id = 15;
    inventory[14].is_borrowed = 0;

    book_count = 15;
}


// Defining the functions of the system:
void add_book();
void delete_books();
void borrow_book();
void return_book();
void search_book();
void overdue_books();
void show_menu();
void initialize_inventory();
void view_inventory();

// The Main function:
int main() {
    int choice;

    // putting the inventory of books in the main function:
    initialize_inventory();

    do {
        show_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To get rid of the newline made by scanf

        switch(choice) {
            case 1:
                view_inventory();
                break;
            case 2:
                add_book();
                break;
            case 3:
                delete_books();
                break;
            case 4:
                borrow_book();
                break;
            case 5:
                return_book();
                break;
            case 6:
                search_book();
                break;
            case 7:
                overdue_books();
                break;
            case 8:
                printf("Exiting the System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 8);

    return 0;
}

// The Menu of the functions to choose from:
void show_menu() {
    printf("\nLibrary Management System\n");
    printf("1. View Books Inventory\n");
    printf("2. Add Book\n");
    printf("3. Delete Book\n");
    printf("4. Borrow Book\n");
    printf("5. Return Book\n");
    printf("6. Search Book\n");
    printf("7. View Overdue Books\n");
    printf("8. Exit\n");
}

// Showing the inventory function:
void view_inventory() {
    printf("\n--- Inventory ---\n");
    for (int i = 0; i < book_count; i++) {
        printf("ID: %d, Title: %s, Author: %s, Department: %s, Borrowed: %s\n",
            inventory[i].id, inventory[i].title, inventory[i].author,
            inventory[i].department,
            inventory[i].is_borrowed ? "Yes" : "No");
    }
}

// Add book function:
void add_book() {
    if (book_count >= MAX_BOOKS) {
        printf("Inventory is full. Cannot add more books.\n");
        return;
    }

    struct Book new_book;
    printf("\n--- Add Book ---\n");
    printf("Enter the title of the book: ");
    fgets(new_book.title, sizeof(new_book.title), stdin);
    new_book.title[strcspn(new_book.title, "\n")] = 0; // Remove newline that fgets does
    printf("Enter the author of the book: ");
    fgets(new_book.author, sizeof(new_book.author), stdin);
    new_book.author[strcspn(new_book.author, "\n")] = 0; // Remove newline that fgets does
    printf("Enter the department of the book: ");
    fgets(new_book.department, sizeof(new_book.department), stdin);
    new_book.department[strcspn(new_book.department, "\n")] = 0; // Remove newline that fgets does
    printf("Enter the ID of the book: ");
    scanf("%d", &new_book.id);
    getchar();

    new_book.is_borrowed = 0; // Book will be added as not borrowed
    inventory[book_count++] = new_book;

    printf("Book '%s' by '%s' added to the '%s' department with ID %d.\n",
        new_book.title, new_book.author, new_book.department, new_book.id);
}

// Delete book function:
void delete_books() {
    char title[50];
    printf("\n--- Delete Book ---\n");
    printf("Enter the title of the book to delete: ");
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline that fgets does

    for (int i = 0; i < book_count; i++) {
        if (strcmp(inventory[i].title, title) == 0) {
            for (int j = i; j < book_count - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            book_count--;
            printf("Book '%s' has been deleted from the library.\n", title);
            return;
        }
    }
    printf("Book '%s' not found in the library.\n", title);
}

// Borrow book function:
void borrow_book() {
    char title[50];
    printf("\n--- Borrow Book ---\n");
    printf("Enter the title of the book to borrow: ");
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline that fgets does
    for (int i = 0; i < book_count; i++) {
        if (strcmp(inventory[i].title, title) == 0) {
            if (inventory[i].is_borrowed) {
                printf("Book '%s' is already borrowed.\n", title);
            } else {
                inventory[i].is_borrowed = 1;
                printf("Book '%s' has been borrowed successfully.\n", title);
            }
            return;
        }
    }
    printf("Book '%s' not found in the library.\n", title);
}

// Return book function:
void return_book() {
    char title[50];
    printf("\n--- Return Book ---\n");
    printf("Enter the title of the book to return: ");
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline that fgets does

    for (int i = 0; i < book_count; i++) {
        if (strcmp(inventory[i].title, title) == 0) {
            if (inventory[i].is_borrowed) {
                inventory[i].is_borrowed = 0;
                printf("Book '%s' has been returned successfully.\n", title);
            } else {
                printf("Book '%s' was not borrowed.\n", title);
            }
            return;
        }
    }
    printf("Book '%s' not found in the library.\n", title);
}

// Search for a book function:
void search_book() {
    char title[50];
    printf("\n--- Search Book ---\n");
    printf("Enter the title of the book to search: ");
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline that fgets does

    for (int i = 0; i < book_count; i++) {
        if (strcmp(inventory[i].title, title) == 0) {
            printf("Book '%s' is found in the library.\n", title);
            return;
        }
    }
    printf("Book '%s' is not found in the library.\n", title);
}

// The overdue books function:
void overdue_books() {
    char title[50];
    int day, month, year;
    printf("\n--- Overdue Books ---\n");
    printf("Enter the title of the book: ");
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = 0; // Remove newline that fgets does
    printf("Enter the date of borrowing (DD MM YYYY): ");
    scanf("%d %d %d", &day, &month, &year);

    // Get the current date
    time_t t = time(NULL);
    struct tm today = *localtime(&t);

    // Calculate the days since borrowing:
    struct tm borrowed_date = {0};
    borrowed_date.tm_mday = day;
    borrowed_date.tm_mon = month - 1;
    borrowed_date.tm_year = year - 1900;
    time_t borrowed_time = mktime(&borrowed_date);

    double diff_in_days = difftime(t, borrowed_time) / (60 * 60 * 24);

    if (diff_in_days > 14) {
        printf("Book '%s' is overdue by %f days.\n", title, diff_in_days - 14);
    } else {
        printf("Book '%s' is not overdue.\n", title);
    }
}
