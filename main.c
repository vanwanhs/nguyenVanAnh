#include <stdio.h>
#include <stdlib.h>
#include "datatypy.h"
#include "function.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	User users[100];
	account acc;
	account user01;
	LogAcc user02[100];
	int n;
	int running=1;
	int choice=0;
	int run=0;
	while (run == 0) {
        loginAcc(&acc, &run);
        //saveAccUser(user01,n); thong tin tai khoan dang nhap
    }
    listUser();
	info(user02, &n);
    saveLogAcc(user02, n);
	do{
		menu(&choice);
		switch (choice){
			case 1:
			menuAdmin(&choice);
			switch (choice){
				case 1:
					addUser(users, &n);
					saveUser(users,n);
					break;
				case 2:
					//listUser();
					//loadLogAcc(user02, &n);
					//showLogAcc(user02, &n);
					break;
				case 3:
					loadUser(users, &n);
					showListUser(users, &n);
					break;
			}
			break;
			case 2:
			menuUser();
			case 0:
			finish();
			running=0;
			break;
			default:
			printf("Khong hop le!");
		}
	}while (running);
	return 0;
}
