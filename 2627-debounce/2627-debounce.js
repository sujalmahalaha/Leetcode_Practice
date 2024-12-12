/**
 * @param {Function} fn
 * @param {number} t milliseconds
 * @return {Function}
 */
var debounce = function(fn, t) {
    let timer; // Store the timeout ID

    return function(...args) {
        clearTimeout(timer); // Clear any previous timer
        timer = setTimeout(() => {
            fn(...args); // Call the function after the delay
        }, t); // Delay by t milliseconds
    };
};


/**
 * const log = debounce(console.log, 100);
 * log('Hello'); // cancelled
 * log('Hello'); // cancelled
 * log('Hello'); // Logged at t=100ms
 */