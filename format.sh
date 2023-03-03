
#!/bin/sh

for file in $(find . -name "*.[ch]"); do
	echo "Formatting $file"
	clang-format -i "$file"
done
