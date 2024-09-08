T=int(input())
for _ in range(T):
    n=int(input())
    k=int(input())
    MOD = 1000000007
    arr=[0]
    for i in range(1, n+1):
        arr.append((int)(input()))
    prefix=[0]
    min_prefix = 0
    max_region = 0
    for i in range(1, n+1):
        prefix.append(prefix[i-1]+arr[i])
        min_prefix = min(min_prefix, prefix[i])
        max_region = max(max_region, prefix[i] - min_prefix)
    another = prefix[n] - max_region
    while another < 0:
        another += MOD
    ans = 0
    for j in range(k):
        max_region = (max_region * 2) % MOD
        ans = max_region
    ans = (ans + another + MOD) % MOD
    print(ans)
    
        