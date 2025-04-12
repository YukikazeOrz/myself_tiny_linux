#include <unistd.h>
#include <sys/wait.h>

int main(){
    char command[255];
    for(;;){write(1, "# ", 2);
        int count = read(0, command, 255);
        command[count - 1] = '\0'; // Replace newline with null terminator
        pid_t fork_result = fork();
        if (fork_result == 0) {
            execve(command, 0, 0);
            break;
        }else{
            siginfo_t info;
            waitid(P_ALL, 0, &info, WEXITED);
        }
        
    }
}