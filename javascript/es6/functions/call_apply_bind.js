const bruce = { name: "Bruce" };
const madeline = { name: "Madeline" };
// this function isn't associated with any object, yet
// it's using 'this'!
function greet() {
    return `Hello, I'm ${this.name}!`;
}

console.log(greet());
console.log(greet.call(bruce));
console.log(greet.call(madeline));
// "Hello, I'm !" - 'this' not bound
// "Hello, I'm Bruce!" - 'this' bound to 'bruce'
// "Hello, I'm Madeline!" - 'this' bound to 'madeline'

function update(birthYear, occupation) {
    this.birthYear = birthYear;
    this.occupation = occupation;
}

const updateBruce = update.bind(bruce);
updateBruce(1904, "actor");
// bruce is now { name: "Bruce", birthYear: 1904, occupation: "actor" }
console.log(">>>" + bruce.occupation);


updateBruce.call(madeline, 1274, "king");
// bruce is now { name: "Bruce", birthYear: 1274, occupation: "king" };
// madeline is unchanged