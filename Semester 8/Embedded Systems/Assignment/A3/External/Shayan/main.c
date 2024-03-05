#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "pthread.h"
#include "semaphore.h"

//BEE173076
//6 %3 =0 + 1 = 1 = option  1
//R and W are variables for count 

int R = 0, W = 0;
int Write = 1, mutex;

struct Message
{
    int ThreadID;
    int Number;
}data[20];


void *print_message_function( void *ptr )
{
     char *message;
     message = (char *) ptr;
     printf("Executing %s \n", message);
	
	 pthread_exit(NULL);

}

int wait(int S)
{
    while (S <= 0)
    {

    }
    S = 0;
}
int signal(int S)
{
    S = 1;
}


void R1_thread()
{
    for (int i = 0; i < 40; i++)
    {
        Sleep(1000);
        if (R >= 20)
        {
            R = 0;
        }
        if (data[R].ThreadID == 111)
        {
            printf("ID = %d\nData = %d\nCount = %d\n\n", data[R].ThreadID, data[R].Number, R);
        }
        R++;
    }
}

void R2_thread()
{
    for (int i = 0; i < 40; i++)
    {
        Sleep(1000);
        if (R >= 20)
        {
            R = 0;
        }
        if (data[R].ThreadID == 222)
        {
            printf("ID = %d\nData = %d\nCount = %d\n\n", data[R].ThreadID, data[R].Number, R);
        }
        R++;
    }
}


void W1_thread()
{

    for (int i = 0; i < 40; i++)
    {
        wait(write);
        Sleep(2000);
        if (W >= 20)
        {
            Sleep(5000);
            W = 0;
        }
        data[W].ThreadID = 111;
        data[W].Number = (rand() % 40) + 21;
        W++;
        signal(write);
    }
}
void W2_thread()
{

    for (int i = 0; i < 40; i++)
    {
        wait(write);
        Sleep(2000);
        if (W >= 20)
        {
            Sleep(5000);
            W = 0;
        }
        data[W].ThreadID = 222;
        data[W].Number = (rand() % 60) + 61;
        W++;
        signal(write);
    }
}



void main()
{
     pthread_t W1, W2, R1, R2;
     char *message1 = "Thread 1";
     char *message2 = "Thread 2";
     int  iret1, iret2, iret3, iret4;
     
    /* Creating independent threads which will call functions */

     iret1 = pthread_create(&W1, NULL, W1_thread, NULL);
     iret2 = pthread_create(&W2, NULL, W2_thread, NULL);
     iret3 = pthread_create(&R1, NULL, R1_thread, NULL);
     iret4 = pthread_create(&R2, NULL, R2_thread, NULL);
     
     //pthread_join( W1, NULL);
     //pthread_join( W2, NULL); 

     //getchar();
	 system("pause");

     exit(0);
}

