#pragma once
//declarations      extern variable;function prototype;class declaration
//出现定义，多个cpp引用头文件时duplicate sample
#ifndef FLAG
#define FLAG


class TicketMachine
{
public:
    void initialization();      //成员函数属于类
    void showPrompt();
    void getMoney();
    //void printTicket();
    void showBalance();
    //void printError();
    void insertMoney(int money);
    int refundBalance();
private:
    const int price=100;        //成员变量属于对象
    int balance;
    //int total;
    int money;
};

#endif