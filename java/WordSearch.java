
import java.util.*;
import wordtrie.*;

public class WordSearch {
    static Set<String> result = new HashSet<String>();

    public static List<String> findWords(char[][] board, String[] words) {
        
        WordTrie trie = new WordTrie();
        for (String word: words) {
            trie.insert(word);
        }

        int m = board.length;
        int n = board[0].length;

        boolean[][] visited = new boolean[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, visited, "", i, j, trie);
            }
        }
        
        return new ArrayList<String>(result);
    }

    public static void dfs(char[][] board, boolean[][] visited, String word, int i, int j, WordTrie trie) {

        int m = board.length;
        int n = board[0].length;

        if (i < 0 || j < 0 || i >= m || j >= n)
            return;

        if (visited[i][j])
            return;

        word = word + board[i][j];

        if (!trie.startsWith(word))
            return;

        if (trie.search(word))
            result.add(word);

        visited[i][j] = true;
        dfs(board, visited, word, i-1, j, trie);
        dfs(board, visited, word, i+1, j, trie);
        dfs(board, visited, word, i, j-1, trie);
        dfs(board, visited, word, i, j+1, trie);
        visited[i][j] = false;
    }

    public static void main(String args[]) {

        char board[][] = {
            {'o', 'a', 'a', 'n'},
            {'e', 't', 'a', 'e'},
            {'i', 'h', 'k', 'r'},
            {'i', 'e', 'a', 't'},
        };

        String words[] = {"oath", "pea", "eat", "rain"};
        List<String> matched_words = findWords(board, words);

        for (String word: matched_words)
            System.out.println(word);
    }
}
