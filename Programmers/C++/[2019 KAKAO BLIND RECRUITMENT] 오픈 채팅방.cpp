#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;


vector<string> solution(vector<string> record) {
	map<string, string> nick;
    vector<string> answer;
    string cmd;
    string id;
    string nickname;
    vector<pair<string, int>> log;
    for (auto r : record) {
    	stringstream ss(r);
    	ss >> cmd;
    	ss >> id;
    	if (cmd == "Enter") {
    		ss >> nickname;
    		nick[id] = nickname;
    		log.push_back(make_pair(id,0));
		}
		else if (cmd == "Leave") {
			log.push_back(make_pair(id,1));
		}
		else if (cmd == "Change") {
			ss >> nickname;
			nick[id] = nickname;
		}
	}
	
	for (int i=0; i<log.size(); i++) {
		string str = nick[log[i].first];
		if(log[i].second == 0) {
			str += "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
		}
		else if(log[i].second == 1){
			str += "´ÔÀÌ ³ª°¬½À´Ï´Ù.";
		}
		answer.push_back(str); 
	}
	
	
    return answer;
}
