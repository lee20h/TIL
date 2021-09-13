package leetcode

func maxNumberOfBalloons(text string) int {

	a := make([]int, 26)
	b := "balloon"
	c := 0
	tmp := 0

	for _, v := range text {
		a[v-'a']++
	}
	for {
		for _, v := range b {
			a[v-'a']--
			if a[v-'a'] < 0 {
				return c
			}
			tmp++
			if tmp == len(b) {
				tmp = 0
				c++
			}
		}
	}
}