//THIS IS AN EXAMPLE CODE ONLY DONT COPY 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "accounts.dat"

// Structure to store customer details
typedef struct {
    char name[50];
    int accountNumber;
    float balance;
} Customer;

// Function prototypes
void createAccount();
void displayAccount();
void deposit();
void withdraw();
void fastCash();
void saveAccount(Customer c);
Customer *findAccount(int accNo);

int main() {
    int choice;
    while (1) {
        printf("\nBanking System Menu:\n");
        printf("1. Create Account\n");
        printf("2. Display Account\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Fast Cash\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: displayAccount(); break;
            case 3: deposit(); break;
            case 4: withdraw(); break;
            case 5: fastCash(); break;
            case 6: printf("Exiting...\n"); exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

void createAccount() {
    Customer c;
    printf("Enter Name: ");
    scanf(" %s", c.name);
    printf("Enter Account Number: ");
    scanf("%d", &c.accountNumber);
    c.balance = 0;  // Default balance
    saveAccount(c);
    printf("Account created successfully!\n");
}

void displayAccount() {
    int accNo;
    printf("Enter Account Number: ");
    scanf("%d", &accNo);

    Customer *c = findAccount(accNo);
    if (c) {
        printf("\nAccount Details:\n");
        printf("Name: %s\n", c->name);
        printf("Account Number: %d\n", c->accountNumber);
        printf("Balance: $%.2f\n", c->balance);
        free(c);
    } else {
        printf("Account not found!\n");
    }
}

void deposit() {
    int accNo;
    float amount;
    printf("Enter Account Number: ");
    scanf("%d", &accNo);
    printf("Enter Deposit Amount: ");
    scanf("%f", &amount);

    Customer *c = findAccount(accNo);
    if (c) {
        c->balance += amount;
        saveAccount(*c);
        printf("Deposit successful! New Balance: $%.2f\n", c->balance);
        free(c);
    } else {
        printf("Account not found!\n");
    }
}

void withdraw() {
    int accNo;
    float amount;
    printf("Enter Account Number: ");
    scanf("%d", &accNo);
    printf("Enter Withdrawal Amount: ");
    scanf("%f", &amount);

    Customer *c = findAccount(accNo);
    if (c) {
        if (c->balance >= amount) {
            c->balance -= amount;
            saveAccount(*c);
            printf("Withdrawal successful! New Balance: $%.2f\n", c->balance);
        } else {
            printf("Insufficient balance!\n");
        }
        free(c);
    } else {
        printf("Account not found!\n");
    }
}

void fastCash() {
    int accNo;
    float amount = 100; // Fixed fast cash amount
    printf("Enter Account Number: ");
    scanf("%d", &accNo);

    Customer *c = findAccount(accNo);
    if (c) {
        if (c->balance >= amount) {
            c->balance -= amount;
            saveAccount(*c);
            printf("Fast Cash Withdrawal Successful! New Balance: $%.2f\n", c->balance);
        } else {
            printf("Insufficient balance!\n");
        }
        free(c);
    } else {
        printf("Account not found!\n");
    }
}

void saveAccount(Customer c) {
    FILE *file = fopen(FILENAME, "r+b");
    if (!file) file = fopen(FILENAME, "wb");

    Customer temp;
    int found = 0;
    long pos;
    while (fread(&temp, sizeof(Customer), 1, file)) {
        if (temp.accountNumber == c.accountNumber) {
            pos = ftell(file) - sizeof(Customer);
            fseek(file, pos, SEEK_SET);
            fwrite(&c, sizeof(Customer), 1, file);
            found = 1;
            break;
        }
    }
    if (!found) fwrite(&c, sizeof(Customer), 1, file);
    fclose(file);
}

Customer *findAccount(int accNo) {
    FILE *file = fopen(FILENAME, "rb");
    if (!file) return NULL;

    Customer *c = malloc(sizeof(Customer));
    while (fread(c, sizeof(Customer), 1, file)) {
        if (c->accountNumber == accNo) {
            fclose(file);
            return c;
        }
    }
    fclose(file);
    free(c);
    return NULL;
}
