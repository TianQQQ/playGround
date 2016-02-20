/* 

    Created by Qiu on 7/5

*/

public class SellOutClass{
    private String name;
    public SellOutClass(){           // build way
        name = "Apple";
    }
    
    public void sell(int price){
        
        
        class Apple{                 // local variable class
            int innerPrice = 0;
            public Apple(int price){
                innerPrice = price;
            }
            public void price(){
                System.out.println("Start selling: " + name);
                System.out.println("price is: " + innerPrice);
            }
        }
        
        
        Apple a = new Apple(price);
        a.price();
    }
    
    public static void main(String[] args){
        SellOutClass sample = new SellOutClass();
        sample.sell(100);
    }
}