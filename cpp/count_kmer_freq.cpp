
#include<iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <vector>
#include <utility>


using namespace std;

const int ALPHABET_SIZE = 5;
std::map<char, int> char_to_index;
char bases[ALPHABET_SIZE] = {'A', 'C', 'G', 'T', 'N'};

// Define a node struct for a trie
// Each node has at most five including 'N'.
// This implementation does not include reads with 'N'.
// But 'N' was kept as it is needed.
struct TrieNode {
        struct TrieNode* children[ALPHABET_SIZE];
        bool isEndOfWord;
        int freq;
};


// A utility function to check if a trie is empty
bool isEmpty(TrieNode* root) {
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return false;
    return true;
}


// A function to allocate each node in a trie
TrieNode* getNode() {
    struct TrieNode* node = new TrieNode;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;
    node->isEndOfWord = false;
    node->freq = 0;
    return node;
}

// Insert a key into a Trie
// root: a pointer to the root of a trie
// key: a key to be inserted into a trie
void insert(TrieNode* root, string key) {
    struct TrieNode* cur = root;

    for (int i = 0; i < key.length(); i++) { 
        int k = char_to_index[key[i]];
        if (!cur->children[k]) {
            cur->children[k] = getNode();
        }
        cur = cur->children[k];
    }
    cur->isEndOfWord = true;
    cur->freq += 1;
}


// A utility function to check if a node is a leaf.
bool isLeafNode(struct TrieNode* root) {
    return root->isEndOfWord != false;
}


// A function to get k-mers and their associated frequencies
// node: a pointer to the root of a trie
// kmer[]: an array to store each base of k-mer while traversing the trie.
// level: It is used as an index of each base while traversing.
// out_fh: an output filehandle
// num_kmers: To count total number of unique k-mers in the trie.
void get_kmer_freq(TrieNode* node, char kmer[], int level, ofstream& out_fh, int& num_kmers) {
    
    if (isLeafNode(node)) {
        kmer[level] = '\0';
        out_fh << string(kmer) <<"\t"<< node->freq <<endl;
        num_kmers += 1;
        return;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i]) {
            kmer[level] = bases[i];
            get_kmer_freq(node->children[i], kmer, level + 1, out_fh, num_kmers);
            delete node->children[i];
        }
    }
}


// A helper function to get the content of the trie into an output file.
void generate_kmers_with_freq(TrieNode* root, string outfilename, int& num_kmers,int kmer_size) {

    int level = 0;
    char str[kmer_size];
    ofstream out_fh (outfilename, std::ofstream::out);;
    get_kmer_freq(root, str, level, out_fh, num_kmers);
    out_fh.close();
}

// Read an intermediate k-mer by frequency file which is not sorted yet.
// infilename: a temp file which stores two columns separated by a tab; k-mer and freq
// freq_to_kmer: a vector to store frequency by k-mer. It will be used to sort k-mers by
// their frequencies.
void read_kmer_freq(string infilename, vector< pair <int, string> >& freq_to_kmer) {
    
    string line, kmer;
    int freq;
    ifstream in_fh(infilename);

    while (!in_fh.eof()) {
        getline(in_fh, line);
        if (line.length() == 0) break;
        int pos = line.find('\t');
        stringstream seq(line.substr(0, pos+1));
        seq >> kmer;
        stringstream num(line.substr(pos+1, line.length() - pos+2));
        num >> freq;
        freq_to_kmer.push_back( make_pair(freq, kmer));
    }

    in_fh.close();
}


// A utility functions to sort k-mers by their frequency in descending order.
bool compareFunc (const pair<int, string>& a, const pair<int, string>& b) {
    return (a.first > b.first);
}


int main(int argc, char** argv)
{
    cout << "Number of args: " << argc << endl;
    if (argc < 3) {
        cout<< "Some of required arguments are missiong" << endl;
        cout << "Usage: ./trie path_to_fastq_file kmer_size" <<endl;
        return 1;
    }

    string filename = argv[1];
    int kmer_size = atoi(argv[2]);
    string outfilename;
    
    if (argc == 4)
        outfilename = argv[3];
    else if(argc < 4)
       outfilename = "kmer_by_freq.tsv";

    struct TrieNode* root = getNode();

    char_to_index['A'] = 0;
    char_to_index['C'] = 1;
    char_to_index['G'] = 2;
    char_to_index['T'] = 3;
    char_to_index['N'] = 4;

    int num_kmers = 0;
    int num_of_invalid_reads = 0;
    int num_of_uniq_kmers = 0;
    
    string kmer, header, read, dumpy, quality;
    std::ifstream ifs;
    
    ifs.open(filename, std::ifstream::in);  

    while (!ifs.eof()) {
        getline(ifs, header);
        getline(ifs, read);
        getline(ifs, dumpy);
        getline(ifs, quality);

        if (read.find('N') != std::string::npos) {
            num_of_invalid_reads++;
            continue;
        }

        for(int i = 0; i < read.length() - kmer_size + 1; i++) {
            kmer = read.substr(i, kmer_size);
            insert(root, kmer);
            num_kmers++;
        }
    }

    generate_kmers_with_freq(root, outfilename, num_of_uniq_kmers, kmer_size);

    vector< pair <int, string> > freq_to_kmer;
    read_kmer_freq(outfilename, freq_to_kmer);
    sort(freq_to_kmer.begin(), freq_to_kmer.end(), compareFunc);

    ofstream out_fh(outfilename, std::ofstream::out);
    
    for(int i = 0; i < freq_to_kmer.size(); i++) {
        out_fh << freq_to_kmer[i].second << "\t"<< freq_to_kmer[i].first << endl;
    }
    
    out_fh.close();

    cout << "K-mer summary: " << endl;
    cout << "Total number of k-mers: " << num_kmers<< endl;
    cout << "Number of invalid reads with N: "<< num_of_invalid_reads<< endl;
    cout << "Number of unique k-mers: " << num_of_uniq_kmers << endl;

    return 0;
}
