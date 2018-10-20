const arr = [5, 7, 12, 15, 17];
arr.some(x => x%2===0); // true; 12 is even
arr.some(x => Number.isInteger(Math.sqrt(x))); // false; no squares