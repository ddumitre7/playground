const obj = { b: 2, c: 3, d: 4 };
let a, b, c;

// This produces an error:
//{a, b, c} = obj;


//This works:
({a, b, c} = obj);

const arr = [1, 2, 3, 4, 5];
let [x, y, ...rest] = arr;
x;
// 1
y;
// 2
rest;
// [3, 4, 5]


let aa = 5, bb = 10;
[aa, bb] = [bb, aa];
aa;
// 10
bb;
// 5