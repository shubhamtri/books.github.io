#include <iostream>
#include <string.h>
using namespace std;

class Freq
{
public:
    int occ;
    char alph;
    Freq()
    {
        occ = 0;
    }
};

void ifOccExist(Freq ar[], int j, int n, int x)
{
    Freq exst;
    int pole = 0;
    int k = j + 1;
    while (k <= n)
    {
        if (ar[k].occ == x)
        {
            pole = 1;
            break;
        }
        k++;
    }
    if (pole == 1)
    {
        for (int l = j + 1; l < k; l++)
        {
            if (ar[l].occ > x)
            {
                exst = ar[l];
                for (int m = l; m < n; m++)
                    ar[m] = ar[m + 1];
                ar[n] = exst;
                l--;
                k--;
            }
            else if (ar[l].occ < x)
            {
                exst = ar[l];
                for (int m = l; m > 0; m--)
                    ar[m] = ar[m - 1];
                ar[0] = exst;
            }
        }
    }
}

void reArrange(Freq frAr[], int arLnf, int occr)
{
    int pole;
    for (int j = 0; j < arLnf; j++) //decide where to put pole =0
    {
        if (frAr[j].occ == occr)
        {
            ifOccExist(frAr, j, arLnf, occr);
        }
    }
    for (int j = 0; j <= arLnf; j++)
    {
        cout << frAr[j].alph << " " << frAr[j].occ << " ";
    }
    cout << endl;
}

int main()
{
    string strng;
    cin >> strng;
    int N;
    cin >> N;
    int occurances[N];
    for (int i = 0; i < N; i++)
    {
        cin >> occurances[i];
    }

    Freq freqAr[26];
    int arrLenf = -1;
    int pole;
    int i;

    for (i = 0; i < strng.length(); i++)
    {
        pole = 0;
        for (int t = 0; t <= arrLenf; t++)
        {
            if (strng[i] == freqAr[t].alph)
                pole = 1;
        }
        if (pole == 1)
            continue;
        else
        {
            arrLenf++;
            freqAr[arrLenf].alph = strng[i];
            freqAr[arrLenf].occ = 1;
            for (int j = i + 1; j < strng.length(); j++)
            {
                if (strng[i] == strng[j])
                    freqAr[arrLenf].occ++;
            }
        }
    }

    for (i = 0; i <= arrLenf; i++)
    {
        cout << freqAr[i].alph << " " << freqAr[i].occ << " ";
    }
    cout << endl;

    for (int i = 0; i < N; i++)
    {
        reArrange(freqAr, arrLenf, occurances[i]);
    }
    return 0;
}
