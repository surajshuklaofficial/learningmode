bool checkInclusion(string s1, string s2) {
        int matching = 0;
        string temp = s1;

        if (s1.size() > s2.size()) return false;
        for (int z = 0; z < s2.size() - s1.size() + 1; z++) {
            for (int i = z; i < s1.size() + z ; i++) {
                for (int j = 0; j < temp.size(); j++) {
                    cout << s2[i] << endl;
                    if (temp[j] == s2[i]) {
                        matching++;
                        temp.erase(j, 1);
                    } 
                } 
                if (matching == 0) break;
            } 
            if (matching == s1.size()) return true;
            matching = 0;
            temp = s1;
        }

        return false;
    }