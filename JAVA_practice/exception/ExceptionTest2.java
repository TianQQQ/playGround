/*
  main.c
  Created by Tian Qiu on 15/4/19.
  Copyright (c) 2015  Tian Qiu. All rights reserved.
*/

//

public class ExceptionTest2
{
    public void method() throws Exception // 将异常抛出，由调用这个方法的方法去处理这个异常,如果main方法也将异常抛出，则交给Java虚拟机来处理
    {
        System.out.println("Hello World");
        // 抛出异常
        throw new Exception();
    }
    
    public static void main(String[] args)
    {
        ExceptionTest2 test = new ExceptionTest2();
        
        try
        {
            test.method();
        }
        catch (Exception e)
        {
            System.out.println("a");
            e.printStackTrace();
            System.out.println("b");
        }
        finally
        {
            System.out.println("Welcome");
        }
        
        
    }
    
}