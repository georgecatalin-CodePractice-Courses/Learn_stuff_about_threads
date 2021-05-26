#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void *thread_no1(void *arg);
void *thread_no2(void *arg);
void *thread_no3(void *arg);

pthread_t tid[3];
int err;

int main()
{
	printf("Now executing main program...\n");

	err=pthread_create(&(tid[0]),NULL, &thread_no1, NULL);

	if(err!=0)
	{	
		printf("\nI can not create the new thread 1: [%s]\n", strerror(err));
	}
	else
	{
		printf("\nNew thread 1 has been created successfully.\n");
	}

	err=pthread_create(&(tid[1]),NULL,&thread_no2,NULL);

	if(err!=0)
	{
		printf("\nI can not create the new thread 2: [%s]\n",strerror(err));
	}
	else
	{
		printf("\nNew thread 2 has been created successfully.\n");
	}

	err=pthread_create(&(tid[2]),NULL,&thread_no3,NULL);

	if (err!=0)
	{	
		printf("\nI can not create the new thread 3:[%s]\n",strerror(err));
	}
	else
	{
		printf("\nNew thread 3 has been created successfully.\n");
	}


	//now simulate a resource intensive action in the main program
	for(int i=0;i<0xFFFFFFFF;i++)
	{

	}

	printf("\nThe main program is now over.\n");
	return 0;
}


void *thread_no1(void *arg)
{
	for(int j=0;j<0xFFFFFFFF;j++)
	{
	}

	printf("\nThread no.1 has terminated.\n");
	return NULL;
}

void *thread_no2(void *arg)
{
	for(int k=0;k<0xFFFFFFFF;k++)
	{
	}

	printf("\nThread no.2 has terminated.\n");
	return NULL;
}

void *thread_no3(void *arg)
{
	for(int l=0;l<0xFFFFFFFF;l++)
	{
	}

	printf("\nThread no.3 has terminated.\n");
	return NULL;
}

// to compile this file use : gcc thread_example.c -o thread_example -lpthread 

