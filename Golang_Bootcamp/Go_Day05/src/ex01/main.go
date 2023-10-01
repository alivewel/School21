package main
 
import (
	"ex01/BT"
)
 
func main() {
	tree := &BT.BinaryTree{}

	tree.Root = &BT.TreeNode{HasToy: true}

	tree.Root.Left = &BT.TreeNode{HasToy: false}
	tree.Root.Right = &BT.TreeNode{HasToy: false}

	tree.Root.Left.Left = &BT.TreeNode{HasToy: true}
	tree.Root.Left.Right = &BT.TreeNode{HasToy: true}
	tree.Root.Right.Left = &BT.TreeNode{HasToy: false}
	tree.Root.Right.Right = &BT.TreeNode{HasToy: true}

	tree.Root.Left.Left.Left = &BT.TreeNode{HasToy: true}
	tree.Root.Left.Left.Right = &BT.TreeNode{HasToy: true}
	tree.Root.Left.Right.Left = &BT.TreeNode{HasToy: true}
	tree.Root.Left.Right.Right = &BT.TreeNode{HasToy: true}
	tree.Root.Right.Left.Left = &BT.TreeNode{HasToy: true}
	tree.Root.Right.Left.Right = &BT.TreeNode{HasToy: true}
	tree.Root.Right.Right.Left = &BT.TreeNode{HasToy: false}
	tree.Root.Right.Right.Right = &BT.TreeNode{HasToy: false}

	BT.UnrollGarland(tree.Root)
	// fmt.Println("UnrollGarland", answer)

	// BT.PrintTree(tree.Root)

}
