#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main()
{
    int boyNum, girlNum, result = 0;
    vector<int> boys;
    vector<int> girls;

    cin >> boyNum;
    for(int i = 0; i < boyNum; i++) {
        int danceSkill;
        cin >> danceSkill;
        boys.push_back(danceSkill);
    }
    sort(boys.begin(), boys.end());

    cin >> girlNum;
    for(int i = 0; i < girlNum; i++) {
        int danceSkill;
        cin >> danceSkill;
        girls.push_back(danceSkill);
    }
    sort(girls.begin(), girls.end());

    int gStart = 0;

    for(int i = 0; i < boyNum; i++) {
        for(int j = gStart; j < girlNum; j++) {
            if ( abs( boys[i] - girls[j] ) < 2){
                gStart = j + 1;
                result++;
                break;
            }
        }
    }

    cout << result << '\n';

    return 0;
}