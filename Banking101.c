#include<stdio.h>

//coded by Prashidhha Raj Sharma// Started
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
void balancein( int accnumber);
void display(int accnumber);
void fastcash(int accnumber);
void desposit(int accnumber);
void fund_transfer(int fromnumber);
void nor_withdrawal(int accnumber);
// void aboutus();
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
        balancein(accnumber);
        break;
    case 3:
        printf("Enter your account number");
        scanf("%d",&accnumber);
        display(accnumber);
        break;
  
    
    case 4:
        printf("Enter your account number");
        scanf("%d",&accnumber);
        fastcash(accnumber);
        break;
    case 5:
        printf("Enter your account number");
        scanf("%d",&accnumber);
        desposit(accnumber);
        break;
    case 6:
        printf("Enter your account number");
        scanf("%d",&accnumber);
        fund_transfer(accnumber);
        break;
    case 7:
        printf("Enter your account number");
        scanf("%d",&accnumber);
        nor_withdrawal(accnumber);
        break;
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


//coded by Prasiddha Raj Shamra// Ended

//coded by Ashish parajuli // Started 
void display(int accnumber)
{
    for (int i = 0; i < countcus; i++)
    {
        if (customer[i].accnumber == accnumber)
        {
            printf("\nClient's Account Details\n");
            printf("Name: %s\n", customer[i].name);
            printf("Account number: %d\n", customer[i].accnumber);
            printf("Address: %s\n", customer[i].address);
            printf("Contact info: %d\n", customer[i].contact_info);
            printf("Office address: %s\n", customer[i].office_address);
            printf("Current balance: %.2f\n", customer[i].balance);
        }
        else
        {
         printf("Account not found");
        }
    }
   
}

//coded by Ashish Parajuli // ended //

//coded by Rijen Kayastha// Started 

void fastcash(int accnumber)
    {
    int choose;
    float withdraw_amt=0;

    for (int i = 0; i < countcus; i++)
    {
        if (customer[i].accnumber == accnumber)
        {
             printf("Choose the Amount you want to withdraw\n 1.500\n 2.1000\n 3.2000\n 4.3000\n 5.5000\n");
            scanf("%d", &choose);
               switch(choose) {
                           
                        case 1:
                            withdraw_amt = 500;
                            break;
                        case 2:
                            withdraw_amt = 1000;
                            break;
                        case 3:
                            withdraw_amt = 2000;
                            break;
                        case 4:
                            withdraw_amt = 3000;
                            break;
                        case 5:
                            withdraw_amt = 5000;
                            break;
                        default:
                            printf("Enter the Number from(1-5)::\n");
                            return;
        
                        }
                        if (withdraw_amt > customer[i].balance){
                            printf("Insufficent Balance!!!\n");
                            }
             else {
            customer[i].balance -= withdraw_amt;
            printf("FastCash Withdrawal Successful!! \n Your Current balance is %.2f",customer[i].balance);
            } return;
        } 
        else{
    printf("Account not found\n");
            }   
        }
}
 void desposit(int accnumber)

{ 
    FILE *fp= fopen("account.txt","a");

    float amount;
   
    for (int i = 0; i<countcus; i++)
    {
        if(customer[i].accnumber==accnumber)
        {
        printf("Enter the amount you want to deposit\n");
        scanf("%f", &amount);

        customer[i].balance += amount;


        printf("The Amount has been successfully added to your account\n");
        printf("The Current Balance is %.2f",customer[i].balance);

        fprintf(fp,"Rs%f has been Deposited into your account\n",amount);

        }

        

    }
}

void nor_withdrawal(int accnumber)
{
    float amount;
    for (int i = 0; i < countcus; i++)
    {
        if (customer[i].accnumber == accnumber)
        {
            printf("Enter the Amount you want to withdraw\n");
            
            scanf("%f", &amount);

            if (customer[i].balance >= amount)
                {
                customer[i].balance -= amount;
                printf(" Normal withdrawal successful! New balance: %.2f\n", customer[i].balance);
                } else{
                printf("Insufficient balance!\n");
                 }
        } else{
    printf("Account not found\n");
             }
    }
    
        
}  
//coded by Rijen Kayastha// ended 



//coded by Nhuja Maharjan// Started
void balancein(int accnumber)
{
    for (int i = 0; i < countcus; i++)
    {
        if (customer[i].accnumber == accnumber)
        {
            printf("Your current balance is %.2f\n", customer[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

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
//coded by Nhuja Maharjan// Ended
