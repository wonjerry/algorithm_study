/**
 * 이 문제는 stock의 변동 값을 받았을 때 이전 변동 값들에 대해 자신의 현재 값보다 같거나 작은 가격에 대해
 * 얼만큼의 weight를 가지는가를 계산하는 문제있다.
 *
 * 이전 값들의 history를 다 훑어보는 방법으로는 당연히 풀 수 있으니 시도조차 안했다.
 * Stack인지 알고 있었음에도 풀지 못했던 이유는 **값들 사이의 연관관계(패턴)을 찾지 못했기 때문이다.**
 * 현재 weight가 이전 weight에 대해 어떻게 계산되는지 규칙을 차분하게 찾으면 되는문제!
 */

import java.util.Stack;

public class StockSpanner {
  Stack<Integer> prices;
  Stack<Integer> weights;

  public StackSpanner() {
    prices = new Stack<Integer>();
    weights = new Stack<Integer>();
  }

  public int next(int price) {
    int weight = 1;
    while (!prices.isEmpty() && prices.peek() <= price) {
      prices.pop();
      weight += weights.peek();
      weights.pop();
    }

    prices.push(price);
    weights.push(weight);
    return weight;
  }
}
