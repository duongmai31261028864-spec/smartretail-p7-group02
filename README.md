# smartretail-p7-group02


## Build and Run Instructions

### 1. Build the program

Compile the program using the following command:

```bash
g++ -std=c++17 -Wall -Wextra src/main.cpp -o bin/p7
```

### 2. Run the program with default data

On Linux/macOS:

```bash
./bin/p7 data/sample
```

On Windows:

```bash
bin\p7.exe data\sample
```

### 3. Run the program with full arguments

```bash
./bin/p7 data/full S002 P005,P021,P029,P020
```

### 4. System Parameters

The system uses the following fixed parameters:

| Parameter | Value |
|---|---:|
| lead_time | 3 |
| safety_days | 2 |
| review_period | 7 |
