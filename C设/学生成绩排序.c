#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CLASSES 4   // 班级数
#define NUM_STUDENTS 45 // 每个班级学生数
#define NUM_SUBJECTS 5  // 科目数

typedef struct // 学生结构体
{
    char studentID[11];       // 学号
    char name[20];            // 姓名
    int scores[NUM_SUBJECTS]; // 成绩
    float averageScore;       // 平均成绩
} Student;

void generateScores(Student *students)// 生成成绩
{
    for (int i = 0; i < NUM_CLASSES; i++)//遍历班级
    {
        for (int j = 0; j < NUM_STUDENTS; j++)//遍历学生
        {
            for (int k = 0; k < NUM_SUBJECTS; k++)//遍历科目
            {
                students[i * NUM_STUDENTS + j].scores[k] = rand() % 101; // 生成0-100之间的随机成绩
            }
        }
    }
}

void calculateAverageScore(Student *students)// 计算平均成绩
{
    for (int i = 0; i < NUM_CLASSES; i++)
    {
        for (int j = 0; j < NUM_STUDENTS; j++)
        {
            int sum = 0;
            for (int k = 0; k < NUM_SUBJECTS; k++)
            {
                sum += students[i * NUM_STUDENTS + j].scores[k];
            }
            students[i * NUM_STUDENTS + j].averageScore = (float)sum / NUM_SUBJECTS;
        }
    }
}

void bubbleSort(Student *students)
{
    for (int i = 0; i < NUM_CLASSES; i++)
    {
        for (int j = 0; j < NUM_STUDENTS - 1; j++)
        {
            for (int k = 0; k < NUM_STUDENTS - 1 - j; k++)
            {
                if (students[i * NUM_STUDENTS + k].averageScore < students[i * NUM_STUDENTS + k + 1].averageScore)
                {
                    // 交换成绩记录
                    Student temp = students[i * NUM_STUDENTS + k];
                    students[i * NUM_STUDENTS + k] = students[i * NUM_STUDENTS + k + 1];
                    students[i * NUM_STUDENTS + k + 1] = temp;
                }
            }
        }
    }
}

void selectionSort(Student *students)
{
    for (int i = 0; i < NUM_CLASSES; i++)
    {
        for (int j = 0; j < NUM_STUDENTS - 1; j++)
        {
            int maxIndex = j;
            for (int k = j + 1; k < NUM_STUDENTS; k++)
            {
                if (students[i * NUM_STUDENTS + k].averageScore > students[i * NUM_STUDENTS + maxIndex].averageScore)
                {
                    maxIndex = k;
                }
            }
            if (maxIndex != j)
            {
                // 交换成绩记录
                Student temp = students[i * NUM_STUDENTS + j];
                students[i * NUM_STUDENTS + j] = students[i * NUM_STUDENTS + maxIndex];
                students[i * NUM_STUDENTS + maxIndex] = temp;
            }
        }
    }
}

void constructSortedArray(Student *students, Student *sortedArray)
{
    int index = 0;
    for (int i = 0; i < NUM_CLASSES; i++)
    {
        for (int j = 0; j < NUM_STUDENTS; j++)
        {
            sortedArray[index] = students[i * NUM_STUDENTS + j];
            index++;
        }
    }
}

void printArray(Student *students)
{
    for (int i = 0; i < NUM_CLASSES; i++)
    {
        printf("Class %d:\n", i + 1);
        for (int j = 0; j < NUM_STUDENTS; j++)
        {
            printf("Student ID: %s, Name: %s, Average Score: %.2f\n", students[i * NUM_STUDENTS + j].studentID,
                   students[i * NUM_STUDENTS + j].name, students[i * NUM_STUDENTS + j].averageScore);
        }
        printf("\n");
    }
}

int main()
{
    Student students[NUM_CLASSES * NUM_STUDENTS];
    Student sortedArray[NUM_CLASSES * NUM_STUDENTS];

    // 生成成绩
    generateScores(students);

    // 计算平均成绩
    calculateAverageScore(students);

    // 冒泡排序
    bubbleSort(students);
    printf("Sorted by Bubble Sort:\n");
    printArray(students);

    // 选择排序
    selectionSort(students);
    printf("Sorted by Selection Sort:\n");
    printArray(students);

    // 构造排序后的新数组
    constructSortedArray(students, sortedArray);
    printf("Sorted Array:\n");
    printArray(sortedArray);

    return 0;
}