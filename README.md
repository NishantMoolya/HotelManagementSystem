# My Managament System Project

Welcome to My Advanced Hotel Management Project! 
**This repository contains the source code for my hotel management system that provides a comprehensive solution for managing the restaurant operations efficiently, from menu management to order processing, inventory tracking, and financial analysis. It streamlines the workflow, enhances customer experience, and helps in making data-driven decisions to improve business performance.**

## Features

1. **Menu Management**:
   - This functionality allows the staff to manage the menu items effectively. They can add new dishes, delete existing ones, view the entire menu, and update the details of menu items such as name, price, raw materials used.
   
2. **Order Processing**:
   - The system enables the staff to take orders from customers efficiently. This may involve selecting dishes from the menu, specifying quantities.
   
3. **Bill Generation**:
   - After the customer finishes their meal, the system calculates the total bill based on the items ordered, their quantities. It generates a bill that can be presented to the customer.
   
4. **Inventory Tracking**:
   - Whenever a dish is prepared and served to a customer, the system automatically updates the inventory by deducting the quantities of raw materials used in preparing the dish. This ensures that the inventory levels are accurate and up to date.
   
5. **Financial Analysis**:
   - The system keeps track of the total income generated from food sales over a period of time. It calculates the profit by subtracting the cost of ingredients from the total income. This information helps in analyzing the financial performance of the restaurant.
   
6. **Menu Optimization**:
   - The system identifies the dish that has been sold the most during a specified period. This information is valuable for understanding customer preferences and optimizing the menu to maximize sales and profitability.
7. **Inventory Management**:
   - The system efficiently manages inventory, enabling staff to fill, refill, update quantities of raw materials, and access detailed inventory information, ensuring streamlined resource tracking and operational efficiency.
  

## 🚀 Getting Started

To get started with this project, follow these steps:

### Prerequisites

- C/C++ language compiler(Ex. mingw) 

## Clone this repository

To clone this repository to your local machine, you can use the following command:

```bash
git clone https://github.com/NishantMoolya/HotelManagementSystem
```
## Project directory
Move to project directory which is the directory that contains all code:
```bash
cd HotelManagementSystem
```
## Open terminal
You can do this in your favourite code editor's terminal like VSCode,etc or open the command prompt and paste this commnands:
- This is to build the C object files
```bash
gcc -c src/analyst.c -o build/analyst.o 
```
```bash
gcc -c src/inventory_managers.c -o build/inventory_managers.o 
```
```bash
gcc -c src/raw_item_managers.c -o build/raw_item_managers.o                          
```
```bash
gcc -c src/hotel_managers.c -o build/hotel_managers.o        
```
```bash
gcc -c src/main.c -o build/main.o      
```

- This is to build the C executable file
```bash
gcc build/analyst.o build/inventory_managers.o build/raw_item_managers.o build/hotel_managers.o build/main.o -o bin/main
```
# Hurray! 🎉
Congratulations! You have successfully built the **Hotel Management System**!
## Run the project
- Just run the main file in bin folder and your project is live😀👍
```bash
./bin/main
```
### Always open for feedback on this project😄
