/* 
    Created by Qiu on 7/5/15
*/

public class TestMaxMin{
    public static void main(String[] args){
        double[] array = new double[5];
        for(int i = 0; i< array.length; i++){    //  initialzation
            array[i] = 100 * Math.random();
        }
        
        System.out.println("original array: ");
        for(int i = 0; i< array.length; i++){
            System.out.println(array[i]);
        }
        
        System.out.println("Max :" + MaxMin.getResult(array).getMax());
        System.out.println("Min :" + MaxMin.getResult(array).getMin());
    }
}