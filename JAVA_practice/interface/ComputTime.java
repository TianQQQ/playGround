/*
  main.c
  Created by Tian Qiu on 15/4/19.
  Copyright (c) 2015  Tian Qiu. All rights reserved.
*/

//import CalTime.vehicle.all.Common;
import java.lang.*;

class Plane implements Common {
    public double runTimer(double a, double b, double c) {
        return (a+ b + c);
    }
}
class Car implements Common {
    public double runTimer(double a, double b, double c) {
        return ( a*b/c );
    }
}

interface Common {
    double runTimer(double a, double b, double c);
}



public class ComputTime {
    public static void main(String args[]) {
        System.out.println("交通工具: "+args[0]);
        System.out.println(" 参数A: "+args[1]);
        System.out.println(" 参数B: "+args[2]);
        System.out.println(" 参数C: "+args[3]);
        double A=Double.parseDouble(args[1]);
        double B=Double.parseDouble(args[2]);
        double C=Double.parseDouble(args[3]);
        double v,t;
        try {
            Common d=(Common) Class.forName("CalTime.vehicle."+args[0]).newInstance();
            v=d.runTimer(A,B,C);
            t=1000/v;
            System.out.println("平均速度: "+v+" km/h");
            System.out.println("运行时间："+t+" 小时");
        } catch(Exception e)    {
            System.out.println("class not found");
        }
    }
}