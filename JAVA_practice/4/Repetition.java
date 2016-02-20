/*
Repetition array, and string test.

Created by Tian on 06/25/2015.
Copyright (c). All rights reserved.

*/
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.Date;
import java.util.Locale;

public class Repetition{
    public static void main(String[] args){
        System.out.print("\n********************************************************\n\n");
        
        
        int arr[] = {4, 7, 0, 1, 1, 1, 1, 1, 20};
        for(int x : arr){
            System.out.print(x+"\t");
        }
        
        
        String[] test = new String[]{"t", "a", "i", "a", "a", "n"};
        int index = 0;
        while(index < test.length){
            System.out.print("\n" + test[index++] + " ");
        }
        
        System.out.print("\n--------------------------------test break\n");
        for(String string : test){
            if(string.equals("n"))  break;    // break ending
            System.out.print(string+"\t");
        }
        
        System.out.print("\n--------------------------------test continue\n");
        int a_num = 0;
        for(String string : test){
            if(string.equals("a"))  {         // continue
                System.out.println("\nFound " + string);   // take into cage
                a_num++;
                continue;
            }
            System.out.print(string+"\t");             // print normally unless no cage
        }
        
        System.out.print("\n--------------------------------Arrays.fill\n");
        
        Arrays.fill(arr, 1, 5, 100);     // fill 1 - 4 elements
        for(int x : arr){
            System.out.print(x+"\t");
        }
        
        int arr2[] = new int[10];
        Arrays.fill(arr2, 100);          // Initilazation all elements
        for(int x : arr2){
            System.out.print(x+"\t");
        }
        
        System.out.print("\n--------------------------------Variable Exchange by using ^ \n");

        Scanner scan = new Scanner(System.in);
        System.out.println("Input value A");
        long A = scan.nextLong();
        System.out.println("Input value B");
        long B = scan.nextLong();
        System.out.println("A = " + A + "\tB =" + B);
        System.out.println("Variable Exchange");
        A = A ^ B;     // 10 01 -> 11 01
        B = A ^ B;     // 11 01 -> 11 10
        A = A ^ B;     // 11 10 -> 01 10
        System.out.println("A = " + A + "\tB =" + B);
        
        
        // str.length
        // str.trim        delete blank of start and end of string
        // import StringTokenizer(String str, String delim)
        /* str.replace(String regex, String replacement)
           str.replaceFirst(String regex, String replacement)
           str.replaceAll(String regex, String replacement)
         */
        /* str.equals(String aim)
           str.equalsIgnoreCase(String aim)
           return boolean
         */
        // str.startsWith(String perfix)    str.endswith(String suffix)
        // str.toLowerCase()                str.toUpperCase()
        
        System.out.print("\n6--------------------------------string operation ^ \n");
        String str1 = "    Java    ";
        String strFinal = str1.trim();
        
        System.out.println("str1.lastIndexOf(a) is :" + str1.lastIndexOf("a"));
        System.out.println("str1.length is :" + str1.length());
        System.out.print("\nbefore trim: " + str1 + "\nafter trim: " + strFinal);
        System.out.print("\nstring replacement :" + str1.replaceAll("a", "b"));
        System.out.print("\nString starts with space?: " + str1.startsWith(" "));
        System.out.print("\nstring to lower case :" + str1.toLowerCase());
        
        // str.split(String aim)
        String s = "abc, bsdf, csdf,d,d,d,d.d.d.qwe";
        String[] sp = s.split(",");
        System.out.print("\nAfter split: \n");
        for(int i=0; i<sp.length; i++){     // print new splited string
            System.out.println(sp[i]);
        }
        
        System.out.print("\nAfter specific numbers split: \n");
        String[] sp2 = s.split("d|a",3);   // define severals deliminates
        for(int i=0; i<sp2.length; i++){     // print new splited string for specific number - 1
            System.out.println(sp2[i]);
        }
        
        // check numbers is numbers
        char num = '1';     // char is ' '
        System.out.print("\ncheck number is numbers: " + Character.isDigit(num));
        
        
        System.out.print("\n6--------------------------------date location format ^ \n");
        
        Date d1 = new Date();
        System.out.println("Default date format: " + d1);
        
        
        //boolean str.matches(String regax)
        System.out.print("\n6--------------------------------date location format ^ \n");
        String regaxTest = "aM433343,";
        System.out.println("regaxTest is legal: " + regaxTest.matches("\\p{Lower}\\p{Upper}\\d{6}\\p{Punct}"));
        
        String regax = "[a,s,d,f][^ABCDEFG]\\d{6}\\p{Punct}";
        System.out.println("regaxTest is legal: " + regaxTest.matches(regax));
        
        
        
        //
        System.out.print("\n6--------------------------------Encrypt and unCrypt ^ \n");
        String value = "Encrypt and Uncrypt test";
        char secret = 'C';
        System.out.print("\n original string is: " + value);
     
        String Encrypt = Repetition.EncryptUncrypt(value, secret);
        System.out.print("\n After Encrypt: " + Encrypt);
        
        String Uncrypt = Repetition.EncryptUncrypt(Encrypt, secret);
        System.out.print("\n After Uncrypt: " + Uncrypt);
        
    
        
        System.out.print("\n\n********************************************************\n\n");
    }
    
    public static String EncryptUncrypt(String value, char secret){
        byte[] bt = value.getBytes();                  // change value to byte array
        for (int i = 0;i < bt.length; i++){
            bt[i] = (byte) (bt[i] ^ secret);      // Any encrypt algorithms
        }
        return new String(bt, 0, bt.length);
    }

}










