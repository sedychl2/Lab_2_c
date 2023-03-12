#include <iostream>
#include <stack>

using namespace std;

struct Node
{
    int x, Height;
    Node(int x, int Height) : x(x), Height(Height) {};
};

stack<Node> s;

int main() {

    int h, n, i;
    long res;
    scanf("%d", &n);
    s.push(Node(0, 0));


    for (res = 0, i = 1; i <= n + 1; i++)
    {

        if (i <= n) scanf("%d", &h);
        else h = 0;
        int x = i;
        while (h < s.top().Height)
        {
            x = s.top().x;
            int Height = s.top().Height;
            s.pop();
            long area = 1L * Height * (i - x);
            if (area > res) res = area;
        }
        if (h > s.top().Height) s.push(Node(x, h));
    }
    printf("%ld\n", res);
    return 0;
}