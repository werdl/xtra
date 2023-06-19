fnames=$(ls src)
echo "">xtra.h
for file in $fnames; do
cat src/$file >> xtra.h
done