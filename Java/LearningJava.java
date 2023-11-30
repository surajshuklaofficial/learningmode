public class LearningJava extends B implements C {
    static int factorial(int num) {
        if (num == 1) {
            return 1;
        }
        return num * factorial(num - 1);
    }

    static boolean checkPalindrome(String word) {
        for (int left = 0, right = word.length() - 1; left <= right; left++, right--) {
            if (word.charAt(left) != word.charAt(right)) {
                return false;
            }
        }
        return true;
    }

    static boolean checkPrime(int num) {
        for (int i = 2; i < num / 2; i++) {
            if (num % i == 0)  return false;
        }
        return true;
    }

    static void fibonacci(int num) {
        System.out.printf("%d ", 0);
        for (int i = 0, i1 = 0, i2 = 1; i < num - 1; i++) {
            int i3 = i1 + i2;
            i1 = i2;
            i2 = i3;
            System.out.printf("%d ", i3);
        }
        System.err.println();
    }

    static int addElements(int[] nums) {
        int sum = 0;
        for (int i: nums) {
            sum += i;
        }

        return sum;
    }

    static int maxElement(int[] nums) {
        int max = Integer.MIN_VALUE;
        for (int i: nums) {
            if (max < i) {
                max = i;
            }
        }

        return max;
    }

    static int simpleDiv(int a, int b) {
        if (b == 0) throw.ArithmaticException("Can't Divide by 0");
    }

    public static void main(String[] args) {
        System.out.println(checkPalindrome("madam"));
        System.out.println(factorial(5));
        System.out.println(checkPrime(1));
        fibonacci(5);

        int[] nums = {1, -29, 3, 4, 5};
        System.out.println(addElements(nums));
        System.out.println(maxElement(nums));
    }

}
