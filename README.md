# SmartRetail P7 - Demand & Replenishment Planner

A C++17 console application that forecasts product demand from historical sales data, generates store replenishment order plans, and calculates warehouse picking route distances.

## 1. Team Members (Group 02)

| No. | Full Name | GitHub Username | Role |
| :--- | :--- | :--- | :--- |
| 1 | Mai Tuyet Anh Duong | `duongmai31261028864-spec` | Team Leader |
| 2 | Pham Ngoc Mai Thuyen | `AnnnieYang` | Member |
| 3 | Trinh Nguyen Anh Thu | `tthu53479-beep` | Member |
| 4 | Tran Quang Duy | `tranduy17042008-star` | Member |
## 2. Task Assignment Table
| Task ID | Task Description | Functions / Files | Assignee | Notes |
| :--- | :--- | :--- | :--- | :--- |
| **T01** | Repository setup, project folder structure, CLI argument parsing, and main workflow | `main()`, directory structure, `.github/pull_request_template.md` | Duong Mai (`duongmai31261028864-spec`) | Project skeleton & CLI |
| **T02** | Read 4 input CSV files and perform data validation / error handling | CSV readers for `products`, `inventory`, `sales_history`, `store_layout` | Member 2 (`AnnnieYang`) | Bad data filtering & `cerr` warnings |
| **T03** | Calculate 7-day moving average demand, Reorder Point (ROP), order quantity, and days of cover | `dailyDemand()`, `reorderPoint()`, `orderQuantity()` | Member 3 (`tthu53479-beep`) | Inventory metrics calculation |
| **T04** | **Classify replenishment status (CORE FUNCTION)** | `replStatus()` | Member 3 (`tthu53479-beep`) | **Core function (requires detailed flowchart & pseudocode)** |
| **T05** | Sort replenishment plan by priority and display formatted order table | `sortPlan()`, `printPlan()` | Member 4 (`tranduy17042008-star`) | Hand-written Bubble/Selection Sort |
| **T06** | Recursive binary search for shelf locations and picking route length calculation | `findShelf()` (recursive), `stepsBetween()`, `routeLength()`, `printRoute()` | Member 4 (`tranduy17042008-star`) | Recursion & route computation |
| **T07** | Design test cases (TC01 - TC07) and execute end-to-end integration testing | `tests/`, testing on `sample`, `full`, `edge` datasets | All Members | Quality assurance & verification |

## 3. Build and Run Instructions

### Prerequisites
* A C++ compiler supporting the **C++17** standard (e.g., `g++`).

### Build Command
Create the `bin` output directory (if it does not exist) and compile with `-Wall -Wextra` ensuring zero warnings:

```bash
mkdir -p bin
g++ -std=c++17 -Wall -Wextra src/main.cpp -o bin/p7
