#include "minishell.h"

int main(int argc, char *argv[], char *envp[])
{
    printf("%d\n", argc);
    *argv = 0;
    *envp = 0;
    return (0);
}
