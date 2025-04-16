class Solution {
    public String removeKdigits(String num, int k) {
        Stack<Character> stack = new Stack<>();
        
        for (char digit : num.toCharArray()) {
            while (k > 0 && !stack.isEmpty() && stack.peek() > digit) {
                stack.pop();
                k--;
            }
            stack.push(digit);
        }
        
       
        while (k > 0) {
            stack.pop();
            k--;
        }
        
        
        StringBuilder result = new StringBuilder();
        for (char digit : stack) {
            result.append(digit);
        }
        
        
        int start = 0;
        while (start < result.length() && result.charAt(start) == '0') {
            start++;
        }
        
        result = new StringBuilder(result.substring(start));
        
        
        return result.length() == 0 ? "0" : result.toString();
    }
}
