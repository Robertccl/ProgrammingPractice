#include <pthread.h>  
#include <unistd.h>  
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <semaphore.h>  

#define MAX_TEXT 512
#define MAXMSQ 10

sem_t sem_full;
sem_t sem_empty;
sem_t sem_mutex;
sem_t sem_p;
sem_t sem_q;
 
struct my_msg_st
{
    long int my_msg_type;
    char some_text[MAX_TEXT];
};  

void sender();
void reciver();

int main()  
{  
    sem_init(&sem_full, 0, 0); 
    sem_init(&sem_empty, 0, MAXMSQ);
    sem_init(&sem_mutex, 0, 1);
    sem_init(&sem_p, 0, 0);  
    sem_init(&sem_q, 0, 0);
    pthread_t tid1, tid2;/*线程标示符*/  
    
    pthread_create(&tid2, NULL, reciver, NULL);
    pthread_create(&tid1, NULL, sender, NULL);/*创建一个线程*/
   
    pthread_join(tid1, NULL);/*等待子线程执行完毕*/  
    pthread_join(tid2, NULL);

    sem_destroy(&sem_full); 
    sem_destroy(&sem_empty);
    sem_destroy(&sem_mutex);
    sem_destroy(&sem_p);
    sem_destroy(&sem_q);

    return 0;  
}  


void sender()
{
    int running = 1;
    struct my_msg_st some_data;
    int msgid;
    char buffer[BUFSIZ];
    long int msg_to_receive = 10;


    //key_t表示消息队列标志，用于获取同一消息队列；0666 表示用户的操作权限
    msgid = msgget((key_t)1234, 0666|IPC_CREAT);
    
    if(msgid==-1)
    {
        fprintf(stderr,"msgget failed with errno: %d\n", errno);
        exit(EXIT_FAILURE);
    }
    
    while(running)
    {
        sem_wait(&sem_empty);            // xinhaoliang p caozuo
        sem_wait(&sem_mutex);            // xinhaoliang p caozuo
        printf("Sender: ");
        fgets(buffer, BUFSIZ, stdin);   //stdin 意思是键盘输入
        some_data.my_msg_type = 1;
        if(strncmp(buffer, "exit", 4) == 0)
        {
            strcpy(buffer, "end");
        }
        
        strcpy(some_data.some_text, buffer);
                      
        if(msgsnd(msgid, (void *)&some_data, MAX_TEXT, 0)==-1)
        {
            fprintf(stderr, "msgsnd failed\n");        //stderr表示标准错误输出
            exit(EXIT_FAILURE);
        }
        sem_post(&sem_mutex);             //xinhaoliang  v  caozuo
        sem_post(&sem_full);             //xinhaoliang  v  caozuo

        sem_post(&sem_p); //xinhaoliang  v  caozuo

        if(strncmp(buffer, "end", 3) == 0)
        {
            sem_wait(&sem_q);            // xinhaoliang p caozuo 
            sem_wait(&sem_full);             //xinhaoliang  p  caozuo
    	    sem_wait(&sem_mutex);             //xinhaoliang  p  caozuo

            if(msgrcv(msgid, (void *)&some_data, BUFSIZ, msg_to_receive, 0) == -1)
            {
                fprintf(stderr, "msgrcv failed with errno: %d\n", errno);
                exit(EXIT_FAILURE);
            }
            sem_post(&sem_mutex);             //xinhaoliang  v  caozuo
    	    sem_post(&sem_empty);             //xinhaoliang  v  caozuo
            printf("Sender: %s\n", some_data.some_text);
            strcpy(buffer, some_data.some_text);  
            if(strncmp(buffer, "over", 4) == 0)
            {
                running = 0;
                if(msgctl(msgid, IPC_RMID, 0)==-1)          //shan chu xiaoxi duilie
                {
                    fprintf(stderr, "msgctl(IPC_RMID) failed\n");
                    exit(EXIT_FAILURE);
                }
                
                exit(EXIT_SUCCESS);
            }
            sleep(1);
         }
        sleep(1); 
    }

    exit(EXIT_SUCCESS);
}

void reciver()
{
  
    int running = 1;
    int msgid;
    struct my_msg_st some_data;
    long int msg_to_receive = 1;
    //sem_wait(&sem_p);                // xinhaoliang p caozuo 
  
    msgid = msgget((key_t)1234,0666|IPC_CREAT);

    if(msgid == -1)
    {
        fprintf(stderr,"msgget failed with error: %d\n", errno);
        exit(EXIT_FAILURE);
    }

    while(running)
    {
        sem_wait(&sem_p);                // xinhaoliang p caozuo 

        sem_wait(&sem_full);                // xinhaoliang p caozuo 
        sem_wait(&sem_mutex);                // xinhaoliang p caozuo 
        if(msgrcv(msgid, (void *)&some_data, BUFSIZ, msg_to_receive, 0) == -1)
        {
            fprintf(stderr, "msgrcv failed with errno: %d\n", errno);
            exit(EXIT_FAILURE);
        }
        
        sem_post(&sem_mutex);             //xinhaoliang  v  caozuo
        sem_post(&sem_empty);             //xinhaoliang  v  caozuo
        printf("Reciver: %s\n", some_data.some_text);
        if(strncmp(some_data.some_text, "end", 3)==0)
        {
            some_data.my_msg_type = 10;
            strcpy(some_data.some_text, "over");

            sem_wait(&sem_empty);                // xinhaoliang p caozuo 
    	    sem_wait(&sem_mutex);                // xinhaoliang p caozuo 
            if(msgsnd(msgid, (void *)&some_data, MAX_TEXT, 0)==-1)
            {
                fprintf(stderr, "msgsnd failed\n");
                exit(EXIT_FAILURE);
            }
            sem_post(&sem_mutex);             //xinhaoliang  v  caozuo
    	    sem_post(&sem_full);             //xinhaoliang  v  caozuo
			
	        sem_post(&sem_q);

            running = 0;
        }
    sleep(1);
    }   
	exit(EXIT_SUCCESS);
}
 
