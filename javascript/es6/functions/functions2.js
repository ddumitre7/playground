
const o = {
	name: 'Wallace',
	speak() { return `My name is ${this.name}!`; },
};


o.speak(); // "My name is Wallace!

const speak = o.speak;
if (speak === o.speak) console.log("TRUE"); // true; both variables refer to the same function
console.log(speak()); // "My name is !"


console.log("1)___________________________________________");

const o1 = o;

if (o === o1) console.log("TRUE Again!");
console.log(o1.speak());

console.log("2)___________________________________________");
console.log("3)___________________________________________");

const o2 = {
	name: "Julie",
	greetBackwards: function() {
		const self = this;
		function getReverseName() {
			let nameBackwards = "";
			for(let i = self.name.length - 1; i >= 0; i--) {
				nameBackwards += self.name[i];
			}
        
			return nameBackwards;
		}

		return `${getReverseName()} si eman ym ,olleH`;
	},
};

console.log(o2.greetBackwards());