#include <iostream>
#include <map>
#include <stack>

using namespace std;

typedef long long ll;

int main()
{
    unsigned long n;
    cin >> n;

    unsigned long ans = 0;
    stack<unsigned long> st;
    map<unsigned long, unsigned long> cnt;

    while (n--)
    {
        {
            ll x;
            cin >> x;

            while (!st.empty() && x > st.top())
            {
                --cnt[st.top()];
                st.pop();
                ++ans;
            }
            if (!st.empty())
                ans += x == st.top() ? cnt[x] + (st.size() > cnt[x]) : 1;
            st.push(x);
            ++cnt[x];
        }
    }

    cout << ans;

    return 0;
}
