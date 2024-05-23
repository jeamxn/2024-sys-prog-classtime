test1() {
  echo "test1"
}

function test2 {
  echo "test2"
}

function test3() {
  echo "test3"
}

function test4 {
  echo "test4"
  echo "$1, $2, ${10}"
  echo $(( $3 + $4 ))
  HELLO="hello"
  return -1
}

# test1
# test2
# test3
HELLO="world"
test4 hello world 100 200
ret=$?
echo "ret=$ret"
echo $result
echo $HELLO