package wordtrie;

public class WordTrie {

    final int ALPHABET_SIZE = 26;

    class TrieNode {
        public TrieNode children[] = new TrieNode[ALPHABET_SIZE];
        public String item = "";
    }

    public TrieNode root = new TrieNode();

    public void insert(String word) {
        TrieNode node = root;
        for (char c: word.toCharArray()) {
            if (node.children[c - 'a'] == null)
                node.children[c - 'a'] = new TrieNode();
            node = node.children[c - 'a'];
        }
        node.item = word;
    }

    public boolean search(String word) {
        TrieNode node = root;
        for (char c: word.toCharArray()) {
            if (node.children[c - 'a'] == null)
                return false;
            node = node.children[c - 'a'];
        }
        
        if (node.item.equals(word)) {
            return true;
        } else {
            return false;
        }
    }

    public boolean startsWith(String word) {
        TrieNode node = root;
        for (char c: word.toCharArray()) {
            if (node.children[c - 'a'] == null)
                return false;
            node = node.children[c - 'a'];
        }
        return true;
    }


}
