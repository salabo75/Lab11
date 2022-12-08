#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

static void signal_handler(int signo) {
	if (signo == SIGINT)
		printf("???????? ?????? SIGINT!\n");
	else if (signo == SIGTERM)
		printf("???????? ?????? SIGTERM!\n");
	else if (signo == SIGUSR1)
		printf("???????? ?????? SIGUSR1!\n");
	else {
		fprintf(stderr, "??????????? ??????!\n");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}


int main (void) {
	if (signal(SIGINT, signal_handler) == SIG_ERR) {
		fprintf(stderr, "?????????? ?????????? SIGINT!\n");
		exit(EXIT_FAILURE);
	}

	if (signal(SIGTERM, signal_handler) == SIG_ERR) {
		fprintf(stderr, "?????????? ?????????? SIGTERM!\n");
		exit(EXIT_FAILURE);
	}

	if (signal(SIGUSR1, signal_handler) == SIG_ERR) {
		fprintf(stderr, "?????????? ?????????? SIGUSR1!\n");
		exit(EXIT_FAILURE);
	}

	if (signal(SIGPROF, SIG_DFL) == SIG_ERR) {
		fprintf(stderr, "?????????? ???????? SIGPROF!\n");
		exit(EXIT_FAILURE);
	}

	if (signal(SIGHUP, SIG_IGN) == SIG_ERR) {
		fprintf(stderr, "?????????? ???????????? SlGHUP!\n");
		exit(EXIT_FAILURE);
	}
	for (;;) {
		pause();
	}
	return 0;
}