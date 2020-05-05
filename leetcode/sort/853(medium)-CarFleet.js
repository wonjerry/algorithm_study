// 이 문제의 해결을 위해서 속도와 시간과 위치가 일차방정식을 이루고, 따라서 교차점이 만나는점이라는 것을
// 잘 계산하여 답을 구했다.
// 알고리즘적 절차 생각은 잘 했으나 만나는 점에 대한 고려가 부족했다.

function carFleet(target, position, speed) {
  // position과 speed를 sorting
  mergeSort(position, speed, 0, position.length - 1)
  // for문을 돌면서 앞 원소와 비교하면서 fleet을 계산
  const fleets = []
  let frontIndex = position.length - 1
  for (let i = position.length - 1; i >= 0; i--) {
    if (i + 1 === position.length) {
      fleets.push(1)
      continue
    }
    const crossingTime = calculateCrossTime(position[frontIndex], speed[frontIndex], position[i], speed[i])
    const crossingPosition = speed[frontIndex] * crossingTime + position[frontIndex]
    if (crossingTime >= 0 && crossingPosition <= target) {
      fleets[fleets.length - 1] += 1
    } else {
      fleets.push(1)
      frontIndex = i
    }

  }
  return fleets.length
}

function calculateCrossTime(positionA, speedA, positionB, speedB) {
  return (positionA - positionB) / (speedB - speedA)
}

function mergeSort(position, speed, start, end) {
  if (start >= end) {
    return
  }
  const mid = Number.parseInt((start + end) / 2)
  mergeSort(position, speed, start, mid)
  mergeSort(position, speed, mid + 1, end)
  merge(position, speed, start, mid, mid + 1, end)
}

function merge(position, speed, start1, end1, start2, end2) {
  let startIndex1 = start1
  let startIndex2 = start2
  let mid = 0
  const positionResult = []
  const speedResult = []
  while (startIndex1 <= end1 && startIndex2 <= end2) {
    mid = Number.parseInt((startIndex1 + startIndex2) / 2)
    if (position[startIndex1] === position[startIndex2]) {
      positionResult.push(position[startIndex1])
      positionResult.push(position[startIndex2])
      speedResult.push(speed[startIndex1++])
      speedResult.push(speed[startIndex2++])
    } else if (position[startIndex1] < position[startIndex2]) {
      positionResult.push(position[startIndex1])
      speedResult.push(speed[startIndex1++])
    } else if (position[startIndex1] > position[startIndex2]) {
      positionResult.push(position[startIndex2])
      speedResult.push(speed[startIndex2++])
    }
  }
  while (startIndex1 <= end1) {
    positionResult.push(position[startIndex1])
    speedResult.push(speed[startIndex1++])
  }

  while (startIndex2 <= end2) {
    positionResult.push(position[startIndex2])
    speedResult.push(speed[startIndex2++])
  }
  for (let i = start1; i <= end2; i++) {
    position[i] = positionResult[i - start1]
    speed[i] = speedResult[i - start1]
  }
}
