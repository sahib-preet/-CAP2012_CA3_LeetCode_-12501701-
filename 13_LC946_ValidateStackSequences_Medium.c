#include <stdbool.h>

bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize)
{
    int stack[1000];
    int top = -1;
    int j = 0;
    int i;

    for(i = 0; i < pushedSize; i++)
    {
        top++;
        stack[top] = pushed[i];

        while(top >= 0 && stack[top] == popped[j])
        {
            top--;
            j++;
        }
    }

    if(j == poppedSize)
        return true;
    else
        return false;
}
