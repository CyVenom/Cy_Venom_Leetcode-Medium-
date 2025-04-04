class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        List<List<Integer>> graph = new ArrayList<>();
        int[] indegree = new int[numCourses];
        
        for (int i = 0; i < numCourses; i++) {
            graph.add(new ArrayList<>());
        }

        for (int[] pair : prerequisites) {
            graph.get(pair[1]).add(pair[0]);
            indegree[pair[0]]++;
        }

        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                queue.offer(i);
            }
        }

        List<Integer> result = new ArrayList<>();
        while (!queue.isEmpty()) {
            int course = queue.poll();
            result.add(course);
            for (int next : graph.get(course)) {
                if (--indegree[next] == 0) {
                    queue.offer(next);
                }
            }
        }

        if (result.size() == numCourses) {
            int[] order = new int[numCourses];
            for (int i = 0; i < numCourses; i++) {
                order[i] = result.get(i);
            }
            return order;
        } else {
            return new int[0];
        }
    }
}
