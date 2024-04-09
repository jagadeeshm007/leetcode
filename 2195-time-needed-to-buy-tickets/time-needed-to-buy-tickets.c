int timeRequiredToBuy(int* tickets, int ticketsSize, int k) {
    if(tickets[k]<=0) return 0;
    int ans=0;
    for(int i=0;i<ticketsSize;i++){
        if(tickets[k]<=0){
            return ans;
        }
        if (tickets[i]>0){
            tickets[i]--;
            ans++;
        }
    }
    return ans + timeRequiredToBuy(tickets,ticketsSize,k);
}