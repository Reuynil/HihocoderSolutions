#include<iostream>
#include<string>

using namespace std;

string subString(const string& str, int begin, int end)
{
	string res;
	int len = str.length();
	if (begin > end)
	{
		res = "";
	}
	else
	{
		res = str.substr(begin, end - begin + 1);
	}
	return res;
}

int score(string& str)
{
	int score = 0;
	bool flag = true;
	int str_len = str.length();
	while (flag)
	{
		flag = false;
		char pre_char = str[0];
		int pre_index = 0;
		for (int j = 1; j <= str.length(); j++)
		{
			if (j == str.length() && pre_index != j - 1)
			{
				str.erase(pre_index, j - pre_index);
				flag = true;
			}
			else if (str[j] != pre_char)
			{
				int same_len = j - pre_index;
				if (same_len > 1)
				{
					flag = true;
					str.erase(pre_index, same_len);
					j -= same_len;
				}
				pre_index = j;
				pre_char = str[j];
			}
		}
	}
	int final_len = str.length();
	score = str_len - final_len;
	return score;
}

int main()
{
	int n;
	string str;
	char letter[3] = { 'A','B','C' };
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		int max_score = 0;
		for (int j = 0; j < 3; j++)
		{
			char insert = letter[j];
			int max_letter = 0;
			int len = str.length();
			string pre_str = "";
			for (int k = 0; k < len + 1; k++)
			{
				string tmp = subString(str, 0, k - 1) + insert + subString(str, k, len);
				if (tmp == pre_str)
				{
					continue;
				}
				pre_str = tmp;
				int temp = score(tmp);
				max_letter = temp > max_letter ? temp : max_letter;
			}
			max_score = max_score > max_letter ? max_score : max_letter;
		}
		cout << max_score << endl;
	}
	return 0;
}