/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function (init) {
    let currvalue = init;
    return {
        increment: () => {
            return ++currvalue;
        },
        decrement: () => {
            return --currvalue;
        },
        reset: () => {
            currvalue = init;
            return init;
        }
    };

};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */