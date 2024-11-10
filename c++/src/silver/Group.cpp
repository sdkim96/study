#include <iostream>
#include <unordered_map>

// https://www.acmicpc.net/problem/16499
bool isSameChar(const std::string &str1, const std::string &str2) {

    std::unordered_map<char, int> dict;
    
    if (str1.size() != str2.size()) {
        return false;
    }

    // str1의 문자가 각각 몇개있는지 확인
    // 예를들어서 "str" 이면 s->1 개 r->1개 t->1개
    // 만약에 "ijci" 이면 i->2개 j->1개 c->1개
    // {
    //     's': 1,
    //     't': 1,  
    //     'r': 1
    // }
    for (size_t i=0; i<str1.size(); i++) {
        dict[str1[i]] += 1;
    }

    for (size_t i=0; i<str2.size(); i++) {
        if (dict[str2[i]] == 0) {
            return false;
        }
        dict[str2[i]] -= 1;
    }

    return true;
}

std::string sortString(const std::string &str) {
    std::string sortedStr = str;
    std::sort(sortedStr.begin(), sortedStr.end());
    return sortedStr;
}


int main() {

    int vocabsNum;
    std::vector<std::string> vocabs;
    std::string vocab;

    std::cin >> vocabsNum;
    std::cout<< "총" << vocabsNum << "개의 단어를 입력하실 예정입니다." << std::endl;

    for (size_t i=0; i<vocabsNum; i++) {
        std::cin >> vocab;
        vocabs.push_back(vocab);
    }

    std::unordered_map<std::string, std::vector<std::string> > group;

    std::cout<< "입력하신 단어들은 다음과 같습니다." << std::endl;
    for (size_t i=0; i<vocabs.size(); i++) {
        
        std::string sorted = sortString(vocabs[i]);
        std::cout<< sorted << std::endl;

        group[sorted].push_back(vocabs[i]);
    }

    // all group :
    std::cout<< "총 그룹 수: " << group.size() << std::endl;


    return 0;
}