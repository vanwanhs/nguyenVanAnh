#ifndef FUNCTION_H
#define FUNCTION_H
void saveUser(User users[], int n);
void loadUser(User user[], int *n);
void saveLogAcc (LogAcc user02[], int n);
void loadLogAcc (LogAcc user02[], int *n);
void finish(void);
void menu(int *choice);
void loginAcc(account *acc, int *run);
void listUser(void);
void menuAdmin(int *choice);
void menuUser(void);
void addUser(User users[],int *n);
void showListUser(User users[], int *n);
void accOfUser(void);
void saveAccUser (account user01[], int n);
void loadAccUser (account user01[], int *n);
void info(LogAcc user02[], int *n);
void showLogAcc(LogAcc user02[], int *n);
#endif
