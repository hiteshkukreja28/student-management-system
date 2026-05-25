#include <stdio.h>
#include <stdlib.h>

// structure creating



struct student
{
    int roll;
    char name[50];

    float physics;
    float chemistry;
    float maths;

    float total;
    float percentage;

    struct student *next;
};

//  highespercentage from students
void highestPercentage(struct student *head)
{
    struct student *temp, *topper;

    temp = head;
    topper = head;

    while(temp != NULL)
    {
        if(temp->percentage > topper->percentage)
        {
            topper = temp;
        }

        temp = temp->next;
    }

    printf("\n\nTopper Student Details:\n");

    printf("\nRoll No: %d", topper->roll);
    printf("\nName: %s", topper->name);
    printf("\nPercentage: %.2f", topper->percentage);
}



// students above 75
void above75(struct student *head)
{
    struct student *temp;

    temp = head;

    printf("\n\nStudents Above 75 Percentage:\n");

    while(temp != NULL)
    {
        if(temp->percentage > 75)
        {
            printf("\nRoll No: %d", temp->roll);
            printf("\nName: %s", temp->name);
            printf("\nPercentage: %.2f", temp->percentage);

            printf("\n-------------------");
        }

        temp = temp->next;
    }
}


// insert at endd function 

void insertAtEnd(struct student **head)
{
    struct student *newnode, *temp;

    newnode = (struct student*)malloc(sizeof(struct student));

    printf("\nEnter Roll No: ");
    scanf("%d", &newnode->roll);

    printf("Enter Name: ");
    scanf("%s", newnode->name);

    printf("Enter Physics Marks out of 80: ");
    scanf("%f", &newnode->physics);

    printf("Enter Chemistry Marks out of 80: ");
    scanf("%f", &newnode->chemistry);

    printf("Enter Maths Marks out of 80: ");
    scanf("%f", &newnode->maths);

    newnode->total = newnode->physics + newnode->chemistry + newnode->maths;

    newnode->percentage = (newnode->total / 240) * 100;

    newnode->next = NULL;

    if(*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        temp = *head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
    }

    printf("\nStudent Inserted Successfully!\n");
}


// delete at end function

