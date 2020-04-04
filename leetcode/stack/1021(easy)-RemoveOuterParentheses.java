import java.util.Stack;

public class RemoveOutermostParentheses {
  public static void main(String[] args) {
    System.out.println(removeOuter("()()"));
  }

  public static String removeOuter(String s) {
    Stack<Character> stack = new Stack<Character>();
    StringBuilder stringBuilder = new StringBuilder("");

    int start = -1;
    int end = -1;

    for (int i = 0; i < s.length(); i++) {
      if (s.charAt(i) == '(') {
        if (stack.isEmpty()) {
          start = i;
        }
        stack.push(s.charAt(i));
      } else {
        if (stack.size() == 1) {
          end = i;
        }
        stack.pop();
      }

      if (start != -1 && end != -1) {
        stringBuilder.append(s.substring(start + 1, end));
        start = end = -1;
      }
    }

    return stringBuilder.toString();
  }
}
