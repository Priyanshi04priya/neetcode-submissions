class Twitter {
public:
    int order=0;
    unordered_map<int,vector<pair<int,int>>> u_tid;
    unordered_map<int,unordered_set<int>> u_following;

    Twitter() {
        int order=0;
    }
    
    void postTweet(int userId, int tweetId) {
        u_tid[userId].push_back({order++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        //recent 10 elements
        // max-heap: {time, tweetId}
        priority_queue<pair<int,int>> pq;
        u_following[userId].insert(userId);

        for (int followeeId : u_following[userId]) {
            auto& tweets = u_tid[followeeId];
            // sirf last 10 tweets is user ke consider karna kaafi hai (optimization)
            int n = tweets.size();
            for (int i = max(0, n-10); i < n; i++) {
                pq.push(tweets[i]);
            }
        }

        vector<int> result;
        while (!pq.empty() && result.size() < 10) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId) u_following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
       u_following[followerId].erase(followeeId);
    }
};
