import java.util.*;

public class cp {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int duit = sc.nextInt(), k = sc.nextInt(), batas = 10000000;
        if(duit>=1 && duit<=batas && k>=1 && k<=batas){
            int sisa = duit-k;
            if(sisa <= 500000) sisa = Math.min(sisa, 100000);
            else sisa = sisa*3/10;
            System.out.println(sisa);
        }else System.out.println("Input diluar constraint");
    }
}