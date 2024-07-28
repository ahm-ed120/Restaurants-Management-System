#include <stdio.h>
#include <string.h>

#define MAX_RECORD 100

typedef struct menu
{
    int mid;
    char mname[50];
    float mprice;
} menu;

typedef struct employee
{
    char ename[50];
    int eid;
    float esalary;

} employee;

typedef struct customer
{
    int cid;
    char cname[50];
    char phone[15];
    char address[100];
} customer;

typedef struct order
{
    int orderId;
    char customerName[50];
    int customerId;
    int quantity;
    int menuItemId;
    float totalPrice;

} order;

void addMenu(menu m[MAX_RECORD], int);
void updateMenu(menu m[MAX_RECORD], int);
int deleteMenu(menu m[MAX_RECORD], int);
void displayMenu(menu m[MAX_RECORD], int);

void addEmployee(employee e[MAX_RECORD], int);
void updateEmployee(employee e[MAX_RECORD], int);
int deleteEmployee(employee e[MAX_RECORD], int);
void displayEmployee(employee e[MAX_RECORD], int);

void addCustomer(customer c[MAX_RECORD], int);
void updateCustomer(customer c[MAX_RECORD], int);
int deleteCustomer(customer c[MAX_RECORD], int);
void displayCustomer(customer c[MAX_RECORD], int);

int addOrder(order o[MAX_RECORD], customer c[MAX_RECORD], menu m[MAX_RECORD], int, int, int);
void updateOrder(order o[MAX_RECORD], customer c[MAX_RECORD], menu m[MAX_RECORD], int, int, int);
int deleteOrder(order o[MAX_RECORD], int);
void displayOrder(order o[MAX_RECORD], int);

void search(order o[MAX_RECORD], customer c[MAX_RECORD], employee e[MAX_RECORD], menu m[MAX_RECORD], int, int, int, int);

void searchMenu(menu m[MAX_RECORD], int);
void searchMenuByName(menu m[MAX_RECORD], int);
void searchMenuById(menu m[MAX_RECORD], int);

void searchEmployee(employee e[MAX_RECORD], int);
void searchEmployeeByName(employee e[MAX_RECORD], int);
void searchEmployeeById(employee e[MAX_RECORD], int);

void searchCustomer(customer c[MAX_RECORD], int);
void searchCustomerById(customer c[MAX_RECORD], int);
void searchCustomerByName(customer c[MAX_RECORD], int);

void searchOrder(order o[MAX_RECORD], int);
void searchOrderById(order o[MAX_RECORD], int);
void searchOrderByCustomerId(order o[MAX_RECORD], int);

void displayRecord(int, int, int, int);
void displayMenuRecord(int);
void displayEmployeeRecord(int);
void displayCustomerRecord(int);
void displayOrderRecord(int);

void displayReport(order o[MAX_RECORD], customer c[MAX_RECORD], employee e[MAX_RECORD], menu m[MAX_RECORD], int, int, int, int);
void displayMenuReport(order o[MAX_RECORD], menu m[MAX_RECORD], int, int);
void displayEmployeeReport(employee e[MAX_RECORD], int);
void displayCustomerReport(customer c[MAX_RECORD], int);
void displayOrderReport(order o[MAX_RECORD], int);

