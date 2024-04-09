bool isPalindrome(int x) {
    if(x<0) return false;
    long long rev=0,cp=x;
    while(cp){
        rev= (rev*10) +cp%10;
        cp=cp/10;
    }
    return rev==x;
}