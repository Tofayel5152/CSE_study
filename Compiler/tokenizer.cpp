#include <bits/stdc++.h>
using namespace std;

int main() {

    string s = "int a = b + 25;";
    string token[20];
    int count = 0;
    string temp = "";

    // Tokenization
    for (int i = 0; i < s.length(); i++) {

        if (isalnum(s[i])) {
            temp += s[i];
        }
        else {

            if (temp != "") {
                token[count] = temp;
                count++;
                temp = "";
            }

            if (s[i] != ' ') {
                token[count] = s[i];
                count++;
            }
        }
    }

    // Classification
    for (int i = 0; i < count; i++) {

        cout << token[i] << " : ";

        if (token[i] == "int")
            cout << "Keyword";

        else if (isdigit(token[i][0]))
            cout << "Number";

        else if (token[i] == "=" || token[i] == "+" ||
                 token[i] == "-" || token[i] == "*")
            cout << "Operator";

        else if (token[i] == ";")
            cout << "Separator";

        else
            cout << "Identifier";

        cout << endl;
    }

    return 0;
}

/*
This is a simple lexical analyzer (tokenizer) for a single line of C-like code. It has two passes:

Tokenization — walks the string character by character. Letters/digits build up into temp (a multi-char token like int or 25). 
Any non-alnum char (operator, separator, space) ends the current token; if that char isn't a space, it becomes its own single-character token.
Classification — loops over the collected tokens and labels each: int → Keyword, starts with a digit → Number, one of = + - * → Operator, ; 
→ Separator, else → Identifier.

Issues / limitations:

Fixed-size array (token[20]) — overflows silently on longer input, no bounds checking.
Multi-digit or decimal numbers work by luck — 25 stays together because isalnum includes digits, but 3.14 would break at the ..
Multi-char operators aren't handled — ==, +=, <= etc. would tokenize as two separate single-char tokens.
Identifiers starting with a letter but containing digits classify fine, but a token like 123abc would be misclassified as "Number" since it only 
checks token[i][0].
Only one hardcoded keyword (int) — no way to recognize float, if, return, etc. without a growing if-chain.
Only works on one fixed string — not reusable for arbitrary input.

No fixed array limit, keywords/operators live in sets so adding more is a one-line change, two-character operators (==, +=, etc.) are greedily 
matched before falling back to single chars, and separators now cover brackets/commas too, not just ;.

Updated:

#include <bits/stdc++.h>
using namespace std;

const set<string> keywords = {"int", "float", "char", "if", "else", "return", "while", "for"};
const set<string> operators = {"=", "+", "-", "*", "/", "==", "+=", "-=", "<=", ">=", "<", ">"};

vector<string> tokenize(const string& s) {
    vector<string> tokens;
    string temp;

    for (size_t i = 0; i < s.length(); i++) {
        char c = s[i];

        if (isalnum(c) || c == '.') {
            temp += c;
            continue;
        }
        if (!temp.empty()) {
            tokens.push_back(temp);
            temp.clear();
        }
        if (isspace(c)) continue;

        // greedily grab two-char operators like == or +=
        if (i + 1 < s.length() && operators.count(string(1, c) + s[i + 1])) {
            tokens.push_back(string(1, c) + s[i + 1]);
            i++;
        } else {
            tokens.push_back(string(1, c));
        }
    }
    if (!temp.empty()) tokens.push_back(temp);
    return tokens;
}

string classify(const string& t) {
    if (keywords.count(t)) return "Keyword";
    if (isdigit(t[0]) || (t[0] == '.' && t.size() > 1)) return "Number";
    if (operators.count(t)) return "Operator";
    if (t == ";" || t == "," || t == "(" || t == ")" || t == "{" || t == "}")
        return "Separator";
    return "Identifier";
}

int main() {
    string s = "int a = b + 25;";

    for (const auto& tok : tokenize(s))
        cout << tok << " : " << classify(tok) << endl;

    return 0;
}

*/

/*
Input:
string s = "int a = b + 25; if (a >= 10) return a;";

output:
int : Keyword
a : Identifier
= : Operator
b : Identifier
+ : Operator
25 : Number
; : Separator
if : Keyword
( : Separator
a : Identifier
>= : Operator
10 : Number
) : Separator
return : Keyword
a : Identifier
; : Separator
*/