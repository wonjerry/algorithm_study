import java.util.HashSet;

class Solution {
  // 겹치는 부분을 찾으려면, 지금 겹치는 부분에 대해서, 중복을 허용하지는 않는 것 같다.
  // set으로 nums1의 원소를 모두 넣어두고, nums2 원소도 set에 넣은 다음에, contains로 비교를 하면 되지 않을까 생각한다.
  public int[] intersection(int[] nums1, int[] nums2) {
      HashSet<Integer> set1 = new HashSet<>();
      HashSet<Integer> set2 = new HashSet<>();

      for(int num : nums1) {
          set1.add(num);
      }

      for(int num : nums2) {
          set2.add(num);
      }

      return set1.stream().filter(element -> set2.contains(element)).mapToInt(element -> element).toArray();
  }
}