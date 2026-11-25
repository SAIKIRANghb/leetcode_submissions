// Last updated: 11/25/2026, 3:47:05 PM
#define k 1000000007
class Solution {
public:
    //absC => abscent count
    //consLC => consecutive leaves count
    long long dp[100001][2][3];
    int Solve1(int n,int absC,int consLC){
        if(n==0){
            return 1;
        }
        if(dp[n][absC][consLC] != -1){
            return dp[n][absC][consLC];
        }
        long long ans = 0;
        ans = (ans + Solve1(n-1,absC,0)) % k;
        if(absC < 1){
            ans = (ans + Solve1(n-1,absC + 1,0)) % k;
        }
        if(consLC < 2){
            ans = (ans + Solve1(n-1,absC,consLC + 1)) % k;
        }
        return dp[n][absC][consLC] = ans % k; 
    }
    
    int Solve2(int n){
        long long Dp[100001][3][4];
        memset(Dp,0,sizeof(Dp));
        for(int absC = 0;absC<=1;absC++){
            for(int consLC=0;consLC<=2;consLC++){
                Dp[0][absC][consLC] = 1;
            }
        }

        for(int day = 1;day<=n;day++){
            for(int absC = 0;absC<=1;absC++){
                for(int consLC=0;consLC<=2;consLC++){
                    Dp[day][absC][consLC] = (Dp[day][absC][consLC] + Dp[day-1][absC][0]) % k;
                    Dp[day][absC][consLC] = (Dp[day][absC][consLC] + Dp[day-1][absC+1][0]) % k;
                    Dp[day][absC][consLC] = (Dp[day][absC][consLC] + Dp[day-1][absC][consLC+1]) % k;
                }
            }
        }

        return Dp[n][0][0];
    }


int Solve3(int n){
    vector<vector<int>> currDp(3, vector<int>(4, 0));
    vector<vector<int>> prevDp(3, vector<int>(4, 0));

    for(int absC = 0; absC <= 1; absC++){
        for(int consLC = 0; consLC <= 2; consLC++){
            prevDp[absC][consLC] = 1;
        }
    }

    for(int day = 1; day <= n; day++){
        for(int absC = 0; absC <= 1; absC++){
            for(int consLC = 0; consLC <= 2; consLC++){
                currDp[absC][consLC] = 0;
                currDp[absC][consLC] = (currDp[absC][consLC] + prevDp[absC][0]) % k;
                currDp[absC][consLC] = (currDp[absC][consLC] + prevDp[absC + 1][0]) % k;
                currDp[absC][consLC] = (currDp[absC][consLC] + prevDp[absC][consLC + 1]) % k;
            }
        }
        prevDp = currDp;
    }

    return currDp[0][0];
}

    int checkRecord(int n) {
        memset(dp,-1,sizeof(dp));
        //method 1
        //return Solve1(n,0,0);
        return Solve2(n);
        //return Solve3(n);
    }
};