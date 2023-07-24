#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NumClasses 4   // 班级数
#define NumStudents 45 // 每个班级的学生数
#define NumSubjects 5  // 科目数

typedef struct // 学生信息(结构体)
{
    char studentID[11];      // 学号
    char name[20];           // 姓名
    int scores[NumSubjects]; // 成绩
    float averageScore;      // 平均成绩
} Student;                   // 学生信息

void generateScores(Student *students) // 生成成绩
{
    for (int i = 0; i < NumClasses; i++) // 生成班级
    {
        for (int j = 0; j < NumStudents; j++) // 生成学生
        {
            // 生成学号
            sprintf(students[i * NumStudents + j].studentID, "S%03d%02d", i + 1, j + 1);

            // 生成姓名
            sprintf(students[i * NumStudents + j].name, "Student-%03d%02d", i + 1, j + 1);

            // 生成成绩
            for (int k = 0; k < NumSubjects; k++)
            {
                students[i * NumStudents + j].scores[k] = rand() % 101; // 生成0-100之间的随机成绩
                printf("学号: %s, 姓名: %s, 分数: %d\n", students[i * NumStudents + j].studentID,
                       students[i * NumStudents + j].name, students[i * NumStudents + j].scores[k]);
            }
        }
    }
}

void calculateAverageScore(Student *students) // 计算平均成绩
{
    for (int i = 0; i < NumClasses; i++) // 计算班级
    {
        for (int j = 0; j < NumStudents; j++) // 计算学生
        {
            int sum = 0;                          // 总分
            for (int k = 0; k < NumSubjects; k++) // 计算科目
            {
                sum += students[i * NumStudents + j].scores[k]; // 累加成绩
            }
            students[i * NumStudents + j].averageScore = (float)sum / NumSubjects; // 计算平均分
            printf("学号: %s, 姓名: %s, 平均分: %.2f\n", students[i * NumStudents + j].studentID,
                   students[i * NumStudents + j].name, students[i * NumStudents + j].averageScore);
        }
    }
}

void bubbleSort(Student *students) // 冒泡排序
{
    for (int i = 0; i < NumClasses; i++) // 排序班级
    {
        for (int j = 0; j < NumStudents - 1; j++) // 排序学生
        {
            for (int k = 0; k < NumStudents - 1 - j; k++) // 排序学生
            {
                if (students[i * NumStudents + k].averageScore < students[i * NumStudents + k + 1].averageScore) // 比较平均分
                {
                    // 交换成绩记录
                    Student temp = students[i * NumStudents + k];                      // 交换成绩记录
                    students[i * NumStudents + k] = students[i * NumStudents + k + 1]; // 交换成绩记录
                    students[i * NumStudents + k + 1] = temp;                          // 交换成绩记录
                }
            }
        }
    }
}

void selectionSort(Student *students) // 选择排序
{
    for (int i = 0; i < NumClasses; i++) // 排序班级
    {
        for (int j = 0; j < NumStudents - 1; j++) // 排序学生
        {
            int maxIndex = j;                         // 最大值索引
            for (int k = j + 1; k < NumStudents; k++) // 排序学生
            {
                if (students[i * NumStudents + k].averageScore > students[i * NumStudents + maxIndex].averageScore) // 比较平均分
                {
                    maxIndex = k; // 更新最大值索引
                }
            }
            if (maxIndex != j) // 如果最大值索引不是当前索引
            {
                // 交换成绩记录
                Student temp = students[i * NumStudents + j];                         // 交换成绩记录
                students[i * NumStudents + j] = students[i * NumStudents + maxIndex]; // 交换成绩记录
                students[i * NumStudents + maxIndex] = temp;                          // 交换成绩记录
            }
        }
    }
}

void constructSortedArray(Student *students, Student *sortedArray) // 构造排序数组
{
    for (int i = 0; i < NumClasses; i++) // 排序班级
    {
        for (int j = 0; j < NumStudents; j++) // 排序学生
        {
            sortedArray[i * NumStudents + j] = students[i * NumStudents + j]; // 复制成绩记录
        }
    }
}

void printArray(Student *students) // 打印数组
{
    for (int i = 0; i < NumClasses; i++) // 打印班级
    {
        printf("班级 %d:\n", i + 1);          // 打印班级
        for (int j = 0; j < NumStudents; j++) // 打印学生
        {
            printf("学号: %s, 姓名: %s, 平均分: %.2f\n", students[i * NumStudents + j].studentID,
                   students[i * NumStudents + j].name, students[i * NumStudents + j].averageScore);
        }
        printf("\n");
    }
}

void displayMenu()
{
    printf("=== 学生成绩排序系统 ===\n");
    printf("1. 生成成绩\n");
    printf("2. 计算平均成绩\n");
    printf("3. 冒泡排序\n");
    printf("4. 按选择排序\n");
    printf("5. 退出\n");
    printf("输入您的选择 (1-5): ");
}

int main()
{
    Student students[NumClasses * NumStudents];    // 学生数组
    Student sortedArray[NumClasses * NumStudents]; // 排序数组
    int choice;

    while (1) // 无限循环
    {
        displayMenu();        // 显示菜单
        scanf("%d", &choice); // 读取选择

        switch (choice)
        {
        case 1:
            generateScores(students);
            printf("生成的分数.\n"); // 生成成绩
            break;
        case 2:
            calculateAverageScore(students);
            printf("计算的平均分数。\n");
            break;
        case 3:
            bubbleSort(students);
            printf("按冒泡排序:\n");
            printArray(students);
            break;
        case 4:
            selectionSort(students);
            printf("按选择排序:\n");
            printArray(students);
            break;
        case 5:
            printf("退出中...\n");
            exit(0);
        default:
            printf("无效选择.请再试一次.\n");
        }
    }

    return 0;
}