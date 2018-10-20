function rand(m, n) {
return m + Math.floor((n - m + 1)*Math.random());
}

// Randomly returns a string representing one of the six
// valeus in a dice
function randFace() {
return [1, 2, 3, 4, 5, 6][rand(0, 5)];
}

let i = 0, average = 0;
do {
    let value = randFace(); 
    // console.log(value);
    average += value;
    i++;
} while (i <= 1000);

console.log("Avegerage is: " + average / i);


let arr1 = [121, 122, 123, 125];
console.log(arr1[3]);