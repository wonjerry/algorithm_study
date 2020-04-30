var dominantIndex = function(nums) {
  const sortedArray = Array.from(nums).sort((a, b) => a - b)
  const largestNumber = sortedArray[sortedArray.length - 1]
  const secondLargestNumber = sortedArray[sortedArray.length - 2]
  if (!secondLargestNumber || largestNumber >= secondLargestNumber * 2) {
    return Array.from(nums).findIndex((value, index) => value === largestNumber)
  }
  return -1
};

// 정렬을 통해 크기 비교를 하여 O(NlogN)의 시간복잡도가 걸렸다.
// 좀 더 개선을 위해서 Linear search를 통해 가장 큰 수와 두번째 큰수를 찾아도 좋고, 가장큰수와 모든 수를 비교해도 좋겠다.