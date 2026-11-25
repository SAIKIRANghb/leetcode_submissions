// Last updated: 11/25/2026, 3:42:37 PM
class Solution {
    static final int mod = 1000000007;

    public int colorTheGrid(int m, int n) {
        Map<Integer,List<Integer>>valid = new HashMap<>();

        int maskEnd = (int)Math.pow(3,m);

        for(int mask = 0;mask < maskEnd;mask++){
            List<Integer>color = new ArrayList<>();
            int mm = mask;                 
            //enumerate all possible coloring schemes(mask) as a "m" length List
            // (0,3^m] range of numbers can be enumerated as "m" length string , just as how
            // (0,2^m] can be enumerated or say encoded into "m" length string
            for(int i = 0;i < m;i++){
                color.add(mm % 3);
                mm /= 3;
            }
            //checking if the encoding is valid scheme (according to problem)
            boolean check = true;
            for(int i = 0;i < m - 1;i++){
                if(color.get(i).equals(color.get(i + 1))){
                    check = false;
                    break;
                }
            }
            if(check){
                valid.put(mask,color);
            }
        }
        Map<Integer,List<Integer>>adjacent = new HashMap<>();
        //mapping each mask' to it's list of all valid mask  (mask' => List<mask>) 
        for(int mask1 : valid.keySet()){
            for(int mask2 : valid.keySet()){
                boolean check = true;
                for(int i = 0;i < m;i++){
                    if(valid.get(mask1).get(i).equals(valid.get(mask2).get(i))){
                        check = false;
                        break;
                    }
                }
                if(check){
                    //returns default empty list if no mapping is present.(just in case)
                    adjacent.computeIfAbsent(mask1,k -> new ArrayList<>()).add(mask2);
                }
            }
        }
        Map<Integer,Integer>f = new HashMap<>();
        for(int mask : valid.keySet()){
            f.put(mask,1);
        }
        for(int i = 1;i < n;i++){
            Map<Integer,Integer>g = new HashMap<>();
            //f is analogous to prevDp and similarly g is for currDp
            //for each mask' find all valid mask then 
            for(int mask2 : valid.keySet()){
            //currDp[mask] = for each mask SumOver All mask' -> currDp[mask] + prevDp[mask'];
                for(int mask1 : adjacent.getOrDefault(mask2 , new ArrayList<>())){              
                    g.put(mask2,(g.getOrDefault(mask2,0) + f.getOrDefault(mask1,0)) % mod);
                }
            }
            //prevDp = currDp;
            f = g;
        }
        int ans = 0;
        for(int num : f.values()){
            ans = (ans + num) % mod;
        }
        return ans;
    }
}