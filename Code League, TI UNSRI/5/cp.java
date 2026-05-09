import java.util.*;

public class cp {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int arr[] = new int[n+5];
        int sum = 0;
        for(int i=1; i<=n; i++){
            arr[i] = sc.nextInt();
            sum += arr[i];
        }

        long ans = sum;
        for(int l=1; l<=n; l++){
            long sumSeg = 0;
            for(int r=l; r<=n; r++){
                sumSeg += arr[r];
                if(sum + sumSeg > ans){
                    ans = sum + sumSeg;
                }
            }
        }
        System.out.println(ans);
    }
}
