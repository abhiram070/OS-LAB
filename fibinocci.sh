echo "Enter the limit for fibinocci"
read limit
n1 = 0
n2 = 1
echo "$n1 \n$n2"
while [ $((n2 -le limit ))]
do
result = $n1 + $n2
$n1 = $n2
$n2 = $result
echo "$result" 
done