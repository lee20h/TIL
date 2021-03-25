import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, k;
        n = sc.nextInt();
        k = sc.nextInt();
	    Queue<Integer> q = new LinkedList<>();
        int[] ans = new int[n];
        for(int i=1; i<=n; i++) {
            q.offer(i);
        }
        int cnt = 0;
        int idx = 0;
        while(!q.isEmpty()) {
            cnt++;
            int temp = q.peek();
            q.remove();
            if(cnt == k) {
                cnt = 0;
                ans[idx++] = temp;
            } else {
                q.add(temp);
            }
        }
        System.out.print("<");
        for(int i=0; i<n-1; i++) {
            System.out.print(ans[i] + ", ");
        }
        System.out.print(ans[ans.length-1] + ">");
    }
}
