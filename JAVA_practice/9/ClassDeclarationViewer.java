/* 
    Created by Qiu on 7/6/15
*/

public class ClassDeclarationViewer{
    public static void main(String[] args) throws ClassNotFoundException{
        Class<?> clazz = Class.forName("java.util.ArrayList");   // get ArrayList class
        System.out.println("class 's standard name: " + clazz.getCanonicalName());
        system.out.println("class 's modifier: " + Modifier.toString(clazz.getModifiers()));
        
        
        // Output class type parameters
        /*TypeVariable<?> typeVariables = clazz.getTypeParameters();
        System.out.print("class 's type parameters: ");
        
        if(typeVariables.length != 0){
            for(TypeVariable<?> typeVariable: typeVariables){
                System.out.println(TypeVariable + "\t");
            }
        }else{
            System.out.println("NULL");
        }*/
        
        // Output class 's Generic Interfaces
        /*Type[] interfaces = clazz.getGenericInterfaces();
        System.out.println("class 's Generic Interfaces: ");
        
        if(interfaces.length != 0){
            for(Type type :interfaces){
                System.out.println("\t" + type);
            }
        }else{
            System.out.println("\t" + "NULL");
        }*/
        
        // Output class 's Generic
        
    }
}