public class conver{
    public static void main(String[] args){
        short s = 130;
        int myint = 100;
        float myfloat = 425.12f;
        char mychar = 10;
        double mydouble = 45.46546;
        
        byte new_s = (byte)s;
        
        System.out.println("new_s = " + (new_s));  //max byte 127, take 8 bits of short
        // boolean cannot be change to another type
      
    }
}