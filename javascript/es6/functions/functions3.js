const g = function f(stop) {
    if(stop) console.log('f stopped');

    else {

        console.log('f going');
        f(true);
    }
};


g(false);
console.log("________________________________");

// f(fasle); // ReferenceError: f is not defined
