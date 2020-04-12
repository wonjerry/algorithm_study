class Solution {
  // peek element는 주변 원소보다 큰 원소를 의미
  // nums의 처음과 끝도 peek이 될 수 있는가?
  // -> 처음과 끝도 peek이 될 수 있다.
  // 답이 없다면??
  public int findPeakElement(int[] nums) {
      for (int i = 0; i < nums.length; i++) {
          // 이전과 현재를 검사해서 감소하는지 체크,
              // 감소한다면 continue;
          // 현재와 다음을 검사해서 증가하는지 체크
              //  증가한다면 continue
          if (checkBoundary(nums.length, i - 1) && nums[i - 1] >= nums[i]) {
              continue;
          }


          if (checkBoundary(nums.length, i + 1) && nums[i] <= nums[i + 1]) {
              continue;
          }

          return i;
      }

      return -1;
  }

  public boolean checkBoundary(int length, int index) {
      return 0 <= index && index < length;
  }
}