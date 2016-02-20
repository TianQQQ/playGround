/*
 
 Created by Qiu 7/1/15
 all right reserved
 
 */

import java.util.Date;

public class Employee{
    private String name;
    private Date birthday;
    private double salary;
    
    public String getName(){
        return name;
    }
    public void setName(String name){
        this.name = name;
    }
    
    
    public double getSalary(){
        return salary;
    }
    public void setSalary(double salary){
        this.salary = salary;
    }
    
    
    public Date getBirthday(){
        return birthday;
    }
    public void setBirthday(Date birthday){
        this.birthday = birthday;
    }
    
    public String getInfo(){
        return "I am employee!";
    }
    
    
}