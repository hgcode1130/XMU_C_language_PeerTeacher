// #include <stdio.h>
// #include <string.h>

// char s[1000];
// char temp[1000], len;
// int b[1000], cnt;
// void work()
// {
//     int x = 0;
//     if (temp[0] == '0')
//     {
//         if (temp[1] == 'x')
//         {
//             for (int j = 2; j < len; j++)
//             {
//                 if (temp[j] <= '9' && temp[j] >= '0')
//                 {
//                     x = x * 16 + (temp[j] - '0');
//                 }
//                 else
//                     x = x * 16 + (temp[j] - 'a' + 10);
//             }
//         }
//         else if (temp[1] == 'b')
//         {
//             for (int j = 2; j < len; j++)
//             {
//                 x = x * 2 + (temp[j] - '0');
//             }
//         }
//         else
//         {
//             for (int j = 1; j < len; j++)
//             {
//                 x = x * 8 + (temp[j] - '0');
//             }
//         }
//     }
//     else
//     {
//         for (int j = 0; j < len; j++)
//         {
//             x = x * 10 + (temp[j] - '0');
//         }
//     }
//     b[cnt++] = x;
// }
// int main()
// {
//     scanf("%s", s);
//     for (int i = 0; s[i]; i++)
//     {
//         if (s[i] != ',')
//         {
//             temp[len++] = s[i];
//         }
//         else
//         {
//             work();
//             len = 0;
//         }
//     }
//     work();
//     // 排序
//     for (int i = 0; i < cnt; i++)
//     {
//         for (int j = i + 1; j < cnt; j++)
//         {
//             if (b[i] > b[j])
//             {
//                 int t = b[i];
//                 b[i] = b[j];
//                 b[j] = t;
//             }
//         }
//     }
//     // 输出
//     for (int i = 0; i < cnt - 1; i++)
//     {
//         printf("%d,", b[i]);
//     }
//     printf("%d", b[cnt - 1]);
//     return 0;
// }
#include <stdio.h>
#include <string.h>
#include <math.h>
int tenl(char *a, int n)
{
    int sum = 0, i = 0;
    while (n)
    {
        sum += (a[i++] - '0') * pow(10, n);
        n -= 1;
    }
    return (sum / 10);
}
int twol(char *a, int n)
{
    int sum = 0, i = 2;
    while (n)
    {
        sum += (a[i++] - '0') * pow(2, n);
        n -= 1;
    }
    return (sum / 2);
}
int eightl(char *a, int n)
{
    int sum = 0, i = 1;
    while (n)
    {
        sum += (a[i++] - '0') * pow(8, n);
        n -= 1;
    }
    return (sum / 8);
}
int sixteenl(char *a, int n)
{
    int sum, i = 2;
    while (n)
    {
        if (a[i] >= 'a' && a[i] <= 'z')
            sum += (a[i] - 'a' + 10) * pow(16, n);
        else
            sum += (a[i] - '0') * pow(16, n);
        n -= 1;
    }
    return (sum / 16);
}
int main()
{
    char asd[1000], a[10];
    int A[100], i = 0, j = 0, k = 0;
    scanf("%s", asd);
    while (asd[j] != '\0' && asd[j + 1] != '\0')
    {
        if (asd[j] == ',' || asd[j] == '\0')
        {
            a[j + 1] = '\0';
            switch (a[0])
            {
            case '0':
            {
                switch (a[1])
                {
                case 'x':
                {
                    A[i++] = sixteenl(a, strlen(a) - 2);
                    break;
                }
                case 'b':
                {
                    A[i++] = twol(a, strlen(a) - 2);
                    break;
                }
                default:
                {
                    A[i++] = eightl(a, strlen(a) - 1);
                    break;
                }
                }
                break;
            }
            default:
            {
                A[i++] = tenl(a, strlen(a));
                break;
            }
            }
            j++;
            k = 0;
            continue;
        }
        a[k++] = asd[j++];
    }
    for (i = 0; A[i] != 0; i++)
    {
        for (j = 1; A[j] != 0; j++)
        {
            if (A[i] > A[j])
            {
                k = A[i];
                A[i] = A[j];
                A[j] = k;
            }
        }
    }
    for (i = 0; A[i + 1] != 0; i++)
        printf("%d,", A[i]);
    printf("%d", A[i + 1]);
    return 0;
}