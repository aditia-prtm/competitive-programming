import java.util.*;

public class cp {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (!sc.hasNextInt()) return;
        int N = sc.nextInt();
        if (N < 1 || N > 100) {
            System.out.println(-1);
            return;
        }

        int[] nums = new int[N];
        for (int i = 0; i < N; i++) {
            if (!sc.hasNextInt()) { System.out.println(-1); return; }
            nums[i] = sc.nextInt();
            if (nums[i] < 10 || nums[i] > 99) { System.out.println(-1); return; }
        }

        int k = (int) Math.floor(Math.sqrt(N));
        if (k < 2) {
            System.out.println(-1);
            return;
        }

        List<Integer> picked = new ArrayList<>();
        for (int num : nums) {
            int tens = num / 10;
            int ones = num % 10;
            if (tens > ones) picked.add(num);
        }

        String[][] grid = new String[k][k];
        for (int i = 0; i < k; i++) Arrays.fill(grid[i], "x");

        int top = 0, bottom = k - 1, left = 0, right = k - 1;
        int idx = 0;
        while (top <= bottom && left <= right && idx < picked.size()) {
            for (int j = left; j <= right && idx < picked.size(); j++)
                grid[top][j] = String.valueOf(picked.get(idx++));
            top++;

            for (int i = top; i <= bottom && idx < picked.size(); i++)
                grid[i][right] = String.valueOf(picked.get(idx++));
            right--;

            for (int j = right; j >= left && idx < picked.size(); j--)
                grid[bottom][j] = String.valueOf(picked.get(idx++));
            bottom--;

            for (int i = bottom; i >= top && idx < picked.size(); i--)
                grid[i][left] = String.valueOf(picked.get(idx++));
            left++;
        }

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                System.out.print(String.format("%-2s", grid[i][j]));
                if (j < k - 1) System.out.print(" ");
            }
            System.out.println();
        }
    }
}
