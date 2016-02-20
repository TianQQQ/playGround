/* 
 
 test multi-type
 
 Created by Qiu on 7/2/15
 All copyright reserved

*/

public class Calculate{
    final float PI = 3.14159f;
    
    // circle's area
    public float getArea(float r){
        float area = PI*r*r;
        return area;
    }
        
    // rectangle's area
    public float getArea(float l, float w){
        float area = l * w;
        return area;
    }
    
    
    public static void main(String[] args){
        Calculate c = new Calculate();
        float areaCircle = c.getArea(20);
        float areaRectangle = c.getArea(20, 20);
        System.out.println("Area of a Circle is: " + areaCircle);
        System.out.println("Area of a Rectangle is: " + areaRectangle);
    }
}