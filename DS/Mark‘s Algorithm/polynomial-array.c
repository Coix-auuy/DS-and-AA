#include "fatal.h"
#define MaxDegree 100
#define Max(x, y) ((x) > (y) ? (x) : (y))
typedef struct
{
    int CoeffArray[MaxDegree + 1];
    int HighPower;
} * Polynomial;

// 初始化
void ZeroPolynomial(Polynomial Poly)
{
    int i;

    for (i = 0; i <= MaxDegree; i++)
        Poly->CoeffArray[i] = 0;
    Poly->HighPower = 0;
}

//add
void AddPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolySum)
{
    ZeroPolynomial(PolySum);
    PolySum->HighPower = Max(Poly1->HighPower, Poly2->HighPower);

    for (int i = PolySum->HighPower; i >= 0; i--)
        PolySum->CoeffArray[i] = Poly1->CoeffArray[i] + Poly2->CoeffArray[i];
}

//multiply
void MultPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolyProd)
{
    ZeroPolynomial(PolyProd);
    PolyProd->HighPower = Poly1->HighPower + Poly2->HighPower;

    if (PolyProd->HighPower > MaxDegree)
        Error("Exceeded array size");
    else
    {
        for (int i = 0; i <= Poly1->HighPower; i++)
            for (int j = 0; j <= Poly2->HighPower; j++)
                PolyProd->CoeffArray[i + j] += Poly1->CoeffArray[i] * Poly2->CoeffArray[j];
    }
}

void PrintPoly(const Polynomial Q)
{
    int i;

    for (i = Q->HighPower; i > 0; i--)
        printf("%dx^%d + ", Q->CoeffArray[i], i);
    printf("%d\n", Q->CoeffArray[0]);
}

int main()
{
    Polynomial P, Q;

    P = malloc(sizeof(*P));
    Q = malloc(sizeof(*Q));

    P->HighPower = 1;
    P->CoeffArray[0] = 1;
    P->CoeffArray[1] = 1;
    MultPolynomial(P, P, Q);
    PrintPoly(Q);
    // MultPolynomial( Q, Q, P );

    AddPolynomial(P, P, Q);
    PrintPoly(Q);
}