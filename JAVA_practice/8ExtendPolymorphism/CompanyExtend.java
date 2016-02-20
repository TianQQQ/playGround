/*
 Manager and Employee extension test
 Created by Qiu on 7/1/15
*/


import java.util.Date;

public class CompanyTest{
    public static void main(String[] args){
        Employee e = new Employee();        // create a new and assign
        e.setName("Mao");
        e.setSalary(1000);
        e.setBirthday(new Date());
        
        System.out.println("employee name is: " + e.getName());
        
        
        
        Manager m = new Manager();
        m.setName("Qiu");
        m.setSalary(1000);
        m.setBonus(2000.0);
        
        
        System.out.println("Manager name is: " + m.getName());
        System.out.println("Manager 's total income is: " + (m.getBonus() + m.getSalary()));
        
        System.out.println("Manager: " + m.getInfo());   // change father's class content
        System.out.println("Employee: " + e.getInfo());
    
    
    }
}