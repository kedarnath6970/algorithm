public class Trie {
    
    static final int ALPHABET_SIZE = 26;

    static class TrieNode { 
    
        TrieNode[] children = new TrieNode[ALPHABET_SIZE];
        boolean isEndOfWord;

        TrieNode() {
            isEndOfWord = false;
            for (int i = 0; i < ALPHABET_SIZE; i++)
                children[i] = null;
        }
    };

    static TrieNode root;

    static void insert(String key) {
        int level;
        int length = key.length();
        int index;

        TrieNode cur = root;

        for (int i = 0; i < length; i++) {
            index = key.charAt(i) - 'a';
            if (cur.children[index] == null)
                cur.children[index] = new TrieNode();
            cur = cur.children[index];
        }
        cur.isEndOfWord = true;
    }

    static boolean search(String key) {
        int length = key.length();
        int index;

        TrieNode cur = root;

        for (int i = 0; i  < length; i++) {
            index = key.charAt(i) - 'a';
            if (cur.children[index] == null)
                return false;
            cur = cur.children[index];
        }

        return (cur != null && cur.isEndOfWord);
    }

    static boolean isEmpty() {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (root.children[i] != null)
                return false;
        }

        return true;
    }

    public static void main(String args[])
    {
        // Input keys (use only 'a' through 'z' and lower case)
        String keys[] = {"the", "a", "there", "answer", "any",
                         "by", "bye", "their"};

        String output[] = {"Not present in trie", "Present in trie"};


        root = new TrieNode();

        // Construct trie
        int i;
        for (i = 0; i < keys.length ; i++)
            insert(keys[i]);

        // Search for different keys
        if(search("the") == true)
            System.out.println("the --- " + output[1]);
        else System.out.println("the --- " + output[0]);

        if(search("these") == true)
            System.out.println("these --- " + output[1]);
        else System.out.println("these --- " + output[0]);

        if(search("their") == true)
            System.out.println("their --- " + output[1]);
        else System.out.println("their --- " + output[0]);

        if(search("thaw") == true)
            System.out.println("thaw --- " + output[1]);
        else System.out.println("thaw --- " + output[0]);
    }
}
