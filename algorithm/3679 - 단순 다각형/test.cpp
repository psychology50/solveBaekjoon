#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct
{
    int x, y, idx;
} node;
typedef long long ll;

node p0;

ll ccw (node &a, node &b)
{
    ll left = (ll)p0.x*a.y + (ll)a.x*b.y + (ll)b.x*p0.y;
    ll right = (ll)p0.y*a.x + (ll)a.y*b.x + (ll)b.y*p0.x;
    
    return left - right;
}

ll dist (node &a)
{
    ll x = p0.x - a.x;
    ll y = p0.y - a.y;
    return x*x + y*y;
}

bool compare (node &a, node &b)
{
    ll cmp = ccw(a, b);
    if (cmp == 0)
    {
        ll dist1 = dist(a);
        ll dist2 = dist(b);
        return dist1 < dist2;
    }
    else
        return cmp > 0;
}

bool compare2 (node &a, node &b)
{
    ll dist1 = dist(a);
    ll dist2 = dist(b);
    return dist1 > dist2;
}

int main (void)
{
    int c;
    scanf("%d", &c);
    
    for (int i = 0; i < c; i++)
    {
        int n;
        vector <node> p;
        
        scanf("%d", &n);
        p.resize(n);
        p0 = {10001, 10001, -1};
        
        for (int j = 0; j < n; j++)
        {
            scanf("%d %d", &p[j].x, &p[j].y);
            p[j].idx = j;
            if (p0.y > p[j].y)
            {
                p0.x = p[j].x;
                p0.y = p[j].y;
                p0.idx = j;
            }
            else if (p0.y == p[j].y && p0.x > p[j].x)
            {
                p0.x = p[j].x;
                p0.y = p[j].y;
                p0.idx = j;
            }
        }
        
        sort(p.begin(), p.end(), compare);
        
        int cnt = 0;
        for (int j = n-1; j >= 1; j--)
        {
            node tmpNode1 = p[j], tmpNode2 = p[j-1];
            ll tmpCcw = ccw(tmpNode1, tmpNode2);
            if (tmpCcw == 0)
                cnt++;
            else
                break;
        }
        
        if (cnt)
            sort(p.begin()+n-cnt-1, p.end(), compare2);
        
        printf("%d", p[0].idx);
        for (int j = 1; j < n; j++)
            printf(" %d", p[j].idx);
            
        printf("\n");
    }
    
    return 0;
}