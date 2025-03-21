#You have information about n different recipes. You are given a string array recipes and a 2D string array ingredients. The ith recipe has the name recipes[i], and you can create it if you have all the needed ingredients from ingredients[i]. A recipe can also be an ingredient for other recipes, i.e., ingredients[i] may contain a string that is in recipes.
#You are also given a string array supplies containing all the ingredients that you initially have, and you have an infinite supply of all of them.
#Return a list of all the recipes that you can create. You may return the answer in any order.
#Note that two recipes may contain each other in their ingredients.

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> supplySet(supplies.begin(), supplies.end());
        unordered_map<string, int> inDegree;
        unordered_map<string, vector<string>> graph;
        
        
        for (int i = 0; i < recipes.size(); i++) {
            inDegree[recipes[i]] = ingredients[i].size();  
            for (const string& ing : ingredients[i]) {
                graph[ing].push_back(recipes[i]);  
            }
        }
        
        queue<string> q;
        for (const string& s : supplies) {
            q.push(s);  
        }
        
        vector<string> result;
        while (!q.empty()) {
            string current = q.front();
            q.pop();
            
            
            if (inDegree.count(current)) {
                result.push_back(current);
            }
            
            for (const string& recipe : graph[current]) {
                inDegree[recipe]--;
                if (inDegree[recipe] == 0) {
                    q.push(recipe);  
                }
            }
        }
        
        return result;
    }
};
