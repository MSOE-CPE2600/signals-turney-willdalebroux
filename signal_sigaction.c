/**
 * File: signal_sigation.c
 * Modified by: Will Dalebroux
 * 
 * Brief summary of program:
 * Registers a handler for SIGUSR1, prints PID of sender and signal sent
 * Note: Run with "./signal_sigaction &" to run in the background
 * from the terminal run "kill -SIGUSR1 <pid>" exit with kill -SIGKILL <pid>
 */
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handle_usr1(int sig, siginfo_t *info, void *context)
{
    printf("Caught SIGUSR1 from %d\n", info->si_pid);
}

int main(void)
{
    struct sigaction sa; // declare struct to hold instructions to handle a signal
    sa.sa_flags = SA_SIGINFO; // enable detailed info
    sa.sa_sigaction = handle_usr1; // use handler
    sigemptyset(&sa.sa_mask); // don't block other signals

    sigaction(SIGUSR1, &sa, NULL); // register handler

    while(1)
    {
        sleep(1); // pause indefinitely so program can be run in background
    }

         
    
    return 0;
}