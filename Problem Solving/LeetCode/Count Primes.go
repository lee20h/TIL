package leetcode

func countPrimes(n int) int {
	isPrime := make([]bool, n)

	for i := 2; i*i < n; i++ {
		if isPrime[i] == true {
			continue
		}
		for j := i * i; j < n; j += i {
			isPrime[j] = true
		}
	}

	cnt := 0
	for i := 2; i < n; i++ {
		if isPrime[i] == false {
			cnt++
		}
	}
	return cnt
}