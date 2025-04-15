class Solution {
    private ListNode head;
    private Random rand;

    public Solution(ListNode head) {
        this.head = head;
        this.rand = new Random();
    }

    public int getRandom() {
        int result = head.val;
        ListNode current = head.next;
        int i = 2;

        while (current != null) {
            if (rand.nextInt(i) == 0) {
                result = current.val;
            }
            current = current.next;
            i++;
        }

        return result;
    }
}
