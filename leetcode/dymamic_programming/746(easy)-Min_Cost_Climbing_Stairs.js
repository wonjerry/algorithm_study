/*
  문제가 애매한데 각 스탭에 드는 cost 배열이 있고, 우리는 cost.length 인덱스까지 도달하는데에 걸리는 최소 cost를 구하는 것이다.

  단순하게 처음 생각은 현재 K번째 step에 있으며, k+1, k+2번째로 가는데, 어디로 가야 적게 비용이 드나를 생각했다.
  하지만 k+3에 뭐가 있느냐도 하나의 변수로 작용하기 때문에 이 방식은 쉽지 않은 풀이법이다.

  거꾸로 생각해서 K번째까지 오기까지 K-1, K-2 번째 step을 밟았을 것이며, K-1, K-2 step 각각의 최소 cost를 구했을 것이다.
  즉 K번째의 cost = min(K-1번째까지의 min cost, K-2번째까지의 min cost) + cost[k]를 구하면 된다.
*/

let step = []

var minCostClimbingStairs = function(cost) {
    step = [cost[0], cost[1]]
    return Math.min(checkNthStepCost(cost, cost.length - 1), checkNthStepCost(cost, cost.length - 2))
};

var checkNthStepCost = function(cost, n) {
    if (step[n] !== undefined) return step[n]
    return step[n] = Math.min(checkNthStepCost(cost, n - 1), checkNthStepCost(cost, n - 2)) + cost[n]
}