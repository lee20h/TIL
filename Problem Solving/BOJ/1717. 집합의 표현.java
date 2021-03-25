import java.util.*;

public class Main {
    static int[] parent;
    static int[] root;
    public static void main(String[] args) {
        int n, m;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        root = new int[n+1];
        parent = new int[n+1];

        for(int i=1; i<=n; i++) {
            parent[i] = i;
        }
        int cmd, node1, node2;
        for(int i=0; i<m; i++) {
            cmd = sc.nextInt();
            node1 = sc.nextInt();
            node2 = sc.nextInt();
            if(cmd == 0) {
                union(node1, node2);
            } else {
                if (isSameParent(node1, node2)) {
                    System.out.println("YES");
                } else {
                    System.out.println("NO");
                }
            }
        }

    }

    public static int find(int x) {
        if (x == parent[x]) {
            return x;
        }

        return parent[x] = find(parent[x]);
    }
    public static void union(int x, int y) {
        x = find(x);
        y = find(y);

        if (x != y) {
            if (x < y) {
                parent[y] = x;
            } else {
                parent[x] = y;
            }
        }
    }
    public static boolean isSameParent(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y) {
            return true;
        }
        return false;
    }
}
