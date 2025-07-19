#include <cstdio>
#include <cmath>
#define MAXFOLD 17

int k,h;
char fold[MAXFOLD];
int hole[4];
char lastHor, lastVer;

int ver(int hole)
{
    if (hole == 0) return 2;
    if (hole == 1) return 3;
    if (hole == 2) return 0;
    return 1;
}

int hor(int hole)
{
    if (hole == 0) return 1;
    if (hole == 1) return 0;
    if (hole == 2) return 3;
    return 2;
}

int getFirst(char cHor, char cVer, int hole)
{
    if (cHor == 'L' && cVer == 'U') return hole;
    if (cHor == 'R' && cVer == 'U') return hor(hole);
    if (cHor == 'L' && cVer == 'D') return ver(hole);
    return hor(ver(hole));
}

int main()
{
    scanf("%d", &k);
    for (int i=0;i<k*2;i++)
    {
        scanf("%c", &fold[i]);
        if (fold[i] == 'D' || fold[i] == 'U')
        {
            lastHor = fold[i];
        } else
        {
            lastVer = fold[i];
        }
    }
    scanf("%d", &h);

    hole[0] = getFirst(lastHor, lastVer, h);
    hole[1] = hor(hole[0]);
    hole[2] = ver(hole[0]);
    hole[3] = hor(ver(hole[0]));
    // hole = [3,2,1,0];

    return 0;
}
