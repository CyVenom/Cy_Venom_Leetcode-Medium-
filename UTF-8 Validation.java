class Solution {
    public boolean validUtf8(int[] data) {
        int remainingBytes = 0;

        for (int num : data) {
            // Only use the least significant 8 bits
            int byteVal = num & 0xFF;

            if (remainingBytes == 0) {
                if ((byteVal >> 7) == 0b0) {
                    remainingBytes = 0; // 1-byte char
                } else if ((byteVal >> 5) == 0b110) {
                    remainingBytes = 1; // 2-byte char
                } else if ((byteVal >> 4) == 0b1110) {
                    remainingBytes = 2; // 3-byte char
                } else if ((byteVal >> 3) == 0b11110) {
                    remainingBytes = 3; // 4-byte char
                } else {
                    return false; // Invalid leading byte
                }
            } else {
                if ((byteVal >> 6) != 0b10) {
                    return false; // Not a valid continuation byte
                }
                remainingBytes--;
            }
        }

        return remainingBytes == 0;
    }
}