int main()
{
    menu m[MAX_RECORD];
    employee e[MAX_RECORD];
    customer c[MAX_RECORD];
    order o[MAX_RECORD];

    int menuCount = 0;
    int employeeCount = 0;
    int customerCount = 0;
    int orderCount = 0;

    // for menu
    FILE *fmenu1;
    fmenu1 = fopen("menu.csv", "r");

    fscanf(fmenu1, "%d\n", &menuCount);

    for (int i = 0; i < menuCount; i++)
    {
        fscanf(fmenu1, "%d,%20[^,],%f\n", &m[i].mid, m[i].mname, &m[i].mprice);
    }

    fclose(fmenu1);

    // for employee
    FILE *femployee1;
    femployee1 = fopen("employee.csv", "r");

    fscanf(femployee1, "%d\n", &employeeCount);

    for (int i = 0; i < employeeCount; i++)
    {
        fscanf(femployee1, "%d,%25[^,],%f\n", &e[i].eid, e[i].ename, &e[i].esalary);
    }

    fclose(femployee1);

    // for customer
    FILE *fcustomer1;
    fcustomer1 = fopen("customer.csv", "r");

    fscanf(fcustomer1, "%d\n", &customerCount);

    for (int i = 0; i < customerCount; i++)
    {
        fscanf(fcustomer1, "%d,%25[^,],%15[^,],%40[^\n]\n", &c[i].cid, c[i].cname, c[i].phone, c[i].address);
    }

    fclose(fcustomer1);

    // for order
    FILE *forder1;
    forder1 = fopen("order.csv", "r");

    fscanf(forder1, "%d\n", &orderCount);

    for (int i = 0; i < orderCount; i++)
    {
        fscanf(forder1, "%d,%25[^,],%d,%d,%d,%f\n", &o[i].orderId, o[i].customerName, &o[i].customerId, &o[i].menuItemId, &o[i].quantity, &o[i].totalPrice);
    }

    fclose(forder1);

    int choice, choice1, choice2, choice3, choice4, choice5;
    int w, x, y, z, f;

    printf("***********Restaurant Management System***********\n\n");
    do
    {
        printf("\n********MAIN MENU********\n\n");
        printf("1. MANAGE DATA\n");
        printf("2. SEARCH DATA\n");
        printf("3. DISPLAY TOTAL NO. OF RECORDS\n");
        printf("4. DISPLAY MEANINGFUL REPORT\n");
        printf("0. EXIT\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            do
            {
                printf("\n******MANAGE DATA******\n\n");
                printf("1. MANAGE MENU\n");
                printf("2. MANAGE EMPLOYEE DATA\n");
                printf("3. MANAGE CUSTOMER DATA\n");
                printf("4. MANAGE ORDER\n");
                printf("0. EXIT\n");
                scanf("%d", &choice1);

                switch (choice1)
                {

                case 1:
                    do
                    {
                        printf("\n*********MANAGE MENU********\n");
                        printf("1.ADD MENUE\n");
                        printf("2.UPDATE MENU\n");
                        printf("3.DISPLAY MENU\n");
                        printf("4.DELETE MENU\n");
                        printf("5.EXIT\n");

                        scanf("%d", &choice2);

                        switch (choice2)
                        {
                        case 1:
                            addMenu(m, menuCount);
                            menuCount++;
                            break;

                        case 2:
                            updateMenu(m, menuCount);
                            break;

                        case 3:
                            displayMenu(m, menuCount);
                            break;

                        case 4:
                            w = deleteMenu(m, menuCount);
                            if (w == 1)
                            {
                                menuCount--;
                            }
                            else
                            {
                                printf("Menu not found !!!\n");
                            }
                            break;

                        case 5:
                            break;
                        }

                        FILE *fmenu;
                        fmenu = fopen("menu.csv", "w");

                        fprintf(fmenu, "%d\n", menuCount);

                        for (int i = 0; i < menuCount; i++)
                        {
                            fprintf(fmenu, "%d,%s,%.2f\n", m[i].mid, m[i].mname, m[i].mprice);
                        }

                        fclose(fmenu);

                    } while (choice2 != 5);
                    break;

                case 2:
                    do
                    {
                        printf("\n*********MANAGE EMPLOYEE DATA*********\n\n");
                        printf("1.ADD EMPLOYEE\n");
                        printf("2.UPDATE EMPLOYEE\n");
                        printf("3.DISPLAY EMPLOYEE\n");
                        printf("4.DELETE EMPLOYEE\n");
                        printf("5.EXIT\n");

                        scanf("%d", &choice3);

                        switch (choice3)
                        {
                        case 1:
                            addEmployee(e, employeeCount);
                            employeeCount++;
                            break;

                        case 2:
                            updateEmployee(e, employeeCount);
                            break;

                        case 3:
                            displayEmployee(e, employeeCount);
                            break;

                        case 4:
                            x = deleteEmployee(e, employeeCount);
                            if (x == 1)
                            {
                                employeeCount--;
                            }
                            else
                            {
                                printf("Employee not found !!!\n");
                            }
                            break;

                        case 5:
                            break;
                        }

                        FILE *femployee;
                        femployee = fopen("employee.csv", "w");

                        fprintf(femployee, "%d\n", employeeCount);

                        for (int i = 0; i < employeeCount; i++)
                        {
                            fprintf(femployee, "%d,%s,%.2f\n", e[i].eid, e[i].ename, e[i].esalary);
                        }

                        fclose(femployee);

                    } while (choice3 != 5);
                    break;

                case 3:
                    do
                    {
                        printf("\n*********MANAGE CUSTOMER*********\n\n");
                        printf("1. ADD CUSTOMER\n");
                        printf("2. UPDATE CUSTOMER\n");
                        printf("3. DISPLAY CUSTOMER\n");
                        printf("4. DELETE CUSTOMER\n");
                        printf("5. EXIT\n");

                        scanf("%d", &choice4);

                        switch (choice4)
                        {
                        case 1:
                            addCustomer(c, customerCount);
                            customerCount++;
                            break;

                        case 2:
                            updateCustomer(c, customerCount);
                            break;

                        case 3:
                            displayCustomer(c, customerCount);
                            break;

                        case 4:
                            y = deleteCustomer(c, customerCount);
                            if (y == 1)
                            {
                                customerCount--;
                            }
                            else
                            {
                                printf("Customer not found !!!\n");
                            }
                            break;

                        case 5:
                            break;
                        }

                        FILE *fcustomer;
                        fcustomer = fopen("customer.csv", "w");

                        fprintf(fcustomer, "%d\n", customerCount);

                        for (int i = 0; i < customerCount; i++)
                        {
                            fprintf(fcustomer, "%d,%s,%s,%s\n", c[i].cid, c[i].cname, c[i].phone, c[i].address);
                        }

                        fclose(fcustomer);

                    } while (choice4 != 5);
                    break;

                case 4:
                    do
                    {
                        printf("\n*********MANAGE ORDER*********\n\n");
                        printf("1. ADD ORDER\n");
                        printf("2. UPDATE ORDER\n");
                        printf("3. DISPLAY ORDER\n");
                        printf("4. DELETE ORDER\n");
                        printf("5. EXIT\n");

                        scanf("%d", &choice5);

                        switch (choice5)
                        {
                        case 1:
                            f = addOrder(o, c, m, orderCount, customerCount, menuCount);
                            if (f == 1)
                            {
                                orderCount++;
                            }
                            break;

                        case 2:
                            updateOrder(o, c, m, orderCount, customerCount, menuCount);
                            break;

                        case 3:
                            displayOrder(o, orderCount);
                            break;

                        case 4:
                            z = deleteOrder(o, orderCount);
                            if (z == 1)
                            {
                                orderCount--;
                            }
                            else
                            {
                                printf("Order not found !!!\n");
                            }
                            break;

                        case 5:
                            break;
                        }

                        FILE *forder;
                        forder = fopen("order.csv", "w");

                        fprintf(forder, "%d\n", orderCount);

                        for (int i = 0; i < orderCount; i++)
                        {
                            fprintf(forder, "%d,%s,%d,%d,%d,%.2f\n", o[i].orderId, o[i].customerName, o[i].customerId, o[i].menuItemId, o[i].quantity, o[i].totalPrice);
                        }

                        fclose(forder);

                    } while (choice5 != 5);
                    break;

                case 0:
                    break;

                default:
                    printf("Invalid input!!!\n");
                    break;
                }

            } while (choice1 != 0);
            break;

        case 2:
            search(o, c, e, m, orderCount, customerCount, employeeCount, menuCount);
            break;

        case 3:
            displayRecord(orderCount, customerCount, employeeCount, menuCount);
            break;

        case 4:
            displayReport(o, c, e, m, orderCount, customerCount, employeeCount, menuCount);
            break;

        case 0:
            printf("Exiting programe .......");
            break;

        default:
            printf("Invalid input.Please try again!!!");
            break;
        }
    } while (choice != 0);
    return 0;
}

