#include <stdio.h>

void transferFunds(float *fromAccount, float *toAccount, float amount)
{
    if (*fromAccount >= amount)
    {
        *fromAccount -= amount;
        *toAccount += amount;
        printf("Transfer successful. Transferred %.2f\n", amount);
    }
    else
    {
        printf("Insufficient funds. Transfer failed.\n");
    }
}

int main()
{
    float account1 = 1000.0;
    float account2 = 500.0;
    float amount;

    printf("Enter the amount to transfer: ");
    scanf("%f", &amount);

    printf("Account 1 balance: %.2f\n", account1);
    printf("Account 2 balance: %.2f\n", account2);

    transferFunds(&account1, &account2, amount);

    printf("Account 1 balance: %.2f\n", account1);
    printf("Account 2 balance: %.2f\n", account2);

    return 0;
}