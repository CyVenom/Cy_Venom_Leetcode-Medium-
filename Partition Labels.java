class Solution {
    public List<Integer> partitionLabels(String s) {
        List<Integer> result = new ArrayList<>();
        int[] lastIndex = new int[26]; // Store last occurrence of each character
        
        // Step 1: Fill lastIndex array
        for (int i = 0; i < s.length(); i++) {
            lastIndex[s.charAt(i) - 'a'] = i;
        }

        // Step 2: Iterate and partition
        int start = 0, end = 0;
        for (int i = 0; i < s.length(); i++) {
            end = Math.max(end, lastIndex[s.charAt(i) - 'a']); // Extend partition
            
            if (i == end) { // If current index reaches partition end
                result.add(end - start + 1);
                start = i + 1; // Start new partition
            }
        }
        
        return result;
    }
}
