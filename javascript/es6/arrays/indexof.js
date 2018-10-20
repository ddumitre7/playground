const o = { name: "Jerry" };
const arr = [1, 5, "a", o, true, 5, [1, 2], {name1: "Mary"} , "9"];


console.log(arr.indexOf(5)); // returns 1
arr.lastIndexOf(5); // returns 5
arr.indexOf("a"); // returns 2
arr.lastIndexOf("a"); // returns 2
arr.indexOf({ name: "Jerry" }); // returns -1
console.log(arr.indexOf({ name1: "Mary" })); // returns -1
arr.indexOf(o); // returns 3
arr.indexOf([1, 2]); // returns -1
arr.indexOf("9"); // returns 7
arr.indexOf(9); // returns -1

arr.indexOf("a", 5);
arr.indexOf(5, 5);
arr.lastIndexOf(5, 4);
arr.lastIndexOf(true, 3);


arr.indexOf("a", 5); // returns -1
arr.indexOf(5, 5); // returns 5
arr.lastIndexOf(5, 4); // returns 1
arr.lastIndexOf(true, 3); // returns -1
