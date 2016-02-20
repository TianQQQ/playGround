/*
  main.c
  Created by Tian Qiu on 15/4/19.
  Copyright (c) 2015  Tian Qiu. All rights reserved.
*/


public class joinThread {
    public static void main(String [] args) throws Exception{
        ThreadTest5 t = new ThreadTest5();
        Thread A = new Thread(t);
        Thread B = new Thread(t);
        A.start();
        //A.join();         //此处A调用 Thread的join方法，主函数将线程分配给A，当A运行完毕后，才会将线程释放出去。给其他的对象。
        B.start();
        for (int i = 1;i < 20;i++)
        {
            System.out.println("树上掉苹果"+ i);
        }
        System.out.println("苹果没了");
    }
}

class ThreadTest5 implements Runnable
{
    public void run()
    {
        for (int i = 1;i < 10;i++)
        {
            System.out.println(Thread.currentThread().getName()+"吃苹果"+(i));
        }
    }
}
