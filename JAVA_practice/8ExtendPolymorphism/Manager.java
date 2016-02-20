/*
 Manager extension test
 Created by Qiu on 7/1/15

*/

public class Manager extends Employee{
    private double bonus;
    
    public void setBonus(double bonus){
        this.bonus = bonus;
    }
    public double getBonus(){
        return bonus;
    }
    
    @Override
    public String getInfo(){
        return "I am manager!";
    }
}