/*A Book Management System is required to efficiently organize and manage information about books. The system should support various operations,
including adding, removing, searching, updating, and displaying book records based on attributes such as Book ID, Book Name, Author Name, Category,
Price, and Rating. Additionally, the system should provide the capability to show details of books written by a specific author, display the top 3 books
based on price and rating, and access information about all the books in the database*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Book
{
    int id;
    char bookName[20];
    char authorName[20];
    char catagory[20];
    int price;
    float rating;
}Book;
//declaration
void hc(Book *);
Book *creatArray(int); //malloc
void add(Book *);
void allBook(Book *);
int search(Book *);
void delete(Book *);
void update(Book *);
void catagory(Book *);
void sort(Book *);

int count = 7; // global intialization
int size = 50;
void main()
{
    Book *arr = creatArray(size);
    hc(arr);
    int choice, res;
    do
    {
        printf("\n\n1 Add Book\n2.Display All Books\n3.Search Book\n4.Remove Book\n5.Update Book Data\n6.Show Category's Books\n7.Display Sorted Books\n");
        printf("\nEnter Your Choice :- ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            add(arr);
            break;
        case 2:
            allBook(arr);
            break;
        case 3:
            res=search(arr);
            break;
        case 4:
            delete (arr);
            break;
        case 5:
            update(arr);
            break;
        case 6:
            catagory(arr);
            break;
        case 7:
            sort(arr);
            break;
        default:
            printf("\n\nEnter Correct Choice!\n\n");
        }
    } while (choice != 0);
}
Book *creatArray(int size)
{
    Book *arr = (Book *)malloc(size * sizeof(Book));
    return arr;
}
void add(Book *arr)
{
    for (int i = count; i <= count; i++)
    {
        printf("\n\nEnter Book ID :- ");
        scanf("%d", &arr[i].id);
        printf("Enter Book name :- ");
        fflush(stdin);
        gets(arr[i].bookName);
        printf("Enter Author name :- ");
        fflush(stdin);
        gets(arr[i].authorName);
        printf("Enter Book Catagory :- ");
        fflush(stdin);
        gets(arr[i].catagory);
        printf("Enter Book price :- ");
        scanf("%d", &arr[i].price);
        printf("Enter Book Rating '0' to '10' :- ");
        scanf("%f", &arr[i].rating);
        while (arr[i].rating >= 10)
        {
            if (arr[i].rating >= 10)
            {
                printf("Give rating under '10' :-");
                scanf("%f", &arr[i].rating);
            }
        }
        printf("\n");
    }
    count++;
}
void allBook(Book *arr)
{
    printf("\n\n***************************************DISPLAY ALL BOOKS*************************************************************");
    printf("\n---------------------------------------------------------------------------------------------------------------------");
    printf("\n|   Book id   |     Book Name                |   Author Name   | Book Category    |  Book Price  |  Book Rating      |");
    printf("\n---------------------------------------------------------------------------------------------------------------------");
    for (int i = 0; i < count; i++)
    {
        printf("\n|    %-5d    |   %-21s      |     %-7s     |     %-9s    |    %-7d   |      %-5.1f        |", arr[i].id, arr[i].bookName, arr[i].authorName, arr[i].catagory, arr[i].price, arr[i].rating);
        printf("\n---------------------------------------------------------------------------------------------------------------------");
    }
}
int search(Book *arr)
{
    int choice, bid, i, cnt = 0;
    char bname[20];
    printf("\n1.Search by id :- \n2.Search by book name :-");
    printf("\n\nEnter Choice :-");
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("\nEnter Book id :- ");
        scanf("%d", &bid);
        printf("\n-- YOUR RESULT --\n");
        for (i = 0; i <= count; i++)
        {
            if (arr[i].id == bid)
            {
                printf("\nBook id : %d\nBook name : %s\nAuthor name : %s\nBook catagory : %s\nBook price :%d\nbook rating : %.1f\n", arr[i].id, arr[i].bookName, arr[i].authorName, arr[i].catagory, arr[i].price, arr[i].rating);
                cnt++;
                return i;
            }
        }
        if (cnt == 0)
        {
            printf("\nBook not found!");
        }
    }
    else if (choice == 2)
    {
        printf("\nEnter Book name :- ");
        scanf("%s", bname);
        printf("\n-- YOUR RESULT --\n");
        for (i = 0; i <= count; i++)
        {
            int res = strcasecmp(arr[i].bookName, bname);
            if (res == 0)
            {
                printf("\nBook id : %d\nBook name : %s\nAuthor name : %s\nBook catagory : %s\nBook price :%d\nbook rating : %.1f\n", arr[i].id, arr[i].bookName, arr[i].authorName, arr[i].catagory, arr[i].price, arr[i].rating);
                count++;
                return i;
            }
        }
        if (count == 0)
        {
            printf("\nBook not found!");
        }
    }
    else
    {
        printf("Enter Correct choice");
    }
}
void delete(Book *arr)
{
    printf("\nSearch Book you want to delete :-");
    int res = search(arr);
    for (int i = res; i < count - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    printf("\nRecord deleted!\n");
    count--;
}
void update(Book *arr)
{
    int choice;
    printf("\nSearch Book you want to update :");
    int res = search(arr);
    printf("\n1.Update price\n2.Update rating");
    printf("\n\nEnter Choice :");
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("Enter updated price : ");
        scanf("%d", &arr[res].price);
        printf("\nRecord updated!");
    }
    else if (choice == 2)
    {
        printf("\nEnter updated rating : ");
        scanf("%f", &arr[res].rating);
        while (arr[res].rating >= 10)
        {
            if (arr[res].rating >= 10)
            {
                printf("!!Give rating under '10' :");
                scanf("%f", &arr[res].rating);
            }
            printf("\nRecord updated!");
        }
    }
    else
    {
        printf("\nEnter Correct choice!!");
    }
}
void catagory(Book *arr)
{
    int count = 0, i;
    char cat[20];
    printf("\n\nEnter catagory :");
    scanf("%s", cat);
    printf("\n-- YOUR RESULT --\n");
    for (i = 0; i <= count; i++)
    {
        int a = strcasecmp(arr[i].catagory, cat);
        if (a == 0)
        {
            count++;
            printf("\nBook id : %d\nBook name : %s\nAuthor name : %s\nBook catagory : %s\nBook price :%d\nbook rating : %.1f\n", arr[i].id, arr[i].bookName, arr[i].authorName, arr[i].catagory, arr[i].price, arr[i].rating);
        }
    }
    if (count == 0)
    {
        printf("Catagory not found!!");
    }
}
void sort(Book *arr)
{
    int choice, choice1;
    Book temp[size];
    printf("\n1.Sort by price\n2.sort by rating");
    printf("\n\nEnter Choice :-");
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("\n1.Asending order\n2.Desending order");
        printf("\n\nEnter Choice :");
        scanf("%d", &choice1);
        if (choice1 == 1)
        {
            for (int i = 0; i < count; i++)
            {
                for (int j = i + 1; j < count; j++)
                {
                    if (arr[i].price > arr[j].price)
                    {
                        temp[0] = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp[0];
                    }
                }
                printf("\nBook id : %d\nBook name : %s\nAuthor name : %s\nBook catagory : %s\nBook price :%d\nbook rating : %.1f\n", arr[i].id, arr[i].bookName, arr[i].authorName, arr[i].catagory, arr[i].price, arr[i].rating);
            }
        }
        else if (choice1 == 2)
        {
            for (int i = 0; i < count; i++)
            {
                for (int j = i + 1; j < count; j++)
                {
                    if (arr[i].price < arr[j].price)
                    {
                        temp[0] = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp[0];
                    }
                }
                printf("\nBook id :- %d\nBook name :- %s\nAuthor name :- %s\nBook catagory : %s\nBook price :-%d\nbook rating : %.1f\n", arr[i].id, arr[i].bookName, arr[i].authorName, arr[i].catagory, arr[i].price, arr[i].rating);
            }
        }
        else
        {
            printf("\nEnter Correct choice!!");
        }
    }
    else if (choice == 2)
    {
        printf("\n1.Asending order\n2.Desending order");
        printf("\n\nEnter Choice :");
        scanf("%d", &choice1);
        if (choice1 == 1)
        {
            for (int i = 0; i < count; i++)
            {
                for (int j = i + 1; j < count; j++)
                {
                    if (arr[i].rating > arr[j].rating)
                    {
                        temp[0] = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp[0];
                    }
                }
                printf("\nBook id : %d\nBook name : %s\nAuthor name : %s\nBook catagory : %s\nBook price :%d\nbook rating : %.1f\n", arr[i].id, arr[i].bookName, arr[i].authorName, arr[i].catagory, arr[i].price, arr[i].rating);
            }
        }
        else if (choice1 == 2)
        {

            // printf("\n----------------------------------------------------------------------------------------------");
            // printf("\n|   Book id  |  Book Name  |  Author Name  |   Book Category  |  Book Price  |  Book Rating  |");
            // printf("\n----------------------------------------------------------------------------------------------");
            for (int i = 0; i < count; i++)
            {
                for (int j = i + 1; j < count; j++)
                {
                    if (arr[i].rating < arr[j].rating)
                    {
                        temp[0] = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp[0];
                    }
                }
                // // printf("\nBook id : %d\nBook name : %s\nAuthor name : %s\nBook catagory : %s\nBook price :%d\nbook rating : %.1f\n",arr[i].id,arr[i].bookName,arr[i].authorName,arr[i].catagory,arr[i].price,arr[i].rating);
                // printf("\n|    Book id   |   Book Name  |   Author Name  |   Book Category  |  Book Price  |   Book Rating  | ");
                printf("\n|       %d   |     %s   |     %s   |     %s    %d   |   %1f    |", arr[i].id, arr[i].bookName, arr[i].authorName, arr[i].catagory, arr[i].price, arr[i].rating);
                printf("\n----------------------------------------------------------------------------------------");
            }
        }
    }
    else
    {
        printf("\nEnter Correct choice!");
    }
}
void hc(Book *arr)
{
    arr[0].id = 1;
    strcpy(arr[0].bookName, "crimepetrol");
    strcpy(arr[0].authorName, "abbb");
    strcpy(arr[0].catagory, "crime");
    arr[0].price = 150;
    arr[0].rating = 7.8;
    //
    arr[1].id = 2;
    strcpy(arr[1].bookName, "Attitude is Every ");
    strcpy(arr[1].authorName, "dd");
    strcpy(arr[1].catagory, "Motivation");
    arr[1].price = 300;
    arr[1].rating = 9.4;
    //
    arr[2].id = 3;
    strcpy(arr[2].bookName, "crimebranch");
    strcpy(arr[2].authorName, "ff");
    strcpy(arr[2].catagory, "crime");
    arr[2].price = 500;
    arr[2].rating = 7.5;
    //
    arr[3].id = 4;
    strcpy(arr[3].bookName, "laugher");
    strcpy(arr[3].authorName, "hh");
    strcpy(arr[3].catagory, "comedy");
    arr[3].price = 280;
    arr[3].rating = 8.8;
    //
    arr[4].id = 5;
    strcpy(arr[4].bookName, "kanchana Is Back");
    strcpy(arr[4].authorName, "jj");
    strcpy(arr[4].catagory, "Horror");
    arr[4].price = 99;
    arr[4].rating = 9;
    //
    arr[5].id = 6;
    strcpy(arr[5].bookName, "Stock Market");
    strcpy(arr[5].authorName, "yrd");
    strcpy(arr[5].catagory, "marketing");
    arr[5].price = 799;
    arr[5].rating = 6.7;
    //
    arr[6].id = 7;
    strcpy(arr[6].bookName, "p");
    strcpy(arr[6].authorName, "n");
    strcpy(arr[6].catagory, "suspense");
    arr[6].price = 650;
    arr[6].rating = 6.9;
}
