#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "pthread.h"
#include "semaphore.h"

//Option 1

int countW = 0, countR = 0;
int wrt = 1, mutex = 1;

struct Message
{
    int ThreadID;
    int Number;
}data[20];

//void *print_message_function( void *ptr );

void *print_message_function( void *ptr )
{
     char *message;
     message = (char *) ptr;
     printf("Executing %s \n", message);
	
	 pthread_exit(NULL);

}

int wait(S)
{
    while (S <= 0)
    {

    }
    S = 0;
}
int signal(S)
{
    S = 1;
}

void W1_thread()
{

    for (int i = 0; i < 40; i++)
    {
        Sleep(2000);
        wait(wrt);
        if (countW >= 20)
        {
            Sleep(5000);
            countW = 0;
        }
        data[countW].ThreadID = 111;
        data[countW].Number = (rand() % 40) + 21;
        countW++;
        signal(wrt);
        //printf("ID = %d\nData = %d\nCount = %d\n\n", data[countW - 1].ThreadID, data[countW - 1].Number, countW - 1);

    }
}
void W2_thread()
{

    for (int i = 0; i < 40; i++)
    {
        Sleep(2000);
        wait(wrt);
        if (countW >= 20)
        {
            Sleep(5000);
            countW = 0;
        }
        data[countW].ThreadID = 222;
        data[countW].Number = (rand() % 60) + 61;
        countW++;
        signal(wrt);
        //printf("ID = %d\nData = %d\nCount = %d\n\n", data[countW - 1].ThreadID, data[countW - 1].Number, countW - 1);
    }
}



void R1_thread()
{
    for (int i = 0; i < 40; i++)
    {
        Sleep(1000);
        wait(mutex);
        wait(wrt);
        signal(mutex);

        if (countR >= 20)
        {
            countR = 0;
        }
        if (data[countR].ThreadID == 111)
        {
            printf("R1\nID = %d\nData = %d\nCount = %d\n\n", data[countR].ThreadID, data[countR].Number, countR);
            countR++;
        }
        //countR++;
        wait(mutex);
        signal(wrt);
        signal(mutex);
    }
}

void R2_thread()
{
    for (int i = 0; i < 40; i++)
    {
        Sleep(1000);
        wait(mutex);
        wait(wrt);
        signal(mutex);

        if (countR >= 20)
        {
            countR = 0;
        }
        if (data[countR].ThreadID == 222)
        {
            printf("R2\nID = %d\nData = %d\nCount = %d\n\n", data[countR].ThreadID, data[countR].Number, countR);
            countR++;
        }
        //countR++;
        wait(mutex);
        signal(wrt);
        signal(mutex);
    }
}

void main()
{
     pthread_t W1, W2, R1, R2;
     char *message1 = "Thread 1";
     char *message2 = "Thread 2";
     int  iret1, iret2, iret3, iret4;
     
    /* Create independent threads each of which will execute function */

     iret1 = pthread_create(&W1, NULL, W1_thread, NULL);
     iret2 = pthread_create(&W2, NULL, W2_thread, NULL);
     Sleep(2000);
     iret3 = pthread_create(&R1, NULL, R1_thread, NULL);
     iret4 = pthread_create(&R2, NULL, R2_thread, NULL);
     
     /* Wait till threads are complete  */

     pthread_join(W1, NULL);
     pthread_join(W2, NULL); 
     pthread_join(R1, NULL);
     pthread_join(R2, NULL);
     //getchar();
	 //system("pause");
     

     exit(0);
}

