bool isValid(char* s) {
    int l=strlen(s);
    int j[l], k = 0;
    for(int i = 0; i < l ; i++) {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
            j[k] = i;
            k++;
        }
        else if(s[i] == ')') {
            if(k == 0 || s[j[k - 1]] != '(') {
                return false;
            }
            k--;
        }
        else if(s[i] == '}') {
            if(k == 0 || s[j[k - 1]] != '{') {
                return false;
            }
            k--;
        }
        else if(s[i] == ']') {
            if(k == 0 || s[j[k - 1]] != '[') {
                return false;
            }
            k--;
        }
    }
    return k == 0;
}