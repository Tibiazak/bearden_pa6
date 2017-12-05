#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_BUF 200

int main(int argc, char *argv[])
{
   pid_t pid = 0;
   pid_t wait = 0;
   int i, pr_limit, pr_count, status;
   pr_count = 0;
   char str[MAX_BUF];
   char * done;
   int code;

   if(argc != 2)
   {
      printf("Wrong number of command line arguments!\n");
      return 1;
   }

   pr_limit = atoi(argv[1]);

   done = fgets(str, MAX_BUF, stdin);

   printf("Just before while loop\n");

   while(done != NULL)
   {
      printf("String is: %s\n", str);
      if(pr_count == pr_limit)
      {
         printf("pr_count == pr_limit\n");
         wait = waitpid(-1, &status, WNOHANG);
         while(wait == 0)
         {
            wait = waitpid(-1, &status, WNOHANG);
         }
         code = WEXITSTATUS(status);
         printf("Process %d exited with status %d\n", wait, code);
         pr_count--;
      }
      
      pid = fork();
      
      if(pid == 0)
      {
         char * args[3];
         args[0] = strtok(str, " ");
         for(i = 1; i < 3; i++)
         {
            args[i] = strtok(NULL, " ");
         }

         execv(args[0], args);
      } 
      else
      {
         pr_count++;
         wait = waitpid(-1, &status, WNOHANG);
         if (wait != 0)
         {
            pr_count--;
            code = WEXITSTATUS(status);
            printf("Process %d exited with status %d\n", wait, code);
            wait = 0;
         }
      }
      done = fgets(str, MAX_BUF, stdin);
   }
   while (pr_count > 0)
   {
      wait = waitpid(-1, &status, WNOHANG);
      if(wait != 0)
      {
         pr_count--;
         code = WEXITSTATUS(status);
         printf("Process %d exited with status %d\n", wait, code);
      }
   }

   return 0;
}