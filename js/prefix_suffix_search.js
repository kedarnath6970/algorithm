var TrieNode = function() {
    this.children = []
    for (let i = 0; i < 27; i++)
        this.children.push(null)
    this.weight = 0;
} 

TrieNode.prototype.getChild = function(index) {
    return this.children[index]
}

TrieNode.prototype.setChild = function(index) {
    this.children[index] = new TrieNode()
}


/**
 * @param {string[]} words
 */
var WordFilter = function(words) {
    this.trie = new TrieNode()
    for (var weight = 0; weight < words.length; weight++) {
        var word = words[weight] + '{'
        for (var i = 0; i < word.length; i++) {
            var cur = this.trie
            cur.weight = weight
            for (var j = i; j < 2 * word.length - 1; j++) {
                var k = word.charCodeAt(j % word.length) - 97
                if (cur.getChild(k) == null)
                    cur.setChild(k)
                cur = cur.getChild(k)
                cur.weight = weight
            }
        }
    }
    
};


/** 
 * @param {string} prefix 
 * @param {string} suffix
 * @return {number}
 */
WordFilter.prototype.f = function(prefix, suffix) {
    var cur = this.trie
    var word = suffix + "{" + prefix
    for (var i = 0; i < word.length; i++)
        if (cur.getChild(word.charCodeAt(i) - 97) != null)
            cur = cur.getChild(word.charCodeAt(i) - 97)
    return cur.weight
};

/** 
 * Your WordFilter object will be instantiated and called as such:
 * var obj = new WordFilter(words)
 * var param_1 = obj.f(prefix,suffix)
 **/
words = ["apple", "aapplee"]
prefix = "a"
suffix = "e"
var obj = new WordFilter(words)
var param_1 = obj.f(prefix, suffix)
console.log(param_1)
