

var myFunction = function() {
	if(this.timesRun)
		this.timesRun += 1;
	else
		this.timesRun = 1;
	// do some actual work

	console.log(this.timesRun);
};
myFunction();
// => 1;
myFunction();
// => 2;
myFunction();
// => 3;

