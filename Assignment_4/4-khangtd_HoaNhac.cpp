#include <iostream>
#include <map>
#include <stack>

using namespace std;

typedef long long ll;

int main()
{
    ll n;
    cin >> n;

    ll ans = 0;
    stack<ll> st;
    map<ll, ll> cnt;

    while (n--)
    {
        {
            ll x;
            cin >> x;

            while (!st.empty() && x > st.top())
            {
                cnt[st.top()]--;
                st.pop();
                ans++;
            }
            if (!st.empty())
                ans += x == st.top() ? cnt[x] + (st.size() > cnt[x]) : 1;
            st.push(x);
            cnt[x]++;
        }
    }

    cout << ans << endl;

    return 0;
}
