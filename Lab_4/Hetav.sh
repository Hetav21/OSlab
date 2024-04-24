echo "Name: Hetav Shah"
echo "Roll no: 198"
echo "Enter subject 1 marks: "
read s1
read -p "Enter subject 2 marks: " s2
echo "Enter subject 3 marls: "
read s3
total=$[s1+s2+s3]
echo "Total marks = $total"
p=$[total/3]
echo "Pr = $p%"
if [ $p -ge 100 ]
then
echo "WAH BETE!!"  
elif [ $p -ge 80 ]&&[ $p -le 100 ]
then
echo "Distinction"
elif [ $p -le 79 ]&&[ $p -ge 60 ]
then
echo "First Class"
elif [ $p -le 59]&&[ $p -ge 40 ]
then
echo "Second Class"
else
echo "Fail"
fi