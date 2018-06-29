//
//  main.cpp
//  score
//
//  Created by 20161104570 on 2018/6/27.
//  Copyright © 2018年 20161104570. All rights reserved.
//
#include<iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void Score()
{
    int j,i=0,max=0,min=100,m;
    int sf[10];
    int f[10];
    ifstream fin("//Users//a20161104570//Desktop//表演名单.csv"); //打开文件流操作
    string line;
    while (getline(fin, line))   //整行读取，换行符“\n”区分，遇到文件尾标志eof终止读取
    {
        cout <<"姓名,性别,班级,节目名称,节目类型,电话："<< endl << line << endl; //整行输出
        
        for(j=1;j<=5;j++)//评分
        {
            cout<<"评委 "<<j<<" 给分:";
            cin>>f[j];
            sf[i]=sf[i]+f[j];
            if(max<f[j])
            {
                max=f[j];
            }
            if(min>f[j])
            {
                min=f[j];
            }
        }
        cout<<"去一个max:"<<max<<endl;
        cout<<"去一个min:"<<min<<endl;
        sf[i]=(sf[i]-max-min)/3;
        cout<<"选手最终得分:"<<sf[i]<<endl;
        
        cout<<"是否继续「是（1）否（0）」"<<endl;//中途结束评分
        cin>>m;
        if(m==0)
        {
            break;
        }
        
    }
    cout<<"幸苦了"<<endl;
}

void Show()
{
    int i=0;
    ifstream fin("//Users//a20161104570//Desktop//表演名单.csv"); //打开文件流操作
    string line;
    while (getline(fin, line))   //整行读取，换行符“\n”区分，遇到文件尾标志eof终止读取
    {
        i++;
        cout<<"第 "<< i <<" 位选手:"<<endl;
        cout <<"姓名,性别,班级,节目名称,节目类型,电话："<< endl << line << endl;
    }
}

void Teacher()
{
    int i=0;
    ifstream fin("//Users//a20161104570//Desktop//评委名单.csv"); //打开文件流操作
    string line;
    while (getline(fin, line))   //整行读取，换行符“\n”区分，遇到文件尾标志eof终止读取
    {
        i++;
        cout <<"         姓名,性别,电话："<< endl << line << endl;
    }

}
int main()
{
    
    int i;
    while(1)
    {
        cout<<"| ---------------------------------- \n";
        cout<<"|	  1 --- 评委打分\n";
        cout<<"|	  2 --- 表演名单\n";
        cout<<"|	  3 --- 评委名单\n";
        
        cout<<"\n 请选择功能：";
        scanf("%d",&i);
        switch(i)
        {
            case 1:
                Score();
                break;
            case 2:
                Show();
                break;
            case 3:
                Teacher();
                break;
        }
    }
}


