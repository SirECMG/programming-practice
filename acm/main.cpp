#include <iostream>
#include <unordered_map>

struct submission {
    int attempt_count;
    int total_time;
    int is_solved;
};

int extract_problems(const std::unordered_map<std::string, submission>& m) {
    int total_submissions = 0;
    for(auto it = m.begin(); it != m.end(); ++it) {
        const submission& cur = it->second;
        if(cur.is_solved == 1) 
            total_submissions += 1;
    }

    return total_submissions;
}

int extract_total_time(const std::unordered_map<std::string, submission>& m) {
    int total_time = 0;
    for(auto it = m.begin(); it != m.end(); ++it) {
        const submission& cur = it->second;
        if(cur.is_solved == 1) {
            int score = cur.total_time + (cur.attempt_count - 1) * 20;
            total_time += score;
        }
    }

    return total_time;
}

int main() {
    
    std::unordered_map<std::string, submission> o;

    int c0;
    std::string c1;
    std::string c2;
    while(std::cin >> c0 >> c1 >> c2) {

        auto itr = o.find(c1);

        // skip solved problems
        if(itr != o.end() && itr->second.is_solved == 1) continue;

        // not found
        if(itr == o.end()) {
            if(c2 == "wrong") {
                o[c1] = {1, c0, 0};
            } else if(c2 == "right") {
                o[c1] = {1, c0, 1};
            }
        } else { //found
            o[c1].attempt_count++;
            if(c2 == "right") {
                o[c1].total_time = c0;
                o[c1].is_solved = 1;
            }
        }
    }

    int total_problems = extract_problems(o);
    int total_time = extract_total_time(o);

    std::cout << total_problems << " " << total_time << "\n";
    return 0;
}

/* 
 *
 * acm content scoring:
 *
 * - content submission system
 *      - keeps chronological log of all submissions
 *      - made by each team during contest
 *      - 1 entry
 *          - number of mins into the competition (from received)
 *          - letter that identifies relevant contest problems
 *          - result of testing the submission (right or wrong)
 *
 *
 *        3 E right
 *        10 A wrong
 *
 *
 *
 *    rank of team relative to others is determined by a primay and second dary scoring measure calculated from the submission data.
 *
 *
 *    - primay is number of problems solved
 *    - combination of time and penalties
 *      - a team's time scored is equal to the sum of those submission
 *      times that resulted in right answers,
 *      - plus a 20-min penalty for each wrong submission of a problem that is ultimately solved.
 *      - if no problems solved, the time measure is 0.
 *
 *
 *      tldr:
 *
 *      for every problem solved if right minus detected penalties.
 *      sum this for every problem.
 *
 *
 *
 *      once a particular problem is solved any further submissions of the same problem are ignored ( and omitted from the log).
 *
 *
 *      there could be more than one submission of the same problem in the same minute, but they are chronological so only the last entry could possibly be correct.
 *
 *
 *      example 1:
 *
 *      sum0 = 3
 *      sum1 = 3 + 3 + 200 + 300 +40
 *
 *      expected 543...
 *
 *      3 E right
 *
 *      10 A wrong
 *      100 A wrong
 *      200 A right
 *      200 - 20 - 20 = 160
 *
 *      300 D right
 *
 *
 *
 *
 *
 *
 *
 *  
 * 
 *
 *
 * input: 
 *
 * 3 E right
 *
 * output:
 *
 * number of problems solved
 * total time measured
 *
 * 4 543
 *
 *
 *
 * solution:
 *
 * we need to calculate the total number of problems solved
 * we need to calculate the total time measured according to the rules
 * the result is for one teams accumulative submission.
 *
 *
 * naturally we will need a cache to determine for a given problem set if it was solved.
 *
 * E is finished? y/n, sum      we can capture this using a struct
 *
 * how would that struct look like?
 *
 * problem:
 *  name: "" (this we can use as a key)
 *  attempts: int
 *  time: int
 *  is_solved: int (0/1)
 *
 *  map[some_problem] = problem (attempts, is_solved)
    

    so we have two structures

    map of submissions
    key being name of submission
    value being metadata of submission


    approach:

    we will build the map as we go down each line

    map["E"] = {1, 3, true}
    //map["A"] = {1, 10, false}
    //map["C"] = {1, 30, false}
    map["B"] = {1, 50, false}
    //map["A"] = {2, 100, false}
    map["A"] = {3, 200, true}
    map["C"] = {2, 250, false}
    map["D"] = {1, 300, true}



    observations from this pass?

    - as we build our map, if is_solved is true ignore future submissions.

    our goal:

    print number of problems solved

    sum of problems solved....
    total time measured....

    iterate through every entry.
    if is_solved is true add to sum.
    total time measured = entry time measured + (attempts - 1) * 20 // minus 1 because only correct answer.
                                                    
 *  action items:
 *
 *  - create map // done
 *  - if_solved continue to next submission // done
 *  - create struct to represent submission (attempt_count, time, is_solved // 
    - need to scan stdin // done
    - parse map to extract problems solved
    - parse map to generate score
 *
 *
 *
 *
 * 

3 E right
10 A wrong
30 C wrong
50 B wrong
100 A wrong
200 A right
250 C wrong
300 D right

 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 * */
