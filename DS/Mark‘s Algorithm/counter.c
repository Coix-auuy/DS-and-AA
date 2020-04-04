#include "stackar.c"
#define MAX 100
char *getPostfix(char str[])
{
    Stack s;
    s = CreateStack(MAX);
    int i = 0, j = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '*' || str[i] == '/')
        {
            while (!IsEmpty(s) && (Top(s) == '*' || Top(s) == '/'))
                str[j++] = TopAndPop(s);
            Push(str[i], s);
        }
        else if (str[i] == '-' || str[i] == '+')
        {
            while (!IsEmpty(s) && Top(s) != '(')
                str[j++] = TopAndPop(s);
            Push(str[i], s);
        }
        else if (str[i] == '(')
            Push(str[i], s);
        else if (str[i] == ')')
        {
            while (!IsEmpty(s) && Top(s) != '(')
                str[j++] = TopAndPop(s);
            Pop(s);
        }
        else
            str[j++] = str[i];
        i++;
    }
    while (!IsEmpty(s))
        str[j++] = TopAndPop(s);
    str[j] = '\0';
    return str;
}
int counter(char *postfix)
{
    int s[MAX], top = -1;
    int i = 0;
    while (postfix[i] != '\0')
    {
        switch (postfix[i])
        {
        case '+':
            s[top - 1] = s[top - 1] + s[top];
            top--;
            break;
        case '-':
            s[top - 1] = s[top - 1] - s[top];
            top--;
            break;
        case '*':
            s[top - 1] = s[top - 1] * s[top];
            top--;
            break;
        case '/':
            s[top - 1] = s[top - 1] / s[top];
            top--;
            break;
        default:
            s[++top] = postfix[i] - '0';
            break;
        }
        i++;
    }
    return s[top];
};
int main()
{
    ElementType infix[MAX];
    scanf("%s", infix);
    char *postfix = getPostfix(infix);
    // printf("%s", postfix);
    printf("%d", counter(postfix));
}