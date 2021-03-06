/**********************************************************
 * @author  Pulkit Verma
 * @email   technopreneur[dot]pulkit[at]gmail[dot]com
 * @year	2014
 **********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "customCommands.h"

int main(int argc, char* argv[])
{
	char c;
	pid_t c_pid,c_pid1;  /* child process id */ 
	c_pid = fork();
	if (c_pid == -1) 
	 	exit(1);

        /* following program segment will be executed by child process */
	if (c_pid == 0) 
	{  
	  	c_pid1 = fork();
		if (c_pid1 == -1) 
		 	exit(1);

	        // following program segment will be executed by child process 
		if (c_pid1 == 0) 
		{  

			int shmid;
			key_t key;
			char *shm, *s;
			key = 5678;
			if ((shmid = shmget(key, BUFFER_SIZE, IPC_CREAT | 0666)) < 0) { //write data on 
				perror("shmget");
				exit(1);
			}
			if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
				perror("shmat");
				exit(1);
			}
			s = shm;
			cat(argv[1],s);

		} 
	        // following will be executed by parent process  
		else 
		{  
			wait(NULL); /* Wait for child */ 
			int shmid2,shmid3;
			key_t key2,key3;
			char *shm2, *s2,*shm3,*s3;

			key2 = 5678;
			key3 = 5679;
			if ((shmid2 = shmget(key2, BUFFER_SIZE, 0666)) < 0) { //Getting data from segment with key 5678
				perror("shmget");
				exit(1);
			}
			if ((shm2 = shmat(shmid2, NULL, 0)) == (char *) -1) {
				perror("shmat");
				exit(1);
			}
			s2 = shm2;

			if ((shmid3 = shmget(key3, BUFFER_SIZE, IPC_CREAT | 0666)) < 0) { //Getting data from segment with key 5678
				perror("shmget");
				exit(1);
			}

			if ((shm3 = shmat(shmid3, NULL, 0)) == (char *) -1) {
				perror("shmat");
				exit(1);
			}

			s3 = shm3;
			grep(argv[2],s2,s3);
			exit(1); 
		}
	} 
        // following will be executed by parent process  
	else 
	{  
		wait(NULL); /* Wait for child */ 	
		int shmid4;
		key_t key4;
		char *shm4, *s4;
		key4 = 5679;
		if ((shmid4 = shmget(key4, BUFFER_SIZE,  0666)) < 0) { //write data on 
			perror("shmget");
			exit(1);
		}
		if ((shm4 = shmat(shmid4, NULL, 0)) == (char *) -1) {
			perror("shmat");
			exit(1);
		}
		s4 = shm4;
		wc(s4);
		exit(1); 
	}
	return 0;
}
