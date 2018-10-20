
// De ce paranteza inainte de funtion??
const getNextRainbowColor = (function() {
	const colors = ["red", "orange", "yellow", "green",
		"blue", "indigo", "violet"];
	let colorIndex = -1; // Why is this preserving its value???
	return function() {
		if(++colorIndex >= colors.length) colorIndex = 0;
		return colors[colorIndex];
	};
})();


const ff = getNextRainbowColor;

console.log(getNextRainbowColor());
console.log(getNextRainbowColor());
console.log(getNextRainbowColor());
console.log(getNextRainbowColor());
console.log(getNextRainbowColor());
console.log(getNextRainbowColor());
console.log(getNextRainbowColor());
console.log(getNextRainbowColor());

console.log("1________________");

console.log(getNextRainbowColor());
console.log(getNextRainbowColor());

function getRainbowIterator() {
    const colors = ['red', 'orange', 'yellow', 'green',
    'blue', 'indigo', 'violet'];
    let colorIndex = -1;
    return {
    next() {
    if(++colorIndex >= colors.length) colorIndex = 0;
    return { value: colors[colorIndex], done: false };
    }
    };
    }


console.log("2________________");


const rainbowIterator1 = getRainbowIterator();
const rainbowIterator2 = getRainbowIterator();
console.log(rainbowIterator1.next().value);
console.log(rainbowIterator1.next().value);
console.log(rainbowIterator2.next().value);
console.log(rainbowIterator2.next().value);






