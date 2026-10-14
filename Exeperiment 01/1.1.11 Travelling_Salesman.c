/*Given a set of cities and the distance between every pair of cities, 
the problem is to find the shortest possible route that visits every city exactly once and returns to the starting point.*/

#include <stdio.h>
#include <limits.h>
int n, cost[15][15], dp[1 << 15][15];
int tsp(int mask, int pos)
{
    if (mask == (1 << n) - 1)
        return cost[pos][0] == -1 ? INT_MAX / 2 : cost[pos][0];
    if (dp[mask][pos] != -1)
        return dp[mask][pos];
    int ans = INT_MAX / 2;
    for (int city = 0; city < n; city++)
    {
        if (!(mask & (1 << city)) && cost[pos][city] != -1)
        {
            int next = tsp(mask | (1 << city), city);
            if (next < INT_MAX / 2)
            {
                int total = cost[pos][city] + next;
                if (total < ans)
                    ans = total;
            }
        }
    }

    return dp[mask][pos] = ans;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);
    for (int i = 0; i < (1 << n); i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = -1;
    int ans = tsp(1, 0);
    if (ans >= INT_MAX / 2)
        printf("-1");
    else
        printf("%d", ans);

    return 0;
}
