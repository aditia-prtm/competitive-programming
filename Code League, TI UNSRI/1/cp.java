import java.util.*;

public class cp {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int a = sc.nextInt(), b = sc.nextInt();

        p(a); p(b);

    }   

    public static void p(int x){
        if(x <= 3000000) System.out.println("Murah");
        else if(x < 78000000) System.out.println("Mahal");
        else System.out.println("Harga Pejabat");
    }
}