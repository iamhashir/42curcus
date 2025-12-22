#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

 

int main(void) {
	

	close(0);
	//close terminal input --- why eveni have this still program is working smooth???? isnt it  supposed to bre? because the input is also getting closed
	close(1); //close terminal output
	close(2); //close error output
	
	int fd = open("test1.txt", O_WRONLY | O_CREAT);    //3
	int fd1 = open("test2.txt", O_WRONLY | O_CREAT);   //4
	int fd2 = open("test3.txt", O_WRONLY | O_CREAT);   //5
	
    printf("fd = %d\n", fd);  // most likely 1
    printf("fd1 = %d\n", fd1);  
    printf("fd2 = %d\n", fd2);  
	fflush(stdout);

	// since stdout which is terminal is closed now fd is assigned the new terminal stdout as a file so output will be written there 
	// thats why first printf is outputed to the file

	char *str = "i came into your fd = 1 thinking u are terminal bcz u closed stdout\n";

	write(1,str,68);
    //but why this write is outputed first? printf is writeen before this write but i see this write as top line
	write(2, "hello fd\n", 9); 
    write(3, "hello fd1\n", 10);   
	

	int fd1 = open("test2.txt", O_RDONLY);  // 🧠 Reopens test2.txt for reading — overwrites earlier fd1!
	int fd2 = dup(fd1);                     // 🔁 Creates new fd (likely 6) that shares the same file offset with fd1
	char buf[5];                            // 🧺 Small buffer to hold read data (not null-terminated after read!)

	read(fd1, buf, 5);                      // 📖 Reads first 5 bytes from test2.txt → advances shared file offset
	printf("%s\n", buf);                   // 🖨️ May print garbage after 5 bytes due to missing null terminator!

	read(fd2, buf, 5);                      // ✅ Continues reading next 5 bytes — because offset is shared
	printf("%s\n", buf);                   // 🖨️ Same risk: unnull-terminated buffer may leak past boundary

	close(fd1);                             // ✅ Safe cleanup
	close(fd2);                             // ✅ Shared file table entry is fully released after this
    return 0;
}







// 🥵 BRUH… you just created a **UNIX horror film** — you closed your terminal’s mouth (stdout), unplugged its ears (stderr), *AND* chopped off its hands (stdin), and yet…
// **IT'S STILL RUNNING?!** 😱

// Let me explain **why your program didn’t crash**, and then why that `write(1, ...)` appears **before** your `printf()` output.

// ---

// ## 🧠 FIRST: Why did your program still "work" even though you closed `stdin`?

// ### 💥 You closed `fd 0` (stdin), BUT:

// * Your program didn’t actually **ask the user for input** (no `scanf()`, `read(0, ...)`, etc.)
// * So **nothing broke** — because you're not trying to use stdin at all.

// 📦 **Closing unused things doesn't crash your program.**
// It just means:

// > “If I try to read from fd 0 later, it will fail.”

// ✅ That’s why it *runs smooth* — you just didn't touch the keyboard!

// ---

// ## 🔥 SECOND: Why did this `write(1, str, 68)` appear **first** in the file?

// ```c
// printf("fd = %d\n", fd);
// write(1, str, 68);
// ```

// You’re expecting:

// ```
// fd = 3
// i came into your fd = 1...
// ```

// But instead you're seeing:

// ```
// i came into your fd = 1...
// fd = 3
// ```

// Why?

// ---

// ## 🧂 The REAL Reason: **`printf()` is buffered, `write()` is not**

// | Function   | Buffering      | When it outputs                                 |
// | ---------- | -------------- | ----------------------------------------------- |
// | `write()`  | ❌ No buffering | Outputs immediately 🔥                          |
// | `printf()` | ✅ Buffered     | Waits until newline, buffer full, or `fflush()` |

// So in your case:

// 1. `write(1, ...)` → goes **directly** to file
// 2. `printf(...)` → goes into buffer first, then flushes to file

//    * That small delay is why `write()` output shows up **first**

// ---

// ## 🎯 TL;DR Rules to Lock in:

// | Action                               | Result                                                                |
// | ------------------------------------ | --------------------------------------------------------------------- |
// | `close(0)`                           | You can't read from keyboard anymore (but no crash unless you try to) |
// | `close(1)`                           | All `printf()` now goes to the next file opened (fd = 1)              |
// | `write()` vs `printf()`              | `write()` hits immediately, `printf()` may delay (buffered)           |
// | `write(1, ...)` before `printf(...)` | Appears first even if written second, due to buffering                |

// ---

// ## 💡 Bonus Tip: Flush `printf()` if you want strict order

// Add this after your `printf()`:

// ```c
// fflush(stdout);
// ```

// Then you'll see output order become consistent — because you're **forcing the buffer to flush**.

// ---

// ## 🔥 Final Insight:

// > Your program didn’t break because you **closed pipes** that you weren’t using.
// > Your `write()` appears first because it’s **unbuffered**, while `printf()` is **lazy** and waits.

// You’re officially tampering with **terminal IO streams like a UNIX black hat** 😈
// Wanna go full pro with `dup()`, `dup2()`, or even restore terminal output mid-program?

// I'll walk you through it 💯
