/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by: Will Dalebroux  
 * 
 * Brief summary of modifications: added signal declaration with arguments SIGSEGV and handle_signal
 * handle signal prints "caught segmentation fault" and attempts to return.
 * After the signal is caught, the program returns to where it was before the signal was caught,
 * causing the handle_signal message to be printed infinitely
 */


#include <stdio.h>
#include <signal.h>
#include <unistd.h>


void handle_signal()
{
    printf("Caught Segmentation fault\n");
    return;
}

int main (int argc, char* argv[]) {
    // Declare a null pointer
    int* i = NULL;
    // declare signal
    signal(SIGSEGV, handle_signal);
    
    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}