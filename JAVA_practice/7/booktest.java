public class booktest{
    public static void main(String[] args){
        Book book = new Book("Discrete Math", "Qu", 20);
    System.out.println("Title : " + book.getTitle());
    System.out.println("Author : " + book.getAuthor());
    System.out.println("Price : "+ book.getPrice());
    }
}