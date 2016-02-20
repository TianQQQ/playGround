/*
  main.c
  Created by Tian Qiu on 15/4/19.
  Copyright (c) 2015  Tian Qiu. All rights reserved.
*/

public class ExceptionTest5
{
    
    public void method()
    {
        try
        {
            System.out.println("进入到try块");
            
            //return;
            //会先执行finally块再返回
            
            //虚拟机退出
            //System.exit(0);
            //不会执行finally块中的语句，直接退出
        }
        catch (Exception e)
        {
            System.out.println("异常发生了！");
            
        }
        finally
        {
            System.out.println("进入到finally块");
            
        }
        
        System.out.println("后续代码");
        
    }
    
    public static void main(String[] args)
    {
        ExceptionTest5 test = new ExceptionTest5();
        test.method();
    }
}