class Twitter {
private:
    long long timeStamp;
    vector<vector<pair<long long,int>>> tweets;
    vector<unordered_set<int>> following;

public:

    Twitter() {
        // write your code here 
        timeStamp = 0;
        tweets.resize(501);
        following.resize(501);
    }

    void postTweet(int userId, int tweetId) {
        // write your code here 
        tweets[userId].push_back({timeStamp, tweetId});
        timeStamp++;
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<long long, int>> pq;
        for(auto &p: tweets[userId]) {
            pq.push(p);
        }

        for(auto &f: following[userId]) {
            for(auto &t: tweets[f]) {
                pq.push(t);
            }
        }
        int cnt = 0;
        vector<int> ans;
        while(!pq.empty() && cnt < 10) {
            ans.push_back(pq.top().second);
            pq.pop();
            cnt++;
        }
        return ans;
    }

    void follow(int followerId, int followeeId) {
        // write your code here 
        if(followeeId == followerId) return;
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        // write your code here 
        if(followeeId == followerId) return;
        following[followerId].erase(followeeId);
    }
};
