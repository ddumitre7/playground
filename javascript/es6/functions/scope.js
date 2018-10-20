const x = 3;
function f() {
console.log(x); // this will work
console.log(y); // this will cause a crash
}

//f();

const y = 4;
f();

console.log("____________________________");

let globalFunc;
{
let blockVar = 'a';
globalFunc = function() {
console.log(blockVar);
}
}
globalFunc();

console.log("____________________________");

const f1 = (function() {
    let count = 0;
    return function() {
        return `I have been called ${++count} time(s).`;
    }
})();

console.log(f1()); // "I have been called 1 time(s)."
console.log(f1()); // "I have been called 2 time(s)."

console.log("____________________________");

xx;
var xx = 55;
// let xx = 3;
xx;

console.log(xx + " ____________________________");

