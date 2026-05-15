# Library Management System
- **Instructor:** Dr. NIAYESH GHARAEI  
- **Project Title:** Library Book Tracking System

## Team Members

| Name                     | Student Number | Role |
|--------------------------|---------------|------|
| AHMED ALAA SAYED ABDALLAH | 230201920 | Main development, Report preparation, GitHub repository, Project structure |
| Mahmut Eburjele          | 220201933 | Library ADT |
| Sarp Varol               | 240201456 | BorrowManager ADT |
| Ahmed Alrayah Suliman    | 210202983 | Book ADT |
| Emil Mammadzada          | 220201882 | Testing, debugging, and validation |



## Project Structure

```
LibrarySystem/
├── include/
│   ├── Book.hpp
│   ├── Library.hpp
│   └── BorrowManager.hpp
├── src/
│   ├── Book.cpp
│   ├── Library.cpp
│   ├── BorrowManager.cpp
│   └── main.cpp
├── tests/
│   └── test.cpp
├── docs/
│   └── report.pdf
└── Makefile
```

## How to Compile and Run

### Requirements
- g++ compiler
- C++11 or later

### Compile
```
make
```

### Run
```
./library
```

### Run Tests
```
make test
```

### Clean
```
make clean
```

## Data Structures Used

- **Linked List** — used in Library ADT to store books (easy insert and remove)
- **Queue** — used in BorrowManager ADT to track borrow history (FIFO order)

## Features

- Add and remove books
- Search by title or ISBN
- Borrow and return books
- Sort books by title
- View borrow history