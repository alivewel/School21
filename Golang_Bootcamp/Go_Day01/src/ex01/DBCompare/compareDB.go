package CompareDB

import (
	"fmt"
	"ex01/Dbreader"
)

func CompareRecipesName(recipesOld *Dbreader.Recipes, recipesNew *Dbreader.Recipes) {
	processedCakes := make(map[string]bool)
	removedCakes := make(map[string]bool)

	// Обрабатываем кексы из recipesOld и помечаем их как обработанные
	for _, cake := range recipesOld.Cakes {
		processedCakes[cake.Name] = true
	}
	// Обрабатываем кексы из recipesNew и помечаем их как обработанные
	for _, cake := range recipesNew.Cakes {
		removedCakes[cake.Name] = true
	}

	for _, cake := range recipesNew.Cakes {
		if !processedCakes[cake.Name] {
			fmt.Println("ADDED cake", cake.Name)
		}
	}
	for _, cake := range recipesOld.Cakes {
		if !removedCakes[cake.Name] {
			fmt.Println("REMOVED cake", cake.Name)
		}
	}
}

func CompareRecipesIngredients(cakeOld Dbreader.Cake, cakeNew Dbreader.Cake) {
	addIngredientsMap := make(map[string]bool)
	removedIngredientsMap := make(map[string]bool)

	// Обрабатываем кексы из recipesOld и помечаем их как обработанные
	for _, ingredient := range cakeOld.Ingredients {
		addIngredientsMap[ingredient.ItemName] = true
	}
	// Обрабатываем кексы из recipesNew и помечаем их как обработанные
	for _, ingredient := range cakeNew.Ingredients {
		removedIngredientsMap[ingredient.ItemName] = true
	}
	for _, ingredient := range cakeNew.Ingredients {
		if !addIngredientsMap[ingredient.ItemName] {
			fmt.Printf("ADDED ingredient \"%s\" for cake \"%s\"\n", ingredient.ItemName, cakeNew.Name)
		}
	}
	for _, ingredient := range cakeOld.Ingredients {
		if !removedIngredientsMap[ingredient.ItemName] {
			fmt.Printf("REMOVED ingredient \"%s\" for cake \"%s\"\n", ingredient.ItemName, cakeOld.Name)
		}
	}
}

func CompareRecipesItemCount(cakeOld Dbreader.Cake, cakeNew Dbreader.Cake) {
	for _, ingredientOld := range cakeOld.Ingredients {
		for _, ingredientNew := range cakeNew.Ingredients {
			if ingredientOld.ItemName == ingredientNew.ItemName && ingredientOld.ItemCount != ingredientNew.ItemCount {
				fmt.Printf("CHANGED unit count for ingredient \"%s\" for cake \"%s\" - \"%.1f\" instead of \"%.1f\"\n", ingredientOld.ItemName, cakeOld.Name, ingredientNew.ItemCount, ingredientOld.ItemCount)
			}
		}
	}
}

func CompareRecipesItemUnit(cakeOld Dbreader.Cake, cakeNew Dbreader.Cake) {
	for _, ingredientOld := range cakeOld.Ingredients {
		for _, ingredientNew := range cakeNew.Ingredients {
			if ingredientOld.ItemName == ingredientNew.ItemName && ingredientOld.ItemUnit != ingredientNew.ItemUnit {
				// CHANGED unit for ingredient "Flour" for cake  "Red Velvet Strawberry Cake" - "mugs" instead of "cups"
				fmt.Printf("CHANGED unit for ingredient \"%s\" for cake \"%s\" - \"%s\" instead of \"%s\"\n", ingredientOld.ItemName, cakeOld.Name, ingredientNew.ItemUnit, ingredientOld.ItemUnit)
			}
		}
	}
}

func CompareRecipesItemUnitAddRemove(cakeOld Dbreader.Cake, cakeNew Dbreader.Cake) {
	addItemUnitMap := make(map[string]bool)
	removedItemUnitMap := make(map[string]bool)

	// Обрабатываем кексы из recipesOld и помечаем их как обработанные
	for _, ingredient := range cakeOld.Ingredients {
		addItemUnitMap[ingredient.ItemUnit] = true
	}
	// Обрабатываем кексы из recipesNew и помечаем их как обработанные
	for _, ingredient := range cakeNew.Ingredients {
		removedItemUnitMap[ingredient.ItemUnit] = true
	}
	// REMOVED unit "tablespoons" for ingredient "Vanilla extract" for cake  "Red Velvet Strawberry Cake"
	for _, ingredient := range cakeNew.Ingredients {
		if !addItemUnitMap[ingredient.ItemUnit] {
			fmt.Printf("ADDED unit \"%s\" for ingredient \"%s\" for cake \"%s\"\n", ingredient.ItemUnit, ingredient.ItemName, cakeOld.Name)
		}
	}
	for _, ingredient := range cakeOld.Ingredients {
		if !removedItemUnitMap[ingredient.ItemUnit] {
			fmt.Printf("REMOVED unit \"%s\" for ingredient \"%s\" for cake \"%s\"\n", ingredient.ItemUnit, ingredient.ItemName, cakeOld.Name)
		}
	}
}

func CompareRecipes(recipesOld *Dbreader.Recipes, recipesNew *Dbreader.Recipes) {
	for _, cakeOld := range recipesOld.Cakes {
		for _, cakeNew := range recipesNew.Cakes {
			if cakeOld.Name == cakeNew.Name && cakeOld.StoveTime != cakeNew.StoveTime {
				fmt.Printf("CHANGED cooking time for cake \"%s\" - \"%s\" instead of \"%s\"\n", cakeOld.Name, cakeNew.StoveTime, cakeOld.StoveTime)
			}
			if cakeNew.Name == cakeOld.Name {
				CompareRecipesIngredients(cakeOld, cakeNew)
				CompareRecipesItemCount(cakeOld, cakeNew)
				CompareRecipesItemUnit(cakeOld, cakeNew)
				CompareRecipesItemUnitAddRemove(cakeOld, cakeNew)
				break
			}
		}
	}
}
