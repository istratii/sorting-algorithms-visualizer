
#!/bin/sh

for file in $(find . -name "*.[ch]"); do
	echo "formatting $file"
	clang-format -i "$file"
done
