class TrieNode: 
	
    # Trie node class 
    def __init__(self): 
            self.children = [None]*5

            # isEndOfWord is True if node represent the end of the word 
            self.isEndOfWord = False

class Trie: 
	
    # Trie data structure class 
    def __init__(self): 
            self.root = self.getNode() 

    def getNode(self): 
    
            # Returns new trie node (initialized to NULLs) 
            return TrieNode() 

    def _charToIndex(self,ch): 
            
            # private helper function 
            # Converts key current character into index 
            # use only 'a' through 'z' and lower case 
            chr_to_index = {'A' : 0, 'C' : 1, 'G' : 2, 'T' : 3, 'N' : 4}            
            return chr_to_index[ch]


    def insert(self,key): 
            
            # If not present, inserts key into trie 
            # If the key is prefix of trie node, 
            # just marks leaf node 
            pCrawl = self.root 
            length = len(key) 
            for level in range(length): 
                    index = self._charToIndex(key[level]) 

                    # if current character is not present 
                    if not pCrawl.children[index]: 
                            pCrawl.children[index] = self.getNode() 
                    pCrawl = pCrawl.children[index] 

            # mark last node as leaf 
            pCrawl.isEndOfWord = True

    def search(self, key): 
            
            # Search key in the trie 
            # Returns true if key presents 
            # in trie, else false 
            pCrawl = self.root 
            length = len(key) 
            for level in range(length): 
                    index = self._charToIndex(key[level]) 
                    if not pCrawl.children[index]: 
                            return False
                    pCrawl = pCrawl.children[index] 

            return pCrawl != None and pCrawl.isEndOfWord 


def generate_kmers(infile, kmer_size):
    with open(infile) as in_fh:
        while in_fh:
            in_fh.readline()
            read = in_fh.readline().strip()
            in_fh.readline()
            in_fh.readline()

            for i in range(len(read) - kmer_size + 1):
                kmer = read[i : i + kmer_size]
                yield kmer


# driver function 
def main(): 

    infile = "/Users/dongkim/Downloads/SRR062634.filt.fastq"
    kmer_size = 50

    # Trie object 
    t = Trie() 

    # Construct trie 
    for kmer in generate_kmers(infile, kmer_size): 
        t.insert(kmer) 


if __name__ == '__main__': 
	main() 

# This code is contributed by Atul Kumar (www.facebook.com/atul.kr.007) 

