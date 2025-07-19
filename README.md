# Retail POS System Enhancer

## Project Overview

This project significantly enhances existing retail Point-of-Sale (POS) systems by integrating advanced data structures: **Interval Trees, Bucket Sort, and Treaps**. Developed for `CSC 212 - Data Structures and Algorithms` at the `University of Rhode Island`, our solution aims to revolutionize search efficiency, storage management, and data organization for retail businesses of all sizes.

It provides critical functionalities for large retail store and warehouse managers, offering streamlined processes for **employee time tracking** and **real-time stock monitoring**.

## Key Features & Data Structure Applications

Our system leverages specific data structures to solve common retail management challenges:

* ### Employee Time Management with Interval Trees
    * **Purpose:** Efficiently manages employee shift records and attendance.
    * **Functionality:** Allows for quick retrieval of employee presence at specific times, identifies the latest staff on duty (maximum interval value), and accurately calculates total work hours per day. Each Interval Tree represents a single day, optimizing daily operational insights.

* ### Efficient Stock Data Handling with Bucket Sort
    * **Purpose:** Organizes and processes incoming item stock numbers.
    * **Functionality:** Employee inputs for item stock are stored as structured elements in a `std::vector`. The **Bucket Sort** algorithm is then applied to swiftly identify items requiring stock adjustments, ensuring fast and effective inventory management.

* ### Prioritized Stock Ordering with Treaps
    * **Purpose:** Manages time-sensitive stock data for optimized ordering decisions.
    * **Functionality:** After stock information is bucket-sorted, a **Treap** is constructed. This unique data structure, combining properties of a binary search tree and a heap, prioritizes items with lower stock numbers, enabling store owners to make informed and efficient reordering decisions.

## Usage

This program serves two primary functions, designed with **large retail and warehouse managers** in mind, but adaptable for smaller businesses:

1.  **Tracking Employee's Weekly Hours:** Monitors individual shifts and total hours worked.
2.  **Monitoring Stock Numbers:** Provides insights into inventory levels for various items.

Both employees and items are represented as `struct`s to facilitate comprehensive data tracking:

* **Employee Struct:** Stores `Name`, `Shift(s)`, and `Total Hours Worked`.
* **Item Struct:** Stores `Name`, `Gross Profit Per Item`, and `Total Sale Information`.

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

## Challenges & Learning Outcomes

Developing this project presented unique challenges in integrating disparate data structures to work cohesively within a single application:

* **Challenge:** Designing a robust system to accurately represent and manage dynamic time intervals for employee shifts using Interval Trees, especially when considering overlapping shifts or complex search queries.
* **Learning:** Gained a deeper understanding of interval tree construction, query optimization, and the practical application of geometric data structures to real-world scheduling problems.

* **Challenge:** Ensuring efficient data flow and accurate prioritization between Bucket Sort (for initial stock organization) and the Treap (for subsequent stock reordering decisions) while maintaining performance for large datasets.
* **Learning:** Solidified knowledge of sorting algorithm efficiency, the unique properties of Treaps for combining search and priority, and the importance of choosing the right data structure for specific operational needs.

## Contributors

This project was a collaborative effort by the following team members from the University of Rhode Island:

* **Mithilesh Pabba**
* **Matthew Connors**
* **Jack Reedy**
* **Justin Keyes**
