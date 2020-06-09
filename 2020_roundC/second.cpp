#include <iostream>
#include <set>
#include <list>

using namespace std;

int t, r, c;
int caseCounter = 1;
char tab[30][30];

void doTask()
{
    string ans = "";
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> tab[i][j];
        }
    }

    set<char> generalChars;
    list<char> sequence;

    for (int i = 0; i < c; i++)
    {
        set<char> used;
        char last = tab[0][i];

        if (generalChars.count(last) == 0)
        {
            sequence.push_back(last);
            generalChars.insert(last);
        }

        used.insert(last);
        for (int j = 1; j < r; j++)
        {
            char next = tab[j][i];
            if (next == last)
            {
                continue;
            }
            else if (used.count(next))
            {
                ans = "-1";
                break;
            }
            else
            {
                if (generalChars.count(next) == 0)
                {
                    list<char>::iterator index = sequence.begin();
                    for (char c : sequence)
                    {
                        if (c == last)
                        {
                            break;
                        }
                        index++;
                    }
                    sequence.insert(index, next);
                    generalChars.insert(next);
                }
                used.insert(next);
                last = next;
            }
        }
        if (ans == "-1")
        {
            break;
        }
    }

    if (ans != "-1")
    {
        for (char c : sequence)
        {
            ans += c;
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t != 0)
    {
        cout << "Case #" << caseCounter << ": ";
        doTask();
        caseCounter++;
        t--;
    }

    return 0;
}