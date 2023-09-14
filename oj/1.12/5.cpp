#include <bits/stdc++.h>
using namespace std;

vector<string> get_words(string artical)
{
    vector<string> words;
    while (artical.length() > 0)
    {
        auto index = artical.find(" ");
        auto word = index == -1 ? artical : artical.substr(0, index);
        artical = index == -1 ? "" : artical.substr(index + 1, artical.length() - index - 1);
        words.push_back(word);
    }
    return words;
}

bool ignore_case_equal(string word1, string word2)
{
    if (word1.length() != word2.length())
        return false;
    for (int i = 0; i < word1.length(); i++)
    {
        if (word1[i] != word2[i] && abs(word1[i] - word2[i]) != 32)
            return false;
    }
    return true;
}

int find(string artical, string word, int &first)
{
    first = -1;
    auto sum = 0;
    auto words = get_words(artical);
    for (auto i = 0; i < words.size(); i++)
    {
        if (ignore_case_equal(words[i], word))
        {
            if (first == -1)
                first = i;
            sum++;
        }
    }
    return sum;
}

int main()
{
    string word, artical;
    int first, sum;
    getline(cin, word);
    getline(cin, artical);
    sum = find(artical, word, first);
    if (first == -1)
        cout << -1;
    else
        cout << sum << " " << first;
    return 0;
}