/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function (arr, n, res=[],curr=0) {
    for(let i=0;i<arr.length;i++){
        if(Array.isArray(arr[i])&&curr<n){
            flat(arr[i],n,res,curr+1)
        }
        else{
            res.push(arr[i])
        }
    }
    return res
};