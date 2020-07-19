#include<stdio.h>
#include<conio.h>
#include<string.h>
 struct student{
    char name[20],address[20],faculty[20];
    int roll,clas;
 };
 struct student st;
 void write_record();
 void read_record();
 void update_record();
 void search_record();
 void delete_record();
 
 void main(){
 	Z:
 	printf("---------------------------------------------------------------------------Password Protected---------------------------------------------------------------------------\n");
	char ch, pass[20];
	printf("\nEnter Password: "); 
	gets(pass);
	system("cls");
if(strcmp("ambition",pass)==0){
	printf("                                                                   -----------------\n");
 	printf("                                                                   |AMBITION ACADAMY|\n");
 	printf("                                                                   -----------------\n");
 	printf("                         ***********************************WELCOME TO STUDENTS RECORD OF AMBITION ACADEMY***********************************\n\n");
	puts("Access Granted.\n");
    do{
 	int n;
 	printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf(" 1.Write record\n 2.Read record\n 3.Update record\n 4.Search record\n 5.Delete record\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("Choose any number:...\n");
	scanf("%d",&n);
	system("cls");
	switch(n)
	{
		case 1:
			write_record();
			break;
		case 2:
			read_record();
			break;
		case 3:
			update_record();
			break;
		case 4:
			search_record();
			break;
		case 5:
			delete_record();
			break;
		default:
			printf("Invalid input. Please try again later.\a");
  }
  getch();
  printf("\n\nDo you want to it again?if yes then 'Y' or 'y' or if not then press any key?\n");
  ch = getch();
 
}while(ch == 'Y' || ch == 'y');
}else{
	printf("!!! Incorrect password !!!\nPlease try again later.\a\n");
	system("pause");
	goto Z;
}
printf("                            -------------------\n");
printf("************************** :Thank you for using: **************************\n");
printf("                            -------------------\n");
getch();
}

void write_record(){
	 FILE *fp;
	printf("                            -------------------\n");
	printf("************************** :To write new record: **************************\n");
	printf("                            -------------------\n\n");
	 char name1[20],factu[20],adress[20];
	 int result,size,flag,rol,cl;
	 A: 
	 size = 0;flag = 0;
	 fp = fopen("practice.txt","r");
	 fseek(fp,0,SEEK_END);
	 size = ftell(fp);
	 fclose(fp);
	 fp = fopen("practice.txt","r+");
	 if(size == 0){
	 	printf("The file is empty.\n");
	 	printf("Enter student name: ");
	 	scanf("%s",st.name);
	 	printf("Enter class: ");
        scanf("%d",&st.clas);
	 	printf("Enter roll no.: ");
	 	scanf("%d",&st.roll);
	 	printf("Enter faculty: ");
	 	scanf("%s",st.faculty);
	 	printf("Enter address: ");
	 	scanf("%s",st.address);
	 	fprintf(fp,"%s\t%d\t%d\t%s\t%s\n",st.name,st.clas,st.roll,st.faculty,st.address);
	    goto E;
	 }else{
	 	printf("The file has some record.\n");
	 	printf("Enter student name: ");
	 	scanf("%s",name1);
	 	while(fscanf(fp,"%s\t%d\t%d\t%s\t%s\n",st.name,&st.clas,&st.roll,st.faculty,st.address)!=EOF){
	 		result = stricmp(st.name,name1);
	 		if(result == 0){
	 			flag = 1;
	 			break;
			 }
		 }
	 }
	 fclose(fp);
	 if(flag == 1){
	 	printf("Name has been duplicated. Please try another name.\a\n");
	 	system("pause");printf("\n");
	 	goto A;
	 }else{
	 	fp =fopen("practice.txt","a");
        printf("Enter class: ");
        scanf("%d",&cl);
	 	printf("Enter roll: ");
	 	scanf("%d",&rol);
	 	printf("Enter faculty: ");
	 	scanf("%s",factu);
	 	printf("Enter address: ");
	 	scanf("%s",adress);
	 	fprintf(fp,"%s\t%d\t%d\t%s\t%s\n",name1,cl,rol,factu,adress);
	 	printf("\nRecord has been added sucessfully!!!\n");
	 }
	 E:fclose(fp);
}
void read_record(){
	printf("                           ----------------\n");
	printf("************************** :To read records: **************************\n");
	printf("                           ----------------\n\n");
	int size=0,len,i=0;
	FILE *fp;
	fp = fopen("practice.txt","r");
	printf("|S.N| |Student Name|\t\t|Class|\t\t|Roll|\t\t |Faculty|\t\t   | Address |\n\n");
	fseek(fp,0,SEEK_END);
	size = ftell(fp);
	fclose(fp);
	if(size == 0){
		printf("Sorry!!! The file is empty.\a\n");
	}else{
		fp = fopen("practice.txt","r");
	while(fscanf(fp,"%s\t%d\t%d\t%s\t%s\n",st.name,&st.clas,&st.roll,st.faculty,st.address)!=EOF){
	    i++;
		len = strlen(st.name);
		if(len>8){
			printf(" %d)    %s\t\t   %d\t\t  %d\t\t   %s\t\t  %s\n",i,st.name,st.clas,st.roll,st.faculty,st.address);
		}else{
		printf(" %d)    %s\t\t\t  %d\t\t   %d\t\t   %s\t\t\t    %s\n",i,st.name,st.clas,st.roll,st.faculty,st.address);
	}
  }
   }
	fclose(fp);
}
void update_record(){
	printf("                           ------------------\n");
	printf("************************** :To update record: **************************\n");
	printf("                           ------------------\n\n");
	FILE *fp,*fp1;
	char name1[20],facu[20],adress[20];
	int flag=0,result,rol,cl;
	fp = fopen("practice.txt","r");
	fp1 = fopen("Gardim.txt","w");
	printf("Enter record name you want to update: ");
	scanf("%s",name1);
	while(fscanf(fp,"%s\t%d\t%d\t%s\t%s\n",st.name,&st.clas,&st.roll,st.faculty,st.address)!=EOF){
		result = stricmp(st.name,name1);
		if(result == 0){
			printf("\n  -------------------------------------\n");
			printf("  !      Updating %s's record      !\n",name1);
			printf("  -------------------------------------\n\n");
			flag = 1;
			printf("Enter new class: ");
			scanf("%d",&cl);
			printf("Enter new roll: ");
			scanf("%d",&rol);
			printf("Enter new faculty: ");
			scanf("%s",facu);
			printf("Enter new address: ");
			scanf("%s",adress);
			fprintf(fp1,"%s\t%d\t%d\t%s\t%s\n",name1,cl,rol,facu,adress);
		}else{
			fprintf(fp1,"%s\t%d\t%d\t%s\t%s\n",st.name,st.clas,st.roll,st.faculty,st.address);
		}
	}
	if(flag == 0){
		printf("Sorry!!!Name not found.\a");
	}else{
			printf("\nRecord has been sucessfully updated\n");
	}
	fclose(fp);fclose(fp1);
	fp = fopen("practice.txt","w");
	fclose(fp);
	
	fp = fopen("practice.txt","a");
	fp1 = fopen("Gardim.txt","r");
	while(fscanf(fp1,"%s\t%d\t%d\t%s\t%s\n",st.name,&st.clas,&st.roll,st.faculty,st.address)!=EOF){
		fprintf(fp,"%s\t%d\t%d\t%s\t%s\n",st.name,st.clas,st.roll,st.faculty,st.address);
	}
	fclose(fp);fclose(fp1);
	fp1 = fopen("Gardim.txt","w");
	fclose(fp1);
}
void search_record(){
	printf("                           ------------------\n");
	printf("************************** :To search record: **************************\n");
	printf("                           ------------------\n\n");
	FILE *fp;
	int result;
	char len,name1[20],flag = 0;
	fp = fopen("practice.txt","r");
	printf("Enter name of the record: ");
	scanf("%s",name1);
	while(fscanf(fp,"%s\t%d\t%d\t%s\t%s\n",st.name,&st.clas,&st.roll,st.faculty,st.address)!=EOF){
		result = stricmp(st.name,name1);
		if(result == 0){
			flag = 1;
			printf(" |Student Name|\t\t|Class|\t\t|Roll|\t\t |Faculty|\t\t   | Address |\n\n");
            	fp = fopen("practice.txt","r");
		len = strlen(st.name);
		if(len>8){
			printf("  %s\t\t  %d\t\t  %d\t\t   %s\t\t  %s\n",st.name,st.clas,st.roll,st.faculty,st.address);
		}else{
		printf("   %s\t\t\t   %d\t\t   %d\t\t  %s\t\t    %s\n",st.name,st.clas,st.roll,st.faculty,st.address);
		}   	 
	break;
	}
	}
	if(flag == 0){
		printf("Sorry!!!Name not found.\a");
	}
	fclose(fp);
}
void delete_record(){
	printf("                           ------------------\n");
    printf("************************** :To delete record: **************************\n");
    printf("                           ------------------\n\n");
	FILE *fp,*fp1;
    char name1[20];
    int flag = 0,result;
    fp = fopen("practice.txt","r");
    fp1 = fopen("Gardim.txt","w");
    printf("Enter record name that you want to delete: ");
    scanf("%s",name1);
    while(fscanf(fp,"%s\t%d\t%d\t%s\t%s\n",st.name,&st.clas,&st.roll,st.faculty,st.address)!=EOF){
	result = stricmp(st.name,name1);
	if(result == 0 ){
		flag = 1;
		printf("Record has been sucessfully deleted.");
	} else{
		fprintf(fp1,"%s\t%d\t%d\t%s\t%s\n",st.name,st.clas,st.roll,st.faculty,st.address);
	}
	}
	if(flag == 0){
		printf("Sorry!!! name not found.\a");
	}
	fclose(fp);	fclose(fp1);
	
	fp =fopen("practice.txt","w");
	fclose(fp);
	
	fp = fopen("practice.txt","a");
	fp1 = fopen("Gardim.txt","r");
	while(fscanf(fp1,"%s\t%d\t%d\t%s\t%s\n",st.name,&st.clas,&st.roll,st.faculty,st.address)!=EOF){
		fprintf(fp,"%s\t%d\t%d\t%s\t%s\n",st.name,st.clas,st.roll,st.faculty,st.address);
	}
	fclose(fp);fclose(fp1);
	fp1 = fopen("Gardim.txt","w");
	fclose(fp1);
}
 
