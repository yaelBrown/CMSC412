// Project file
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

// int main(void) {
//   int pid;
//   pid = fork();
//   printf("pid: %d", pid);
//   if (pid < 0) {
//     printf("\n Error: pid is less than 0");
//     exit(1);
//   } else if (pid == 0) {
//     printf("\n I am the child process and my pid is %d", getpid());
//     exit(0);
//   } else {
//     printf("\n I am the parent process and my pid is %d", getpid());
//     exit(1);
//   }
// }

int main() { 
	if(fork() == 0) { 
		int gparent = getppid(); 
		if (fork() == 0) { 
			printf("I am the child process C and my pid is %d. My parent P has pid %d. My grandparent G has pid %d.\n", getpid(), getppid(), gparent); 
		} else { 
			while (wait(NULL) > 0) {
        printf("I am the parent process P and my pid is %d. My parent G has pid %d.\n", getpid(), gparent); 
      }
		} 
	} else { 
		while (wait(NULL) > 0); 
		printf("I am the grandparent process G and my pid is %d.\n", getpid()); 
	} 
} 