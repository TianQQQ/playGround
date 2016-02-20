/*
  main.c
  Created by Tian Qiu on 15.
  Copyright (c) 2015  Tian Qiu. All rights reserved.
*/


public class internTest {
    
    public static String hello(String[] strs, String s2) {
        s2.toUpperCase();
        return s2;
    }
    
    /**
     * @param args
     */
    public static void main(String... args) {
        String a = new String("t");
        String[] b = new String[] { "t", "a" };
        
        String str1 = "a";
        String str2 = "bc";
        String str3 = "a"+"bc";
        String str4 = str1+str2;
        
        System.out.println(str3==str4);
        System.out.println("str3 = " + str3);
        System.out.println("before intern str4 = " + str4);
        str4 = str4.intern();
        System.out.println("after intern str4 = " + str4);
        System.out.println(str3==str4); 

    }
}