void addMenu(menu m[MAX_RECORD], int menuCount)
{

    printf("\nEnter item ID:\n");
    scanf("%d", &m[menuCount].mid);

    printf("Enter the name of item:\n");
    scanf(" %[^\n]s", m[menuCount].mname);

    printf("Enter the price of item: \n");
    scanf("%f", &m[menuCount].mprice);

    printf("Item added successfully!!\n");
}

void updateMenu(menu m[MAX_RECORD], int menuCount)
{
    int id;
    printf("\nEnter item id to update: \n");
    scanf("%d", &id);

    for (int i = 0; i < menuCount; i++)
    {
        if (m[i].mid == id)
        {
            printf("Enter new name : ");
            scanf("%s", m[i].mname);

            printf("Enter new price : ");
            scanf("%f", &m[i].mprice);

            printf("Item updated successfully!!!\n");
            return;
        }
    }
    printf("\nItem id not found!!\n");
}

int deleteMenu(menu m[MAX_RECORD], int menuCount)
{
    int id, found = -1;
    printf("\nEnter the id number of item you want to delete:");
    scanf("%d", &id);

    for (int i = 0; i < menuCount; i++)
    {
        if (m[i].mid == id)
        {
            found = i;
            break;
        }
    }

    if (found == -1)
    {
        return 0;
    }

    else
    {
        for (int j = found; j < menuCount - 1; j++)
        {
            m[j] = m[j + 1];
        }
        printf("Menu deleted successfuly\n");
        return 1;
    }
}

void displayMenu(menu m[MAX_RECORD], int menuCount)
{
    for (int i = 0; i < menuCount; i++)
    {
        printf("\nMenu Item %d : \n", i + 1);
        printf("ITEM ID : %d , NAME : %s , PRICE : %.2f\n", m[i].mid, m[i].mname, m[i].mprice);
    }
    if (menuCount == 0)
    {
        printf("\nItem not available!!!\n");
    }
}

void addEmployee(employee e[MAX_RECORD], int employeeCount)
{

    printf("\nEnter Employee ID:\n");
    scanf("%d", &e[employeeCount].eid);

    printf("Enter the name of Employee:\n");
    scanf(" %[^\n]s", e[employeeCount].ename);

    printf("Enter the salary of Employee: \n");
    scanf("%f", &e[employeeCount].esalary);

    printf("Employee added successfully!!\n");
}

