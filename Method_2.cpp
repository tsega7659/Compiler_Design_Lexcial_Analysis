#include<iostream>
#include<vector>
#include<cctype>
#include<string>

using namespace std;

struct Token {
    string type;
    string value;
};

bool keyword(const string &str) {
    return (str == "int" || str == "float" || str == "char" || str == "double" || str == "if" || str == "else" || str == "do" || str == "while");
}

vector<Token> LexicalAnalyzer(const string &input) {
    vector<Token> tokens;
    string buffer = "";
    int i = 0;

    while (i < input.size()) {
        char ch = input[i];
        if (isspace(ch)) {
            i++;
            continue;
        }
        if (isalpha(ch)) {
            buffer = "";
            while (isalnum(ch) && i < input.size()) {
                buffer += ch;
                i++;
                if (i < input.size()) ch = input[i];
            }
            if (keyword(buffer)) {
                tokens.push_back({"KEYWORD", buffer});
            } else {
                tokens.push_back({"IDENTIFIER", buffer});
            }
        } else if (isdigit(ch)) {
            buffer = "";
            while (isdigit(ch) && i < input.size()) {
                buffer += ch;
                i++;
                if (i < input.size()) ch = input[i];
            }
            tokens.push_back({"NUMBER", buffer});
        } else if (ch == '=') {
            if (i + 1 < input.size() && input[i + 1] == '=') {
                tokens.push_back({"EQUALITY", "=="});
                i++;
            } else {
                tokens.push_back({"ASSIGNMENT", "="});
            }
            i++;
        } else if (ch == '+') {
            tokens.push_back({"ADDITION", "+"});
            i++;
        } else if (ch == '-') {
            tokens.push_back({"SUBTRACTION", "-"});
            i++;
        } else if (ch == '*') {
            tokens.push_back({"MULTIPLICATION", "*"});
            i++;
        } else if (ch == '/') {
            tokens.push_back({"DIVISION", "/"});
            i++;
        } else if (ch == '(') {
            tokens.push_back({"OPENING BRACKET", "("});
            i++;
        } else if (ch == ')') {
            tokens.push_back({"CLOSING BRACKET", ")"});
            i++;
        } else if (ch == '{') {
            tokens.push_back({"OPENING CURLY BRACKET", "{"});
            i++;
        } else if (ch == '}') {
            tokens.push_back({"CLOSING CURLY BRACKET", "}"});
            i++;
        } else if (ch == ';') {
            tokens.push_back({"SEMICOLON", ";"});
            i++;
        } else {
            i++;
        }
    }
    return tokens;
}

int main() {
    cout<<"Please enter some code \n";
    string input;
    getline(cin, input);
    vector<Token> tokens = LexicalAnalyzer(input);
    for (Token token : tokens) {
        cout << "Type: " << token.type << " Value: " << token.value << endl;
    }
    return 0;
}