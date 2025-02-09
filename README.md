
#include <stdio.h>

void transferFunds(double *fromAccount, double *toAccount, double amount) {
    if (*fromAccount >= amount) {
        *fromAccount -= amount;
        *toAccount += amount;
        printf("Transfer successful. Transferred %.2f\n", amount);
    } else {
        printf("Insufficient funds. Transfer failed.\n");
    }
}

int main() {
    double account1 = 1000.0;
    double account2 = 500.0;
    double amount = 200.0;

    printf("Account 1 balance: %.2f\n", account1);
    printf("Account 2 balance: %.2f\n", account2);

    transferFunds(&account1, &account2, amount);

    printf("Account 1 balance: %.2f\n", account1);
    printf("Account 2 balance: %.2f\n", account2);

    return 0;
}
```