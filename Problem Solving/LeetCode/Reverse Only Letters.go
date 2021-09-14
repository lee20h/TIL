package leetcode

func reverseOnlyLetters(s string) string {
	runes := []rune(s)

	for i, j := 0, len(runes)-1; i < j; {
		flag := false
		if 65 > int(runes[i]) || (int(runes[i]) > 90 && 97 > int(runes[i])) || 122 < int(runes[i]) {
			i++
			flag = true
		}
		if 65 > int(runes[j]) || (int(runes[j]) > 90 && 97 > int(runes[j])) || 122 < int(runes[j]) {
			j--
			flag = true
		}
		if flag {
			continue
		}

		runes[i], runes[j] = runes[j], runes[i]
		i, j = i+1, j-1
	}
	return string(runes)
}
