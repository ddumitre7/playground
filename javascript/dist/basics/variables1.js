"use strict";

let currentTemp;
const targetTemp = null;
currentTemp = 19.5;
currentTemp = undefined;

//targetTemp = 78;

const obj = {};

console.log(`${currentTemp}`);

console.log(obj);

obj.size; // undefined
obj.color = "yellow"; // "yellow"


obj["not an identifier"] = 3;
obj["not an identifier"];
obj["color"];
const SIZE = Symbol();
obj[SIZE] = 8;
obj[SIZE];

console.log(obj);

obj.SIZE = 99;

console.log(obj);

obj[SIZE] = 808;

console.log(obj);

const sam1 = {
    name: 'Sam',
    age: 4
};
const sam2 = { name: 'Sam', age: 14 };
const sam3 = {
    name: 'Sam',
    classification: {
        kingdom: 'Anamalia',
        phylum: 'Chordata',
        class: 'Mamalia',
        order: 'Carnivoria',
        family: 'Felidae',
        subfaimily: 'Felinae',
        genus: 'Felis',
        species: 'catus'
    }
};

console.log(`${sam1.name}   ${sam2}   ${sam3}`);
console.log("_________________________________________");
console.log(sam1);
console.log(sam2);
console.log(sam3);

console.log("_________________________________________");

let s = "hello";
//s.rating = 3;
s.rating;

console.log(s.rating);

const numStr = "sss33.3";
const num = Number(numStr);

console.log(numStr);
console.log(num);

const b = true;
const n = b ? 1 : 0;

console.log(n);

console.log("#_________________________________________");

const v = { s: 1, k: true, l: "hello" };

console.log(v);