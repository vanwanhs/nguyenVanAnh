#include <stdio.h>
#include <string.h>
#include <stdbool.h> 
#include "datatypy.h"
#include "function.h"
void saveUser(User users[], int n) {
	// Mo file 
	FILE *ptr=fopen("ListUser.dat","wb");
	// Thao tac file
	if(ptr==NULL){
		printf("Khong mo duoc file\n");
	}
	fwrite(users,sizeof(User),n,ptr);
	printf("Luu thong tin thanh cong\n");
	// Dong file 
	fclose(ptr);
}
void loadUser(User users[], int *n) {
    FILE *ptr = fopen("ListUser.dat", "rb");
    if (ptr == NULL) {
        printf("Khong the mo tep!\n");
        return;
    }
    User readUsers[100];
    *n = fread(readUsers, sizeof(User), 100, ptr);
    for (int i = 0; i < *n; i++) {
        printf("User Name: %s\n", readUsers[i].userName);
        printf("User ID: %s\n", readUsers[i].userId);
        printf("Full Name: %s\n", readUsers[i].name);
        printf("Date of Birth: %d/%d/%d\n", readUsers[i].dateOfBirth.month, readUsers[i].dateOfBirth.day, readUsers[i].dateOfBirth.year);
        printf("Account ID: %s\n", readUsers[i].UserAccount.userId);
        printf("Balance: %.2f\n", readUsers[i].UserAccount.balance);
        printf("Gender: %s\n", readUsers[i].gender ? "Male" : "Female");
        printf("Phone: %s\n", readUsers[i].phone);
        printf("Email: %s\n", readUsers[i].email);
        printf("\n");
    }
    fclose(ptr);
    printf("Da luu du lieu thanh cong\n");
}

        // In ra cac dao dich neu co
        /*if (readUsers[i].UserAccount.transactionCount > 0) {
            for (int j = 0; j < readUsers[i].UserAccount.transactionCount; j++) {
                printf("  Transaction %d:\n", j + 1);
                printf("    Transfer ID: %s\n", readUsers[i].UserAccount.TransactionHistory[j].transferId);
                printf("    Receiving ID: %s\n", readUsers[i].UserAccount.TransactionHistory[j].receivingId);
                printf("    Amount: %.2lf\n", readUsers[i].UserAccount.TransactionHistory[j].amount);
                printf("    Type: %s\n", readUsers[i].UserAccount.TransactionHistory[j].type);
                printf("    Message: %s\n", readUsers[i].UserAccount.TransactionHistory[j].message);
                printf("    Transaction Date: %d/%d/%d\n", readUsers[i].UserAccount.TransactionHistory[j].transactionDate.day,
                                                      readUsers[i].UserAccount.TransactionHistory[j].transactionDate.month,
                                                      readUsers[i].UserAccount.TransactionHistory[j].transactionDate.year);
            }
        } else {
            printf("  No transactions.\n");
        }
        printf("\n");
    }*/



// luu mat nguoi dang nhap
void saveAccUser (account user01[], int n){
 // mo file
 FILE *ptr=fopen("AccountUser.dat","wb");
	// Thao tac file
	if(ptr==NULL){
		printf("Khong mo duoc file\n");
	}
	fwrite(user01,sizeof(account),n,ptr);
	printf("Luu thong tin thanh cong\n");
	// Dong file 
	fclose(ptr);	
}
// doc mat khau nguoi dang nhap
void loadAccUser(account user01[], int *n) {
    FILE *ptr = fopen("accountUser.dat", "rb");
    if (ptr == NULL) {
        printf("Khong the mo tep!\n");
        return;
    }
    account readAccount[100];
    *n = fread(readAccount, sizeof(account), 100, ptr);
    
    if (*n <= 0) {
        printf("Khong co du lieu hoac doc du lieu that bai!\n");
        fclose(ptr);
        return;
    }
    // Copy the data into the provided user01 array
    for (int i = 0; i < *n; i++) {
        printf("Email of User: %s\n", readAccount[i].email);
        printf("Password of User: %s\n", readAccount[i].pass);
    }

    fclose(ptr);
    printf("Da luu du lieu thanh cong\n");
}
// thong tin co ban cua nguoi dung
void saveLogAcc (LogAcc user02[], int n){
 // mo file
 FILE *ptr=fopen("LogAcc.dat","wb");
	// Thao tac file
	if(ptr==NULL){
		printf("Khong mo duoc file\n");
	}
	fwrite(user02,sizeof(LogAcc),n,ptr);
	printf("Luu thong tin thanh cong\n");
	// Dong file 
	fclose(ptr);	
}
// doc thong tin co ban cua nguoi dung
void LoadLogAcc(LogAcc user02[], int *n) {
    FILE *ptr = fopen("LogAcc.dat", "rb");
    if (ptr == NULL) {
        printf("Khong the mo tep!\n");
        return;
    }
    LogAcc readLogAcc[100];
    *n = fread(readLogAcc, sizeof(LogAcc), 100, ptr);
    
    if (*n <= 0) {
        printf("Khong co du lieu hoac doc du lieu that bai!\n");
        fclose(ptr);
        return;
    }
    for (int i = 0; i < *n; i++) {
        printf("Name of User: %s\n", readLogAcc[i].name);
        printf("Email of User: %s\n", readLogAcc[i].email);
        printf("Phone of User: %s\n", readLogAcc[i].phone);
        printf("Status of User: %s\n", readLogAcc[i].status ? "Active" : "Inactive");
    }

    fclose(ptr);
    printf("Da luu du lieu thanh cong\n");
}



