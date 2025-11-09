/**
 * File: signal_alarm.c
 * Modified by: Will Dalebroux  
 * 
 * Brief summary of program:
 * sets an alarm for 5 seconds, counts up to 5
 */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handle_signal()
{
    printf("received a signal\n");
}

int main(void)
{
    signal(SIGALRM, handle_signal);
    alarm(5);
    printf("Sleeping....\n");
    for(int i=1; i<6; i++)
    {
        printf("%d\n",i);
        sleep(1);
    }
    return 0;
}