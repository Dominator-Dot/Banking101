void fund_transfer(int fromnumber)
{
    int to_accnumber;
    float amount;
    printf("Enter the account number to transfer to: ");
    scanf("%d", &to_accnumber);
    printf("Enter the amount to transfer: ");
    scanf("%f", &amount);

    int from_index = -1, to_index = -1;
    for (int i = 0; i < countcus; i++) {
        if (customer[i].accnumber == fromnumber) {
            from_index = i;
        }
        if (customer[i].accnumber == to_accnumber) {
            to_index = i;
        }
    }

    if (from_index == -1 || to_index == -1) {
        printf("Account number not found.\n");
        return;
    }

    if (customer[from_index].balance >= amount) {
        customer[from_index].balance -= amount;
        customer[to_index].balance += amount;
        printf("Transfer successful. Transferred %.2f\n", amount);
    } else {
        printf("Insufficient funds. Transfer failed.\n");
    }
}