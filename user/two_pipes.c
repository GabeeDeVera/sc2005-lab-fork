#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int p1[2], p2[2];
  char buf[6];

  pipe(p1);
  pipe(p2);

  if(fork() == 0){
    // Implement the Child code here
    read(p1[0], buf, 4);
    printf("%d: received %s\n", getpid(), buf);
    write(p2[1], "pong", 4);
    
    exit(0);
} else {
    // Implement the Parent code here
    
    write(p1[1], "ping", 4);
    read(p2[0], buf, 4);
    printf("%d: received %s\n", getpid(), buf);
    
    close(p1[0]);
    close(p1[1]);
    close(p2[0]);
    close(p2[1]);
    wait(0);
    exit(0);
  }
}

// int
// main(int argc, char *argv[])
// {
//   int p[2];
//   char buf[5];
  
//   pipe(p);
//   if(fork() == 0){
//     // Child
//     char* buf;
//     for (int j=0; j<5; j++) {
//       if ((j % 2) == 0) {
//         buf = "ping";
//         write(p[1], buf, 4);
//       } else {
//         buf = "pong";
//         write(p[1], buf, 4);
//       }
//     }
//     exit(0);
//   } else {
//     // Parent
//     for (int j=0; j<5; j++) {
//       read(p[0], buf, 4);
//       printf("%d: received %s\n", getpid(), buf);
//     }

//     close(p[0]);
//     close(p[1]);
//     wait(0);
//     exit(0);
//   }
// }