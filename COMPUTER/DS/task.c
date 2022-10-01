#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>

struct Ta
{
    int task_id;
    char title[100];
    int duration;
    char status[30];
}task[10];

#define MAX 10
struct Ta queue[MAX];
int front=-1;
int rear=-1;

void schedule();
int isFull();
void insert(int item,int time);
void run();
void del();
void display();
int isEmpty();

int main()
{
    
    FILE *t=fopen("task.txt","r");
    if(t==NULL)
    {
        printf("File cannot be opened:\n");
        exit(1);
    }

    int options;
    int id;
    char name[10];
    int d;
    char st[10];
    /*while(fscanf(t,"%d%s%d%s",&id,name,&d,st)==1)
    {
        for(int i=0;i<10;i++)
        {
            task[i].task_id=id;
            gets(task[i].title);
            //strcpy(task[i].title,name);
            //task[i].title=name;
            task[i].duration=d;
            gets(task[i].status);
            //strcpy(task[i].status,st); 
        }
    }*/
    task[0].task_id=1;
    strcpy(task[0].title,"one");
    task[0].duration=10;
    strcpy(task[0].status,"idle");

    task[1].task_id=2;
    strcpy(task[1].title,"two");
    task[1].duration=20;
    strcpy(task[1].status,"idle");
    for(int i=0;i<10;i++)
    {
        printf("Details of task %d\n",i+1);
        printf("%d",task[i].task_id);
        puts(task[i].title);
        printf("%d",task[i].duration);
        puts(task[i].status);
    }

    while(1)
    {
        printf("enter:\n");
        printf("1-scheduling a task\n");
        printf("2-running a task\n");
        printf("3-Display task details\n");
        
        scanf("%d",&options);

        switch(options)
        {
            case 1:schedule();
                   break;

            case 2:run();
                   break;

            case 3:display();
                   break;
        }
    }
}

void schedule()
{
    int id,flag=0;
    printf("Enter id number of task to be scheduled\n");
    scanf("%d",&id);
    for (int i=0;i<10;i++)
    {
        if(task[i].task_id==id )
        {
            insert(id,task[i].duration);
            strcpy(task[i].status,"Queued");
            break;
        }
        else
        {
            continue;
            flag++;
        }
    }
    if(flag<=9)
    {
        printf("Task of ID number %d not found\n",id);
    }
}

void insert(int item,int time)
{
    if(isFull())
    {
        printf("Queue overflow\n");
        printf("Task cannot be scheduled\n");
        return ;
    }
    else
    {
        if(front==-1)
        {
            front=0;
        }
        rear=rear+1;
	    queue[rear].task_id=item;
        queue[rear].duration=time;
        printf("Task of ID number %d is scheduled\n",item);
    }
}

int isFull()
{
    if(rear==MAX-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void run()
{
    if(isEmpty())
    {
        printf("Task is not scheduled\n");
        return;
    }
    for(int i=0;i<queue[rear].duration;i++)
    {
        printf("%d. ",i);
        //delay(1000);
    }
    printf("Task is completed\n");
    for(int i=0;i<10;i++)
    {
        if(queue[front].task_id==task[i].task_id)
        {
            strcpy(task[i].status,"completed");
            break;
        }
    }
    del();
}

void del()
{
    int item;
    if(isEmpty())
    {
        printf("Tasks are not scheduled\n");
        exit(1);
    }
    else
    {
        front++;
    }

    
}

int isEmpty()
{
	if(front==-1 || front==rear+1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void display()
{
    printf("\nIdle tasks are:\n");
        for(int i=0;i<10;i++)
        {
            if(strcmp(task[i].status,"idle")==0||strcmp(task[i].status,"Idle")==0)
            {
                printf("%d\n",task[i].task_id);
                puts(task[i].title);
                printf("%d\n",task[i].duration);
                puts(task[i].status);

            }
        }

        printf("\nQueued tasks are:\n");
        for(int i=0;i<10;i++)
        {
            if(strcmp(task[i].status,"Queued")==0)
            {
                printf("%d\n",task[i].task_id);
                puts(task[i].title);
                printf("%d\n",task[i].duration);
                puts(task[i].status);
            }
        }

        printf("\nCompleted tasks are:\n");
        for(int i=0;i<10;i++)
        {
            if(strcmp(task[i].status,"completed")==0)
            { 
                printf("%d\n",task[i].task_id);
                puts(task[i].title);
                printf("%d\n",task[i].duration);
                puts(task[i].status);
            }
            else
            {
                printf("Tasks are not completed\n");
            }
        }
}

