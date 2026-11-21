 duongmai31261028864-spec-patch-1
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


## Task assignment table

| ID | Task | Function / file | Assignee | Reviewer | Flowchart | PR |
|---|---|---|---|---|---|---|

## Assumptions & Limitations

### 1. Data Validation & Error Handling
- **Invalid Records:** Any invalid line is skipped with a warning printed to `std::cerr` including the line number, allowing the program to continue running without crashing:
  - Missing columns or non-numeric values in numeric fields.
  - Negative numbers (e.g., `units_sold < 0`, `stock < 0`, `price < 0`) or invalid shelf coordinates (`aisle < 1`, `position < 1`).
  - Malformed or non-existent dates (e.g., `2026-13-01`).
  - Unknown `product_id` not found in `products.csv`.
- **Duplicate Keys:** When duplicate primary keys occur, the first valid occurrence is kept and subsequent duplicates are ignored with a warning.
- **Missing Input Files:** If any required CSV file cannot be opened, the program reports a clear error message and exits safely without crashing.

### 2. Business Logic Assumptions (P7 - Demand & Replenishment Planner)
- **Scope Boundary:** The program computes replenishment order quantities and warehouse picking route distances, but does not classify retail shelf alerts for sales staff.
- **Default Stock:** If a product exists in the catalogue without a corresponding stock entry for the target store in `inventory.csv`, its current stock is assumed to be `0`.
- **Fixed Replenishment Parameters:** `lead_time = 3` days, `safety_days = 2` days, and `review_period = 7` days.
- **Forecasting & Division-by-Zero Handling:**
  - Daily demand is calculated as the average `units_sold` over the 7 most recent days available in `sales_history.csv` for that store and product (including days with `0` units sold); if fewer than 7 days exist, the average is computed over all available days.
  - When `demand == 0`, Days of Cover (`Cover`) is displayed as `inf` to prevent division by zero.
  - Order quantities are rounded up using `ceil()`; if the computed value is `<= 0` or the replenishment status is `OK`, the order quantity is set to `0`.
- **Picking Route:** Every picking route starts at `ENTRANCE (0, 0)`. Any product in the pick list that has no shelf assignment in `store_layout.csv` is reported clearly and skipped when calculating total steps.

 main
