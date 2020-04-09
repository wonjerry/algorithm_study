public class Sqrt {
  public int mySqrt(int x) {
    long left = 0;
    long right = x;
    long mid = 0;

    while(left <= right) {
      mid = (left + right) / 2;
      long sqrt = mid * mid;

      if (x == sqrt) {
        return (int)mid;
      }

      if (x < sqrt) {
        right = mid - 1;
      }

      if (x > sqrt) {
        left = mid + 1;
      }
    }

    if (left * left < x) {
      return (int)left;
    }

    return (int)right;
  }
}
