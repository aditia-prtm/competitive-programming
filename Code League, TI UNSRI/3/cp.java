import java.util.*;

public class cp {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String a = sc.nextLine(), b = sc.nextLine();    
        int p = sc.nextInt(), q = sc.nextInt();

        a = a.toUpperCase(); b = b.toUpperCase();
        // cek emyu
        boolean emyu1 = cek(a), emyu2 = cek(b);
        // System.out.println(emyu1+" "+emyu2);
        if(emyu1 ^ emyu2){
            // manipulasi skor jika emyu kalah
            if(emyu1 && p<q){
                int tmp = p;
                p = q;
                q = tmp;
                
            }else if(emyu2 && p>q){
                int tmp = p;
                p = q;
                q = tmp;
            }

            System.out.print(a+" vs "+b+" "+p+" : "+q);
            if(Math.abs(p-q) > 3) System.out.println(", Tsunami Trofii!!");
        }else System.out.println(a+" vs "+b+" "+p+" : "+q);

    }

    public static boolean cek(String s){
        if(s.equals("MU") || s.equals("MAN UTD") || s.equals("MANCHESTER UNITED")) return true;
        else return false;
    }
}