void updateEmployee(employee e[MAX_RECORD], int employeeCount)
{
    int id;
    printf("\nEnter Employee id to update: \n");
    scanf("%d", &id);

    for (int i = 0; i < employeeCount; i++)
    {
        if (e[i].eid == id)
        {
            printf("Enter new name : ");
            scanf("%s", e[i].ename);

            printf("Enter new salary : ");
            scanf("%f", &e[i].esalary);

            printf("Employee updated successfully!!!\n");
            return;
        }
    }
    printf("\nEmployee id not found!!\n");
}

int deleteEmployee(employee e[MAX_RECORD], int employeeCount)
{
    int id, found = -1;
    printf("\nEnter the id number of Employee you want to delete :");
    scanf("%d", &id);

    for (int i = 0; i < employeeCount; i++)
    {
        if (e[i].eid == id)
        {
            found = i;
            break;
        }
    }

    if (found == -1)
    {
        return 0;
    }

    else
    {
        for (int j = found; j < employeeCount - 1; j++)
        {
            e[j] = e[j + 1];
        }

        printf("Employee deleted successfully!!!\n");
        return 1;
    }
}

void displayEmployee(employee e[MAX_RECORD], int employeeCount)
{
    for (int i = 0; i < employeeCount; i++)
    {
        printf("\nEMPLOYEE %d : \n", i + 1);
        printf("ID : %d , NAME : %s , SALARY : %.2f\n", e[i].eid, e[i].ename, e[i].esalary);
    }
    if (employeeCount == 0)
    {
        printf("\nEmployee not available!!!\n");
    }
}

void addCustomer(customer c[MAX_RECORD], int customerCount)
{
    printf("\nEnter Customer ID:\n");
    scanf("%d", &c[customerCount].cid);

    printf("Enter Customer Name:\n");
    scanf(" %[^\n]s", c[customerCount].cname);

    printf("Enter Customer Phone:\n");
    scanf(" %[^\n]s", c[customerCount].phone);

    printf("Enter Customer Address:\n");
    scanf(" %[^\n]s", c[customerCount].address);

    printf("Customer added successfully!\n");
}

void updateCustomer(customer c[MAX_RECORD], int customerCount)
{
    int id;
    printf("\nEnter Customer ID to update: \n");
    scanf("%d", &id);

    for (int i = 0; i < customerCount; i++)
    {
        if (c[i].cid == id)
        {
            printf("Enter new name: ");
            scanf(" %[^\n]s", c[i].cname);

            printf("Enter new phone: ");
            scanf(" %[^\n]s", c[i].phone);

            printf("Enter new address: ");
            scanf(" %[^\n]s", c[i].address);

            printf("Customer updated successfully!\n");
            return;
        }
    }
    printf("\nCustomer ID not found!\n");
}

