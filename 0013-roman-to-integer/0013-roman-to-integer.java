class Solution {
    public enum Roman {
        I(0, 1),
        V(1, 5),
        X(2, 10),
        L(3, 50),
        C(4, 100),
        D(5, 500),
        M(6, 1000);
        private int priority, value;
        Roman(int priority, int value) {
            this.priority = priority;
            this.value = value;
        }
        public int getValue() {
            return value;
        }
        public int getPriority() {
            return priority;
        }
    };
    public int romanToInt(String s) {
        int res = 0;
        int i = s.length()-1;
        while (i >= 0) {
            if (i != 0 && Roman.valueOf(""+s.charAt(i)).getPriority() > Roman.valueOf(""+s.charAt(i-1)).getPriority()) {
                res += Roman.valueOf(""+s.charAt(i)).getValue() - Roman.valueOf(""+s.charAt(i-1)).getValue();
                i -= 2;
            } else {
                res += Roman.valueOf(""+s.charAt(i)).getValue();
                i--;
            }
        }
        return res;
    }
}
