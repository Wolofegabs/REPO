#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

// Structure avec des tubes full-duplex
typedef struct fdpipe {
	int father[2];
	int son[2];
} fdpipe;

// Nombre total de thread
#define NB_FORK 10
// Taille du message
#define LENGTH_MSG 50
// Tableau contenant le message
char message[LENGTH_MSG] = "";

// Fonction exécutée dans le fork
void job(fdpipe * pipes) {
	int tid = getpid();
	// timer pour attendre maximum 5 secondes
	int i = 5;
	while (i > 0) {
		// lecture dans le tube
		if (read((*pipes).father[0], message, LENGTH_MSG) > 0) {
			printf("Message du processus [%i] : %s\n", tid, message);
			// Ecriture du message dans le tableau
			sprintf(message, "je suis [%i] et j'ai bien reçu ton message !\n", tid);
			write((*pipes).son[1], message, LENGTH_MSG);
			break;
		}
		sleep(1);
	}
}
// Fonction qui attend chacun des processus fils
void waitForAll() {
	int status;
	pid_t pid;
	int n = 0;
	while (n < NB_FORK) {
		pid = wait(&status);
		n++;
	}
}

int main() {
	for (int i = 0; i < NB_FORK; i++) {
		fdpipe pipes;
		pipe(pipes.father);
		pipe(pipes.son);
		pid_t pid = fork();
		if (pid == -1) {
			// Il y a une erreur
			perror("fork");
			return EXIT_FAILURE;
		} else if (pid == 0) {
			// On est dans le fils
			close(pipes.father[1]);
			job(&pipes);
			close(pipes.father[0]);
			close(pipes.son[0]);
			close(pipes.son[1]);
			exit(EXIT_SUCCESS);
		} else {
			// On est dans le père
			// Ecriture du message dans le tableau
			sprintf(message, "Fork [%i], je suis ton père !\n", pid);
			// Ecriture du message dans le tube
			write(pipes.father[1], message, LENGTH_MSG);
			while (i > 0) {
				// lecture dans le tube
				if (read(pipes.son[0], message, LENGTH_MSG) > 0) {
					printf("Réponse du fils : %s\n", message);
					break;
				}
				sleep(1);
			}
			close(pipes.father[1]);
			close(pipes.father[0]);
			close(pipes.son[0]);
			close(pipes.son[1]);
		}
	}
	waitForAll();
	return EXIT_SUCCESS;
}
