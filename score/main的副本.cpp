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

string Trim(string& str)
{
    //str.find_first_not_of(" \t\r\n"),在字符串str中从索引0开始，返回首次不匹配"\t\r\n"的位置
    str.erase(0,str.find_first_not_of(" \t\r\n"));
    str.erase(str.find_last_not_of(" \t\r\n") + 1);
    return str;
}

int main()
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
        
        
        
        istringstream sin(line); //将整行字符串line读入到字符串流istringstream中
        vector<string> fields; //声明一个字符串向量
        string field;
        while (getline(sin, field, ',')) //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符
        {
            fields.push_back(field); //将刚刚读取的字符串添加到向量fields中
        
        }
    }
    cout<<"幸苦了"<<endl;
    return 0;
}
