function myF(i = 99) {
	let counter = 1;
	
	console.log(i===0 ? "GO!" : i);
	console.log(" Counter: " + counter);

	return function() { return `I have been called ${counter++} time(s).`; };
}



function countdown2() {
	console.log("Countdown:");
	for(let i=5; i>=0; i--) {
		// i is now block-scoped
		setTimeout(function() { myF(i); }, (5-i)*1000);
	}
}

countdown2();

console.log("1)__________________________________");

let ff = myF(9);

console.log(ff());
console.log(ff());
console.log(ff());
console.log(ff());
console.log(ff());
console.log(ff());

console.log("2)__________________________________");


setTimeout(function() { 
	let ff = myF(9);
	console.log("XXX__________________________________XXX");
	console.log(ff());
	console.log(ff());
	console.log(ff());
	console.log(ff()); 
	console.log("XXX__________________________________XXX");
}, 7000);

console.log("3)__________________________________");

setTimeout(myF, 8000);
setTimeout(myF, 9000);

