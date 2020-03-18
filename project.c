#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
struct books
{
    char name[100];
    int id;
    char author[20];
    char stname[100];
    int rack_no;
    int day;
    int month;
    int year;
    char stid[100];
} a,books[12345];
int total=0,total2=0;
int main()
{
    system("COLOR 07");
    system("cls");
    printf("Enter password: ");
    char a[10]= {'p','o','t','h','i','s','a','l','a'},pass[10];
    gets(pass);
    if(strcmp(a,pass)==0)
        mainmenu();
    else
    {
        printf("Wrong password\n");
        printf("Press any key for re-password\n");
        getchar();
        main();
    }
    return 0;
}
void reload()
{
    FILE *fp;
    fp = fopen("addbook.txt", "r");
    total = 0;
    while (fread(&a, sizeof (a), 1, fp) == 1)
    {
        books[total++] = a;
    }
    fclose(fp);
}
void reissue()
{
    FILE *fp;
    fp = fopen("issue.txt", "r");
    total2= 0;
    while (fread(&a, sizeof (a), 1, fp) == 1)
    {
        books[total2++] = a;
    }
    fclose(fp);
}
int mainmenu()
{
    system("COLOR 3A");
    reload();
    reissue();
    char ch;
    system("cls");
    printf("[1]. Add books \n");
    printf("[2]. Delete Books \n");
    printf("[3]. Issue Books \n");
    printf("[4]. View All Books \n");
    printf("[5]. Non-issue Books \n");
    printf("[6]. Project Developer info\n");
    printf("[7]. Exit \n");
    printf("Enter your choice:");
    switch(getchar())
    {
    case '1':
        add();
        break;
    case '2':
        del();
        break;
    case '3':
        issue();
        break;
    case '4':
        view();
        break;
    case '5':
        nonissue();
        break;
    case '6':
        developer();
        break;
    case'7':
        end();
        break;
    default:
    {
        printf("Wrong entry, Try again\n");
        mainmenu();
    }
    }
}
int add()
{
    system("COLOR 27");
    char ch;
    getchar();
    system("cls");
    FILE *fp;
    fp=fopen("addbook.txt","a+");

    printf("Enter book name: ");
    gets(a.name);
    printf("Enter book id: ");
    scanf("%d",&a.id);
    printf("Enter book author: ");
    scanf("%s",a.author);
    printf("Enter rack no : ");
    scanf("%d",&a.rack_no);
    getchar();
    fwrite(&a,sizeof(a),1,fp);
    fclose(fp);
    printf("Save successfully && do u save another (Y\N)  \n");
    ch=getchar();
    if(ch=='y'||ch=='Y')
    {
        system("cls");
        add();
    }
    else
        mainmenu();
}
void del()
{
    system("COLOR 4E");
    system("cls");
    FILE *fp;
    int id, i, j;
    printf("Enter the book id : ");
    scanf("%d", &id);
    for (i = 0; i < total; i++)
    {
        if (books[i].id == id)
        {
            printf("The book record is available\n");
            printf("Book name is %s\n",books[i].name);
            printf("Rack No. is %d\n",books[i].rack_no);
            fp = fopen("addbook.txt", "w");
            for (j = 0; j < total; j++)
            {
                if (j == i) continue;
                fwrite(&books[j], sizeof books[total], 1, fp);
            }
            reload();
            fclose(fp);
            printf("Data Deleted.\n");
            getchar();
            printf("Press 'Enter' for mainmenu");
            getchar();
            mainmenu();
        }
    }
    printf("Data not found.\n");
    getchar();
    printf("Press 'Enter' for mainmenu");
    getchar();
    mainmenu();
}
int issue()
{
    int t;
    system("COLOR 3E");
    system("cls");
    printf("********************************ISSUE SECTION**************************\n");
    printf("1. Issue a Book\n");
    printf("2. View Issued Book\n");
    printf("Enter a Choice: ");
    FILE *fs,*fp;
    getchar();
    switch(getchar())
    {
        getchar();
    case '1':
    {
        system("cls");
        int c=0;
        system("cls");
        printf("Enter the Book Id:");
        scanf("%d",&t);
        fp=fopen("addbook.txt","a+");
        fs=fopen("issue.txt","a+");
        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(a.id==t)
            {
                printf("The book record is available\n");
                printf("Book name is %s\n",a.name);
                printf("Enter student name:");
                scanf("%s",a.stname);
                printf("Enter student ID:");
                scanf("%s",a.stid);
                printf("Enter issue Date:");
                scanf("%d%d%d",&a.day,&a.month,&a.year);
                fseek(fs,sizeof(a),SEEK_END);
                fwrite(&a,sizeof(a),1,fs);
                fclose(fs);
                c=1;
            }
        }
        if(c==0)
        {
            getchar();
            printf("No record found\n");
            fclose(fp);
            printf("Press 'Enter' any key for mainmenu\n");
            getchar();
            mainmenu();
        }
        getchar();
        printf("Enter any key for mainmenu\n");
        getchar();
        mainmenu();
        break;
    }
    case '2':
    {
        system("cls");
        printf("*******************************Issued book list*******************************\n");
        printf("--------------------------------------------------------------------------------\n");
        printf("STUDENT NAME       ID    BOOK NAME    ISSUED DATE     STUDENT_ID \n");
        printf("--------------------------------------------------------------------------------\n");
        fs=fopen("issue.txt","rb");
        while(fread(&a,sizeof(a),1,fs)==1)
        {
            printf("%s\t\t",a.stname);
            printf("%d\t",a.id);
            printf("%s\t\t",a.name);
            printf("%d-%d-%d\t",a.day,a.month,a.year);
            printf("%s",a.stid);
            printf("\n");
        }
    }
    getchar();
    printf("Press 'Enter' key for mainmenu\n");
    getchar();
    mainmenu();
    break;
    getchar();
    printf("Press 'Enter' key for mainmenu\n");
    getchar();
    mainmenu();
    break;
    }
}
int view()
{
    system("COLOR 3F");
    system("cls");
    printf("*****************************All Books List**********************************\n");
    printf("--------------------------------------------------------------------------------\n");
    FILE *fp;
    fp=fopen("addbook.txt","a+");
    while(fread(&a,sizeof(a),1,fp)==1)
    {
        printf("Book name:  ");
        printf("%s\n",a.name);
        printf("Book id:  ");
        printf("%d\n",a.id);
        printf("Book author:  ");
        printf("%s\n",a.author);
        printf("Rack_no :  ");
        printf("%d\n",a.rack_no);
        printf("\n");
    }
    fclose(fp);
    getchar();
    printf("Press 'Enter' for mainmenu");
    getchar();
    mainmenu();
}
int nonissue()
{
    system("cls");
    FILE *fp;
    int i,d,j;
    printf("Enter book id:");
    scanf("%d",&d);
    for(i=0; i<total2; i++)
    {
        if(books[i].id==d)
        {
            fp=fopen("issue.txt","w");
            for(j=0; j<total2; j++)
            {
                if(j==i)continue;
                fwrite(&books[j], sizeof books[total2], 1, fp);
            }
        }
        reissue();
        fclose(fp);
        printf("Non-issue successfully.\n");
        getchar();
        printf("Press 'Enter' for mainmenu");
        getchar();
        mainmenu();
    }
}
int developer()
{
    system("cls");
    printf("*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#  Project Developer  *#*#*#*#*#*#*#*#*#*#*#*#*#*#\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("Student Name : Jahidul Afrad\n");
    printf("Student ID   : 20151101024\n");
    printf("Department   : Computer Scinence And Engineering\n");
    printf("Session      : 2015-16\n");
    printf("Project Coach: Md. Jamal Uddin(Sir)\n");
    getchar();
    printf("Press 'ENTER' for mainmenu");
    getchar();
    mainmenu();
}
int end()
{
    return 0;
}
