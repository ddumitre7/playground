
//–1 printed out six times
var i;
for(i=5; i>=0; i--) {
	setTimeout(function() {
        console.log("1 -");    
		console.log(i===0 ? "go1!" : i);
	}, (5-i)*1000);
}

console.log("______________________________");

function loopBody(i) {
	setTimeout(function() {
        console.log("2 -");    
		console.log(i===0 ? "go2!" : i);
	}, (5-i)*1000);
}
var j;
for(j=5; j>0; j--) {
	loopBody(j);
}

console.log("______________________________");

var k;
for(k=5; k>0; k--) {
	(function(i) {
		setTimeout(function() {
            console.log("3 - ");    
			console.log(i===0 ? "go3!" : i);
		}, (5-i)*1000);
	})(k);
}

console.log("______________________________");

for(let i=5; i>0; i--) {
    setTimeout(function() {
    console.log("4 -");    
    console.log(i===0 ? "go!" : i);
    }, (5-i)*1000);
    }

console.log("______________________________");


