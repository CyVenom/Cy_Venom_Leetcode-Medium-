class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int totalGas = 0, totalCost = 0, tank = 0;
        int startStation = 0;
        
        for (int i = 0; i < gas.length; i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            tank += gas[i] - cost[i];
            
            // If tank goes negative, reset starting point
            if (tank < 0) {
                startStation = i + 1; // Move to next station
                tank = 0; // Reset tank
            }
        }
        
        return totalGas >= totalCost ? startStation : -1;
    }
}
