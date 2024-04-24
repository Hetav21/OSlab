echo "Name: Hetav Shah"
echo "Roll no: 198"
read -p "Enter the size of array : " N
echo "Enter $N elememts"
for((i=0;i<N;i++))
do
printf "$i: "
read a[$i]
done
echo "Array : ${a[@]}"
for ((i=0;i<N-1;i++))
do
for((j=i+1;j<N;j++))
do
if [[ ${a[i]} -gt ${a[j]} ]]
then
t=${a[i]}
a[i]=${a[j]}
a[j]=$t
fi
done
done
echo "Sorted Array : ${a[@]}"
