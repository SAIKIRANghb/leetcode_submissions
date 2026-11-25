// Last updated: 11/25/2026, 3:38:10 PM
class Solution {
    int[] bfs(int n, List<List<Integer>> graph, int[] color) {
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{0, -1});
        int[] colorCount = {0, 0};
        int isEven = 0;

        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int[] curr = queue.poll();
                int node = curr[0], par = curr[1];
                color[node] = isEven;
                colorCount[isEven]++;

                for (int neighbour : graph.get(node)) {
                    if (neighbour == par) continue;
                    queue.offer(new int[]{neighbour, node});
                }
            }
            isEven = 1 - isEven; // Toggle after each level
        }
        return colorCount;
    }

    public int[] build(int[][] edges, int[] color) {
        int n = edges.length + 1;
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            graph.get(edge[0]).add(edge[1]);
            graph.get(edge[1]).add(edge[0]);
        }
        return bfs(n, graph, color);
    }

    public int[] maxTargetNodes(int[][] edges1, int[][] edges2) {
        int n = edges1.length + 1, m = edges2.length + 1;
        int[] color1 = new int[n];
        int[] color2 = new int[m];
        int[] count1 = build(edges1, color1);
        int[] count2 = build(edges2, color2);
        int[] res = new int[n];

        for (int i = 0; i < n; i++) {
            res[i] = count1[color1[i]] + Math.max(count2[0], count2[1]);
        }
        return res;
    }
}
