#include<stdio.h>
struct Customer {
    char name[100];
    int accnumber;
    float balance;
    char address[100];
    int contact_info;
    char office_address[100];
};
struct Customer customer[100];
int countcus = 0;

void createcustomer();
// void balancein( int accnumber);
void display(int accnumber);
// void fastcash(int accnumber);
// void desposit(int accnumber);
// void fund_transfer(int fromnumber);
// void nor_withdrawal(int accnumber);
int main(){
    int choice, accnumber;
      while(choice !=8){
    printf("\nHello to the new banking system\n");
    printf("1. NEW CUSTOMER \n");
    printf("2. BALANCE INQUIRY \n");
    printf("3. DISPLAY ACCOUNT DETAILS \n");
    printf("4. FAST CASH WITHDRAWAL \n");
    printf("5. DESPOSIT \n");
    printf("6. FUND TRANSFER \n");
    printf("7. STANDARD WITHDRAW \n");
    printf("8. EXIT \n");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        createcustomer();
        break;
    case 2:
        printf("Enter your account number");
        scanf("%d",&accnumber);
        display(accnumber);
        break;
    // case 3:
    //     printf("Enter your account number");
    //     scanf("%d",&accnumber);
    //     balancein(accnumber);
    //     break;
    
    // case 4:
    //     printf("Enter your account number");
    //     scanf("%d",&accnumber);
    //     fastcash(accnumber);
    //     break;
    // case 5:
    //     printf("Enter your account number");
    //     scanf("%d",&accnumber);
    //     desposit(accnumber);
    //     break;
    // case 6:
    //     printf("Enter your account number");
    //     scanf("%d",&accnumber);
    //     fund_transfer(accnumber);
    //     break;
    // case 7:
    //     printf("Enter your account number");
    //     scanf("%d",&accnumber);
    //     nor_withdrawal(accnumber);
    //     break;
    case 8:
        printf("Now Existing the SYSTEM");
        return 0;
    default:
        printf("The doesn't recongize this command");
        break;
    } 
    }
    printf("Existing the system");
}
void createcustomer(){
    printf("Enter the client's name: \n");
    scanf("%s",customer[countcus].name);
    printf("Enter the client's account number:  \n");
    scanf("%d", &customer[countcus].accnumber);
    printf("Enter the client's address:  \n");
    scanf("%s", customer[countcus].address);
    printf("Enter the client's contact information:  \n");
    scanf("%d", &customer[countcus].contact_info);
    printf("Enter the client's office address:  \n");
    scanf("%s", customer[countcus].office_address);
    printf("Enter the client's balance:  \n");
    scanf("%f", &customer[countcus].balance);
    countcus++;
    printf("Client's account added successfully! \n");
}

void display(int accnumber){
    for (int i = 0; i < countcus; i++) {
        if (customer[i].accnumber == accnumber) {
            printf("\nClient's Account Details\n");
            printf("Name: %s\n", customer[i].name);
            printf("Account number: %d\n", customer[i].accnumber);
            printf("Address: %s\n", customer[i].address);
            printf("Contact info: %d\n", customer[i].contact_info);
            printf("Office address: %s\n", customer[i].office_address);
            printf("Current balance: %.2f\n", customer[i].balance);
        }
    }
    printf("Account not found/n");
}
