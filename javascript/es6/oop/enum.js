const SYM2 = Symbol();

const o = { a: 1, b: 2, c: 3, [SYM2]: 4 };

// Note that the for...in loop doesn’t include properties with symbol keys. 
for(let prop in o) {
    if(!o.hasOwnProperty(prop)) continue;
    console.log(`${prop}: ${o[prop]}`);
}

console.log(`__________________________________________`);

const SYM1 = Symbol();
const o1 = { a: 1, b: 2, c: 3, [SYM1]: 4 };
Object.keys(o1).forEach(prop => console.log(`${prop}: ${o[prop]}`));

console.log(`__________________________________________`);

const o3 = { apple: 1, xochitl: 2, balloon: 3, guitar: 4, xylophone: 5, };
Object.keys(o3)
.filter(prop => prop.match(/^x/))
.forEach(prop => console.log(`${prop}: ${o3[prop]}`));

