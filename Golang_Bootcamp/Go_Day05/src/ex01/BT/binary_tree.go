package BT
 
import (
	"fmt"
	"os"
	"io"
)
 
type TreeNode struct {
	HasToy bool
	Left  *TreeNode
	Right *TreeNode
}
 
type BinaryTree struct {
	Root *TreeNode
}

func print(w io.Writer, node *TreeNode, ns int, ch rune) {
	if node == nil {
		return
	}

	for i := 0; i < ns; i++ {
		fmt.Fprint(w, " ")
	}
	fmt.Fprintf(w, "%c:%v\n", ch, node.HasToy)
	print(w, node.Left, ns+2, 'L')
	print(w, node.Right, ns+2, 'R')
}

func PrintTree(node *TreeNode) {
  print(os.Stdout, node, 0, 'M')
}

func countTrueNodes(node *TreeNode) int {
	if node == nil {
		return 0
	}
	count := 0
	if node.HasToy {
		count++
	}
	count += countTrueNodes(node.Left)
	count += countTrueNodes(node.Right)
	return count
}

func (t *BinaryTree) AreToysBalanced() bool {
	countLeftNode := countTrueNodes(t.Root.Left)
	countRightNode := countTrueNodes(t.Root.Right)
	if (countLeftNode == countRightNode) {
		return true
	}
	return false
}

func UnrollGarland(Root *TreeNode) {
  if Root == nil {
      return
  }

  stack1 := []*TreeNode{Root}
  stack2 := []*TreeNode{}

  leftToRight := false // Флаг для определения направления обхода

  for len(stack1) > 0 {
    node := stack1[len(stack1)-1] // Извлекаем верхний узел из первого стека
    stack1 = stack1[:len(stack1)-1] // Убираем его из стека

    fmt.Printf("%v ", node.HasToy)

    if leftToRight {
      // Если обход слева направо, добавляем левого потомка, затем правого
      if node.Left != nil {
        stack2 = append(stack2, node.Left)
      }
      if node.Right != nil {
        stack2 = append(stack2, node.Right)
      }
    } else {
      // Если обход справа налево, добавляем правого потомка, затем левого
      if node.Right != nil {
        stack2 = append(stack2, node.Right)
      }
      if node.Left != nil {
        stack2 = append(stack2, node.Left)
      }
    }

    // Если первый стек опустел, меняем направление и переключаем стеки
    if len(stack1) == 0 {
      leftToRight = !leftToRight
      stack1, stack2 = stack2, stack1
    }
  }
  fmt.Println()
}
