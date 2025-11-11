/**
 * File: recv_signal.c  
 * Modified by: Will Dalebroux
 * 
 * Brief summary of program:
 * handles signals sent from send_signal.c, prints recieved signal and value sent from
 * send_signal.c
 * Note: run with ./recv_signal &
 * Note 2: terminate process with kill -SIGKILL <pid> (in commandline)
 */
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

void handle_usr1(int sig, siginfo_t *info, void *context)
{
    printf("got SIGUSR1 from pid %d, value=%d\n", info->si_pid, info->si_value.sival_int);
}

int main(void)
{
    struct sigaction sa; // declare struct to hold signal handler instructions
    sa.sa_flags = SA_SIGINFO; // enable detailed info
    sa.sa_sigaction = handle_usr1; // use handler
    sigemptyset(&sa.sa_mask); // don't block other signals

    if(sigaction(SIGUSR1, &sa, NULL) == -1) // register handler
    {
        perror("sigaction");
        return 1;
    }

    printf("receiving pid: %d (waiting for SIGUSR1)\n", getpid());

    while(1)
    {
        sleep(1); // pause indefinitely to run in background
    }

    return 0;
}