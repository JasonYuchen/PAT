#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);                   
	cin.tie(0);
	map<string, int> words;
	string text, word;
	getline(cin, text);
	for (int i = 0; i < text.size(); ++i)
	{
		if (isalnum(text[i]))
		{
			word += tolower(text[i]);
		}
		if (!isalnum(text[i]) || i + 1 == text.size())  //不能是else if，getline不将最后\n写入string
		{
			if(word.size() != 0)                        //对于最后一个单词的最后一个字符，也需要words[word]++，写为else if就会导致漏掉最后一个词的words[word]++
				words[word]++;
			word = "";
		}
	}
	int n = 0;
	for (auto w : words)
	{
		if (w.second > n)
		{
			word = w.first;
			n = w.second;
		}
	}
	cout << word << " " << n << endl;
	return 0;
}