void deleteAtEnd(struct student **head)
{
    struct student *temp, *prev;

    if(*head == NULL)
    {
        printf("\nList is Empty!\n");
    }

    else if((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;

        printf("\nLast Student Deleted!\n");
    }

    else
    {
        temp = *head;

        while(temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = NULL;

        free(temp);

        printf("\nLast Student Deleted!\n");
    }
}

// count function used for counting how many link list are there 

void countStudents(struct student *head)
{
    struct student *temp;
    int count = 0;

    temp = head;

    while(temp != NULL)
    {
        count++;

        temp = temp->next;
    }

    printf("\nTotal Students = %d\n", count);
}






// search function used for searching a astudent 

void searchStudent(struct student *head)
{
    struct student *temp;
    int rollno, found = 0;

    temp = head;

    printf("\nEnter Roll Number to Search: ");
    scanf("%d", &rollno);

    while(temp != NULL)
    {
        if(temp->roll == rollno)
        {
            printf("\nStudent Found!\n");

            printf("\nRoll No: %d", temp->roll);
            printf("\nName: %s", temp->name);
            printf("\nPhysics: %.2f", temp->physics);
            printf("\nChemistry: %.2f", temp->chemistry);
            printf("\nMaths: %.2f", temp->maths);
            printf("\nTotal: %.2f", temp->total);
            printf("\nPercentage: %.2f", temp->percentage);

            found = 1;

            break;
        }

        temp = temp->next;
    }

    if(found == 0)
    {
        printf("\nStudent Not Found!\n");
    }
}

//  to update a student record 
void updateStudent(struct student *head)
{
    struct student *temp;
    int rollno, found = 0;

    temp = head;

    printf("\nEnter Roll Number to Update: ");
    scanf("%d", &rollno);

    while(temp != NULL)
    {
        if(temp->roll == rollno)
        {
            printf("\nStudent Found!\n");

            printf("\nEnter New Physics Marks: ");
            scanf("%f", &temp->physics);

            printf("Enter New Chemistry Marks: ");
            scanf("%f", &temp->chemistry);

            printf("Enter New Maths Marks: ");
            scanf("%f", &temp->maths);

            temp->total = temp->physics + temp->chemistry + temp->maths;

            temp->percentage = (temp->total / 240) * 100;

            printf("\nStudent Record Updated Successfully!\n");

            found = 1;

            break;
        }

        temp = temp->next;
    }

    if(found == 0)
    {
        printf("\nStudent Not Found!\n");
    }
}

// delte function used to delete a record 
void deleteStudent(struct student **head)
{
    struct student *temp, *prev;
    int rollno, found = 0;

    temp = *head;

    printf("\nEnter Roll Number to Delete: ");
    scanf("%d", &rollno);

    if(*head == NULL)
    {
        printf("\nList is Empty!\n");
        return;
    }

    if(temp->roll == rollno)
    {
        *head = temp->next;

        free(temp);

        printf("\nStudent Deleted Successfully!\n");

        return;
    }

    while(temp != NULL)
    {
        if(temp->roll == rollno)
        {
            prev->next = temp->next;

            free(temp);

            printf("\nStudent Deleted Successfully!\n");

            found = 1;

            break;
        }

        prev = temp;
        temp = temp->next;
    }

    if(found == 0)
    {
        printf("\nStudent Not Found!\n");
    }
}

// student pass or fail list function 

void passStudents(struct student *head)
{
    struct student *temp;
    int found = 0;

    temp = head;

    printf("\n\nPassed Students List:\n");

    while(temp != NULL)
    {
        if(temp->percentage >= 36)
        {
            printf("\nRoll No: %d", temp->roll);
            printf("\nName: %s", temp->name);
            printf("\nPercentage: %.2f", temp->percentage);

            printf("\n-------------------");

            found = 1;
        }

        temp = temp->next;
    }

    if(found == 0)
    {
        printf("\nNo Students Passed!\n");
    }
} 






// fai students list 
void failStudents(struct student *head)
{
    struct student *temp;
    int found = 0;

    temp = head;

    printf("\n\nFailed Students List:\n");

    while(temp != NULL)
    {
        if(temp->percentage < 36)
        {
            printf("\nRoll No: %d", temp->roll);
            printf("\nName: %s", temp->name);
            printf("\nPercentage: %.2f", temp->percentage);

            printf("\n-------------------");

            found = 1;
        }

        temp = temp->next;
    }

    if(found == 0)
    {
        printf("\nNo Students Failed!\n");
    }
}

int main()
{
    struct student *head = NULL, *newnode, *temp;
    int i;

    for(i = 1; i <= 5; i++)
    {
        newnode = (struct student*)malloc(sizeof(struct student));

        printf("\nEnter details of student %d\n", i);

        printf("Enter Roll No: ");
        scanf("%d", &newnode->roll);

        printf("Enter Name: ");
        scanf("%s", newnode->name);

        printf("Enter Physics Marks out of 80: ");
        scanf("%f", &newnode->physics);

        printf("Enter Chemistry Marks out of 80: ");
        scanf("%f", &newnode->chemistry);

        printf("Enter Maths Marks out of 80: ");
        scanf("%f", &newnode->maths);

        newnode->total = newnode->physics + newnode->chemistry + newnode->maths;

         newnode->percentage = (newnode->total / 240) * 100;
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }

    temp = head;

    printf("\n\nStudent Records:\n");

    while(temp != NULL)
    {
        printf("\nRoll No: %d", temp->roll);
        printf("\nName: %s", temp->name);
        printf("\nPhysics: %.2f", temp->physics);
        printf("\nChemistry: %.2f", temp->chemistry);
        printf("\nMaths: %.2f", temp->maths);
        printf("\nTotal: %.2f", temp->total);
        printf("\nPercentage: %.2f", temp->percentage);

        printf("\n-----------------------");

        temp = temp->next;
    }

//     //insert at end
     insertAtEnd(&head);
    insertAtEnd(&head);
    insertAtEnd(&head);


     //function calling for highest percentage
     highestPercentage(head);
     //functioncalling for students above 75 percent
         above75(head);
    
//functioncalling to search a student 
   searchStudent(head);

//functioncalling for  list of student passed
    passStudents(head);

//functioncalling for list of student failed
    failStudents(head);  

  updateStudent(head);
    
    //functioncalling to delete a student
 deleteStudent(&head);

    
    //functioncalling to count how many students are there
    countStudents(head);
    



    return 0;
}