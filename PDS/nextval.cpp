#include "const.cpp"
int main()
{
    int next[6] = {-1, 0, 1, 2, 3, 4};
    int nextval[6] = {0};
    for (int i = 2; i < 6; i++)
    {
        if (nextval[next[i]] == next[i])
            nextval[i] = nextval[next[i]];
        else
        {
            nextval[i] = next[i];
        }

    }
    for(int i = 1; i < 6; i++)
        cout<<nextval[i]<<" ";
    return 0;
}