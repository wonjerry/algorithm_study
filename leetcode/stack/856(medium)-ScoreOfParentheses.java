import java.util.Stack;

/**
 * 이 문제는 괄호와 recursion을 적절히 섞어서 풀어야 한다.
 * 덧셈만 있었다면 뭔가 그냥 리니어하게 풀어도 괜찮겠지만 곱셉이 섞여있기 때문에 사칙연산간의 우선순위가 존재하며
 * 따라서 괄호를 만나면 자식 괄호가 어디까지인지 찾아서 재귀적으로 함수에 넣엇서 scoring을 구한다음 현재 값에 더해준다.
 */

public class ScoreOfParentheses {
  public static int scoring(String s) {
    Stack<Character> stack = new Stack<Character>();
    int start = -1;
    int end = -1;
    int result = 0;
    for(int i = 0; i < s.length(); i ++) {
      if (s.charAt(i) == '(') {
        if (stack.empty()) {
          start = i;
        }
        stack.push('(');
      } else {
        if (stack.size() == 1) {
          end = i;
        }
        stack.pop();
      }

      if (start != -1 && end != -1) {
        if (end - start == 1) {
          result += 1;
        } else {
          result += (scoring(s.substring(start + 1, end)) * 2);
        }
        start = end = -1;
      }
    }

    return result;
  }
}
