class Solution {
    public int lengthLongestPath(String input) {
        String[] parts = input.split("\n");
        Map<Integer, Integer> levelLength = new HashMap<>();
        int maxLength = 0;

        for (String part : parts) {
            int level = part.lastIndexOf('\t') + 1;
            String name = part.substring(level);
            int length = name.length();

            if (part.contains(".")) {
                maxLength = Math.max(maxLength, levelLength.getOrDefault(level - 1, 0) + length);
            } else {
                levelLength.put(level, levelLength.getOrDefault(level - 1, 0) + length + 1);
            }
        }

        return maxLength;
    }
}
