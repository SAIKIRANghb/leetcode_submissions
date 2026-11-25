// Last updated: 11/25/2026, 3:38:12 PM
// class SegmentTree {
//     int[] segmentTree;
//     int[] lazyTree;
//     int n;


//     public SegmentTree(int[] arr) {
//         this.n = arr.length;
//         segmentTree = new int[4 * n];
//         lazyTree = new int[4 * n];
//         buildSegmentTree(0, 0, n - 1, arr);
//     }

//     private void buildSegmentTree(int i, int l, int r, int[] arr) {
//         if (l == r) {
//             segmentTree[i] = arr[l];
//             return;
//         }
//         int mid = (l + r) / 2;
//         buildSegmentTree(2 * i + 1, l, mid, arr);
//         buildSegmentTree(2 * i + 2, mid + 1, r, arr);
//         segmentTree[i] = Math.max(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
//     }

//     //l and r are necessary to check if only one element remains
//     //pushDown and lazy are required to make sure updates propagate nothing to do with query.
//     private void apply(int i, int l, int r, int val) {
//         segmentTree[i] = Math.max(segmentTree[i] - val, 0);
//         if (l != r) {
//             lazyTree[i] += val; // Accumulate lazy value
//         }
//     }

//     private void pushDown(int i, int l, int r) {
//         if (lazyTree[i] == 0) return;
//         int mid = (l + r) / 2;
//         apply(2 * i + 1, l, mid, lazyTree[i]);
//         apply(2 * i + 2, mid + 1, r, lazyTree[i]);
//         lazyTree[i] = 0;
//     }

//     public void update(int start, int end, int val) {
//         update(0, 0, n - 1, start, end, val);
//     }

//     private void update(int i, int l, int r, int start, int end, int val) {
//         pushDown(i, l, r);

//         if (l > end || r < start) return;

//         //[start , end] is aligned and should delay update and return for now.
//         if (l >= start && r <= end) {
//             apply(i, l, r, val);
//             return;
//         }

//         int mid = (l + r) / 2;
//         update(2 * i + 1, l, mid, start, end, val);
//         update(2 * i + 2, mid + 1, r, start, end, val);
//         segmentTree[i] = Math.max(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
//     }

//     public int query(int start, int end) {
//         return query(0, 0, n - 1, start, end);
//     }

//     private int query(int i, int l, int r, int start, int end) {
//         if (l > end || r < start) return Integer.MIN_VALUE;

//         pushDown(i, l, r);

//         // [start , end] is query and it is guaranteed that we get  
//         // perfectly answer for [start,end] range
//         // cummulatively sub [l,r]'s merge to [start , end]  
//         if (l >= start && r <= end) return segmentTree[i];

//         int mid = (l + r) / 2;
//         int left = query(2 * i + 1, l, mid, start, end);
//         int right = query(2 * i + 2, mid + 1, r, start, end);
//         return Math.max(left, right);
//     }
// }


// class Solution {
//     public int maxRemoval(int[] nums, int[][] queries) {
//         int n = nums.length;
//         SegmentTree SegTree = new SegmentTree(nums);
//         SegTree.buildSegmentTree(0,0, n - 1,nums);

//     }
// }
class Solution {

    public int maxRemoval(int[] nums, int[][] queries) {
        Arrays.sort(queries, (a, b) -> a[0] - b[0]);
        PriorityQueue<Integer> heap = new PriorityQueue<>(
            Collections.reverseOrder()
        );
        int[] deltaArray = new int[nums.length + 1];
        int operations = 0;

        for (int i = 0, j = 0; i < nums.length; i++) {
            operations += deltaArray[i];
            while (j < queries.length && queries[j][0] == i) {
                heap.offer(queries[j][1]);
                j++;
            }
            while (
                operations < nums[i] && !heap.isEmpty() && heap.peek() >= i
            ) {
                operations += 1;
                deltaArray[heap.poll() + 1] -= 1;
            }
            if (operations < nums[i]) {
                return -1;
            }
        }
        return heap.size();
    }
}