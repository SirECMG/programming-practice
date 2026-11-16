/*
 *
 * day 8: matchsticks
 *
 * - santa needs to know how much space it will take up when stored
 * - it is common in many languages to provide a way to escape special
 *   characters in strings.
 *
 * - it is important to realize the diff between a num of character in the code representation of the string literal and the number of characters in the in-memory string itself
 *
 * for example:
 *
 * - "" is 2 characters of code (two double quotes), but the string contain zero characters
 *
 * - "abc" is 5 characters of code, but 3 characters in the string data.
 *
 * - "aaa\"aaa" is 10 characters of code, but the strin itself contains six "a" characters and a single, escaped quote character, for a total of 7 character in string data.
 *
 * - "\x27" is 6 characters of code, but the strin gitself contains just one - an  apostrophe('), escaped using hexadecimal notation.
 *
 *
 *  details:
 *
 *  santa's list is a file that contains many double-quoted string literals, one on each line
 *
 *  only escape sequences are used are:
 *
 *   \\ (which represent backslash)
 *   \" (which represent a lone double-quote character)
 *   \x (plus two hexadecimal characters (which represent a single character with that ASCII code)
 *
 *
 *   disregardin the whitespace in file
 *
 *
 *
 *
 *  output:
 *
 *  what is the number of characters of code for string literals minux the number of characters in memory for the values of strings in total for the entire file.
 *
 *  2 + 5 + 10 + 6 = 23
 *
 *  in memory
 *
 *  0 + 3 + 7 + 1 = 11
 *
 *  23 - 11 = 12
 *
 *  
 *
 * notes/observations:
 *
 * - there is code representation
 * - there is in-memory string representation
 *
 * - code representation is given
 * - in-memory reprsenetation is the actual string (rules applied)
 *
 *
 *   mini problems
 *
 *   get code representation count
 *      we can just get the size of the string
 *
 *   get in-memory string representation count
 *
 *      ""
 *
 *      - i can pattern match it
 *
 *      if cur[i] == '"' && current[n - 1] == '"'
*
*       what is the rule for in-memory string representation code"?
    *
    *   - the constriant (i = 1 until i < n-1
*       - exclude double quote (beginning and end)
    *       +0
    *   - we want the strings between the quote quotes (mainly)
    *       +1 per character
    *   - if we see a \ - it means escape
    *       - \ represents backslash
    *       - " represents lone double-quote character
    *       - \x + 2 HEX (A-F) which represent a single character
    *
    *       +1
    *
    *
    *
    * we can get each line
    *
    * std::getline(stdin, line)
    *
    * def code_rep_count(line):
    *   line.size()
    *
    * def mem_rep_count(line):

        int i,n;
        int count;

        i = 1
        while i < n - 1

        if isalpha(line[i])
            count += 1
        else if line[i] == '/'
            next_char = line[i+1]
            if(next_char == '\' || next_char == '"')
                count += 1
            else if(next_char == 'x')
                first = line[i+2]
                second = line[i+3]
                if(!isxdigit(first) && !isxdigit(second)):
                    continue
                count += 1  
                i += 4
            else:
                continue:
        end
        i += 1

        return count;

    *   
*       
*
*
*
 * */

#include <iostream>
#include <string>
#include <cctype>

int get_code_count(const std::string&  line) {
    return line.size();
}

int get_mem_count(const std::string line) {

    int count = 0;

    int n = line.size();
    int i = 1;

    while ( i < n - 1) {
        char cur = line[i];
        if (cur == '\\') {
            char next = line[i+1];

            if(next == '\\' || next == '"') {
                count += 1;
                i += 2;
                continue;
            } else if(next == 'x') {
                char first = line[i+2];
                char second= line[i+3];

                if(!std::isxdigit(first) || !std::isxdigit(second)) {
                    i += 1;
                    continue;
                }
                count += 1;
                i += 4;
                continue;
            } else {
                i += 1;
            }
        } else {
            count += 1;
            i += 1;
        }
    }

    return count;
}

int main() {

    std::string line;
    int answer = 0;
    while(std::getline(std::cin, line)) {
        std::cout << line << "\n";
        int code_count = get_code_count(line);
        int mem_count = get_mem_count(line);

        std::cout << "code count: " << code_count << "\n";
        std::cout << "mem count: " << mem_count << "\n";
        answer += (code_count - mem_count);

    }

    std::cout << "answer: " << answer << "\n";

    return 0;
}

 
