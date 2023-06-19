fnames=$(ls src| sort -r)
echo "">xtra.h
if [ "$1" = "true" ]; then
printf "#define __thenfi__ 1\n\n" >> xtra.h
fi
for file in $fnames; do
cat src/$file >> xtra.h
done
gcc -Wall -Werror -pedantic xtra.h && echo "No Errors Found"
rm -rf xtra.h.gch
