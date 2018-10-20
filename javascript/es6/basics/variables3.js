
function g(m) {

    m++;
}

const a1 = null;

console.log(`${a1}`);

// Numbers are immutable
let a = 4;
console.log(`${a}`);
g(a);
console.log(`${a}`);



function h(m) {

    m.a++;
}


let obj =  {
a : 33,
}


console.log(`${obj.a}`);

h(obj);

console.log(`${obj.a}`);