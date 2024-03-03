
class Twitter {
public:
    unordered_map<int , unordered_set<int>>friends;
    priority_queue<vector<int>>timeline;
    int t;
    Twitter() {
        t = 0;
    }

    void postTweet(int userId, int tweetId) {
        timeline.push({t , userId , tweetId});
        t++;
    }

    vector<int> getNewsFeed(int userId) {
        vector<int>ans;
        priority_queue<vector<int>>tmp=timeline;
        int n=0;
        while(!tmp.empty() && n<10 ){
            auto top = tmp.top();
            tmp.pop();
            if(top[1]==userId){

                ans.push_back(top[2]);
                 n++;
            }
    else if (friends[userId].find(top[1])!=friends[userId].end()){

                ans.push_back(top[2]);
     n++;
            }



    }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        friends[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        friends[followerId].erase(followeeId);
    }
};
