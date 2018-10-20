let s1 = 3 + 5 + "8"; // evaluates to string "88"
let s2 = "3" + 5 + 8; // evaluates to string "358"

console.log(s1);
console.log(s2);

const a = { name: "Paris" };

let m = a + 2;
console.log(m);

let n = a + "22";
console.log(n);

let x = 0, y = 10, z;
let u = 89;
z = (++x, ++y, ++u);
console.log(z);
