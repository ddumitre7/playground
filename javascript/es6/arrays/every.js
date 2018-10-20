const arr = [4, 6, 16, 36];
arr.every(x => x%2===0); // true; no odd numbers
arr.every(x => Number.isInteger(Math.sqrt(x))); // false; 6 is not square