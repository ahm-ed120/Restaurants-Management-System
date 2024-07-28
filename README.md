# Restaurant Management System

This project is a Restaurant Management System written in C. It provides functionalities to manage orders, customers, employees, and menu items in a restaurant. The system includes various features such as adding, updating, deleting records, searching for specific data, and displaying meaningful reports.

## Features

- **Customer Management**
  - Add, update, delete, and display customer information.
  
- **Employee Management**
  - Add, update, delete, and display employee information.
  
- **Menu Management**
  - Add, update, delete, and display menu items.
  
- **Order Management**
  - Add, update, delete, and display orders.
  
- **Search Functionality**
  - Searching for specific data.
  
- **Reports**
  - Display detailed reports for customers, employees, menu items, and orders.

## Functions Overview

### Customer Functions
- `void addCustomer(customer c[MAX_RECORD], int *customerCount)`
- `void updateCustomer(customer c[MAX_RECORD], int customerCount)`
- `int deleteCustomer(customer c[MAX_RECORD], int customerCount)`
- `void displayCustomer(customer c[MAX_RECORD], int customerCount)`

### Employee Functions
- `void addEmployee(employee e[MAX_RECORD], int *employeeCount)`
- `void updateEmployee(employee e[MAX_RECORD], int employeeCount)`
- `int deleteEmployee(employee e[MAX_RECORD], int employeeCount)`
- `void displayEmployee(employee e[MAX_RECORD], int employeeCount)`

### Menu Functions
- `void addMenu(menu m[MAX_RECORD], int *menuCount)`
- `void updateMenu(menu m[MAX_RECORD], int menuCount)`
- `int deleteMenu(menu m[MAX_RECORD], int menuCount)`
- `void displayMenu(menu m[MAX_RECORD], int menuCount)`

### Order Functions
- `void addOrder(order o[MAX_RECORD], customer c[MAX_RECORD], menu m[MAX_RECORD], int *orderCount, int customerCount, int menuCount)`
- `void updateOrder(order o[MAX_RECORD], customer c[MAX_RECORD], menu m[MAX_RECORD], int orderCount, int customerCount, int menuCount)`
- `int deleteOrder(order o[MAX_RECORD], int orderCount)`
- `void displayOrder(order o[MAX_RECORD], int orderCount)`

### Search Functions
- `void searchOrderByCustomerId(order o[MAX_RECORD], int orderCount)`
- `void searchOrderById(order o[MAX_RECORD], int orderCount)`
- `void search(order o[MAX_RECORD], customer c[MAX_RECORD], employee e[MAX_RECORD], menu m[MAX_RECORD], int orderCount, int customerCount, int employeeCount, int menuCount)`

### Report Functions
- `void displayRecord(int orderCount, int customerCount, int employeeCount, int menuCount)`
- `void displayMenuReport(order o[MAX_RECORD], menu m[MAX_RECORD], int orderCount, int menuCount)`
- `void displayEmployeeReport(employee e[MAX_RECORD], int employeeCount)`
- `void displayCustomerReport(customer c[MAX_RECORD], int customerCount)`
- `void displayOrderReport(order o[MAX_RECORD], int orderCount)`

## Usage

1. Clone the repository to your local machine.
2. Open the project in your preferred C development environment.
3. Compile and run the `main.c` file.
4. Follow the on-screen prompts to navigate through the system.

