def possible(N, M, a):
    tallest_row = []
    for i in range(N):
        tallest_row.append(max(a[i])) 
    tallest_col = []
    for j in range(M):
        tallest_col.append(0)
        for i in range(N):
            tallest_col[-1] = max(tallest_col[-1], a[i][j])
    for i in range(N):
        for j in range(M):
            if a[i][j] != min(tallest_row[i], tallest_col[j]):
                return "NO"
    return "YES"
        
def main():
    T = int(raw_input())
    for t in range(1, T + 1):
        N, M = (int(x) for x in raw_input().split())
        a = []
        for i in range(N):
            a.append([int(x) for x in raw_input().split()])
        print "Case #{}: {}".format(t, possible(N, M, a))
        
if __name__ == "__main__":
    main()