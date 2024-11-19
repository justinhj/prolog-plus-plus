// main.cpp
#include <memory>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>

// let's create a simple type system that consists of words and variables.
// punctuation such as . and , are words, as are carriage returns
// Words beginning with ? are variables. Escape with \ to start a word with ?
// We can convert to and from a string from the user

#include <string>

using std::unique_ptr;
using std::make_unique;

class Lexeme {
public:
    virtual ~Lexeme() = default;  // Virtual destructor for proper cleanup in inheritance
    virtual const std::string getType() const = 0;
};

class Word : public Lexeme {
  private: 
    std::string content;
  public:
    Word(const std::string& content) : content(content) {
    }
    const std::string getType() const {
      return std::string("Word");
    }
};

class Variable : public Lexeme {
private:
    std::string name;
public:
    Variable(const std::string& name) : name(name) {
    }
    const std::string getType() const {
      return std::string("Variable");
    }
};

typedef std::vector<unique_ptr<Lexeme>> LexemeVector;

LexemeVector createLexemeVector(const std::string& input) {
    LexemeVector lexemes;
    std::istringstream stream(input);
    std::string token;
    bool isVariable = false;

    while (stream >> token) {
        if (token[0] == '?') {
            if (token.size() > 1) {
                lexemes.push_back(make_unique<Variable>(token.substr(1)));
            } else {
                lexemes.push_back(make_unique<Word>("?"));
            }
        } else if (ispunct(token[0])) {
            lexemes.push_back(make_unique<Word>(token));
        } else {
            lexemes.push_back(make_unique<Word>(token));
        }
    }

    return lexemes;
}

int main() {
    LexemeVector lv1 = createLexemeVector("Hello, World!");
    return 0;
}
