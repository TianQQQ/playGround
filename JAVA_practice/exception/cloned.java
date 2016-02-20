/*
  main.c
  Created by Tian Qiu on 15/4/19.
  Copyright (c) 2015  Tian Qiu. All rights reserved.
*/

public class cloned {
    public static void main(String[] args) {
        System.out.println("classes");
        try{
            //when running as java -ea Cloned -5, it's supposed to throw AssertError;
            assert (Integer.parseInt(args[0]) > 0):"assertTest";
        }catch(Exception e){
            //Exception fails to catch "AssertError"; so no chance to execute the following block;
            System.out.println("catch exec..");
        }
        //finally will be always executed before main() is done.
        //Once any exception is thrown out here, program terminates here...Hence no chance to throw assertError;
        finally{
            throw new IllegalArgumentException();
        }
    }
}