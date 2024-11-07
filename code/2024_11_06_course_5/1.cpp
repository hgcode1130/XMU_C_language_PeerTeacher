#include<stdio.h>
#include<string.h>
#include<algorithm>
//sort();
//冒泡排序
//每次都是相邻对吧 ，
//
// int isPrime(int  x)
// { 
//     if(x == 1) return0;
//     int cnt = 0;//除掉了1和他本身
//     for(int i = 2 ; i <= x / i ; i ++) 
//         if(x % i == 0) 
//         {
//             cnt ++;
//             if(x / i != i) cnt ++; 
//         }
//     if(cnt) return 0;
//     return 1;
// }

//如何判断1-x中有多少个素数
//素数筛
//欧拉筛

//如果是字符数组
// int huiwen(char a[])
// {
//     int len = strlen(a);
//     for(int i = 0 ; i <= len / 2 ; i ++) 
//         if(a[i] != a[len - i - 1]) 
//             return 0;
//     return 1;
// }

//-0 
//x > 0
// int huiwen(int x)
// {
//     int a[100];
//     int cnt = 0;
//     int t = x;
//     while(t)
//     {
//         a[cnt ++] =  t % 10;
//         t /= 10;
//     }
//     // …… 
//     return 0;
// }

int gcd(int a , int b)
{
    return b == 0 ? a : gcd(b , a % b); 
    // 最最简单的理解可以先从辗转相减
    //，然后再过渡到辗转相除法
}

//
// qsort(); 
//

int main()
{
    // int i;//
    // int x ,  y;
    // int t = y;
    // y = x;
    // x = t;
    // for(i = 0 ; i < n - 1 ; i ++) 
    //     for(int j = i + 1 ; j < n - i - 1 ; i ++) 
    //         if(cmp(i , j)) 
    //             swap(i , j);

    // int n , k , u;
    // scanf("%d%d",&n,&k);
    // int a[1100] = {0};
    // for(int i = 1 ; i <= k ; i ++)
    // {
    //     for(int j = 1 ; j * i <= n ; j ++) a[j * i] ^= 1;
    // }
    // int cnt = 0;
    // for(int i = 1 ; i <= n ; i++) if(a[i]) printf("%d ", i);
    return 0;
}


