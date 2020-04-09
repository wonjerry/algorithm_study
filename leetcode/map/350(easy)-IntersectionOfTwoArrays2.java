import java.util.ArrayList;
import java.util.HashMap;


/**
 * nums1, nums2가 중복을 허용한므로 map을 사용하여 구현하였다.
 *
 * 만일 중복이 없다면, 하나만 set에 넣고 contains로 비교하면 된다. set의 contains는 O(1)이기 때문에 효율적이다.
 */
class Solution {
  public int[] intersect(int[] nums1, int[] nums2) {
      HashMap<Integer, Integer> map = new HashMap<>();

  for(int num : nums1) {
    map.putIfAbsent(num, 0);
    map.put(num, map.get(num) + 1);
  }

  ArrayList<Integer> results = new ArrayList<>();
  for (int num : nums2) {
    int value = map.getOrDefault(num, 0);
    if (value == 0) {
      continue;
    }
    results.add(num);
    map.put(num, value - 1);
  }

  return results.stream().mapToInt(value -> value).toArray();
  }
}