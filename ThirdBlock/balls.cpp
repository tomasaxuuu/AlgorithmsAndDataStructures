#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string s, s1 = "";

	vector<char> v;

	int resultStr = 0;
	int n = 0;
	cin >> n;
	getline(cin, s);

	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] != ' ')
		{
			s1 += s[i];
		}
	}

	for (int i = 0; i < s1.size(); ++i)
	{
		v.push_back(s1[i]);
	}

	for (int i = 0; i < v.size(); ++i)
	{
		if (v.size() < 3)
		{
			break;
		}

		int a = v[i];
		int b = v[i + 1];
		int c = 0;

		if (i + 2 < v.size())
		{
			c = v[i + 2];
		}
		else
		{
			break;
		}

		if (a == b && a == c && b == c)
		{
			v.erase(v.begin() + i);
			v.erase(v.begin() + i);
			v.erase(v.begin() + i);

			resultStr += 3;

			while (v.size() != 0)
			{
				if (i < v.size())
				{
					if (v[i] == a)
					{
						v.erase(v.begin() + i);
						resultStr++;
					}
					else
					{
						i = -1;
						break;
					}

				}
				else
				{
					break;
				}
			}
		}
	}

	cout << resultStr << endl;

	return 0;
}