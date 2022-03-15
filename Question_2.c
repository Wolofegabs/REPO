#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main (void)
{
    pid_t fils_pid;

    fils_pid = fork();

    if (fils_pid<0)

      {
        printf("Erreur dans la creation du processus fils\n");
      }

    else
    {
         if (fils_pid==0)
        {
            printf(" Je suis le pere. Le pid de mon fils est : %d\n", getpid());
        }
        else { if (fils_pid>0)

                    {
                    printf("je suis le fils, le pid de mon pere est : %d\n", getpid());
                    }

            }
    }


    }

