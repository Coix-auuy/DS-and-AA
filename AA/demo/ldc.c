#include <stdio.h>
//h[]为储存对元素的数组，n为元素个数
//交换元素
void swap(int h[], int i, int j)
{
    int temp = h[i];
    h[i] = h[j];
    h[j] = temp;
}
//调整建堆
void Sift(int h[], int n, int m) //m为需要调整的子树的双亲结点
{
    int i, j, t;
    i = m, j = 2 * i; //将需调整的双亲结点赋值给i,左儿子给j，t存储双亲节点
    while (j <= n)    //当有左儿子时循环
    {
        if (j < n && h[j] < h[j + 1]) //若有左右儿子且左儿子小于右儿子
            j++;                      //确保与双亲比较的值是儿子中最大的值
        if (h[i] < h[j])
        {
            swap(h, i, j);
            i = j;
            j = 2 * i;
        }
        else
            return;
    }
}
//堆排序
void heapsort(int h[], int n)
{
    int i;
    int p = n / 2;           //将p等于最后一个结点的双亲结点
    for (i = p; i >= 1; i--) //从最后一颗子树开始调整
        Sift(h, n, i);
    for (i = n; i > 1; --i)
    {
        swap(h, 1, i);     //将第i大的结点换到位置i
        Sift(h, i - 1, 1); //再重新调整剩余结点，由于前一遍调整已经将其他节点调整好，所以只需要调整根节点
    }
}
//主函数
int main()
{
    int h[101], n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &h[i]);
    heapsort(h, n);
    for (int i = 1; i <= n; i++)
        printf("%d ", h[i]);
    return 0;
}