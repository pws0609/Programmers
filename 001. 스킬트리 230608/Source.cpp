#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int flg = 0;
    int notskill = 0;
    stack<char> skills;
    for (int i = skill.length() - 1; i >= 0; i--)
        skills.push(skill[i]);
    for (int i = 0; i < skill_trees.size(); i++) {
        flg = 0;
        notskill = 0;
        for (int j = 0; j < skill_trees[i].length(); j++) {
            if (skill.length() > skill.find(skill_trees[i][j]) && skill.find(skill_trees[i][j]) >= 0) {
                if (!skills.empty() && skill_trees[i][j] == skills.top()) {
                    flg = 1;
                    skills.pop();
                }
                else {
                    flg = 0;
                    j = skill_trees[i].length();
                }
            }
            else
                notskill++;
        }
        while (!skills.empty())
            skills.pop();
        for (int k = skill.length() - 1; k >= 0; k--)
            skills.push(skill[k]);
        if (flg == 1 || notskill == skill_trees[i].length())
            answer++;
    }
    return answer;
}