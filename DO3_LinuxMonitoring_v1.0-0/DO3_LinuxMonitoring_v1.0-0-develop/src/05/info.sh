#!/bin/bash

# Общее число папок, включая подпапки
num_dirs=$(find "$1" -type d | wc -l)
echo "Total number of folders (including all nested ones) = $num_dirs"

# Топ 5 папок с самым большим весом в порядке убывания (путь и размер)
top_dirs=$(du -hs "$1"* 2>/dev/null | sort -r -n | head -5 | awk 'BEGIN{i=1}{printf "%d - %s, %s\n", i, $2, $1, i++}')
echo "TOP 5 folders of maximum size arranged in descending order (path and size):"
echo "$top_dirs"

# Общее число файлов
total_files=$(find $1 -type f | wc -l)
echo "Total number of files = $total_files"

# Получаем число конфигурационных файлов (с расширением .conf), текстовых файлов, исполняемых файлов, логов (файлов с расширением .log), архивов, символических ссылок и выводим на экран
echo "Number of:"
# Число конфигурационных файлов (с расширением .conf)
num_files_conf=$(find "$1" -type f -name "*.conf" | wc -l)
echo "Configuration files (with the .conf extension) =" $num_files_conf
# Число текстовых файлов
num_files_txt=$(find "$1" -type f -name "*.txt" | wc -l)
echo "Text files =" $num_files_txt
# Число исполняемых файлов
num_files_executable=$(find "$1" -type f -executable | wc -l)
echo "Executable files =" $num_files_executable
# Число логов (файлов с расширением .log)
num_files_log=$(find "$1" -type f -name "*.log" | wc -l)
echo "Log files (with the extension .log) =" $num_files_log
# Число архивов
num_files_archive=$(find "$1" -type f \( -name "*.zip" -o -name "*.tar.gz" -o -name "*.rar" -o -name "*.7z" \) | wc -l)
echo "Archive files =" $num_files_archive
# Число символических ссылок
num_symbol_links=$(find "$1" -type l | wc -l)
echo "Symbolic links =" $num_symbol_links

echo "TOP 10 files of maximum size arranged in descending order (path, size and type):"
for ((i=1; i<=10; i++))
do
    current_line=$(find $1 2>/dev/null -type f -exec du -h {} + | sort -rh | head -10 | sed "${i}q;d")
    if ! [[ -z $current_line ]]
    then
        path_to_file=$(echo $current_line | awk '{print $2}')
        file_size=$(echo $current_line | awk '{print $1}')
        file_extension=$(echo $current_line | grep -o -E "\.[^/.]+$" | sed 's/\.//')
        echo "$i - $path_to_file, $file_size, $file_extension"
    fi
done

echo "TOP 10 executable files of the maximum size arranged in descending order (path, size and MD5 hash of file):"
for ((i=1; i<=10; i++))
do
    current_line=$(find $1 -executable -type f -exec du -h {} + | sort -rh | head -10 | sed "${i}q;d")
    if ! [[ -z $current_line ]]
    then
        path_to_file=$(echo $current_line | awk '{print $2}')
        file_size=$(echo $current_line | awk '{print $1}')
        hash=$(md5sum $path_to_file | awk '{print $1}')
        echo "$i - $path_to_file, $file_size, $hash"
    fi
done
