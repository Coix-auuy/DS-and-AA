#include<iostream>
using namespace std;
struct node{
    int num;
    bool flag;
};
void JohnsonTrotter(int n)
{
    node* a = new node[n + 1];
    int i;
    for (i = 0; i <= n; i++)
    {
        a[i].num = i;
        a[i].flag = false;
    }
    int k = 1;
    node tp;

    for (i = 1; i <= n; i++)
    {
        cout << a[i].num << " ";
    }
    cout << endl;
    while (k != 0)
    {
        k = 0;
        for (i = 1; i <= n; i++)
        {
            if (a[i].flag && a[i].num>a[i + 1].num && a[k].num<a[i].num && i<n) k = i;
            else if (i>1 && !a[i].flag && a[i].num>a[i - 1].num && a[k].num<a[i].num) k = i;
        }
        if (k != 0)
        {
            if (a[k].flag)
            {
                tp = a[k];
                a[k] = a[k + 1];
                a[k + 1] = tp;
                k = k + 1;
            }
            else
            {
                tp = a[k - 1];
                a[k - 1] = a[k];
                a[k] = tp;
                k = k - 1;
            }

            for (i = 1; i <= n; i++)
            {
                if (a[i].num>a[k].num)
                    a[i].flag = (a[i].flag ? false : true);
                cout << a[i].num << " ";
            }
            cout << endl;
        }
    }
}
