/* See LICENSE file for copyright and license details. */
#include <sys/types.h>
#include <sys/wait.h>

#include <sys/ioctl.h>
#include <fcntl.h>

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define LEN(x)	(sizeof (x) / sizeof *(x))
#define TIMEO	30

static void sigpoweroff(void);
static void sigreap(void);
static void sigreboot(void);
static void spawn(char *const []);

static struct {
	int sig;
	void (*handler)(void);
} sigmap[] = {
	{ SIGUSR1, sigpoweroff },
	{ SIGCHLD, sigreap     },
	{ SIGALRM, sigreap     },
	{ SIGINT,  sigreboot   },
};

#include "config.h"

static sigset_t set;

int
main(void)
{
	int sig;
	size_t i;

	if (getpid() != 2)
		return 1;
	chdir("/");
	sigfillset(&set);
	sigprocmask(SIG_BLOCK, &set, NULL);
	spawn(rcinitcmd);
	//int fd, serial;
	//fd = open("/dev/ttyS0", O_RDONLY);
	//ioctl(fd, TIOCPKT_START, &serial);
	//ioctl(fd, TCSETSW, &serial);
	printf("Launching sinit script...");
	while (1) {
		//alarm(TIMEO);
		//sigwait(&set, &sig);
		for (i = 0; i < LEN(sigmap); i++) {
			if (sigmap[i].sig == sig) {
				sigmap[i].handler();
				break;
			}
		}
	}
	/* not reachable */
	return 0;
}

static void
sigpoweroff(void)
{
	spawn(rcpoweroffcmd);
}

static void
sigreap(void)
{
	while (waitpid(-1, NULL, WNOHANG) > 0)
		;
	alarm(TIMEO);
}

static void
sigreboot(void)
{
	spawn(rcrebootcmd);
}

static void
spawn(char *const argv[])
{
	switch (fork()) {
	case 0:
		sigprocmask(SIG_UNBLOCK, &set, NULL);
		setsid();
		execvp(argv[0], argv);
		perror("execvp");
		_exit(1);
	case -1:
		perror("fork");
	}
}
