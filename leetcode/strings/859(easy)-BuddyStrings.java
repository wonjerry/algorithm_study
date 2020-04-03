/**
 * 두 String이 주어졌을 때, 어떤 character 두개를 swap해서 같은 String이 되면 true
 *
 * 뭔가 어렵게 생각해가지고 처음에는 for문을 돌다가 틀린부분을 만나면 그 char와 같은 char를 만날때까지 for문을 더 돌리고
 * 찾았을때 맞는지 아닌지, 그 인덱스까지 가는 도중 또 다른게 없는지 등을 체크했다... 너무 더러워!!!
 *
 * 솔루션을 보니, for문을 돌면서 다른 char가 나왔을 때 index를 저장하고 또 다른 부분이 나와야 하니까 그걸 체크해서
 * 결론적으로 A[firstIndex] == B[secondIndex] && B[firstIndex] == A[secondIndex] 를 체크한다!
 *
 * index만 잘 추적하면서 다루면 깔끔하게 풀리는 문제
 */

public class BuddyStrings {
  public static void main(String[] args) {
  System.out.println(buddyStrings("", "aa"));
  }

  public static boolean buddyStrings(String A, String B) {
    if (A.length() != B.length() || A.isEmpty()) {
      return false;
    }

    int length = A.length();
    int firstIndex = -1, secondIndex = - 1;
    for (int i = 0; i < length; i++) {
      if (A.charAt(i) != B.charAt(i)) {
        if (firstIndex == -1) {
          firstIndex = i;
        } else if (secondIndex == -1) {
          secondIndex = i;
        } else {
          return false;
        }
      }
    }
    if (firstIndex == -1) {
      return A.substring(1).chars().anyMatch((character) -> character == A.charAt(0));
    }
    return secondIndex != -1 && A.charAt(firstIndex) == B.charAt(secondIndex) && B.charAt(firstIndex) == A.charAt(secondIndex);
  }
}
