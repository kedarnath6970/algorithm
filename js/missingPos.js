

var segregate = function(array, size) {
    let j = 0;
    for (let i = 0; i < size; i++) {
        if (array[i] <= 0) {
            var temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            j++;
        }
    }
    return j;
}

var findMissingPositive = function(array, size) {

    for (let i = 0; i < size; i++) {
        var x = Math.abs(array[i]);
        if (x - 1 < size && array[x - 1] > 0)
            array[x - 1] = -array[x - 1];
    }

    for (let i = 0; i < size; i++) {
        if (array[i] > 0)
            return i + 1;
    }

    return size + 1;
}

var findMissing = function(array, size) {

    var shift = segregate(array, size);
    var array2 = [];
    var j = 0;
    for (let i = shift; i < size - shift; i++) {
        array2.push(array[i]);
        j++;
    }
    return findMissingPositive(array2, j);
}

var array = [0, 10, 2, -10, -20];
var size = 5;
var missing = findMissing(array, size);
console.log("The small positive missing number is " + missing);
