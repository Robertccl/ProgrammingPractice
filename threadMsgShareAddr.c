#include <sys/shm.h>
#include <pthread.h>  
#include <unistd.h>  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <semaphore.h> 
#include <fcntl.h> 

#define TEXT_SZ 4096
#define SEM_NAME1 "/ccl1xinhaoliang"
#define SEM_NAME2 "/ccl2xinhaoliang" 
#define SEM_NAME3 "/ccl3xinhaoliang" 
#define SEM_NAME4 "/ccl4xinhaoliang" 
#define SEM_NAME5 "/ccl5xinhaoliang" 
  
#define MAXMSQ 10

sem_t *sem_full;
sem_t *sem_empty;
sem_t *sem_mutex;
sem_t *sem_p;
sem_t *sem_q;

struct shared_use_st  
{  
    //int written;//作为一个标志，非0：表示可读，0表示可写  
    char text[TEXT_SZ];//记录写入和读取的文本  
};  

void shmread();
void shmwrite();

int main()
{
    pthread_t tid1, tid2;/*线程标示符*/ 
    sem_full = sem_open(SEM_NAME1, O_CREAT, 0666, 0);
    sem_empty = sem_open(SEM_NAME2, O_CREAT, 0666, MAXMSQ);
    sem_mutex = sem_open(SEM_NAME3, O_CREAT, 0666, 1);
    sem_p = sem_open(SEM_NAME4, O_CREAT, 0666, 0);
    sem_q = sem_open(SEM_NAME5, O_CREAT, 0666, 0);
    
    pthread_create(&tid2, NULL, shmread, NULL);
    pthread_create(&tid1, NULL, shmwrite, NULL);/*创建一个线程*/    
 
    pthread_join(tid1, NULL);/*等待子线程执行完毕*/  
    pthread_join(tid2, NULL);
    
    sem_close(sem_full); 
    sem_close(sem_empty);
    sem_close(sem_mutex);
    sem_close(sem_p);
    sem_close(sem_q);

    sem_unlink(SEM_NAME1); 
    sem_unlink(SEM_NAME2);
    sem_unlink(SEM_NAME3);
    sem_unlink(SEM_NAME4);
    sem_unlink(SEM_NAME5);
   

    return 0;
}

void shmwrite()
{
    int running = 1;  
    void *shm = NULL;  
    struct shared_use_st *shared = NULL;  
    char buffer[BUFSIZ + 1];//用于保存输入的文本  
    int shmid;  
    //创建共享内存  
    shmid = shmget((key_t)1234, sizeof(struct shared_use_st), 0666|IPC_CREAT);  
    if(shmid == -1)  
    {  
        fprintf(stderr, "shmget failed\n");  
        exit(EXIT_FAILURE);  
    }  
    //将共享内存连接到当前进程的地址空间  
    shm = shmat(shmid, (void*)0, 0);  
    if(shm == (void*)-1)  
    {  
        fprintf(stderr, "shmat failed\n");  
        exit(EXIT_FAILURE);  
    }  
    //printf("Memory attached at %X\n", (int)shm);  
    //设置共享内存  
    shared = (struct shared_use_st*)shm;  
    while(running)//向共享内存中写数据  
    {  
        
        //向共享内存中写入数据
        sem_wait(sem_empty);            // xinhaoliang p caozuo
        sem_wait(sem_mutex);            // xinhaoliang p caozuo  
        printf("Writer:");  
        fgets(buffer, BUFSIZ, stdin);  
        strncpy(shared->text, buffer, TEXT_SZ);  
        //写完数据，设置written使共享内存段可读  
       
        sem_post(sem_mutex);             //xinhaoliang  v  caozuo
        sem_post(sem_full);             //xinhaoliang  v  caozuo
        sleep(1);
        sem_post(sem_p); //xinhaoliang  v  caozuo  
        
        //输入了end，退出循环（程序）  
        if(strncmp(buffer, "exit", 4) == 0)  
        {
            sem_wait(sem_q);                // xinhaoliang p caozuo 
            sem_wait(sem_full);                // xinhaoliang p caozuo 
            sem_wait(sem_mutex);                // xinhaoliang p caozuo    
            printf("Writer: %s\n", shared->text);  
            //sleep(rand() % 3);
            sem_post(sem_mutex);             //xinhaoliang  v  caozuo
            sem_post(sem_empty);             //xinhaoliang  v  caozuo  
            //读取完数据，设置written使共享内存段可写  
            
            running=0;  
        }
    }  
    //把共享内存从当前进程中分离  
    if(shmdt(shm) == -1)  
    {  
        fprintf(stderr, "shmdt failed\n");  
        exit(EXIT_FAILURE);  
    }
    shmctl(shmid, IPC_RMID, NULL); 
    sleep(2);  
    exit(EXIT_SUCCESS);
}

void shmread()
{
    int running = 1;//程序是否继续运行的标志  
    void *shm = NULL;//分配的共享内存的原始首地址  
    struct shared_use_st *shared;//指向shm  
    int shmid;//共享内存标识符  
    //创建共享内存  
    shmid = shmget((key_t)1234, sizeof(struct shared_use_st), 0666|IPC_CREAT);  
    if(shmid == -1)  
    {  
        fprintf(stderr, "shmget failed\n");
        printf("error1");  
        exit(EXIT_FAILURE);  
    }  
    //将共享内存连接到当前进程的地址空间  
    shm = shmat(shmid, 0, 0);  
    if(shm == (void*)-1)  
    { 
        printf("error2");  
        fprintf(stderr, "shmat failed\n");  
        exit(EXIT_FAILURE);  
    }  
    //printf("\nMemory attached at %X\n", (int)shm);  
    //设置共享内存  
    shared = (struct shared_use_st*)shm;  
    
    while(running)//读取共享内存中的数据  
    {  
       
        sem_wait(sem_p);                // xinhaoliang p caozuo 
        sem_wait(sem_full);                // xinhaoliang p caozuo 
        sem_wait(sem_mutex);                // xinhaoliang p caozuo    
        printf("Reader: %s", shared->text);  
        //sleep(rand() % 3);
        
        sem_post(sem_mutex);             //xinhaoliang  v  caozuo
        sem_post(sem_empty);             //xinhaoliang  v  caozuo  
        sleep(1);
       
        //输入了exit，  
        if(strncmp(shared->text, "exit", 4) == 0)  
        {
            sem_wait(sem_empty);            // xinhaoliang p caozuo
            sem_wait(sem_mutex);            // xinhaoliang p caozuo  
            strncpy(shared->text, "over", TEXT_SZ);  
            //写完数据，设置written使共享内存段可读  
            
            sem_post(sem_mutex);             //xinhaoliang  v  caozuo
            sem_post(sem_full);             //xinhaoliang  v  caozuo
            //把共享内存从当前进程中分离  
            if(shmdt(shm) == -1)  
            {  
                fprintf(stderr, "shmdt failed\n");  
                exit(EXIT_FAILURE);  
            }  
            sem_post(sem_q); //xinhaoliang  v  caozuo 
            running=0;   
        }
        
         
        sleep(1);
    }  
    
    
    exit(EXIT_SUCCESS);
}



