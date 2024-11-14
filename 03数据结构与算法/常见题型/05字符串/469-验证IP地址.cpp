class Solution {
public:
    string validIPAddress(string queryIP) {
        vector<string> ip;
        if(queryIP.find('.') != string::npos) {
            ip = split(queryIP, '.');
            return parser_ipv4(ip) ? "IPv4" : "Neither";
        } else {
            ip = split(queryIP, ':');
            return parser_ipv6(ip) ? "IPv6" : "Neither"; 
        }
    }

    bool parser_ipv4(vector<string> ip) {
        if(ip.size() != 4) return false;
        for(string s : ip) {
            // 子段长度
            if(s.size() == 0 || s.size() > 3) 
                return false;
            // 有不是数字的字符
            for(char c : s) {
                if(!isdigit(c))
                    return false;
            }
            // 前导零或大于255
            if(stoi(s) > 255 || s.size() >= 2 && s[0] == '0')
                return false;
        }
        return true;
    }

    bool parser_ipv6(vector<string> ip) {
        if(ip.size() != 8) return false;
        for(string s : ip) {
            // 子段长度
            if(s.size() == 0 || s.size() > 4) 
                return false;
            // 有非法字符
            for(char c : s) {
                if(!(c >= '0' && c <= '9' || c >= 'a' && c <= 'f' || c >= 'A' && c <= 'F'))
                    return false;
            }
        }
        return true;
    }

    vector<string> split(string &s, char delimiter) {
        int l = 0;
        vector<string> res;
        for(int r = 0; r < s.size(); ++r) {
            if(s[r] == delimiter) {
                res.push_back(s.substr(l, r - l));
                l = r + 1;
            }
        }

        res.push_back(s.substr(l, s.size() - l));
        return res;
    }
};