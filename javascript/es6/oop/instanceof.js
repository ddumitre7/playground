
class Vehicle {
	constructor() {
		this.passengers = [];
		console.log("Vehicle created");
	}
	addPassenger(p) {
		this.passengers.push(p);
	}
}

class Car extends Vehicle {
	constructor() {
		super();
		console.log("Car created");
	}
	deployAirbags() {
		console.log("BWOOSH!");
	}
}


class Motorcycle extends Vehicle {}

const c = new Car();
const m = new Motorcycle();
if (c instanceof Car) console.log("TRUE");

if (c instanceof Vehicle) // true 
	console.log("TRUE"); 
else 
	console.log("FALSE");
if (m instanceof Car) // false
	console.log("TRUE"); 
else 
	console.log("FALSE");
if (m instanceof Motorcycle) // true
	console.log("TRUE"); 
else 
	console.log("FALSE");
if (m instanceof Vehicle)  // true
	console.log("TRUE");
else 
	console.log("FALSE");