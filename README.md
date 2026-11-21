# smartretail-p7-group02

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