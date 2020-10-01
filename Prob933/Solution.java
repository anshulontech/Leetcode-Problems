// Approach 1:-

class RecentCounter {
    
    private Queue<Integer> q;

    public RecentCounter() {
        q = new LinkedList<Integer>();
    }
    
    public int ping(int t) {
        q.add(t);
        
        while((t-q.peek())>3000)
            q.poll();
        
        return q.size();
    }
}