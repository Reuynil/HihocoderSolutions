#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 1000001;
int len, p[2*MAX];
char str[2*MAX], newstr[2*MAX];

void change()
{
     newstr[0] = '@';
     newstr[1] = '#';
     for (int i = 0; i < len; i++)
     {
         newstr[2*i + 2] = str[i];
         newstr[2*i + 3] = '#';
     }
     newstr[2*len + 2] = '\0';
}


void Manacher()
{
     int i, id, maxid = 0, ans = 1;
     len = 2 * len + 2;
     for (i = 0; i < len; i++)
	 {
         if (maxid > i)
		 {
             p[i] = min(p[2*id - i], maxid - i);
         }
         else
		 {
              p[i] = 1;
         }
         while (newstr[i+p[i]] == newstr[i-p[i]])
                p[i]++;
         if (p[i] + i > maxid)
		 {
             maxid = p[i] + i;
             id = i;
         }
         if (ans < p[i])
             ans = p[i];
     }
     cout << ans - 1 << endl;
}


int main()
{
    int m;
    cin>>m;
    while (m--)
    {
		scanf("%s",&str);
		len = strlen(str);
        change();
        Manacher();
    }
    return 0;
}
