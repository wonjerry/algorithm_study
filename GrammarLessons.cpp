#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>

using namespace std;

pair<int, int> checkTail(string word) {
    if(word.find("soil") == 0) {
        return make_pair(0,2);
    }else if(word.find("rte") == 0) {
        return make_pair(0,3);
    }else if(word.find("sitini") == 0) {
        return make_pair(0,4);
    }else if(word.find("alail") == 0) {
        return make_pair(1,2);
    }else if(word.find("arte") == 0) {
        return make_pair(1,3);
    }else if(word.find("setini") == 0) {
        return make_pair(1,4);
    }
    return make_pair(-1,0);
}

// 기본적으로 문장 하나의 형식은 adj -> noun -> verb
// 무조건 이 순서대로 나와야 한다.
// adj, verb는 개수가 상관 없지만, noun은 무조건 하나만 나와야 한다.
// 문장은 오직 하나여야 하므로 verb나 noun뒤에 또 adj가 올 수 없다.

int main() {
    string input;
    getline(cin, input);
    
    // 들어온 문장을 단어 단위로 쪼갠다.
    vector<string> words;
    
    char* token = NULL;
    char *str = (char*)input.c_str();
    
    token = strtok(str, " ");
    
    while(token != NULL) {
        words.push_back(string(token));
        token = strtok(NULL, " ");
    }
    
    // 성별이 항상 같은 단어가 나왔는지 true는 남자 false는 여자
    bool genderFlag = true;
    // adj가 나오면 true로 바뀐다.
    bool adjCheck = false;
    // noun이 나오면 true로 바뀐다.
    bool nounCheck = false;
    //verb가 나오면 true로 바뀐다.
    bool verbCheck = false;
    bool result = true;
    // 문제에 따르면 noun은 딱 한개 나와야 한다 그것을 체크한다.
    int nounCnt = 0;
    
    
    for( int i = 0, len = words.size(); i < len; i++ ) {
        string word = words[i];
        // 단어 끝에 문법에 맞는 접미사가 오는지 체크
        reverse(word.begin(), word.end());
        // 리턴값으로 성별 ( 0 : 남자 1 : 여자 ), 품사( 2: adj 3: noun 4: verb) 쌍이 리턴된다.
        pair<int,int> check = checkTail(word);
        
        // 성별에 따라서 계속 같은 성별이 나오는지 체크.
        // -1이면 없는 접미사라 바로 종료한다.
        if(check.first == 0) {
            if(i == 0) {
                genderFlag = true;
            }else if(!genderFlag) {
                result = false;
                break;
            }
        }else if(check.first == 1) {
            if(i == 0) {
                genderFlag = false;
            }else if(genderFlag) {
                result = false;
                break;
            }
        }else if(check.first == -1) {
            result = false;
            break;
        }

        // adj일때
        if(check.second == 2) {
            // 앞에 noun이나 verb가 있으면 안된다.
            if(i > 0 && (nounCheck || verbCheck)) {
                result = false;
                break;
            }                
            // adj가 나왔다고 체크한다.
            adjCheck = true;
            
        // noun 일 때
        }else if(check.second == 3) {
            // 앞에 adj 가 있어야 한다.
            // noun이 2 이상이면 문제 조건에 맞지 않아서 false
            if(i > 0 && (!adjCheck || nounCnt >= 1)) {
                result = false;
                break;
            }
            //noun이 얼마나 나왔는지 카운팅 하고, noun이 나왔다고 체크한다.
            nounCnt++;
            nounCheck = true;
                
        // verb일 때
        }else if(check.second == 4) {
            // 앞에 noun이 있어야 한다.
            if(i > 0 && !nounCheck) {
                result = false;
                break;
            }
            // verb가 나왔다고 체크한다.
            verbCheck = true;
        }    
    }
    //만약 adj가 나왔을 때 2단어 이상인데 noun이 안나왔으면 문제 조건에 안맞아서 false
    if(adjCheck) {
        if(words.size() > 1 && !nounCheck) result = false;
    }
    
    if(result) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
    
    return 0;
}
