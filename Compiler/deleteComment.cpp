#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    char ch, next;
    bool multiComment = false;

    while (input.get(ch)) {

        if (multiComment) {
            if (ch == '*') {
                input.get(next);

                if (next == '/') {
                    multiComment = false;
                } else {
                    input.putback(next);
                }
            }
        }

        else if (ch == '/') {
            input.get(next);

            // Single line comment
            if (next == '/') {
                while (input.get(ch) && ch != '\n');

                output << '\n';
            }

            // Multi-line comment
            else if (next == '*') {
                multiComment = true;
            }

            // Normal slash
            else {
                output << ch;
                input.putback(next);
            }
        }

        else {
            output << ch;
        }
    }

    input.close();
    output.close();

    cout << "Comments removed successfully!" << endl;

    return 0;
}

/*
This program strips comments from a C/C++-style source file: it reads input.txt char by char, detects // and "/ * * /" comments,
skips their contents, and writes everything else to output.txt.

How it works:

Normal characters are copied straight through.
On seeing /, it peeks at the next char: // → skip to end of line (but still write a \n so line count doesn't shift); /* → enter 
"multi-comment" mode; otherwise it's just a division/slash, so both chars are written back.
While in multi-comment mode, it watches for * followed by / to close it.

Bugs / gaps worth fixing:

String and char literals aren't respected. "http://example.com" or char c = '/'; would get mangled, since the code doesn't know it's 
inside a string when it sees //.
get+putback is fragile at EOF — if / is the last byte in the file, input.get(next) fails and next holds a stale value that still gets processed.
Newlines inside "/ * * /"" comments are dropped, shifting line numbers in the output relative to the original.
Uses input.peek() instead of get+putback simplifies the logic and avoids the EOF edge case entirely.

Key changes: it now tracks whether it's inside a "..." or '...' literal and copies those chars verbatim (including escaped chars like \"), uses 
peek() instead of get+putback so there's no stale-char risk at EOF, and emits a \n for each newline swallowed inside a "/ * * / "block so line 
numbers in the output still match the original.

Updated:

#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    char ch, next;
    bool inMulti = false, inString = false, inChar = false;

    while (input.get(ch)) {
        if (inMulti) {
            if (ch == '*' && input.peek() == '/') {
                input.get();
                inMulti = false;
            } else if (ch == '\n') {
                output << '\n'; // keep line numbers aligned
            }
            continue;
        }

        if (inString || inChar) {
            output << ch;
            if (ch == '\\') { // escaped char, copy next as-is
                if (input.get(next)) output << next;
            } else if ((inString && ch == '"') || (inChar && ch == '\'')) {
                inString = inChar = false;
            }
            continue;
        }

        if (ch == '"') { inString = true; output << ch; continue; }
        if (ch == '\'') { inChar = true; output << ch; continue; }

        if (ch == '/' && input.peek() == '/') {
            while (input.get(ch) && ch != '\n');
            output << '\n';
            continue;
        }

        if (ch == '/' && input.peek() == '*') {
            input.get();
            inMulti = true;
            continue;
        }

        output << ch;
    }

    cout << "Comments removed successfully!" << endl;
    return 0;
}
*/

/*
Input:
#include <iostream> // basic io
using namespace std;

/* This program
   prints a greeting * /
int main() {
    string url = "http://example.com"; // not a real comment
    char c = '/';                      // division-looking char literal
    int a = 10 / 2;  /* inline comment * / cout << a;
    return 0;
}

Output:
#include <iostream> 
using namespace std;


int main() {
    string url = "http://example.com"; 
    char c = '/';                      
    int a = 10 / 2;   cout << a;
    return 0;
}


*/