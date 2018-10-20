let v1 = 33;
let v2 = "33"


if (v1 == v2)
    console.log("Equal - abstract");
else
    console.log("Not equal - abstract");


if (v1.toString() === v2)
    console.log("Equal - strict");
else
    console.log("Not equal - strict");


const a = { name: "an object" };
const b = { name: "an object" };

if (a === b)
    console.log("a, b Equal - strict");
else
    console.log("a, b Not equal - strict");


let suppliedOptions;
const options = suppliedOptions || { name: "Default" }
console.log(options);
suppliedOptions = {name: "Given"};
const options1 = suppliedOptions || { name: "Default" }
console.log(options1);
