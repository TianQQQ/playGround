/*
 Hanoi Tower ABC n levels
 
 Created by Tian on 07/01/2015.
 Copyright (c). All rights reserved.
 
 */


public class HanoiTower{
    public static void moveDish(int level, char A, char B, char C){
        if(level == 1){  //until just have 1 disk
            System.out.println("Move 1 disk from " + A + " to " + C);
        } else {
            moveDish(level - 1, A, C, B);     //
            System.out.println("Move " + level + " disk from " + A + " to " + C);
            moveDish(level - 1, B, A, C);     //
        }
    }
    
    public static void main(String[] args){
        int nDisks = 2;
        moveDish(nDisks,'A', 'B', 'C' );
    }
}