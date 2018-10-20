const x = 3;
function f() {
	console.log(x); // this will work
	console.log(y); // this will cause a crash
}
const y = 30;
f();