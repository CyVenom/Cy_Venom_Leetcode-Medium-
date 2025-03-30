1.Solution Using DFS Approach 

class Solution {
    private Map<Node, Node> cloneMap = new HashMap<>();

    public Node cloneGraph(Node node) {
        if (node == null) return null;
        return dfs(node);
    }

    private Node dfs(Node node) {
        if (cloneMap.containsKey(node)) {
            return cloneMap.get(node);
        }

        // Clone the node
        Node clone = new Node(node.val);
        cloneMap.put(node, clone);

        // Clone the neighbors recursively
        for (Node neighbor : node.neighbors) {
            clone.neighbors.add(dfs(neighbor));
        }

        return clone;
    }
}

2. Solution Using BFS Approach

class Solution {
    public Node cloneGraph(Node node) {
        if (node == null) return null;

        Map<Node, Node> cloneMap = new HashMap<>();
        Queue<Node> queue = new LinkedList<>();

        // Clone the first node and add it to the map
        Node clone = new Node(node.val);
        cloneMap.put(node, clone);
        queue.add(node);

        while (!queue.isEmpty()) {
            Node curr = queue.poll();

            for (Node neighbor : curr.neighbors) {
                if (!cloneMap.containsKey(neighbor)) {
                    cloneMap.put(neighbor, new Node(neighbor.val));
                    queue.add(neighbor);
                }
                // Add cloned neighbor to the cloned node's neighbors list
                cloneMap.get(curr).neighbors.add(cloneMap.get(neighbor));
            }
        }

        return clone;
    }
}



