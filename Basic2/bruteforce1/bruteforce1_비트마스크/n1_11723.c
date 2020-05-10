#include <stdio.h>
#include <string.h>

char comm[20];

int main(void)
{
    int num_problem;
    scanf("%d", &num_problem);
    int len = 20;
    int bits = 0;
    int operand;
    
    while (num_problem--) {
        scanf("%s", comm);
        if (!strcmp(comm, "add")) {
            scanf("%d", &operand);
            operand--;
            bits = (bits | (1 << operand));
        }
        else if (!strcmp(comm, "remove")) {
            scanf("%d", &operand);
            operand--;
            bits = (bits & ~(1 << operand));
        }
        else if (!strcmp(comm, "check")) {
            int res;
            scanf("%d", &operand);
            operand--;
            res = (bits & (1 << operand));
            if (res) {
                puts("1");
            }else{
                puts("0");
            }
        }
        else if (!strcmp(comm, "toggle")) {
            scanf("%d", &operand);
            operand--;
            bits = (bits ^ (1 << operand));
        }
        else if (!strcmp(comm, "all")) {
            bits = (1 << len) - 1;
        }
        else if (!strcmp(comm, "empty")) {
            bits = 0;
        }
    }

    return 0;
}
