#include <unistd.h>

int main() {
	int argc = 2;
    char *argv[] = {"./a", " hr is ng n"};
    int start;
    int end;
    int i = 0;
    int j = 0;

    if (argc == 2) {
        while (argv[1][j] == ' ')
            j++;
        i = j;
        while (argv[1][i] != '\0')
            i++;
        while (i >= 0) {
            while (argv[1][i] == '\0' || argv[1][i] == ' ' || argv[1][i] == '\t')
                i--;
            end = i;
            while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
                i--;
            start = i + 1;
            // Skip trailing whitespace
            while (start <= end && (argv[1][start] == ' ' || argv[1][start] == '\t'))
                start++;
            int flag;
            flag = start;
            while (start <= end) {
                write(1, &argv[1][start], 1);
                start++;
            }
            if (flag != 0)
                write(1, " ", 1);
            i--;
        }
    }
    write(1, "\n", 1);
    return 0;
}