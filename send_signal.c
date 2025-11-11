/**
 * File: send_signal.c  
 * Modified by: Will Dalebroux
 * 
 * Brief summary of program:
 * take in pid from commandline arg, generates random number to send to receiving process,
 * queues then sends random number to receiving process
 */
 

 #include <stdio.h>
 #include <stdlib.h>
 #include <signal.h>
 #include <time.h>

 int main(int argc, char *argv[])
 {
   if(argc != 2)
   {
      fprintf(stderr, "Usage: %s <receiving pid>\n", argv[0]);
      return 2;
   }

   pid_t pid = (pid_t)strtol(argv[1], NULL, 10); // convert argument from string to pid_t

   srand((unsigned)time(NULL)); // seed
   int value = rand() % 1000000; // random value to send

   union sigval sv; // declare union to store sending value in 
   sv.sival_int = value; //include value while sending signal

   printf("sending value %d to pid %d through SIGUSR1\n", value, pid);
   if(sigqueue(pid, SIGUSR1, sv) == -1) // find pid, verify signal can be sent, queue signal to be sent, store attached int in sv
   {
      perror("sigqueue");
      return 1;
   }
   return 0;
 }