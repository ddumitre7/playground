function countdown() {
	let i;
	// note we declare let outside of the for loop
	console.log("Countdown:");
	for(i=5; i>=0; i--) {
		setTimeout(function() {
            let now = new Date();
            console.log(i===0 ? "GO!" : i);
            console.log(`Time: ${now}`);
		}, (5-i)*1000);
	}
}


countdown();