int deleteCustomer(customer c[MAX_RECORD], int customerCount)
{
    int id, found = -1;
    printf("\nEnter the Customer ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < customerCount; i++)
    {
        if (c[i].cid == id)
        {
            found = i;
            break;
        }
    }

    if (found == -1)
    {
        return 0;
    }

    else
    {
        for (int j = found; j < customerCount - 1; j++)
        {
            c[j] = c[j + 1];
        }

        printf("Customer deleted successfully!\n");
        return 1;
    }

    printf("Customer ID not found!\n");
}

void displayCustomer(customer c[MAX_RECORD], int customerCount)
{
    for (int i = 0; i < customerCount; i++)
    {
        printf("\nCustomer %d : \n", i + 1);
        printf("ID: %d, NAME: %s, PHONE: %s, ADDRESS: %s\n", c[i].cid, c[i].cname, c[i].phone, c[i].address);
    }
    if (customerCount == 0)
    {
        printf("\nNo customers available!\n");
    }
}

int addOrder(order o[MAX_RECORD], customer c[MAX_RECORD], menu m[MAX_RECORD], int orderCount, int customerCount, int menuCount)
{
    int customerId, menuItemId;

    printf("\nEnter Customer ID:\n");
    scanf("%d", &customerId);

    int customerExists = 0;
    for (int i = 0; i < customerCount; i++)
    {
        if (c[i].cid == customerId)
        {
            customerExists = 1;
            break;
        }
    }

    if (customerExists == 0)
    {
        printf("Customer ID not found! Order cannot be placed.\n");
        return 0;
    }

    printf("\n****CURRENT MENU****\n");
    displayMenu(m, menuCount);

    if (menuCount == 0)
    {
        printf("No item available!!!!");
        return 0;
    }

    printf("\nEnter Menu Item ID:\n");
    scanf("%d", &menuItemId);

    int menuItemExists = 0;
    for (int i = 0; i < menuCount; i++)
    {
        if (m[i].mid == menuItemId)
        {
            menuItemExists = 1;
            break;
        }
    }

    if (menuItemExists == 0)
    {
        printf("Menu Item ID not found! Order cannot be placed.\n");
        return 0;
    }

    printf("Enter Order ID:\n");
    scanf("%d", &o[orderCount].orderId);

    printf("Enter Customer Name:\n");
    scanf(" %[^\n]s", o[orderCount].customerName);

    o[orderCount].customerId = customerId;
    o[orderCount].menuItemId = menuItemId;

    printf("Enter Quantity:\n");
    scanf("%d", &o[orderCount].quantity);

    for (int i = 0; i < menuCount; i++)
    {
        if (m[i].mid == o[orderCount].menuItemId)
        {
            o[orderCount].totalPrice = m[i].mprice * o[orderCount].quantity;
            break;
        }
    }

    printf("Total Price: %.2f\n", o[orderCount].totalPrice);

    printf("Order added successfully!\n");

    return 1;
}

void updateOrder(order o[MAX_RECORD], customer c[MAX_RECORD], menu m[MAX_RECORD], int orderCount, int customerCount, int menuCount)
{
    int id, customerId;
    printf("\nEnter Order ID to update: \n");
    scanf("%d", &id);

    for (int i = 0; i < orderCount; i++)
    {
        if (o[i].orderId == id)
        {
            printf("\nEnter new Customer ID:\n");
            scanf("%d", &customerId);

            int customerExists = 0;
            for (int i = 0; i < customerCount; i++)
            {
                if (c[i].cid == customerId)
                {
                    customerExists = 1;
                    break;
                }
            }

            if (customerExists == 0)
            {
                printf("Customer ID not found! Order cannot be placed.\n");
                return;
            }

            printf("Enter new Customer Name: ");
            scanf(" %[^\n]s", o[i].customerName);

            int newMenuItemId;
            printf("Enter new Menu Item ID: ");
            scanf("%d", &newMenuItemId);

            int menuItemFound = 0;
            for (int j = 0; j < menuCount; j++)
            {
                if (m[j].mid == newMenuItemId)
                {
                    menuItemFound = 1;
                    break;
                }
            }

            if (menuItemFound == 0)
            {
                printf("Menu item with ID %d not found. Order not updated.\n", newMenuItemId);
                return;
            }

            o[i].customerId = customerId;
            o[i].menuItemId = newMenuItemId;

            printf("Enter new Quantity: ");
            scanf("%d", &o[i].quantity);

            for (int j = 0; j < menuCount; j++)
            {
                if (m[j].mid == o[i].menuItemId)
                {
                    o[i].totalPrice = m[j].mprice * o[i].quantity;
                    break;
                }
            }

            printf("Total Price: %.2f\n", o[i].totalPrice);
            printf("Order updated successfully!\n");
            return;
        }
    }
    printf("\nOrder ID not found!\n");
}

int deleteOrder(order o[MAX_RECORD], int orderCount)
{
    int id, found = -1;
    printf("\nEnter the Order ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < orderCount; i++)
    {
        if (o[i].orderId == id)
        {
            found = i;
            break;
        }
    }

    if (found == -1)
    {
        return 0;
    }

    else
    {
        for (int j = found; j < orderCount - 1; j++)
        {
            o[j] = o[j + 1];
        }

        printf("Order deleted successfully!\n");
        return 1;
    }
}

void displayOrder(order o[MAX_RECORD], int orderCount)
{
    for (int i = 0; i < orderCount; i++)
    {
        printf("\nOrder %d : \n", i + 1);
        printf("ORDER ID: %d , CUSTOMER NAME: %s , MENU ITEM ID: %d , QUANTITY: %d , TOTAL PRICE: %.2f\n",
               o[i].orderId, o[i].customerName, o[i].menuItemId, o[i].quantity, o[i].totalPrice);
    }
    if (orderCount == 0)
    {
        printf("\nNo orders available!\n");
    }
}

void search(order o[MAX_RECORD], customer c[MAX_RECORD], employee e[MAX_RECORD], menu m[MAX_RECORD], int orderCount, int customerCount, int employeeCount, int menuCount)
{
    int choice;
    do
    {
        printf("\n******SEARCH******\n\n");
        printf("1. SEARCH FOR MENU\n");
        printf("2. SEARCH FOR EMPLOYEE\n");
        printf("3. SEARCH FOR CUSTOMER\n");
        printf("4. SEARCH FOR ORDER\n");
        printf("0. EXIT\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            searchMenu(m, menuCount);
            break;

        case 2:
            searchEmployee(e, employeeCount);
            break;

        case 3:
            searchCustomer(c, customerCount);
            break;

        case 4:
            searchOrder(o, orderCount);
            break;

        case 0:
            break;

        default:
            printf("Invalid Input!!!\n");
            break;
        }

    } while (choice != 0);
}

void searchMenu(menu m[MAX_RECORD], int menuCount)
{
    int choice;
    do
    {
        printf("\n******SEARCH MENU******\n\n");
        printf("1.SEARCH BY NAME\n");
        printf("2.SEARCH BY MENU ID\n");
        printf("3.EXIT\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            searchMenuByName(m, menuCount);
            break;

        case 2:
            searchMenuById(m, menuCount);
            break;

        case 3:
            break;

        default:
            printf("\nInvalid input\n");
            break;
        }
    } while (choice != 3);
}

void searchMenuByName(menu m[MAX_RECORD], int menuCount)
{
    int found = 0;
    char name[50];
    printf("\nEnter the name of item\n");
    scanf(" %[^\n]s", name);
    for (int i = 0; i < menuCount; i++)
    {
        if (strcmp(m[i].mname, name) == 0)
        {
            printf("ID: %d, NAME: %s, PRICE: %.2f\n", m[i].mid, m[i].mname, m[i].mprice);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("Item not found!!!\n");
    }
}

void searchMenuById(menu m[MAX_RECORD], int menuCount)
{
    int found = 0;
    int id;

    printf("\nEnter the id of item\n");
    scanf("%d", &id);

    for (int i = 0; i < menuCount; i++)
    {
        if (m[i].mid == id)
        {
            printf("ID: %d, NAME: %s, PRICE: %.2f\n", m[i].mid, m[i].mname, m[i].mprice);
            found = 1;
        }
    }

    if (found == 0)
    {
        printf("\nItem not found!!!\n");
    }
}

void searchEmployee(employee e[MAX_RECORD], int employeeCount)
{
    int choice;
    do
    {
        printf("\n******SEARCH EMPLOYEE******\n\n");
        printf("1.SEARCH BY NAME\n");
        printf("2.SEARCH BY EMPLOYEE ID\n");
        printf("3.EXIT\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            searchEmployeeByName(e, employeeCount);
            break;

        case 2:
            searchEmployeeById(e, employeeCount);
            break;

        case 3:
            break;

        default:
            printf("\nInvalid input\n");
            break;
        }
    } while (choice != 3);
}

void searchEmployeeByName(employee e[MAX_RECORD], int employeeCount)
{
    int found = 0;
    char name[50];

    printf("\nEnter the name of Employee\n");
    scanf(" %[^\n]s", name);

    for (int i = 0; i < employeeCount; i++)
    {
        if (strcmp(e[i].ename, name) == 0)
        {
            printf("EMPLOYEE ID: %d, NAME: %s, SALARY: %.2f\n", e[i].eid, e[i].ename, e[i].esalary);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("Item not found!!!\n");
    }
}

void searchEmployeeById(employee e[MAX_RECORD], int employeeCount)
{
    int found = 0;
    int id;

    printf("\nEnter employee id \n");
    scanf("%d", &id);

    for (int i = 0; i < employeeCount; i++)
    {
        if (e[i].eid == id)
        {
            printf("EMPLOYEE ID: %d, NAME: %s, SALARY: %.2f\n", e[i].eid, e[i].ename, e[i].esalary);

            found = 1;
        }
    }

    if (found == 0)
    {
        printf("\nItem not found!!!\n");
    }
}

void searchCustomer(customer c[MAX_RECORD], int customerCount)
{
    int choice;
    do
    {
        printf("\n******SEARCH CUSTOMER******\n\n");
        printf("1. SEARCH BY NAME\n");
        printf("2. SEARCH BY CUSTOMER ID\n");
        printf("3. EXIT\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            searchCustomerByName(c, customerCount);
            break;

        case 2:
            searchCustomerById(c, customerCount);
            break;

        case 3:
            break;

        default:
            printf("\nInvalid input\n");
            break;
        }
    } while (choice != 3);
}

void searchCustomerByName(customer c[MAX_RECORD], int customerCount)
{
    char name[50];
    printf("\nEnter the name of the customer to search: ");
    scanf(" %[^\n]s", name);

    int found = 0;
    for (int i = 0; i < customerCount; i++)
    {
        if (strcmp(c[i].cname, name) == 0)
        {
            printf("Customer found:\n");
            printf("ID: %d, Name: %s, Phone: %s, Address: %s\n", c[i].cid, c[i].cname, c[i].phone, c[i].address);
            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("Customer with name '%s' not found.\n", name);
    }
}

void searchCustomerById(customer c[MAX_RECORD], int customerCount)
{
    int id;
    printf("\nEnter the ID of the customer to search: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < customerCount; i++)
    {
        if (c[i].cid == id)
        {
            printf("Customer found:\n");
            printf("ID: %d, Name: %s, Phone: %s, Address: %s\n", c[i].cid, c[i].cname, c[i].phone, c[i].address);
            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("Customer with ID '%d' not found.\n", id);
    }
}

void searchOrder(order o[MAX_RECORD], int orderCount)
{
    int choice;
    do
    {
        printf("\n******SEARCH ORDER******\n\n");
        printf("1.SEARCH ORDER BY CUSTOMER ID\n");
        printf("2.SEARCH BY ORDER ID\n");
        printf("3.EXIT\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            searchOrderByCustomerId(o, orderCount);
            break;

        case 2:
            searchOrderById(o, orderCount);
            break;

        case 3:
            break;

        default:
            printf("\nInvalid input\n");
            break;
        }
    } while (choice != 3);
}

void searchOrderByCustomerId(order o[MAX_RECORD], int orderCount)
{
    int found = 0;
    int id;

    printf("\nEnter the id of customer\n");
    scanf(" %d", &id);

    for (int i = 0; i < orderCount; i++)
    {
        if (o[i].customerId == id)
        {
            printf("ORDER ID: %d , CUSTOMER NAME: %s , MENU ITEM ID: %d , QUANTITY: %d , TOTAL PRICE: %.2f\n",
                   o[i].orderId, o[i].customerName, o[i].menuItemId, o[i].quantity, o[i].totalPrice);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("Item not found!!!\n");
    }
}

void searchOrderById(order o[MAX_RECORD], int orderCount)
{
    int found = 0;
    int id;

    printf("\nEnter order id \n");
    scanf("%d", &id);

    for (int i = 0; i < orderCount; i++)
    {
        if (o[i].orderId == id)
        {
            printf("ORDER ID: %d , CUSTOMER NAME: %s , MENU ITEM ID: %d , QUANTITY: %d , TOTAL PRICE: %.2f\n",
                   o[i].orderId, o[i].customerName, o[i].menuItemId, o[i].quantity, o[i].totalPrice);

            found = 1;
        }
    }

    if (found == 0)
    {
        printf("\nItem not found!!!\n");
    }
}

void displayRecord(int orderCount, int customerCount, int employeeCount, int menuCount)
{
    int choice;
    do
    {
        printf("\n********RECORDS********\n\n");
        printf("1. DISPLAY TOTAL NO. OF MENU ITEM\n");
        printf("2. DISPLAY TOTAL NO. OF EMPLOYEE\n");
        printf("3. DISPLAY TOTAL NO. OF CUSTOMER\n");
        printf("4. DISPLAY TOTAL NO. OF ORDERS\n");
        printf("0. EXIT\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            displayMenuRecord(menuCount);
            break;
        case 2:
            displayEmployeeRecord(employeeCount);
            break;
        case 3:
            displayCustomerRecord(customerCount);
            break;
        case 4:
            displayOrderRecord(orderCount);
            break;
        case 0:
            break;
        default:
            printf("Invalid Input!!!\n");
            break;
        }
    } while (choice != 0);
}

void displayMenuRecord(int menuCount)
{

    printf("Total Menu Item Added: %d\n", menuCount);
}

void displayEmployeeRecord(int employeeCount)
{

    printf("Total No. Of Employee Added: %d\n", employeeCount);
}

void displayCustomerRecord(int customerCount)
{

    printf("Total Customer Added: %d\n", customerCount);
}
void displayOrderRecord(int orderCount)
{

    printf("Total Orders Added: %d\n", orderCount);
}

void displayReport(order o[MAX_RECORD], customer c[MAX_RECORD], employee e[MAX_RECORD], menu m[MAX_RECORD], int orderCount, int customerCount, int employeeCount, int menuCount)
{
    int choice;
    do
    {
        printf("\n********REPORT********\n\n");
        printf("1. DISPLAY MEANINGFUL REPORT FOR MENU\n");
        printf("2. DISPLAY MEANINGFUL REPORT FOR EMPLOYEE\n");
        printf("3. DISPLAY MEANINGFUL REPORT FOR CUSTOMER\n");
        printf("4. DISPLAY MEANINGFUL REPORT FOR ORDERS\n");
        printf("0. EXIT\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            displayMenuReport(o, m, orderCount, menuCount);
            break;
        case 2:
            displayEmployeeReport(e, employeeCount);
            break;
        case 3:
            displayCustomerReport(c, customerCount);
            break;
        case 4:
            displayOrderReport(o, orderCount);
            break;
        case 0:
            break;
        default:
            printf("Invalid Input!!!\n");
            break;
        }
    } while (choice != 0);
}

void displayMenuReport(order o[MAX_RECORD], menu m[MAX_RECORD], int orderCount, int menuCount)
{
    printf("\n********MENU REPORT********\n\n");
    if (menuCount == 0)
    {
        printf("No menu item available!!\n");
        return;
    }

    int index = -1;
    int mostOrder = 0;

    int orderCounts[MAX_RECORD] = {0};

    for (int i = 0; i < orderCount; i++)
    {
        for (int j = 0; j < menuCount; j++)
        {
            if (o[i].menuItemId == m[j].mid)
            {
                orderCounts[j] += o[i].quantity;
            }
        }
    }

    for (int i = 0; i < menuCount; i++)
    {
        if (orderCounts[i] > mostOrder)
        {
            mostOrder = orderCounts[i];
            index = i;
        }
    }

    for (int i = 0; i < menuCount; i++)
    {
        printf("Item ID: %d, Name: %s, Price: %.2f, Orders: %d\n",
               m[i].mid, m[i].mname, m[i].mprice, orderCounts[i]);
    }

    if (mostOrder != -1)
    {
        printf("\nMost Ordered Menu Item: %s with %d orders\n",
               m[index].mname, mostOrder);
    }

    printf("\n*****************END OF REPORT*****************\n");
}

void displayEmployeeReport(employee e[MAX_RECORD], int employeeCount)
{
    printf("\n******EMPLOYEE REPORT******\n\n");
    if (employeeCount == 0)
    {
        printf("No employees available to display.\n");
        return;
    }

    float totalSalary = 0;
    float highestSalary = 0;
    float lowestSalary = e[0].esalary;
    int highIndex = 0;
    int lowIndex = 0;

    for (int i = 0; i < employeeCount; i++)
    {
        totalSalary += e[i].esalary;
        if (e[i].esalary > highestSalary)
        {
            highestSalary = e[i].esalary;
            highIndex = i;
        }
        if (e[i].esalary < lowestSalary)
        {
            lowestSalary = e[i].esalary;
            lowIndex = i;
        }
    }

    float averageSalary = totalSalary / employeeCount;

    printf("\n******SUMMARY******\n\n");

    printf("Total Number of Employees: %d\n", employeeCount);
    printf("Total Salary Expenditure: %.2f\n", totalSalary);
    printf("Average Salary: %.2f\n\n", averageSalary);

    printf("Employee with the Highest Salary:\n");
    printf("ID: %d, Name: %s, Salary: %.2f\n\n", e[highIndex].eid, e[highIndex].ename, e[highIndex].esalary);

    printf("Employee with the Lowest Salary:\n");
    printf("ID: %d, Name: %s, Salary: %.2f\n\n", e[lowIndex].eid, e[lowIndex].ename, e[lowIndex].esalary);

    printf("********EMPLOYEE LIST********\n\n");
    printf("--------------------------------------------------\n");
    printf("| %-5s | %-20s | %-15s |\n", "ID", "NAME", "SALARY");
    printf("--------------------------------------------------\n");

    for (int i = 0; i < employeeCount; i++)
    {
        printf("| %-5d | %-20s | %-15f |\n", e[i].eid, e[i].ename, e[i].esalary);
    }

    printf("--------------------------------------------------\n");

    printf("\n******************END OF REPORT******************\n");
}

void displayCustomerReport(customer c[MAX_RECORD], int customerCount)
{
    if (customerCount == 0)
    {
        printf("\nNo customers available to display the report!\n");
        return;
    }

    printf("\n*********CUSTOMER LIST********\n");
    printf("-----------------------------------------------------------------------------------\n");
    printf("| %-5s | %-20s | %-15s | %-30s |\n", "ID", "NAME", "PHONE", "ADDRESS");
    printf("-----------------------------------------------------------------------------------\n");

    for (int i = 0; i < customerCount; i++)
    {
        printf("| %-5d | %-20s | %-15s | %-30s |\n", c[i].cid, c[i].cname, c[i].phone, c[i].address);
    }

    printf("-----------------------------------------------------------------------------------\n");

    printf("\n******************END OF REPORT******************\n");
}

void displayOrderReport(order o[MAX_RECORD], int orderCount)
{
    printf("\n\n********** ORDER REPORT **********\n");

    if (orderCount == 0)
    {
        printf("No orders available!\n");
        return;
    }

    double totalRevenue = 0.0;
    int totalQuantity = 0;
    double maxPrice = o[0].totalPrice;
    double minPrice = o[0].totalPrice;
    int maxIndex = 0;
    int minIndex = 0;

    for (int i = 0; i < orderCount; i++)
    {
        totalRevenue += o[i].totalPrice;
        totalQuantity += o[i].quantity;

        if (o[i].totalPrice > maxPrice)
        {
            maxPrice = o[i].totalPrice;
            maxIndex = i;
        }
        if (o[i].totalPrice < minPrice)
        {
            minPrice = o[i].totalPrice;
            minIndex = i;
        }
    }

    printf("\n********** SUMMARY **********\n\n");
    printf("Total Revenue           : $%.2f\n", totalRevenue);
    printf("Total Quantity Sold     : %d\n", totalQuantity);
    printf("Order with Highest Price: Order ID %d, Total Price $%.2f\n", o[maxIndex].orderId, maxPrice);
    printf("Order with Lowest Price : Order ID %d, Total Price $%.2f\n", o[minIndex].orderId, minPrice);
    printf("Average Order Value     : $%.2f\n", totalRevenue / orderCount);

    printf("\n*********ORDER LIST********\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("| %-8d | %-20s | %-10s | %-11s | %-14s |\n", "ID", "CUSTOMER NAME", "ITEM ID", "QUANTITY", "TOTAL PRICE");
    printf("-------------------------------------------------------------------------------\n");

    for (int i = 0; i < orderCount; i++)
    {
        printf("| %-8d | %-20s | %-10d | %-11d | %-14.2f |\n", o[i].orderId, o[i].customerName, o[i].menuItemId, o[i].quantity, o[i].totalPrice);
    }

    printf("-------------------------------------------------------------------------------\n");

    printf("\n********** END OF REPORT **********\n\n");
}