void finish(void){
	printf("	================	\n");
	printf("	   Thank you		\n");
	printf("	 *See you again*		\n");
	printf("	================	\n");
}
// chon menu
void menu(int *choice){
	printf("*****Bank Manaegement System Using C*****\n");
	printf("            CHOOSE YOUR ROLE             \n");
	printf("	=========================		 \n");
	printf("	[1]. Admin\n");
	printf("	[2]. User\n");
	printf("	[0]. Exit the program\n");
	printf("	=========================		\n");
	printf("	What are you options? ");
	scanf("%d", choice);
}
// dang nhap tai khoan

void loginAcc(account *acc, int *run) {
    int i = 0;
    printf("*****Bank Management System Using C*****\n\n");
    printf("              LOGIN                     \n");
    printf("    =========================           \n");
    printf("    Email: ");
    fgets(acc->email, sizeof(acc->email), stdin);
    acc->email[strcspn(acc->email, "\n")] = '\0';
    printf("    Pass: ");
    while (1) {
        char ch = getch();
        if (ch == '\r' || ch == '\n') { 
            acc->pass[i] = '\0';
            break;
        } else if (ch == 8) {
            if (i > 0) {
                i--;
                printf("\b \b");
            }
        } else {
            acc->pass[i] = ch;
            i++;
            printf("*");
        }
    }

    printf("\n    =========================           \n");
    if (strchr(acc->email, '@') == NULL || strlen(acc->pass) == 0) {
        printf("Email hoac mat khau hong hop le. Vui long thu lai!\n");
        *run = 0;
    } else {
    	printf("Dang nhap thanh cong!\n");
    	*run = 1;
	}
}
// danh sach nguoi dung
void listUser(void){
    char choice[20];
    int running = 1;

    printf("		------------List of user------------------		\n");
    printf("====================================================================================\n");
    printf("| %-10s | %-20s | %-20s | %-11s | %-6s |\n",
           "ID", "Name", "Email", "Phone", "Status");
    printf("====================================================================================\n");
    printf("| %-10s | %-20s | %-20s | %-11s | %-6s |\n",
           "0333928768", "Nguyen Thi Van A", "Vanh@gmail.com", "0999888000", "open");
    printf("| %-10s | %-20s | %-20s | %-11s | %-6s |\n",
           "0333928763", "Nguyen Van A", "A@gmail.com", "0999888777", "Lock");
	 printf("| %-10s | %-20s | %-20s | %-11s | %-6s |\n",
           "0333928763", "Nguyen Van Anh", "Anh@gmail.com", "1234567890", "Lock");
           
    printf("====================================================================================\n");

    do {
        printf("Go back(b) or Exit(0)?: ");
        fgets(choice, sizeof(choice), stdin);
        choice[strcspn(choice, "\n")] = '\0';
        if (strcmp(choice, "b") == 0) {
            printf("Returning to the menu...\n");
            running = 0;
        } else if (strcmp(choice, "0") == 0) {
            printf("Exiting the program...\n");
            running = 0;
        } else {
            printf("Please enter (b or 0)!\n");
        }
    } while (running);
}
void menuAdmin(int *choice1){
	printf("*****Bank Manaegement System Using C*****\n");
	printf("\n");
	printf("		MENU		\n");
	printf("	=========================		 \n");
	printf("	[1]. Add a new user.\n");
	printf("	[2]. Show all user.\n");
	printf("	[3]. Show datail an user.\n");
	printf("	[4]. Lock (unlock) an user.\n");
	printf("	[5]. User guideline.\n");
	printf("	[6]. About us.\n");
	printf("	[0]. Exit the program.\n");
	printf("	=========================		 \n");
	printf("	What are you options?: ");
	scanf("%d", choice1);
}
void menuUser(void){
	printf("anh yeu em\n");
}
void addUser(User users[],int *n){
    printf("Enter number of users: ");
    scanf("%d", n);
    getchar();
    for (int i = 0; i < *n; i++) {
        printf("\nEnter information for user %d:\n", i + 1);
        printf("Enter username: ");
        scanf("%s", users[i].userName);
        getchar();
        do {
            printf("Enter user ID (must be exactly 10 digits): ");
            scanf("%s", users[i].userId);
            if (strlen(users[i].userId) != 10) {
                printf("Invalid user ID! It must be exactly 10 digits.\n");
            }
        } while (strlen(users[i].userId) != 10);
        printf("Enter full name: ");
        getchar();
        fgets(users[i].name, sizeof(users[i].name), stdin);
        users[i].name[strcspn(users[i].name, "\n")] = '\0';
        getchar();
        printf("Enter date of birth (MM DD YYYY): ");
        scanf("%d %d %d", &users[i].dateOfBirth.month, &users[i].dateOfBirth.day, &users[i].dateOfBirth.year);
        printf("Enter gender (1 for male, 0 for female): ");
        scanf("%d", &users[i].gender);
        printf("Enter phone number: ");
        scanf("%s", users[i].phone);
        printf("Enter email: ");
        scanf("%s", users[i].email);
    }
}
// CHi tiet toan bo nguoi dung
void showListUser(User users[], int *n){
	printf("\nUser Information:\n");
    for (int i = 0; i < *n; i++) {
        printf("\nUser %d:\n", i + 1);
        printf("Username: %s\n", users[i].userName);
        printf("User ID: %s\n", users[i].userId);
        printf("Full Name: %s\n", users[i].name);
        printf("Date of Birth: %02d/%02d/%d\n", users[i].dateOfBirth.month, users[i].dateOfBirth.day, users[i].dateOfBirth.year);
        printf("Gender: %s\n", users[i].gender == 1 ? "Male" : "Female");
        printf("Phone: %s\n", users[i].phone);
        printf("Email: %s\n", users[i].email);
    }
}
// hien thong tin co ban
void showLogAcc(LogAcc user02[], int *n) {
    printf("\nUser base of Information:\n");
    if (*n <= 0) {
        printf("No user information available.\n");
        return;
    }

    // Iterate through the user array and print details for each user
    for (int i = 0; i < *n; i++) {
        printf("User %d:\n", i + 1);
        printf("Name: %s\n", user02[i].name);
        printf("Email: %s\n", user02[i].email);
        printf("Phone: %s\n", user02[i].phone);
        printf("Status: %s\n", user02[i].status ? "lock" : "open");
        printf("------------------------\n");
    }
}
// Nhap thong tin co ban
void info(LogAcc user02[],int *n){
	printf("Enter the number of user: ");
	scanf("%d", n);
	getchar();
	for (int i=0; i<*n; i++){
        printf("\nEnter basic information for user %d:\n", i + 1);
        printf("Enter username: ");
        fgets(user02[i].name, sizeof(user02[i].name), stdin);
        user02[i].name[strcspn(user02[i].name, "\n")] = '\0';
        printf("Enter email: ");
        fgets(user02[i].email, sizeof(user02[i].email), stdin);
        user02[i].email[strcspn(user02[i].email, "\n")] = '\0';
        printf("Enter phone: ");
        fgets(user02[i].phone, sizeof(user02[i].phone), stdin);
        user02[i].phone[strcspn(user02[i].phone, "\n")] = '\0';
        // Input for status (active or inactive)
        printf("Enter status (1 for lock, 0 for open): ");
        int statusInput;
        scanf("%d", &statusInput);
        getchar();
        user02[i].status = statusInput == 1;
    }
}





















