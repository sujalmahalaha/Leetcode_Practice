/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function(fn) {
    
    let obj = {};
    for(let i=0; i<this.length ; i++){
        let key = fn(this[i]);
        if(obj.hasOwnProperty(key)){
            obj[key].push(this[i]);
        }
        else{
            obj[key] = [this[i]];
        }
    }
    return obj;
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */