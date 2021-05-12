package leetcode

type NumMatrix struct {
	Data [][]int
	Sum  [][]int
}

func Constructor(matrix [][]int) NumMatrix {
	d := NumMatrix{Data: matrix, Sum: make([][]int, len(matrix)+1)}
	if len(matrix) == 0 || len(matrix[0]) == 0 {
		return d
	}
	d.Sum[0] = make([]int, len(matrix[0])+1)
	for i := 1; i <= len(matrix); i++ {
		d.Sum[i] = make([]int, len(matrix[0])+1)
		for j := 1; j <= len(matrix[0]); j++ {
			d.Sum[i][j] = d.Sum[i-1][j] + d.Sum[i][j-1] - d.Sum[i-1][j-1] + d.Data[i-1][j-1]
		}
	}
	return d
}

func (this *NumMatrix) SumRegion(row1 int, col1 int, row2 int, col2 int) int {
	return this.Sum[row2+1][col2+1] - this.Sum[row1][col2+1] - this.Sum[row2+1][col1] + this.Sum[row1][col1]
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * obj := Constructor(matrix);
 * param_1 := obj.SumRegion(row1,col1,row2,col2);
 */