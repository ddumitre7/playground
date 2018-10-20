const f1 = function() { return "hello!"; }
// OR
const f1_ = () => "hello!";

//__________________________________________

const f2 = function(name) { return `Hello, ${name}!`; }
// OR
const f2_ = name => `Hello, ${name}!`;

//__________________________________________

const f3 = function(a, b) { return a + b; }
// OR
const f3_ = (a,b) => a + b;

const o = {
    name: 'Julie',
    greetBackwards: function() {
        const getReverseName = () => {
            let nameBackwards = '';
            for(let i=this.name.length-1; i>=0; i--) {
                nameBackwards += this.name[i];
            }
            return nameBackwards;
        };
    return `${getReverseName()} si eman ym ,olleH`;
    },
};

console.log(o.greetBackwards());