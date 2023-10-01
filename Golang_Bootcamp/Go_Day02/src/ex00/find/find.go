package find

import (
	"fmt"
	"flag"
	"os"
	"path/filepath"
)

func FindFilesByExtension(rootDir string, searchFiles bool, searchDirs bool, searchSymlink bool, targetExtension string) ([]string, error) {
	var resultFiles []string
	err := filepath.Walk(rootDir, func(path string, info os.FileInfo, err error) error {
		if err != nil {
			// Пропустить элементы с ошибкой разрешений
			if os.IsPermission(err) {
				return nil
			}
			return err
		}
		if searchSymlink && info.Mode()&os.ModeSymlink != 0 {
			targetPath, err := os.Readlink(path)
			if err == nil {
				resultFiles = append(resultFiles, path + " -> " + targetPath)
			} else {
				resultFiles = append(resultFiles, path + " -> [broken]")
			}
			return nil // Не продолжаем обработку для символических ссылок
		}
		if searchFiles && !info.IsDir() {
			if targetExtension == "" || filepath.Ext(info.Name()) == ("." + targetExtension) {
				resultFiles = append(resultFiles, path)
			}
		}
		if searchDirs && info.IsDir() {
			resultFiles = append(resultFiles, path)
		}
		return nil
	})
	if err != nil {
		return nil, err
	}
	return resultFiles, nil
}

func Find() {
	searchFiles := flag.Bool("f", false, "Поиск файлов")
	searchDirs := flag.Bool("d", false, "Поиск директорий")
	searchSymlink := flag.Bool("sl", false, "Поиск символических ссылок")
	targetExtension:= flag.String("ext", "", "Расширение файлов")
	flag.Parse()
	
	// Получение аргументов после обработки флагов
	args := flag.Args()
  
	// Проверка наличия хотя бы одного аргумента (пути)
	if len(args) == 0 {
		fmt.Println("Usage: ./myFind [-d] [-f] [-sl] <directory>")
		return
	}
	
	if !*searchFiles && !*searchDirs && !*searchSymlink && *targetExtension == "" {
		*searchFiles = true
		*searchDirs = true
	}

	if !*searchFiles && *targetExtension != "" {
    fmt.Println("find: illegal option -- e\nUsage: ./myFind [-d] [-f] [-sl] <directory>")
    return
	}

	directory := args[len(args)-1]

	files, err := FindFilesByExtension(directory, *searchFiles, *searchDirs, *searchSymlink, *targetExtension)
	if err != nil {
		fmt.Println("Error:", err)
		return
	}

	for _, file := range files {
		fmt.Println(file)
	}
}