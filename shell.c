#include <unistd.h>

int main(){
    char command[255];
    write(1, "# ", 2);
    int count = read(0, command, 255);
    command[count - 1] = '\0'; // Replace newline with null terminator
    execve(command, 0, 0);
}