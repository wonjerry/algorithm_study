#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <utility>

using namespace std;

vector< pair<string, string> > servers;

int main() {
    int server, duplicate;
    scanf("%d %d", &server, &duplicate);

    for(int i = 0; i < server; i++) {
        string temp1, temp2;
        cin >> temp1 >> temp2;
        servers.push_back(make_pair(temp1,temp2));
    }

    for(int i = 0; i < duplicate; i++) {
        string temp1, temp2;
        cin >> temp1 >> temp2;
        for(int i = 0; i < servers.size(); i++) {
            if((servers[i].second).compare(temp2.substr(0, temp2.length() -1)) == 0) {
                cout << temp1 << " " << temp2 << " #" << servers[i].first << '\n';
                break;
            }
        }
    }

    return 0;
}