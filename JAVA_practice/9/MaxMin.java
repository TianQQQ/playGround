/* 
    Created by Qiu on 7/5/15

*/

public class MaxMin{
    public static class Result{      // local result class
        private double max;
        private double min;
        public Result(double max, double min){   // local assignment
            this.max = max;
            this.min = min;
        }
        public double getMax(){
            return max;
        }
        public double getMin(){
            return min;
        }
    }
    
    public static Result getResult(double[] array){
        double max = Double.MIN_VALUE;     // double 's max value
        double min = Double.MAX_VALUE;
        
        for(double i:array){
            if(i > max){
                max = i;
            }
            if(i < min){
                min = i;
            }
            
        }
        
        return new Result(max,min);
        
    }
}