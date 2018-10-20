"use strict";

function add(a, b) {

     return a + b;
}

let c = 23.44;

console.log(`${c}`);

c = "Height";
console.log(`${c}`);

let c1;
console.log(`${c1}`);

const ROOM_TEMP_C = 21.5,
      MAX_TEMP_C = 30;

// ROOM_TEMP_C = 12;

let A = add("abc", "efg");

console.log(`${A}`);

let B = add("abc", 222);

console.log(`${B}`);

let S = 0.1,
    T = 0.2;
console.log(`${S + T}`);

const inf = Infinity;
console.log(`${inf + T}`);

console.log(`${inf / 0}`);
console.log(`${T / 0}`);
console.log(`${T / inf}`);

const small = Number.EPSILON;

//
const bigInt = Number.MAX_SAFE_INTEGER; //
const max = Number.MAX_VALUE;
//
const minInt = Number.MIN_SAFE_INTEGER; //
const min = Number.MIN_VALUE;
//
const nInf = Number.NEGATIVE_INFINITY;
//

console.log(`bigInt = ${bigInt}`);
console.log(`max    = ${max}`);
console.log(`minInt = ${minInt}`);
console.log(`min    = ${min}`);
console.log(`nInf   = ${nInf}`);

let s1 = "De Morgan’s law: \u2310(P \u22c0 Q) \u21D4 (\u2310P) \u22c1 (\u2310Q)";
console.log(`${s1}`);

let s2 = "\xc9p\xe9e is fun, but foil is more fun.";
console.log("This is a string: " + `${s2}`);

const multiline = `line1
     line2
     line3`;
console.log("This is a string: " + `${multiline}`);