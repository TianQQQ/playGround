/*
  main.c
  Created by Tian Qiu on 15/4/19.
  Copyright (c) 2015  Tian Qiu. All rights reserved.
*/

interface Extendbroadable{
    public void inPut();
}
class KeyBroad implements Extendbroadable{
    public void inPut(){
        System.out.println("\n hi,keybroad has be input into then mainbroad!\n");
    }
}
class NetCardBroad implements Extendbroadable{
    public void inPut(){
        System.out.println("\n hi,netCardBroad has be input into then mainbroad!\n");
    }
}
class CheckBroad{
    public void getMainMessage(Extendbroadable ext){
        ext.inPut();
    }
}
public class board{
    public     static void main(String []args){
        KeyBroad kb=new KeyBroad();
        NetCardBroad ncb=new NetCardBroad();
        CheckBroad cb=new CheckBroad();
        cb.getMainMessage(kb);      // get ext keybroad in interface
        cb.getMainMessage(ncb);     // get ext netcardbroad in interface
        
    }
}