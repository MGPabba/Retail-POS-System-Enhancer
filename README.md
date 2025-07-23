# Retail POS System Enhancer

## Project Overview

This project significantly enhances existing retail Point-of-Sale (POS) systems by integrating advanced data structures: **Interval Trees, Bucket Sort, and Treaps**. Developed for `CSC 212 - Data Structures and Algorithms` at the University of Rhode Island, our solution aims to improve search efficiency, storage management, and data organization for retail businesses of all sizes. It provides critical functionalities for large retail store and warehouse managers, offering streamlined processes for **employee time tracking** and **real-time stock monitoring**. We built this project to apply classroom concepts to a real-world use case and deepen our understanding of data structures through hands-on development.

## Key Features & Data Structure Applications

Our system leverages specific data structures to solve common retail management challenges:

* ### Employee Time Management with Interval Trees
    * **Purpose:** Efficiently manages employee shift records and attendance.
    * **Functionality:** Allows for quick retrieval of employee presence at specific times, identifies the latest staff on duty, and calculates total work hours per day. Each Interval Tree represents a single day, optimizing daily operational insights.

* ### Efficient Stock Data Handling with Bucket Sort
    * **Purpose:** Organizes and processes incoming item stock numbers.
    * **Functionality:** Employee inputs for item stock are stored as structured elements in a `std::vector`. The **Bucket Sort** algorithm is then applied to swiftly identify items requiring stock adjustments, ensuring fast and effective inventory management.

* ### Prioritized Stock Ordering with Treaps
    * **Purpose:** Manages time-sensitive stock data for optimized ordering decisions.
    * **Functionality:** After stock information is bucket-sorted, a **Treap** is constructed. This unique data structure, combining properties of a binary search tree and a heap, prioritizes items with lower stock numbers, enabling store owners to make informed and efficient reordering decisions.

## Usage

This program serves two primary functions, designed with **large retail and warehouse managers** in mind, but adaptable for smaller businesses:

1.  **Tracking Employees' Weekly Hours:** Monitors individual shifts and total hours worked.
2.  **Monitoring Stock Numbers:** Provides insights into inventory levels for various items.

Employee data is represented using a struct to track names and hours worked, while item stock information is stored and prioritized using a Treap.

* **Employee Struct:** Stores the employee's `Name` and `Total Hours Worked`. Shift start and end times are managed separately using an Interval Tree.
* **Item Tracking:** Item names and quantities are recorded using a Treap data structure, allowing for fast access to the item with the highest stock level.

## How to Build & Run

### Prerequisites

* All project source files must be downloaded into the same directory.
* We recommend using a modern Integrated Development Environment (IDE) such as:
    * **Visual Studio Code (VSCode):** [https://code.visualstudio.com/](https://code.visualstudio.com/)
    * **CLion:** [https://www.jetbrains.com/clion/](https://www.jetbrains.com/clion/)

### Compile and Execute

1.  **Navigate to the project directory** in your terminal or command prompt.
2.  **Compile the source files** using a C++ compiler:
    ```bash
    g++ main.cpp interval_tree.cpp treap.cpp -o prog
    ```
3.  **Run the executable:**
    ```bash
    ./prog
    ```

## Contributors

This project was a collaborative effort by:

* **Mithilesh Pabba**
* **Matthew Connors**
* **Jack Reedy**
* **Justin Keyes**
