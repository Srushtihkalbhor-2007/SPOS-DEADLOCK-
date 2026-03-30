# Deadlock Simulator using Banker’s Algorithm

This project is a simple simulation of deadlock detection in an operating system using Banker’s Algorithm. It demonstrates how processes request and release resources, and how the system determines whether it is in a safe state or a deadlock condition.

## Features

* Takes input for processes and resources
* Calculates Need matrix (Need = Max − Allocation)
* Simulates process execution step-by-step
* Displays safe sequence if system is safe
* Detects deadlock and shows stuck processes

## Technologies Used

* C Programming Language

## Project Structure

Deadlock-Simulator/
│
├── src/        # Source code
├── include/    # Header files
├── docs/       # Report and explanation
└── README.md

## How to Run

1. Compile the program:

gcc src/main.c src/deadlock.c -o deadlock

2. Run the program:

./deadlock

(For Windows PowerShell, use: .\deadlock.exe)

## Sample Output

Safe State:

P1 is executing...
P2 is executing...
P0 is executing...

System is in SAFE state
Safe sequence: P1 -> P2 -> P0

Deadlock Case:

Deadlock detected!
Processes stuck:
P0 waiting (Need: 1 1)
P1 waiting (Need: 1 1)
P2 waiting (Need: 1 1)

## Documentation

The full project report and explanation are available in the docs folder.
