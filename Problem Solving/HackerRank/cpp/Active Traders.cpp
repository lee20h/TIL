#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'mostActive' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY customers as parameter.
 */

vector<string> mostActive(vector<string> customers) {
    sort(customers.begin(),customers.end());
    set<string> s;
    vector<pair<string, double>> v;
    int cnt = 1;
    int size = customers.size();
    s.insert(customers[0]);
    for (int i=1; i<size; i++) {
        if(s.find(customers[i]) == s.end()) {
            s.insert(customers[i]);
            v.push_back({customers[i-1], (double)cnt/size * 100});
            cnt = 1;
        }
        else {
            cnt++;
        }
    }
    v.push_back({customers[size-1], (double)cnt/size * 100});
    vector<string> answer;
    for (int i=0; i<v.size(); i++) {
        if(v[i].second >= 5) {
            answer.push_back(v[i].first);
        }
    }
    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string customers_count_temp;
    getline(cin, customers_count_temp);

    int customers_count = stoi(ltrim(rtrim(customers_count_temp)));

    vector<string> customers(customers_count);

    for (int i = 0; i < customers_count; i++) {
        string customers_item;
        getline(cin, customers_item);

        customers[i] = customers_item;
    }

    vector<string> result = mostActive(customers);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

