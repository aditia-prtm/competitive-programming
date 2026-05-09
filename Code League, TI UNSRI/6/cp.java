import java.util.*;

public class cp {
    static int r, c, k, ans = 1000000007;
    static int[][] arr = new int[105][105];
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        r = sc.nextInt(); c = sc.nextInt(); 
        
        if(r < 1 || c < 1 || r > 100 || c > 100){
            System.out.println("Baris atau Kolom diluar constraint");
            return;
        }
        
        k = sc.nextInt();

        if(k < 0 || k > 10) System.out.println("Jumlah tiket diluar constraint");
        else{
            boolean outConstraint= false;
            for(int i=1; i<=r; i++){
                for(int j=1; j<=c; j++){
                    arr[i][j] = sc.nextInt();
                    if(arr[i][j] < 0 || arr[i][j] > 1000000){
                        outConstraint = true;
                        break;
                    }
                }

                if(outConstraint) break;
            }
            if(outConstraint) System.out.println("Biaya pada peta diluar constraint");
            else{
                solve(k, 1, 1, 0);
                System.out.println(ans);
            }
        }
    }

    public static void solve(int tiket, int x, int y, int cost){
        // System.out.println(tiket+" - "+x+", "+y+": "+cost);
        if(x < 1 || y < 1 || x > r || y > c) return;
        else if(x == r && y == c){
            // System.out.println(ans+" "+cost);
            ans = Math.min(ans, cost);
        }else{
            if(tiket > 0){
                // pake tiket = free
                solve(tiket-1, x+1, y, cost);
                solve(tiket-1, x, y+1, cost);
            }
            solve(tiket, x+1, y, cost+arr[x][y]);
            solve(tiket, x, y+1, cost+arr[x][y]);
        }
    }
}
