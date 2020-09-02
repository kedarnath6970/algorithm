

#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <utility>

using namespace std;

void copy_bases(std::list<string> &seqs, std::map<char, int> bases) {
    for(std::map<char, int>::iterator it=bases.begin(); it != bases.end(); it++)
        seqs.push_back(string(1, it->first));
}

void print_bases(std::map<char, int> bases) {
    std::cout << "bases to be appened" << std::endl;
    for(std::map<char, int>::iterator it = bases.begin(); it != bases.end(); it++)
        if (it->first)
            std::cout << it->first << "\t" << it->second << std::endl;
}


void print_consensus_str(std::list<string> consensus_str, int seq_len) {
    for(std::list<string>::iterator it=consensus_str.begin(); it != consensus_str.end(); it++) {
        std::cout << (*it).length() << "\t" << (*it) << std::endl;
    }
}


void print_seqs(string** seqs, int num_tests, int num_seqs) {
    std::cout<<std::endl;
    std::cout << "Print out seqs from stdin" << std::endl;
    for(int i=0; i < num_tests; i++) {
        for(int j=0; j < num_seqs+1; j++) {
            std::cout << seqs[i][j] << std::endl;
        }
    }
}


std::list<string> get_consensus_seqs(string *seqs, int num_seqs, int seq_len) {
    std::list<string> base_string;
    for(int i=0; i<seq_len; i++) {
        std::map<char, int> base_map;
        int max_count = 0;
        for(int j=0; j<num_seqs+1; j++) {
            char b = seqs[j][i];
            if (base_map.count(b) == 0)
                base_map[b] = 1;
            else base_map[b] += 1;

            if (base_map[b] > max_count)
                max_count = base_map[b];
        }
        if (base_string.size() == 0) {
            for(std::map<char, int>::iterator it = base_map.begin(); it != base_map.end(); it++) {
                if (it->first && (it->second == max_count)) {
                    base_string.push_back(string(1, it->first));
                }
            }
        } else {
            int q_size = base_string.size();
            while (q_size > 0) {
                string bstr = base_string.front();
                base_string.pop_front();
                for (std::map<char, int>::iterator it=base_map.begin(); it != base_map.end(); it++) {
                    if (it->first) {
                        base_string.push_back(bstr + string(1, it->first));
                    }
                }
                q_size--;  
            }
        }
    }
    return base_string;
}

bool compare_lex(std::pair<string, int> p1, std::pair<string, int> p2) {
    if (p1.first < p2.first)
        return true;
    else return false;
}


int hamming_distance(string seq1, string seq2) {
    int h_dist = 0;
    for (int i=0; i < seq1.size(); i++)
        if (seq1[i] != seq2[i])
            h_dist++;
    return h_dist;
}

std::list<std::pair<string, int> > find_min_consensus(std::list<string> seqs, std::list<int> errors) {
    int min_error = std::numeric_limits<int>::max();
    std::list<std::pair<string, int> > consensus_index;
    std::list<string>::iterator sit = seqs.begin();
    for (std::list<int>::iterator it = errors.begin(); it != errors.end(); it++) {
        if ((*it) <= min_error) {
            min_error = *it;
        }
        sit++;
    }

    sit = seqs.begin();
    for (std::list<int>::iterator it = errors.begin(); it != errors.end(); it++) {
        if ((*it) == min_error) {
            consensus_index.push_back(std::make_pair(*sit, *it));
        }
        sit++;
    }
    return consensus_index;
}

std::pair<string, int> find_consensus_error(std::list<string> &consensus_str, string *seqs, int num_seqs) {
    std::list<int> consensus_error;
    for (std::list<string>::iterator it=consensus_str.begin(); it != consensus_str.end(); it++) {
        int con_error = 0;
        for (int i=0; i < num_seqs+1; i++) {
            if (seqs[i].size() > 0) {
                int dist = hamming_distance(*it, seqs[i]);
                con_error += dist;
            }
        }
        consensus_error.push_back(con_error); 
    }
    std::list<std::pair<string, int> > seq_info = find_min_consensus(consensus_str, consensus_error);
    if (seq_info.size() > 1)
        seq_info.sort(compare_lex);
    return seq_info.front();
}

int main() {
    int num_tests, num_seqs, seq_len;
    int n = 0;
    std::cout <<"num_tests: ";
    std::cin >> num_tests;
    string** test_seqs = new string *[num_tests];
    int test_num_seqs[num_tests+1];
    int test_seq_len[num_tests+1];
    while (n < num_tests) {
        std::cout << "num_seqs seq_len: ";
        std::cin >> num_seqs >> seq_len;
        test_num_seqs[n] = num_seqs;
        test_seq_len[n] = seq_len;
        test_seqs[n] = new string[num_seqs+1];
        int m = 0;
        while (m  < num_seqs+1) {
            std::getline(std::cin, test_seqs[n][m]);
            m++;
        }
        n++;
    }
    n = 0;
    while (n < num_tests) {
        std::list<string> consensus_str = get_consensus_seqs(test_seqs[n], test_num_seqs[n], test_seq_len[n]);
        std::pair<string, int> seq_info = find_consensus_error(consensus_str, test_seqs[n], test_num_seqs[n]);
        n++;

        std::cout << "Consensus seq: " << seq_info.first << std::endl;
        std::cout << "Consensus error: " << seq_info.second << std::endl;
    }
return 0;

}
