# Bank Management System

A console-based bank management application developed in C to manage clients, bank accounts, and financial transactions.

## Features

- **Client Management:** Add, display, search, modify, and delete clients.
- **Account Management:** Create, display, search, modify, and delete bank accounts.
- **Transactions:** Deposit, withdraw, and transfer money between accounts.
- **Data Persistence:** Save and load client and account information using text files.
- **Search:** Find clients and accounts by their identifiers.
- **Statistics:** Display the total number of clients and accounts, total account balances, and average balance per account.
- **Input Validation:** Handle invalid inputs and check transaction amounts.

## Technologies Used

- C
- Standard C Library
- File Handling
- Structures and Arrays
- Modular Programming

## Project Structure

```text
BankManagement/
├── include/
│   ├── models.h
│   ├── client.h
│   ├── account.h
│   └── transaction.h
├── src/
│   ├── main.c
│   ├── client.c
│   ├── account.c
│   └── transaction.c
└── data/
    ├── clients.txt
    └── comptes.txt
```

## How to Compile and Run

Make sure GCC is installed.

1. Open a terminal in the project root directory.
2. Compile the source files:

```bash
gcc src/main.c src/client.c src/account.c src/transaction.c -o bank.exe
```

3. Run the application on Windows:

```powershell
.\bank.exe
```

## Learning Objectives

This project demonstrates the practical application of C programming concepts, including structures, functions, arrays, modular programming, file handling, and basic data validation.

## Author

Computer Science Student
