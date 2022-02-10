#include <management.h>

#include <stdio.h>;
#include <conio.h>;
#include <string.h>;

void namefun(){
	system("cls");
	printf("NEW SECTION\n");
	FILE *fptr;
	char name[100];
	char gmail[100];
	double phone;
	fptr=fopen("siva.txt","ab+");
	if(fptr==NULL){
		printf("Failed to create the required file.");
	}
	else{
		printf("Name:\t");
		gets(name);
		printf("Gmail:\t");
		gets(gmail);
		printf("Phone Number:\t");
		scanf("%lf",&phone);
		fprintf(fptr,"%s %s %.0lf\n",name,gmail,phone);
	}
	fclose(fptr);
	system("cls");
	char ch;
	printf("Press y to Main Menu");
	Sleep(1000);
	fflush(stdin);
	while((ch=getch())=='Y'){
		menu();
	}
}
void listfun(){
		FILE *fptr;
	char name[100],gmail[100];
	double phone;

	fptr=fopen("siva.txt","r");
	system("cls");
	printf("LIST SECTION OPENED");
	printf("\n");
	while(fscanf(fptr,"%s %s %lf",name,gmail,&phone)!=EOF){

			printf("------------------------------------------\n");
		printf("Name:%s\n",name);
		printf("Gmail:%s\n",gmail);
		printf("Phone:%.0lf\n",phone);

            printf("------------------------------------------");
            printf("\n\n");
            printf("\n\n");
		}
		Sleep(1000);
		printf("Enter y for menu section:");
		while(getch()=='y'){
			menu();
		}
			fclose(fptr);
}
void deletefun(){
	FILE *fptr,*fptr1;
	char name[100],gmail[100],gmail1[100],name1[100];
	int res,f=0;
	double phone,phone1;
	fptr=fopen("siva.txt","r");
	fptr1=fopen("temp.txt","a");
	system("cls");
	printf("Enter the CONTACT name that you want to delete:\n");
	gets(name1);
	system("cls");
	while(fscanf(fptr,"%s %s %lf\n",name,gmail,&phone)!=EOF){
		res=strcmp(name,name1);
		if(res==0)
		{
			f=1;
			printf("Data deleted successfully");

		}else{
			fprintf(fptr1,"%s %s %.0lf\n",name,gmail,phone);
		}
	}
	if(f==0){
		printf("Data Not found.");
			}
	fclose(fptr);
	fclose(fptr1);
	fptr=fopen("siva.txt","w");
	fclose(fptr);
	fptr=fopen("siva.txt","a");
	fptr1=fopen("temp.txt","r");
	while(fscanf(fptr1,"%s %s %lf\n",name,gmail,&phone)!=EOF)
    {
		fprintf(fptr,"%s %s %.0lf\n",name,gmail,phone);

	}
	fclose(fptr);
	fclose(fptr1);
	fptr1=fopen("temp.txt","w");
	fclose(fptr1);
	printf("\n\nPress y for menu option.");
	fflush(stdin);
	if(getch()=='y'){
		menu();
	};
}
void exitfun(){
	system("cls");
	printf("SIVA SHANKAR");
}