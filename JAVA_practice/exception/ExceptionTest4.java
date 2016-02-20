/*
  main.c
  Created by Tian Qiu on 15/4/19.
  Copyright (c) 2015  Tian Qiu. All rights reserved.
*/

public class ExceptionTest4
{
    
    public void method(String str) throws MyException
    {
        if(null == str)
        {
            throw new MyException("传入的字符串参数不能为null！");
        }
        else
        {
            System.out.println(str);
        }
    }
    
    public static void main(String[] args) throws MyException //异常处理方式1，不断向外抛出
    {
        ExceptionTest4 test = new ExceptionTest4();
        test.method(null);
    }
}