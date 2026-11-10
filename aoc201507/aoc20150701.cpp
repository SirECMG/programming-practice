#include <iostream>
#include <unordered_map>
#include <sstream>
#include <cctype>

void parse(const std::string &wire, const std::string signal, std::unordered_map<std::string, std::string> &map) {

    map[wire] = signal;

    return;
}

unsigned short evaluate(
    const std::string& wire,
    const std::unordered_map<std::string, std::string>& map,
    std::unordered_map<std::string, unsigned short>& cache
) {
    // Base case: numeric literal
    if (std::isdigit(wire[0])) {
        return static_cast<unsigned short>(std::stoi(wire));
    }

    if (cache.count(wire)) {
        return cache.at(wire);
    }

    std::string signal = map.at(wire);
    std::istringstream iss(signal);

    std::string a, b, c;
    iss >> a >> b >> c;

    unsigned short result = 0;

    if (a == "NOT") {
        result = ~evaluate(b, map, cache);
    }
    else if (b == "AND") {
        result = evaluate(a, map, cache) & evaluate(c, map, cache);
    }
    else if (b == "OR") {
        result = evaluate(a, map, cache) | evaluate(c, map, cache);
    }
    else if (b == "LSHIFT") {
        result = evaluate(a, map, cache) << evaluate(c, map, cache);
    }
    else if (b == "RSHIFT") {
        result = evaluate(a, map, cache) >> evaluate(c, map, cache);
    }
    else {
        result = evaluate(a, map, cache);
    }

    // Cache the result
    cache[wire] = result;

    return result;
}

int main() {
    std::string line;
    std::unordered_map<std::string, std::string> map = {};
    while(std::getline(std::cin, line)) {
        std::size_t pos = line.find(" -> ");
        if(pos == std::string::npos) {
            continue;
        }
        std::string left = line.substr(0, pos);
        std::string right= line.substr(pos + 4, line.size());

        parse(right, left, map);
    }

    std::unordered_map<std::string, unsigned short> cache;
    int result = evaluate("a", map, cache);
    std::cout << "result: " << result << "\n";
    return 0;
}


/*
 *
 *  aoc 2015 day 7:
 *
 *  - separate the left and right
 *
 *
 *  123 -> x
 *
 *  - build a map
 *   where key is the wire
 *   and the value is the signal
 *
 *   "x" : "123"
 *   "y" : "456"
 *   "d" : "x AND y"
 *   "e" : "x OR y"
 *   "f" : "x LSHIFT 2"
 *   "g" : "r RSHIFT 2"
 *   "h" : "NOT x"
 *   "i" : "NOT y"
 *
 *   evaluate("d")
 *      get "d" from map -> x AND y
 *      evaluate("x AND y")
 *          // here there needs to be an detection and extraction of values
 *          evaluate("x") AND evaluate("y")
 *
 *
 *          
 *
 *   - extraction of values
 *      - i think i can use istringstream
 *      - 
 *      std::istringstream iss("foo AND bar")
 *      int a,b;
 *      std::string op;
 *      if(std::iss >> a >> op >> b && op == "AND") {
 *          do something
 *          return a & b;
 *      }
 *
 *
 *   - parse (builds the map)
 *   - evaluate(") - gets the desire and finds the delegated method
 *      - evaluate_and(x,y)
 *      - evaluate_or(
 *      
 *
 * */
