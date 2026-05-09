import java.util.*;

public class cp {
    static char[][] grid = new char[5][5];
    static boolean[][] ubah = new boolean[5][5];
    static int ano = 0, n, m;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt(); m = sc.nextInt();
        if(n<2 || n>5 || m<2 || m>5) System.out.println("-1");
        else{
            //input
            int anomali = 0, manusia = 0, dot = 0;
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    String s = sc.next();
                    grid[i][j] = s.charAt(0);
                    if(grid[i][j] == 'A') anomali++;
                    else if(grid[i][j] == 'M') manusia++;
                    else dot++;
                }
            }
            if(manusia == 0 || dot == 0 || anomali==0){
                System.out.println("-1");
                return;
            }
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    // cari connected component
                    if(ubah[i][j] == false && grid[i][j] == 'A') f(i, j);
                }
            }

            System.out.println("Manusia to Anomali : "+(ano-anomali));
            System.out.println("Total Anomali : "+ano);
            System.out.println("Manusia Selamat : "+(manusia-(ano-anomali)));

            
        }
    }
    public static void f(int i, int j){
        if(ubah[i][j] == true) return;;
        // System.out.println(i+" "+j);
        ubah[i][j] = true;
        grid[i][j] = 'A';
        ano++;
        if(i+1<n && grid[i+1][j] != '.') f(i+1, j);
        if(i-1>=0 && grid[i-1][j] != '.') f(i-1, j);
        if(j+1<m && grid[i][j+1] != '.') f(i, j+1);
        if(j-1>=0 && grid[i][j-1] != '.') f(i, j-1);
    }
}

