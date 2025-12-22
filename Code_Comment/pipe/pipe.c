#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];  // pipe creates 2 file descriptors: read end [0] and write end [1]
    
    pipe(fd);   // this creates a temporary buffer in kernel (RAM), connected to fd[0] and fd[1]
                // fd[0] will be the read side, fd[1] will be the write side
                // these will usually be assigned fd = 3 and 4, since 0, 1, 2 are stdin, stdout, stderr

    char msg[] = "HelloPipe";  // the message we want to write into the pipe (goes into the RAM box)
    char read_buf[100];        // buffer where we’ll store what comes out (simulate taking out of pipe)

    // simulate writing to the pipe (to kernel RAM box) — this goes in one direction only
    write(fd[1], msg, strlen(msg) + 1); // writing all bytes at once (yes, write size can be big)

    // now simulate reading from the pipe — like taking bytes out from a queue
    read(fd[0], read_buf, 5);           // read only 5 bytes (FIFO behavior: gets "Hello")
    read_buf[5] = '\0';                 // null terminate for clean output
    printf("First read: %s\n", read_buf); // should print "Hello"

    // read the remaining part — it didn’t disappear yet, only first 5 were popped
    read(fd[0], read_buf, 100);          // reads "Pipe"
    printf("Second read: %s\n", read_buf); // should print "Pipe"

    // try reading again — buffer should now be empty (queue is drained)
    int n = read(fd[0], read_buf, 100);   // should return 0 (EOF)
    printf("Third read returned: %d bytes (means pipe is empty)\n", n);

    // closing ends to show we’re done — this frees the pipe in kernel RAM
    close(fd[0]);  // we’re done reading
    close(fd[1]);  // we’re done writing

    return 0;
}



//pipe just gives temp file desc
// like 3 for read 4 for write
//thats how u share in process


// 🧬 Analogy: The Gaslighting Realization
// You're not "sending data through magic channels".
// You're just:

// Writing bytes into a box

// Reading them back

// The kernel is the babysitter

// So yes, the read() and write() just give the illusion of communication — but underneath?

// You're both passing a post-it note inside a locked room you don't see.

// 🧵 A pipe is just a queue in disguise — once you read it, the byte is history.
// 🕳️ Try to rewind it, and the kernel says: "What rewind? This ain’t a file, son." 💣