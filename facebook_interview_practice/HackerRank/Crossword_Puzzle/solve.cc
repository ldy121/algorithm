#include <bits/stdc++.h>

using namespace std;


// Complete the crosswordPuzzle function below.
const char avail = '-';
const char unavail = '+';

bool is_horizontal(vector<string>& crossword, int row, int col, string& word)
{
    int i, j;
    for (i = 0, j = col; i < word.length() && j < crossword[row].length() &&
        ((word[i] == crossword[row][j]) || (crossword[row][j] == avail)); ++i, ++j);

    return ((i == word.length()) && 
        ((j == crossword[row].length()) || (crossword[row][j] != avail)));
}

bool is_vertical(vector<string>& crossword, int row, int col, string& word)
{
    int i, j;
    for (i = 0, j = row; i < word.length() && j < crossword.size() &&
        ((word[i] == crossword[j][col]) || (crossword[j][col] == avail)); ++i, ++j);

    return ((i == word.length()) &&
        ((j == crossword.size()) || (crossword[j][col] != avail)));
}

bool get_answer(vector<string>& crossword, string words, int idx)
{

    bool ret = false;
    string word;

    if (idx > words.length()) return true;

    for (int len = 0; ((idx + len) < words.length() && (words[idx + len] != ';'));) {
        word += words[idx + len];
        ++len;
    }


    for (int i = 0; i < crossword.size(); ++i) {
        cout << crossword[i] << endl;
    }

    for (int i = 0; (i < crossword.size()) && (ret == false); ++i) {
        for (int j = 0; (j < crossword[i].length()) && (ret == false); ++j) {
            if ((crossword[i][j] == avail) || (crossword[i][j] == words[idx])) {

                if (is_horizontal(crossword, i, j, word)) {
                    string buffer;
                    for (int k = 0; k < word.length(); ++k) {
                        buffer += crossword[i][j + k];
                        crossword[i][j + k] = word[k];
                    }
                    ret = get_answer(crossword, words, idx + word.length() + 1);

                    if (ret == false) {
                        for (int k = 0; k < word.length(); ++k) {
                            crossword[i][j + k] = buffer[k];
                        }
                    }
                }

                if ((ret == false) && is_vertical(crossword, i, j, word)){
                    string buffer;
                    for (int k = 0; k < word.length(); ++k) {
                        buffer += crossword[i + k][j];
                        crossword[i + k][j] = word[k];
                    }
                    ret = get_answer(crossword, words, idx + word.length() + 1);
                    if (ret == false) {
                        for (int k = 0; k < word.length(); ++k) {
                            crossword[i + k][j] = buffer[k];
                        }
                    }
                }
            }
        }
    }

    return ret;
}

vector<string> crosswordPuzzle(vector<string> crossword, string words) {
    get_answer(crossword, words, 0);
    return crossword;
}
