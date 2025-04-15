public class Solution {
    public NestedInteger deserialize(String s) {
        Object parsed = parse(s);
        return dfs(parsed);
    }

    private Object parse(String s) {
        if (s.charAt(0) == '[') {
            List<Object> list = new ArrayList<>();
            int start = 1, depth = 0;
            for (int i = 1; i < s.length(); i++) {
                if (s.charAt(i) == '[') depth++;
                else if (s.charAt(i) == ']') depth--;
                else if (s.charAt(i) == ',' && depth == 0) {
                    list.add(parse(s.substring(start, i)));
                    start = i + 1;
                }
            }
            if (start < s.length() - 1) list.add(parse(s.substring(start, s.length() - 1)));
            return list;
        } else {
            return Integer.parseInt(s);
        }
    }

    private NestedInteger dfs(Object input) {
        if (input instanceof Integer) {
            return new NestedInteger((int) input);
        }
        NestedInteger ni = new NestedInteger();
        for (Object obj : (List<Object>) input) {
            ni.add(dfs(obj));
        }
        return ni;
    }
}
