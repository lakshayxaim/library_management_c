# Library Management System in C

A console-based C program that manages a small library. It stores book records (ID, title, author and status), lets the user issue and return books, and saves the data in a file so it is kept after the program closes.

## Features

1. Add a book (duplicate IDs are not allowed)
2. Show all books with their status (Available or Issued)
3. Issue a book
4. Return a book
5. Delete a book
6. Save records to a file and exit

## How to Run

```
gcc library_simple.c -o library
./library
```

On Windows, run `library.exe` instead of `./library`.

Records are saved in `library.dat`, which is created automatically on the first save.

## Concepts Used

| Unit | Concepts |
|---|---|
| 1 | Data types, variables, header file, `printf` and `scanf` |
| 2 | `#define`, `if/else`, `switch`, `do-while` and `for` loops |
| 3 | Arrays, strings, functions |
| 4 | Structure, array of structures, pointer to a structure, file handling (`fopen`, `fread`, `fwrite`, `fclose`) |

## How It Works

1. Start and load the saved records from the file.
2. Show the menu and read the user's choice.
3. Perform the chosen operation (add, show, issue, return or delete).
4. Repeat until the user selects Exit.
5. Save the records to the file and stop.

## Data Design

| Field | Type | Purpose |
|---|---|---|
| `id` | int | Unique book number |
| `title` | char[50] | Book name |
| `author` | char[30] | Author name |
| `issued` | int | 0 = available, 1 = issued |

## Limitations

- Holds a maximum of 100 books
- No search by title or author
- Does not record which member has a book or the due date

## Future Scope

- Member records and due dates with fines
- Search by title or author
- Dynamic memory to remove the 100-book limit

## Conclusion

The project combines structures, arrays, pointers, functions and file handling into one working program, and it covers all four units of the syllabus.
