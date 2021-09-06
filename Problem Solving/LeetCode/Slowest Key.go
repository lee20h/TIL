package leetcode

func slowestKey(releaseTimes []int, keysPressed string) byte {
	max := releaseTimes[0]
	letter := keysPressed[0]

	for i := 1; i < len(releaseTimes); i++ {
		difference := releaseTimes[i] - releaseTimes[i-1]
		if difference > max {
			max = difference
			letter = keysPressed[i]
		} else if difference == max && keysPressed[i] > letter {
			max = difference
			letter = keysPressed[i]
		}
	}

	return letter
}