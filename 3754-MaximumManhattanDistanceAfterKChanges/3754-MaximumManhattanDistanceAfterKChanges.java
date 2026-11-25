// Last updated: 11/25/2026, 3:37:50 PM
class Solution {
    static public int maxDistance(String str, int k) {
        char[] arr = str.toCharArray();
        int n = 0, s = 0, w = 0, e = 0, ans = 0;
        for (char c : arr) {
            if (c == 'N') n++;
            else if (c == 'S') s++;
            else if (c == 'E') e++;
            else w++;
            ans = Math.max(ans, maxi(n, s, w, e, k));
        }
        return ans;
    }

    static int maxi(int n, int s, int w, int e, int k) {
        int x = 0, y = 0, z = 0;
        x = n + s;
        y = Math.abs(n - s);
        z = (x - y) / 2;
        if (z > k) return y + 2 * k + Math.abs(w - e);
        else {
            k -= z;
            x = w + e;
            y = Math.abs(w - e);
            z = (x - y) / 2;
            if (z > k) return (n + s) + y + 2 * k;
            return (n + s) + (w + e);
        }
    }
}