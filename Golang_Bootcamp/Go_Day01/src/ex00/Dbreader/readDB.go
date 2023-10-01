package Dbreader

import (
	"encoding/xml"
  "encoding/json"
	"fmt"
  "os"
  "io/ioutil"
)

type Recipes struct {
	XMLName xml.Name `xml:"recipes" json:"-"`
	Cakes   []Cake   `xml:"cake" json:"cake"`
}

type Cake struct {
	Name        string       `xml:"name" json:"name"`
	StoveTime   string       `xml:"stovetime" json:"time"`
	Ingredients []Ingredient `xml:"ingredients>item" json:"ingredients"`
}

type Ingredient struct {
	ItemName  string  `xml:"itemname" json:"ingredient_name"`
	ItemCount float64 `xml:"itemcount" json:"ingredient_count,string"`
	ItemUnit  string  `xml:"itemunit" json:"ingredient_unit"`
}

type DBReader interface {
	Read(data []byte, v interface{}) error
}

type XMLParser struct{}

func (p XMLParser) Read(data []byte, v interface{}) error {
	err := xml.Unmarshal(data, v)
	if err != nil {
		return fmt.Errorf("Ошибка демаршалирования XML: %v", err)
	}
	return nil
}

type JSONParser struct{}

func (p JSONParser) Read(data []byte, v interface{}) error {
	err := json.Unmarshal(data, v)
	if err != nil {
		return fmt.Errorf("Ошибка демаршалирования JSON: %v", err)
	}
	return nil
}

func HandleError(err error) {
  if err != nil {
   fmt.Println(err)
   os.Exit(1)
  }
}
 
func PrintRecipes(recipes *Recipes) {
  fmt.Printf("\n")
	for i, cake := range recipes.Cakes {
		fmt.Println("Cake Name:", cake.Name)
		fmt.Println("Stove Time:", cake.StoveTime)
		for _, ingredient := range cake.Ingredients {
			fmt.Println("Item Name:", ingredient.ItemName)
			fmt.Println("Item Count:", ingredient.ItemCount)
			fmt.Println("Item Unit:", ingredient.ItemUnit)
		}
    if (i < len(recipes.Cakes) - 1) {
      fmt.Printf("\n")
    }
	}
}

func ReadFromFile(filename string) ([]byte, error) {
	data, err := ioutil.ReadFile(filename)
	if err != nil {
		return nil, fmt.Errorf("Ошибка чтения файла: %v", err)
	}
	return data, nil
}

func HandleErrorFilename(filename string) {
  if filename == "" {
		fmt.Println("Необходимо указать имя файла через флаг -f")
		os.Exit(1)
	}
}

func DetectFormat(data []byte) DBReader {
	if len(data) > 0 {
		if data[0] == '<' {
			return XMLParser{}
		} else if data[0] == '{' {
			return JSONParser{}
		}
	}
	return nil
}


func PrintXML(data interface{}) {
	xmlData, err := xml.MarshalIndent(data, "", "    ")
	if err != nil {
		fmt.Println("Ошибка при маршалинге в XML:", err)
		return
	}
	fmt.Printf("XML:\n%s\n", xmlData)
}

func PrintJSON(data interface{}) {
	jsonData, err := json.MarshalIndent(data, "", "    ")
	if err != nil {
		fmt.Println("Ошибка при маршалинге в JSON:", err)
		return
	}
	fmt.Printf("JSON:\n%s\n", jsonData)
}

// func main() {
//   filename := flag.String("f", "", "Имя файла для чтения")
// 	flag.Parse()
//   handleErrorFilename(*filename)

//   /* если название файла содержит */
//   /* xmlData заменить на Data, чтобы универсальное считывание с файла было */
// 	parserData, err := readFromFile(*filename)
// 	handleError(err)

//   parser := detectFormat(parserData)

//   recipes := new(Recipes)
//   /*  если filename содержит xml вызывать одну функцию, если json, то другую */
//   err2 := parser.Read(parserData, &recipes)
//   handleError(err2)

//   // printRecipes(recipes)

//   // printXML(recipes)
//   printJSON(recipes)

// }

// go run ex00.go -f original_database.xml
// go run ex00.go -f stolen_database.json

// go mod init parser.com/dbreader

// go build -o readDB && ./readDB 
