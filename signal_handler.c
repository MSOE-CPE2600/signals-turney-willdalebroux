/**
 * @file signal_handler.c
 * @brief Sets a signal handler for SIGINT, the handler prints a message and then quits
 */

/**
 * Modified by: Will Dalebroux
 * 
 * Brief summary of modifications:
 */


#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Signal handler for SIGINT - prints a message and exits
 */
void handle_signal() {
    printf("\nReceived a signal\n");
}

int main() {

    // Register for the signal
    signal(SIGINT, handle_signal);
    int pid = getpid();
    printf("PID is: %d\n", pid);
    printf("Press CTRL + C to send interrupt\n");
    printf("Exit by suspending with CTRL + Z, then run kill -SIGKILL <pid> from commandline\n");

    

    // Wait until a signal is received
    while(1) {
        printf("sleeping...\n");
        sleep(10);
    }

    return 0;
}