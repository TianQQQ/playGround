/* 
   Created by Tian Qiu 9/2 to test collection
*/
import java.util.*;

public class List{
    public static void main(String[] args){
        String a="A", b="B", c="C";
        List <String> list = new LinkedList<String>();  // created list
        list.add(a);
        list.add(b);
        Iterator<String> firstIterator = list.iterator();
        System.out.println("before modified");
        while (firstIterator.hasNext()){
            System.out.println(firstIterator.next()+" ");
        }
        list.set(1,b);
        list.add(2,c);
        Iterator<String> it = list.iterator();
        System.out.println();
        System.out.println("after modified");
        while (it.hasNext()){
            System.out.print(it.next()+ " ");
        }
    }
}
