class Twitter {

    private static class Tweet {
        int tweetId;
        int time;

        Tweet(int tweetId, int time) {
            this.tweetId = tweetId;
            this.time = time;
        }
    }

    private Map<Integer, Set<Integer>> followMap;
    private Map<Integer, List<Tweet>> tweetMap;
    private int timestamp;

    public Twitter() {
        followMap = new HashMap<>();
        tweetMap = new HashMap<>();
        timestamp = 0;
    }

    public void postTweet(int userId, int tweetId) {
        tweetMap.putIfAbsent(userId, new ArrayList<>());
        tweetMap.get(userId).add(new Tweet(tweetId, timestamp++));
    }

    public List<Integer> getNewsFeed(int userId) {
        PriorityQueue<Tweet> pq = new PriorityQueue<>((a, b) -> b.time - a.time);

        
        if (tweetMap.containsKey(userId)) {
            pq.addAll(tweetMap.get(userId));
        }

        
        Set<Integer> followees = followMap.getOrDefault(userId, new HashSet<>());
        for (int followeeId : followees) {
            if (tweetMap.containsKey(followeeId)) {
                pq.addAll(tweetMap.get(followeeId));
            }
        }

        List<Integer> feed = new ArrayList<>();
        int count = 0;
        while (!pq.isEmpty() && count < 10) {
            feed.add(pq.poll().tweetId);
            count++;
        }
        return feed;
    }

    public void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return; 
        followMap.putIfAbsent(followerId, new HashSet<>());
        followMap.get(followerId).add(followeeId);
    }

    public void unfollow(int followerId, int followeeId) {
        if (followMap.containsKey(followerId)) {
            followMap.get(followerId).remove(followeeId);
        }
    }
}
