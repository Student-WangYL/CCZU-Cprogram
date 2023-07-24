#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义图书结构体
typedef struct
{
    char bookNumber[20];
    char bookTitle[100];
    char author[100];
    float price;
} Book;

// 函数声明
void displayMenu();
void displayBooks(Book **books, int count);
void addBook(Book ***books, int *count);
void deleteBook(Book ***books, int *count);
int main()
{
    Book **books = NULL;
    int count = 0;

    int choice;
    do
    {
        displayMenu();
        printf("请选择操作：");
        scanf("%d", &choice);
        getchar(); // 读取换行符

        switch (choice)
        {
        case 1:
            displayBooks(books, count);
            break;
        case 2:
            addBook(&books, &count);
            break;
        case 3:
            deleteBook(&books, &count);
            break;
        case 0:
            printf("程序退出。\n");
            break;
        default:
            printf("无效的选择，请重新输入。\n");
        }

    } while (choice != 0);

    // 释放动态分配的内存
    for (int i = 0; i < count; i++)
    {
        free(books[i]);
    }
    free(books);

    return 0;
}

// 显示菜单
void displayMenu()
{
    printf("图书管理系统菜单\n");
    printf("1. 查看图书信息\n");
    printf("2. 添加图书\n");
    printf("3. 删除图书\n");
    printf("0. 退出程序\n");
}

// 显示图书信息
void displayBooks(Book **books, int count)
{
    // 实现显示图书信息的功能
    if (count == 0)
    {
        printf("没有图书可以显示！\n");
        return;
    }

    printf("图书信息如下：\n");
    for (int i = 0; i < count; i++)
    {
        printf("图书编号：%s\n", books[i]->bookNumber);
        printf("图书标题：%s\n", books[i]->bookTitle);
        printf("图书作者：%s\n", books[i]->author);
        printf("图书价格：%f\n", books[i]->price);
        printf("--------------------\n");
    }
}

// 添加图书
void addBook(Book ***books, int *count)
{
    // 实现添加图书的功能
    Book *newBook = (Book *)malloc(sizeof(Book));

    printf("请输入图书编号：");
    fgets(newBook->bookNumber, sizeof(newBook->bookNumber), stdin);
    printf("请输入图书标题：");
    fgets(newBook->bookTitle, sizeof(newBook->bookTitle), stdin);
    printf("请输入图书作者：");
    fgets(newBook->author, sizeof(newBook->author), stdin);
    printf("请输入图书价格：");
    scanf("%f", &(newBook->price));
    getchar(); // 读取换行符

    *books = (Book **)realloc(*books, ((*count) + 1) * sizeof(Book *));
    (*books)[*count] = newBook;
    (*count)++;
}

// 删除图书
void deleteBook(Book ***books, int *count)
{
    // 实现删除图书的功能
    if (*count == 0)
    {
        printf("没有图书可以删除！\n");
        return;
    }

    printf("请输入要删除的图书编号：");
    char bookNumber[20];
    fgets(bookNumber, sizeof(bookNumber), stdin);

    int found = 0;
    for (int i = 0; i < *count; i++)
    {
        if (strcmp((*books)[i]->bookNumber, bookNumber) == 0)
        {
            found = 1;
            free((*books)[i]);
            for (int j = i; j < (*count) - 1; j++)
            {
                (*books)[j] = (*books)[j + 1];
            }
            (*count)--;
            *books = (Book **)realloc(*books, (*count) * sizeof(Book *));
            printf("已成功删除图书。\n");
            break;
        }
    }

    if (!found)
    {
        printf("未找到指定的图书编号。\n");
    }
}
