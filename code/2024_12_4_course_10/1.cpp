#include<stdio.h>
struct a{
    //所有的成员都是public的
    //都是公有的
    int b;
};

int main(){
    a c;//对于一个结构体本身是可以直接用.来访问相关成员的
    c.b = 1;
    printf("%d\n",c.b);
    //用指针
    struct a *p = &c;
    p->b = 2;
    printf("%d\n",c.b);
}