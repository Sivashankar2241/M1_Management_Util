#include "management.h"
#include "management.c"

void menu(void);

void menu(void);
void password(void);

int main(){
	system("color 7");
	password();
	getch();
}

void menu(){
	system("cls");
	printf("PHONELOG MANAGEMENT\n");
    printf("1.Add\n");
	printf("2.List\n");
	printf("3.Delete\n");
	printf("4.Exit\n");
	switch(getch()){
		case '1':
			namefun();
			break;
		case '2':
			listfun();
			break;
        case '3':
            deletefun();
            break;
		case '4':
			exitfun();
			break;
		default:
			system("cls");
			printf("Invalid Enter.");
			getch();
}
}
void password(void){
	char passwords[20]={"siva"};
	char name[40]="Admin Access\n";
		printf("%s",name);
	printf("Password:\n");
	char ch,pass[20];
	char w='*';
	int i=0;
	while(ch!=13){
		ch=getch();
		if(ch!=13 && ch!=8){
			printf("%c",w);
			pass[i]=ch;
			i++;
		}
			}
	pass[i]='\0';
	if(strcmp(pass,passwords)==0)
        {
		printf("\nCORRECT PASSWORD.");
		Sleep(100);
		menu();
	}
	else{
		printf("PASSWORD IS INCORRECT.\n");
		Sleep(100);
		system("cls");
		password();
    }

}